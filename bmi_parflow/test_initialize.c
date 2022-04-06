#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include <bmi.h>
#include "bmi_parflow.h"

int
main (void)
{
  int status = BMI_SUCCESS;
  Bmi * model = (Bmi*)malloc (sizeof(Bmi));

  register_bmi_heat(model);

  {
    fprintf (stdout, "Initializing... ");

    status = model->initialize(model, "config.txt");
    if (status == BMI_FAILURE)
      return BMI_FAILURE;

    fprintf (stdout, "PASS\n");
  }
  return BMI_SUCCESS;
}
