/*
 * Include Files
 *
 */

#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>

/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width                        7
#define y_width                        1

/*
 * Create external references here.
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void Lead_car_find_Outputs_wrapper(const real32_T *u0,
  const real32_T *u1,
  real32_T *closest_car_pos,
  real32_T *closest_car_spd,
  real32_T *dist)
{
  /* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
  /* This sample sets the output equal to the input
     y0[0] = u0[0];
     For complex signals use: y0[0].re = u0[0].re;
     y0[0].im = u0[0].im;
     y1[0].re = u1[0].re;
     y1[0].im = u1[0].im;
   */
  int n= 6;
  int i= 1;
  for (i=1;i<=n;i++) {
    if (u0[i]>u0[0]) {
      closest_car_pos[0] = u0[i];
      closest_car_spd[0] = u1[i];
      break;
    } else {
      closest_car_pos[0] = u0[0];
      closest_car_spd[0] = u1[0];
    }
  }

  for (i=1;i<=n;i++) {
    if (u0[i]>u0[0] && u0[i]<closest_car_pos[0]) {
      closest_car_pos[0] = u0[i];
      closest_car_spd[0] = u1[i];
    }
  }

  dist[0] = closest_car_pos[0] - u0[0];

  /* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
