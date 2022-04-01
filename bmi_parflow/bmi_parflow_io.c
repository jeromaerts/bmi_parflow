#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "amps.h"
#include "parflow.h"
#include "solver.h"

#include <bmi.h>
#include "bmi_parflow.h"


#define OK (0)
#define NOT_OK (1)

amps_ThreadLocalDcl(PFModule *, Solver_module);
amps_ThreadLocalDcl(PFModule *, solver);
amps_ThreadLocalDcl(Vector   *, evap_trans);

int initialize_arrays (ParflowBMIModel *self);


void wrfparflowinit_(const char *input_file)
{
  Grid         *grid;
  const char *seperators = " \n";
  /* Fortran char array is not NULL terminated */
  const char *filename = strtok((char *)input_file, seperators);

  /*-----------------------------------------------------------------------
  * Initialize AMPS from existing MPI state
  *-----------------------------------------------------------------------*/
  if (amps_EmbeddedInit())
  {
    amps_Printf("Error: amps_EmbeddedInit initalization failed\n");
    exit(1);
  }

  /*-----------------------------------------------------------------------
  * Set up globals structure
  *-----------------------------------------------------------------------*/
  
  NewGlobals((char *)filename);

  /*-----------------------------------------------------------------------
  * Read the Users Input Deck
  *-----------------------------------------------------------------------*/
  amps_ThreadLocal(input_database) = IDB_NewDB(GlobalsInFileName);

  /*-----------------------------------------------------------------------
  * Setup log printing
  *-----------------------------------------------------------------------*/
  NewLogging();

  /*-----------------------------------------------------------------------
  * Setup timing table
  *-----------------------------------------------------------------------*/
  /* NewTiming(); */

  /* End of main includes */

  /* Begin of Solver includes */

  GlobalsNumProcsX = GetIntDefault("Process.Topology.P", 1);
  GlobalsNumProcsY = GetIntDefault("Process.Topology.Q", 1);
  GlobalsNumProcsZ = GetIntDefault("Process.Topology.R", 1);

  GlobalsNumProcs = amps_Size(amps_CommWorld);

  GlobalsBackground = ReadBackground();

  GlobalsUserGrid = ReadUserGrid();

  SetBackgroundBounds(GlobalsBackground, GlobalsUserGrid);

  GlobalsMaxRefLevel = 0;

  amps_ThreadLocal(Solver_module) = PFModuleNewModuleType(SolverImpesNewPublicXtraInvoke, SolverRichards, ("Solver"));

  amps_ThreadLocal(solver) = PFModuleNewInstance(amps_ThreadLocal(Solver_module), ());

  /* End of solver includes */

  SetupRichards(amps_ThreadLocal(solver));

  /* Create the flow grid */
  grid = CreateGrid(GlobalsUserGrid);

  /* Create the PF vector holding flux */
  amps_ThreadLocal(evap_trans) = NewVectorType(grid, 1, 1, vector_cell_centered);
  InitVectorAll(amps_ThreadLocal(evap_trans), 0.0);
}

void
parflow_from_input_file (ParflowBMIModel **parflow_bmi_model, const char * filename)
{
  ParflowBMIModel * self = NULL;

  if (parflow_bmi_model == NULL)
    *parflow_bmi_model = (ParflowBMIModel*) malloc (sizeof(ParflowBMIModel));

  self = *parflow_bmi_model;


  wrfparflowinit_(filename);
  
  self->spacing[0] = 1.;
  self->spacing[1] = 1.;

  initialize_arrays (self);
}

void
parflow_from_default (ParflowBMIModel **parflow_bmi_model)
{
  ParflowBMIModel * self;

  if (*parflow_bmi_model == NULL)
    *parflow_bmi_model = (ParflowBMIModel*) malloc (sizeof(ParflowBMIModel));

  self = *parflow_bmi_model;

  if (self) {
    self->alpha = 1.;
    self->t_end = 10.;
    self->shape[0] = 10;
    self->shape[1] = 20;
    self->spacing[0] = 1.;
    self->spacing[1] = 1.;
    self->dt = 1. / (4. * self->alpha);
  }

  initialize_arrays (self);
}

int
initialize_arrays (ParflowBMIModel *self)
{
  if (self) {
    int i;
    const int n_rows = self->shape[0];
    const int n_cols = self->shape[1];
    const int n_elements = n_rows * n_cols;
    double top_x = self->shape[1] - 1;

    /* Allocate memory */
    self->z = (double **)malloc (sizeof (double*) * n_rows);
    self->temp_z = (double **)malloc (sizeof (double*) * n_rows);

    if (!self->temp_z || !self->z)
      return NOT_OK;

    self->z[0] = (double *)malloc (sizeof (double) * n_elements);
    self->temp_z[0] = (double *)malloc (sizeof (double) * n_elements);

    if (!self->temp_z[0] || !self->z[0])
      return NOT_OK;

    for (i=1; i<n_rows; i++) {
      self->z[i] = self->z[i-1] + n_cols;
      self->temp_z[i] = self->temp_z[i-1] + n_cols;
    }

    self->t = 0;
    for (i = 0; i < n_elements; i++)
      self->z[0][i] = rand ()*1./RAND_MAX * top_x * top_x * .5 - top_x * top_x * .25;
    for (i = 0; i < n_rows; i++) {
      self->z[i][0] = 0.;
      self->z[i][n_cols-1] = 0.;
    }
    for (i = 0; i < n_cols; i++) {
      self->z[0][i] = 0.;
      self->z[n_rows-1][i] = 0.;
    }

    memcpy (self->temp_z[0], self->z[0], sizeof (double) * n_elements);
  }
  else
    return 1;

  return OK;
}



int
parflow_free (ParflowBMIModel *self)
{
  if (self) {
    free (self->temp_z[0]);
    free (self->temp_z);
    free (self->z[0]);
    free (self->z);
    free (self);
  }
  return OK;
}

