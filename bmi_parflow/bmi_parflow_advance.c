
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

int
parflow_advance_in_time (ParflowBMIModel * self)
{
  if (self) {
    const int n_elements = self->shape[0] * self->shape[1];

    parflow_solve_2d (self->z, self->shape, self->spacing, self->alpha,
        self->dt, self->temp_z);
    self->t += self->dt;
    memcpy (self->z[0], self->temp_z[0], sizeof (double) * n_elements);
  }
  else
    return NOT_OK;

  return OK;
}


int
parflow_solve_2d (double ** z, int shape[2], double spacing[2], double alpha,
    double dt, double ** out)
{
  {
    int i, j;
    const int top_row = shape[0] - 1;
    const int top_col = shape[1] - 1;
    const double dx2 = spacing[1] * spacing[1];
    const double dy2 = spacing[0] * spacing[0];
    const double c = alpha * dt / (dx2 + dy2);

    for (i=1; i<top_row; i++)
      for (j=1; j<top_col; j++)
        out[i][j] = c * (dx2 * (z[i][j - 1] + z[i][j + 1]) +
                         dy2 * (z[i - 1][j] + z[i + 1][j]) -
                         2. * (dx2 + dy2) * z[i][j]);

    for (j=0; j<shape[1]; j++) {
        out[0][j] = 0.;
        out[top_row][j] = 0.;
    }
    for (i=0; i<shape[0]; i++) {
        out[i][0] = 0.;
        out[i][top_col] = 0.;
    }

    for (i=1; i<top_row; i++)
      for (j=1; j<top_col; j++)
        out[i][j] += z[i][j];
  }
}