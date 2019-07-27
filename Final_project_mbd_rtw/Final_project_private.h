/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_project_private.h
 *
 * Code generated for Simulink model 'Final_project'.
 *
 * Model version                   : 1.291
 * Simulink Coder version          : 8.14 (R2018a) 06-Feb-2018
 * MBDT for S32K1xx Series Version : 2018.R1 (R2016b-R2018a) 23-Jul-2018
 * C/C++ source code generated on  : Fri Apr 19 12:10:53 2019
 *
 * Target selection: mbd_s32k14.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Final_project_private_h_
#define RTW_HEADER_Final_project_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "path_data.h"
#include "path_data.h"
#include "Final_project.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void VD_equation_Start_wrapper(const real_T *L1, const int_T p_width0,
    const real_T *L2, const int_T p_width1,
    const real_T *m, const int_T p_width2);
  extern void VD_equation_Outputs_wrapper(const real32_T *delta,
    const real32_T *u,
    const real32_T *psi,
    real32_T *x_dot,
    real32_T *y_dot,
    real32_T *psi_dot,
    const real_T *L1, const int_T p_width0,
    const real_T *L2, const int_T p_width1,
    const real_T *m, const int_T p_width2);
  extern void VD_equation_Terminate_wrapper(const real_T *L1, const int_T
    p_width0,
    const real_T *L2, const int_T p_width1,
    const real_T *m, const int_T p_width2);

#ifdef __cplusplus

}
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern void Lead_car_find_Start_wrapper(void);
  extern void Lead_car_find_Outputs_wrapper(const real32_T *u0,
    const real32_T *u1,
    real32_T *closest_car_pos,
    real32_T *closest_car_spd,
    real32_T *dist);
  extern void Lead_car_find_Terminate_wrapper(void);

#ifdef __cplusplus

}
#endif

extern flexcan_state_t canCom0_State;
extern flexcan_msgbuff_t canCom0_recvBuff2;
extern flexcan_msgbuff_t canCom0_recvBuff3;
extern flexcan_msgbuff_t canCom0_recvBuff12;
extern flexcan_msgbuff_t canCom0_recvBuff13;
extern flexcan_msgbuff_t canCom0_recvBuff14;
extern flexcan_msgbuff_t canCom0_recvBuff15;
extern flexcan_msgbuff_t canCom0_recvBuff16;
extern flexcan_msgbuff_t canCom0_recvBuff17;
extern flexcan_msgbuff_t canCom0_recvBuff4;
extern flexcan_msgbuff_t canCom0_recvBuff5;
extern flexcan_msgbuff_t canCom0_recvBuff6;
extern flexcan_msgbuff_t canCom0_recvBuff7;
extern flexcan_msgbuff_t canCom0_recvBuff8;
extern flexcan_msgbuff_t canCom0_recvBuff9;
extern flexcan_msgbuff_t canCom0_recvBuff10;
extern flexcan_msgbuff_t canCom0_recvBuff11;

#if defined(__MWERKS__)

double fmod (double x, double y);
double fabs (double);

#endif

extern real_T uMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1);
extern void uMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[],
  int32_T n2, uint32_T y[], int32_T n);
extern void SwitchCaseActionSubsystem2(const uint8_T rtu_sn[8], real32_T *rty_s,
  real32_T *rty_n);
extern void SwitchCaseActionSubsystem3(const uint8_T rtu_psius[8], real32_T
  *rty_psi, real32_T *rty_us);
extern void Final_project_step0(void);
extern void Final_project_step1(void);
extern void Final_project_step2(void);

#endif                                 /* RTW_HEADER_Final_project_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
