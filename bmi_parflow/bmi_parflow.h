#ifndef BMI_PARFLOW_H_INCLUDED
#define BMI_PARFLOW_H_INCLUDED

#if defined(__cplusplus)
extern "C" {
#endif

#include <bmi.h>


typedef struct {
  double alpha;
  double dt;
  double t;
  double t_end;

  int shape[2];
  double spacing[2];
  double **z;

  double **temp_z;
} ParflowBMIModel;


Bmi* register_bmi_parflow(Bmi *model);
ParflowBMIModel* new_bmi_parflow(void);

extern void parflow_from_input_file (ParflowBMIModel **parflow_bmi_model, const char *filename);
extern void parflow_from_default (ParflowBMIModel **parflow_bmi_model);
extern int parflow_advance_in_time (ParflowBMIModel * self);
extern int parflow_solve_2d (double ** z, int shape[2], double spacing[2],
    double alpha, double dt, double ** out);
extern int parflow_free (ParflowBMIModel *self);


#if defined(__cplusplus)
}
#endif

#endif
