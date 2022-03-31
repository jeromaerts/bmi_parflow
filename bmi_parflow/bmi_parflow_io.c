#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <bmi.h>
#include "bmi_parflow.h"

#define OK (0)
#define NOT_OK (1)


int initialize_arrays (ParflowBMIModel *self);


void
parflow_from_input_file (ParflowBMIModel **parflow_bmi_model, const char * filename)
{
  ParflowBMIModel * self = NULL;

  if (parflow_bmi_model == NULL)
    *parflow_bmi_model = (ParflowBMIModel*) malloc (sizeof(ParflowBMIModel));

  self = *parflow_bmi_model;

  {
    FILE *fp = NULL;
    double alpha = 0.;
    double t_end = 1.;
    int n_x = 0;
    int n_y = 0;

    fp = fopen (filename, "r");
    fscanf (fp, "%lf, %lf, %d, %d", &alpha, &t_end, &n_x, &n_y);

    self->dt = 1. / (4. * alpha);
    self->alpha = alpha;
    self->t_end = t_end;
    self->shape[0] = n_y;
    self->shape[1] = n_x;
  }

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

