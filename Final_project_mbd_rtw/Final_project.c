/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_project.c
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

#include "Final_project.h"
#include "Final_project_private.h"

/* Named constants for Chart: '<S25>/Chart' */
#define IN_MANUAL                      ((uint8_T)1U)
#define IN_POSITION                    ((uint8_T)2U)
#define IN_Speed                       ((uint8_T)3U)

/* Block signals (default storage) */
B rtB;

/* Block states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static void rate_monotonic_scheduler(void);
flexcan_state_t canCom0_State;
flexcan_msgbuff_t canCom0_recvBuff2;
flexcan_msgbuff_t canCom0_recvBuff3;
flexcan_msgbuff_t canCom0_recvBuff12;
flexcan_msgbuff_t canCom0_recvBuff13;
flexcan_msgbuff_t canCom0_recvBuff14;
flexcan_msgbuff_t canCom0_recvBuff15;
flexcan_msgbuff_t canCom0_recvBuff16;
flexcan_msgbuff_t canCom0_recvBuff17;
flexcan_msgbuff_t canCom0_recvBuff4;
flexcan_msgbuff_t canCom0_recvBuff5;
flexcan_msgbuff_t canCom0_recvBuff6;
flexcan_msgbuff_t canCom0_recvBuff7;
flexcan_msgbuff_t canCom0_recvBuff8;
flexcan_msgbuff_t canCom0_recvBuff9;
flexcan_msgbuff_t canCom0_recvBuff10;
flexcan_msgbuff_t canCom0_recvBuff11;
real_T uMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T i;
  int32_T exp_0;
  y = 0.0;
  exp_0 = e1;
  for (i = 0; i < n1; i++) {
    y += ldexp(u1[i], exp_0);
    exp_0 += 32;
  }

  return y;
}

void uMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T nj;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a1;
  uint32_T a0;
  uint32_T b1;
  uint32_T w10;
  uint32_T w01;
  uint32_T cb;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    k = n - i;
    nj = n2 <= k ? n2 : k;
    k = i;
    for (j = 0; j < nj; j++) {
      yk = y[k];
      u1i = u2[j];
      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk += cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Final_project_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(rtM, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(rtM, 2));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 2 */
  rtM->Timing.RateInteraction.TID0_2 = (rtM->Timing.TaskCounters.TID[2] == 0);

  /* tid 1 shares data with slower tid rate: 2 */
  if (rtM->Timing.TaskCounters.TID[1] == 0) {
    rtM->Timing.RateInteraction.TID1_2 = (rtM->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (rtM->Timing.TaskCounters.TID[1])++;
  if ((rtM->Timing.TaskCounters.TID[1]) > 19) {/* Sample time: [0.01s, 0.0s] */
    rtM->Timing.TaskCounters.TID[1] = 0;
  }

  (rtM->Timing.TaskCounters.TID[2])++;
  if ((rtM->Timing.TaskCounters.TID[2]) > 99) {/* Sample time: [0.05s, 0.0s] */
    rtM->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S7>/Switch Case Action Subsystem2'
 *    '<S8>/Switch Case Action Subsystem2'
 *    '<S9>/Switch Case Action Subsystem2'
 *    '<S10>/Switch Case Action Subsystem2'
 *    '<S11>/Switch Case Action Subsystem2'
 *    '<S12>/Switch Case Action Subsystem2'
 */
void SwitchCaseActionSubsystem2(const uint8_T rtu_sn[8], real32_T *rty_s,
  real32_T *rty_n)
{
  /* S-Function (xpcbytepacking): '<S13>/Byte Unpacking ' */

  /* Byte Unpacking: <S13>/Byte Unpacking  */
  (void)memcpy((uint8_T*)rty_s, (uint8_T*)&rtu_sn[0] + 0, 4);
  (void)memcpy((uint8_T*)rty_n, (uint8_T*)&rtu_sn[0] + 4, 4);
}

/*
 * Output and update for action system:
 *    '<S7>/Switch Case Action Subsystem3'
 *    '<S8>/Switch Case Action Subsystem3'
 *    '<S9>/Switch Case Action Subsystem3'
 *    '<S10>/Switch Case Action Subsystem3'
 *    '<S11>/Switch Case Action Subsystem3'
 *    '<S12>/Switch Case Action Subsystem3'
 */
void SwitchCaseActionSubsystem3(const uint8_T rtu_psius[8], real32_T *rty_psi,
  real32_T *rty_us)
{
  /* S-Function (xpcbytepacking): '<S14>/Byte Unpacking ' */

  /* Byte Unpacking: <S14>/Byte Unpacking  */
  (void)memcpy((uint8_T*)rty_psi, (uint8_T*)&rtu_psius[0] + 0, 4);
  (void)memcpy((uint8_T*)rty_us, (uint8_T*)&rtu_psius[0] + 4, 4);
}

/* Model step function for TID0 */
void Final_project_step0(void)         /* Sample time: [0.0005s, 0.0s] */
{
  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<S4>/RT' */
  if (rtM->Timing.RateInteraction.TID0_2) {
    rtB.RT_f = rtDW.RT_Buffer0;

    /* RateTransition: '<S4>/RT1' */
    memcpy(&rtB.RT1[0], &rtDW.RT1_Buffer0[0], 90U * sizeof(uint8_T));
  }

  /* End of RateTransition: '<S4>/RT' */

  /* S-Function (fcncallgen): '<S4>/Function-Call Generator2' incorporates:
   *  SubSystem: '<S4>/UART Iteration'
   */
  /* Outputs for Resettable SubSystem: '<S76>/Resettable Subsystem' incorporates:
   *  ResetPort: '<S77>/Reset'
   */
  if (((rtPrevZCX.ResettableSubsystem_Reset_ZCE == POS_ZCSIG) != (int32_T)
       rtB.RT_f) && (rtPrevZCX.ResettableSubsystem_Reset_ZCE !=
                     UNINITIALIZED_ZCSIG)) {
    /* InitializeConditions for Delay: '<S77>/Delay' */
    rtDW.Delay_DSTATE = 0.0;
  }

  rtPrevZCX.ResettableSubsystem_Reset_ZCE = rtB.RT_f;

  /* Sum: '<S77>/Sum' incorporates:
   *  Constant: '<S77>/Constant'
   *  Delay: '<S77>/Delay'
   */
  rtDW.Delay_DSTATE++;

  /* End of Outputs for SubSystem: '<S76>/Resettable Subsystem' */

  /* MultiPortSwitch: '<S76>/Index Vector' incorporates:
   *  Delay: '<S77>/Delay'
   */
  rtB.IndexVector = rtB.RT1[(int32_T)rtDW.Delay_DSTATE - 1];

  /* S-Function (lpuart_s32k14_transmit): '<S76>/LPUART_Transmit1' */
  {
    LPUART_DRV_SendData(1, &rtB.IndexVector, 1);
  }

  /* End of Outputs for S-Function (fcncallgen): '<S4>/Function-Call Generator2' */

  /* S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive' */
  FLEXCAN_DRV_Receive(0, 2, &canCom0_recvBuff2);

  /* S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive1' */
  FLEXCAN_DRV_Receive(0, 3, &canCom0_recvBuff3);

  /* S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive10' */
  FLEXCAN_DRV_Receive(0, 12, &canCom0_recvBuff12);

  /* S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive11' */
  FLEXCAN_DRV_Receive(0, 13, &canCom0_recvBuff13);

  /* S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive12' */
  FLEXCAN_DRV_Receive(0, 14, &canCom0_recvBuff14);

  /* S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive13' */
  FLEXCAN_DRV_Receive(0, 15, &canCom0_recvBuff15);

  /* S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive14' */
  FLEXCAN_DRV_Receive(0, 16, &canCom0_recvBuff16);

  /* S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive15' */
  FLEXCAN_DRV_Receive(0, 17, &canCom0_recvBuff17);

  /* S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive2' */
  FLEXCAN_DRV_Receive(0, 4, &canCom0_recvBuff4);

  /* S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive3' */
  FLEXCAN_DRV_Receive(0, 5, &canCom0_recvBuff5);

  /* S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive4' */
  FLEXCAN_DRV_Receive(0, 6, &canCom0_recvBuff6);

  /* S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive5' */
  FLEXCAN_DRV_Receive(0, 7, &canCom0_recvBuff7);

  /* S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive6' */
  FLEXCAN_DRV_Receive(0, 8, &canCom0_recvBuff8);

  /* S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive7' */
  FLEXCAN_DRV_Receive(0, 9, &canCom0_recvBuff9);

  /* S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive8' */
  FLEXCAN_DRV_Receive(0, 10, &canCom0_recvBuff10);

  /* S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive9' */
  FLEXCAN_DRV_Receive(0, 11, &canCom0_recvBuff11);

  /* S-Function (ftm_s32k14_pwm_config): '<S2>/FTM_PWM_Config1' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   */
  {
    uint16_t dutyA = FTM_MAX_DUTY_CYCLE * 0.5F;
    FTM_DRV_UpdatePwmChannel(FTM_PWM3, 0U, FTM_PWM_UPDATE_IN_DUTY_CYCLE, dutyA,
      0, true);
  }
}

/* Model step function for TID1 */
void Final_project_step1(void)         /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_DataTypeConversion;
  real_T rtb_dsdt;
  real32_T rtb_Gain_ie;
  boolean_T rtb_spd;
  boolean_T rtb_man;
  uint16_T rtb_DataTypeConversion_p;
  real32_T rtb_Sum1_o;
  real_T rtb_TSamp;
  real_T rtb_Sum4;
  real_T rtb_TSamp_h;
  uint32_T HighLevelDesign_ELAPS_T;
  real32_T rtb_C_ib_idx_0;
  uint64m_T tmp;
  uint32_T tmp_0;

  /* S-Function (fcncallgen): '<Root>/Function-Call Top' incorporates:
   *  SubSystem: '<Root>/High Level Design'
   */
  if (rtDW.HighLevelDesign_RESET_ELAPS_T) {
    HighLevelDesign_ELAPS_T = 0U;
  } else {
    HighLevelDesign_ELAPS_T = rtM->Timing.clockTick1 -
      rtDW.HighLevelDesign_PREV_T;
  }

  rtDW.HighLevelDesign_PREV_T = rtM->Timing.clockTick1;
  rtDW.HighLevelDesign_RESET_ELAPS_T = false;

  /* Inport: '<S3>/s,n,psi,us (Cars 1-6)' */
  rtB.snpsiusCars16[0] = rtB.ByteUnpacking_o1_l;
  rtB.snpsiusCars16[1] = rtB.ByteUnpacking_o2_in;
  rtB.snpsiusCars16[2] = rtB.ByteUnpacking_o1_a2;
  rtB.snpsiusCars16[3] = rtB.ByteUnpacking_o2_c5;
  rtB.snpsiusCars16[4] = rtB.ByteUnpacking_o1_e;
  rtB.snpsiusCars16[5] = rtB.ByteUnpacking_o2_n0;
  rtB.snpsiusCars16[6] = rtB.ByteUnpacking_o1_f;
  rtB.snpsiusCars16[7] = rtB.ByteUnpacking_o2_cw;
  rtB.snpsiusCars16[8] = rtB.ByteUnpacking_o1_o;
  rtB.snpsiusCars16[9] = rtB.ByteUnpacking_o2_c0;
  rtB.snpsiusCars16[10] = rtB.ByteUnpacking_o1_a;
  rtB.snpsiusCars16[11] = rtB.ByteUnpacking_o2_n;
  rtB.snpsiusCars16[12] = rtB.ByteUnpacking_o1_n;
  rtB.snpsiusCars16[13] = rtB.ByteUnpacking_o2_e4;
  rtB.snpsiusCars16[14] = rtB.ByteUnpacking_o1_b;
  rtB.snpsiusCars16[15] = rtB.ByteUnpacking_o2_i;
  rtB.snpsiusCars16[16] = rtB.ByteUnpacking_o1_mf;
  rtB.snpsiusCars16[17] = rtB.ByteUnpacking_o2_e;
  rtB.snpsiusCars16[18] = rtB.ByteUnpacking_o1_m;
  rtB.snpsiusCars16[19] = rtB.ByteUnpacking_o2_c;
  rtB.snpsiusCars16[20] = rtB.ByteUnpacking_o1_p;
  rtB.snpsiusCars16[21] = rtB.ByteUnpacking_o2_k;
  rtB.snpsiusCars16[22] = rtB.ByteUnpacking_o1;
  rtB.snpsiusCars16[23] = rtB.ByteUnpacking_o2;

  /* SignalConversion: '<S25>/TmpSignal ConversionAtS-Function BuilderInport1' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtB.TmpSignalConversionAtSFunctionB[0] = rtDW.UnitDelay_DSTATE[0];
  rtB.TmpSignalConversionAtSFunctionB[1] = rtB.snpsiusCars16[0];
  rtB.TmpSignalConversionAtSFunctionB[2] = rtB.snpsiusCars16[4];
  rtB.TmpSignalConversionAtSFunctionB[3] = rtB.snpsiusCars16[8];
  rtB.TmpSignalConversionAtSFunctionB[4] = rtB.snpsiusCars16[12];
  rtB.TmpSignalConversionAtSFunctionB[5] = rtB.snpsiusCars16[16];
  rtB.TmpSignalConversionAtSFunctionB[6] = rtB.snpsiusCars16[20];

  /* SignalConversion: '<S25>/TmpSignal ConversionAtS-Function BuilderInport2' incorporates:
   *  UnitDelay: '<S3>/Unit Delay'
   */
  rtB.TmpSignalConversionAtSFunctio_m[0] = rtDW.UnitDelay_DSTATE[3];
  rtB.TmpSignalConversionAtSFunctio_m[1] = rtB.snpsiusCars16[3];
  rtB.TmpSignalConversionAtSFunctio_m[2] = rtB.snpsiusCars16[7];
  rtB.TmpSignalConversionAtSFunctio_m[3] = rtB.snpsiusCars16[11];
  rtB.TmpSignalConversionAtSFunctio_m[4] = rtB.snpsiusCars16[15];
  rtB.TmpSignalConversionAtSFunctio_m[5] = rtB.snpsiusCars16[19];
  rtB.TmpSignalConversionAtSFunctio_m[6] = rtB.snpsiusCars16[23];

  /* S-Function (gpio_s32k14_input): '<S38>/Digital_Input' */

  /* GPIPORTE14 signal update */
  rtB.Digital_Input = (PINS_DRV_ReadPins(PTE) >> 14) & 0x01;

  /* S-Function (Lead_car_find): '<S25>/S-Function Builder' */
  Lead_car_find_Outputs_wrapper(&rtB.TmpSignalConversionAtSFunctionB[0],
    &rtB.TmpSignalConversionAtSFunctio_m[0], &rtB.SFunctionBuilder_o1,
    &rtB.SFunctionBuilder_o2, &rtB.SFunctionBuilder_o3);

  /* Chart: '<S25>/Chart' incorporates:
   *  DataTypeConversion: '<S38>/Data Type Conversion'
   */
  if (rtDW.is_active_c3_Final_project == 0U) {
    rtDW.is_active_c3_Final_project = 1U;
    rtDW.is_c3_Final_project = IN_MANUAL;
    rtb_spd = false;
    rtb_man = true;
  } else {
    switch (rtDW.is_c3_Final_project) {
     case IN_MANUAL:
      if (rtB.Digital_Input) {
        rtDW.is_c3_Final_project = IN_Speed;
        rtb_spd = true;
        rtb_man = false;
      } else {
        rtb_spd = false;
        rtb_man = true;
      }
      break;

     case IN_POSITION:
      if ((rtB.SFunctionBuilder_o2 > rtDW.UnitDelay_DSTATE[3] + 5.0F) ||
          (rtB.SFunctionBuilder_o3 > 25.0F)) {
        rtDW.is_c3_Final_project = IN_Speed;
        rtb_spd = true;
        rtb_man = false;
      } else if (!rtB.Digital_Input) {
        rtDW.is_c3_Final_project = IN_MANUAL;
        rtb_spd = false;
        rtb_man = true;
      } else {
        rtb_spd = false;
        rtb_man = false;

        /* Outputs for Enabled SubSystem: '<S25>/Position Ctrl' incorporates:
         *  EnablePort: '<S32>/Enable'
         */
        /* Sum: '<S32>/Sum5' incorporates:
         *  Constant: '<S25>/Constant'
         *  Gain: '<S32>/D-gain'
         *  Gain: '<S32>/Feed-forward'
         *  Gain: '<S32>/P-gain'
         *  Sum: '<S32>/Sum1'
         *  Sum: '<S32>/Sum2'
         *  Sum: '<S32>/Sum3'
         *  Sum: '<S32>/Sum4'
         *  UnitDelay: '<S3>/Unit Delay'
         */
        rtB.Merge = ((20.0F - (rtB.SFunctionBuilder_o1 - rtDW.UnitDelay_DSTATE[0]))
                     * -3000.0F + (rtB.SFunctionBuilder_o2 -
          rtDW.UnitDelay_DSTATE[3]) * 4900.0F) + 100.0F *
          rtB.SFunctionBuilder_o2;

        /* End of Outputs for SubSystem: '<S25>/Position Ctrl' */
      }
      break;

     default:
      if ((rtB.SFunctionBuilder_o3 <= 20.0F) && (rtB.SFunctionBuilder_o3 != 0.0F)
          && (rtB.SFunctionBuilder_o2 < rtDW.UnitDelay_DSTATE[3])) {
        rtDW.is_c3_Final_project = IN_POSITION;
        rtb_spd = false;
        rtb_man = false;

        /* Outputs for Enabled SubSystem: '<S25>/Position Ctrl' incorporates:
         *  EnablePort: '<S32>/Enable'
         */
        /* Sum: '<S32>/Sum5' incorporates:
         *  Constant: '<S25>/Constant'
         *  Gain: '<S32>/D-gain'
         *  Gain: '<S32>/Feed-forward'
         *  Gain: '<S32>/P-gain'
         *  Sum: '<S32>/Sum1'
         *  Sum: '<S32>/Sum2'
         *  Sum: '<S32>/Sum3'
         *  Sum: '<S32>/Sum4'
         *  UnitDelay: '<S3>/Unit Delay'
         */
        rtB.Merge = ((20.0F - (rtB.SFunctionBuilder_o1 - rtDW.UnitDelay_DSTATE[0]))
                     * -3000.0F + (rtB.SFunctionBuilder_o2 -
          rtDW.UnitDelay_DSTATE[3]) * 4900.0F) + 100.0F *
          rtB.SFunctionBuilder_o2;

        /* End of Outputs for SubSystem: '<S25>/Position Ctrl' */
      } else if (!rtB.Digital_Input) {
        rtDW.is_c3_Final_project = IN_MANUAL;
        rtb_spd = false;
        rtb_man = true;
      } else {
        rtb_spd = true;
        rtb_man = false;
      }
      break;
    }
  }

  /* End of Chart: '<S25>/Chart' */

  /* S-Function (gpio_s32k14_input): '<S37>/Digital_Input' */

  /* GPIPORTE6 signal update */
  rtB.Digital_Input_m = (PINS_DRV_ReadPins(PTE) >> 6) & 0x01;

  /* S-Function (gpio_s32k14_input): '<S37>/Digital_Input1' */

  /* GPIPORTE7 signal update */
  rtB.Digital_Input1 = (PINS_DRV_ReadPins(PTE) >> 7) & 0x01;

  /* S-Function (gpio_s32k14_input): '<S37>/Digital_Input2' */

  /* GPIPORTE8 signal update */
  rtB.Digital_Input2 = (PINS_DRV_ReadPins(PTE) >> 8) & 0x01;

  /* S-Function (gpio_s32k14_input): '<S37>/Digital_Input3' */

  /* GPIPORTE9 signal update */
  rtB.Digital_Input3 = (PINS_DRV_ReadPins(PTE) >> 9) & 0x01;

  /* S-Function (gpio_s32k14_input): '<S37>/Digital_Input4' */

  /* GPIPORTE10 signal update */
  rtB.Digital_Input4 = (PINS_DRV_ReadPins(PTE) >> 10) & 0x01;

  /* S-Function (gpio_s32k14_input): '<S37>/Digital_Input5' */

  /* GPIPORTE11 signal update */
  rtB.Digital_Input5 = (PINS_DRV_ReadPins(PTE) >> 11) & 0x01;

  /* S-Function (gpio_s32k14_input): '<S37>/Digital_Input6' */

  /* GPIPORTE12 signal update */
  rtB.Digital_Input6 = (PINS_DRV_ReadPins(PTE) >> 12) & 0x01;

  /* S-Function (gpio_s32k14_input): '<S37>/Digital_Input7' */

  /* GPIPORTE13 signal update */
  rtB.Digital_Input7 = (PINS_DRV_ReadPins(PTE) >> 13) & 0x01;

  /* Gain: '<S37>/Gain' incorporates:
   *  ArithShift: '<S37>/Shift Arithmetic1'
   *  ArithShift: '<S37>/Shift Arithmetic2'
   *  ArithShift: '<S37>/Shift Arithmetic3'
   *  ArithShift: '<S37>/Shift Arithmetic4'
   *  ArithShift: '<S37>/Shift Arithmetic5'
   *  ArithShift: '<S37>/Shift Arithmetic6'
   *  ArithShift: '<S37>/Shift Arithmetic7'
   *  DataTypeConversion: '<S37>/Data Type Conversion'
   *  DataTypeConversion: '<S37>/Data Type Conversion1'
   *  DataTypeConversion: '<S37>/Data Type Conversion2'
   *  DataTypeConversion: '<S37>/Data Type Conversion3'
   *  DataTypeConversion: '<S37>/Data Type Conversion4'
   *  DataTypeConversion: '<S37>/Data Type Conversion5'
   *  DataTypeConversion: '<S37>/Data Type Conversion6'
   *  DataTypeConversion: '<S37>/Data Type Conversion7'
   *  DataTypeConversion: '<S37>/Data Type Conversion8'
   *  Sum: '<S37>/Add'
   */
  rtb_Gain_ie = (real32_T)((int32_T)(((((((uint32_T)(rtB.Digital_Input1 << 1) +
    rtB.Digital_Input_m) + (rtB.Digital_Input2 << 2)) + (rtB.Digital_Input3 << 3))
    + (rtB.Digital_Input4 << 4)) + (rtB.Digital_Input5 << 5)) +
    (rtB.Digital_Input6 << 6)) + (rtB.Digital_Input7 << 7)) * 0.25F;

  /* Outputs for Enabled SubSystem: '<S25>/Speed Ctrl' incorporates:
   *  EnablePort: '<S33>/Enable'
   */
  if (rtb_spd) {
    /* Sum: '<S33>/Sum1' incorporates:
     *  UnitDelay: '<S3>/Unit Delay'
     */
    rtb_Sum1_o = rtb_Gain_ie - rtDW.UnitDelay_DSTATE[3];

    /* Sum: '<S33>/Sum' incorporates:
     *  Gain: '<S33>/Gain'
     *  Gain: '<S35>/Gain1'
     *  Sum: '<S35>/Sum'
     *  UnitDelay: '<S36>/Unit Delay'
     */
    rtB.Merge = (5000.0F * rtb_Sum1_o + rtDW.UnitDelay_DSTATE_e) + 100.0F *
      rtb_Gain_ie;

    /* Sum: '<S36>/Sum' incorporates:
     *  Gain: '<S35>/Gain'
     *  Gain: '<S36>/Gain'
     *  UnitDelay: '<S36>/Unit Delay'
     */
    rtDW.UnitDelay_DSTATE_e += 50.0F * rtb_Sum1_o * 0.01F;
  }

  /* End of Outputs for SubSystem: '<S25>/Speed Ctrl' */

  /* S-Function (adc_s32k14_start): '<S40>/ADC_Start' */
  {
    adc_chan_config_t adc0_chan_cfg = {
      .interruptEnable = false,
      .channel = ADC_INPUTCHAN_EXT0
    };

    /* Initialize channel configuration of ADC0. */
    ADC_DRV_ConfigChan(0, 0, &adc0_chan_cfg);
    uint16_t result;

    /* Get conversion result of ADC0 */
    ADC_DRV_WaitConvDone(0);
    ADC_DRV_GetChanResult(0, 0, &result);
    rtB.ADC_Start = result;
  }

  /* Outputs for Enabled SubSystem: '<S25>/Subsystem' incorporates:
   *  EnablePort: '<S34>/Enable'
   */
  if (rtb_man) {
    /* Gain: '<S40>/Gain' */
    tmp_0 = 4194304000U;
    uMultiWordMul(&tmp_0, 1, &rtB.ADC_Start, 1, &tmp.chunks[0U], 2);

    /* Inport: '<S34>/In1' incorporates:
     *  Constant: '<S40>/Constant'
     *  Gain: '<S40>/Gain1'
     *  Sum: '<S40>/Subtract'
     */
    rtB.Merge = -(real32_T)(uMultiWord2Double(&tmp.chunks[0U], 2, 0) *
      2.3283064365386963E-10 - 2000.0);
  }

  /* End of Outputs for SubSystem: '<S25>/Subsystem' */

  /* S-Function (ftm_s32k14_quadrature_decoder): '<S41>/Quadrature_Decoder' */

  /* FTM2: get counter value */
  rtB.Quadrature_Decoder = FTM_DRV_GetCounter (FTM2);

  /* DataTypeConversion: '<S43>/Data Type Conversion' */
  rtb_DataTypeConversion_p = (uint16_T)rtB.Quadrature_Decoder;

  /* Sum: '<S43>/Sum1' incorporates:
   *  DataTypeConversion: '<S43>/Data Type Conversion1'
   *  DataTypeConversion: '<S43>/Data Type Conversion2'
   *  Gain: '<S43>/Gain'
   *  Sum: '<S43>/Sum'
   *  UnitDelay: '<S43>/Unit Delay'
   *  UnitDelay: '<S43>/Unit Delay1'
   */
  rtDW.UnitDelay1_DSTATE += (real32_T)(int16_T)(rtb_DataTypeConversion_p -
    rtDW.UnitDelay_DSTATE_b) * 0.00157F;

  /* Gain: '<S26>/Gain' incorporates:
   *  UnitDelay: '<S43>/Unit Delay1'
   */
  rtB.Gain = -0.2F * rtDW.UnitDelay1_DSTATE;

  /* Outputs for Atomic SubSystem: '<S3>/Vehicle Dynamics' */
  /* DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */
  if (rtDW.DiscreteTimeIntegrator_SYSTEM_E == 0) {
    rtDW.DiscreteTimeIntegrator_DSTATE += 0.01F * (real32_T)
      HighLevelDesign_ELAPS_T * rtDW.DiscreteTimeIntegrator_PREV_U;
  }

  /* End of DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */

  /* DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' */
  if (rtDW.DiscreteTimeIntegrator1_SYSTEM_ == 0) {
    rtDW.DiscreteTimeIntegrator1_DSTATE += 0.01F * (real32_T)
      HighLevelDesign_ELAPS_T * rtDW.DiscreteTimeIntegrator1_PREV_U;
  }

  /* End of DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' */

  /* UnitDelay: '<S72>/Unit Delay' */
  rtB.UnitDelay = rtDW.UnitDelay_DSTATE_d;

  /* DiscreteIntegrator: '<S29>/Discrete-Time Integrator2' */
  if (rtDW.DiscreteTimeIntegrator2_SYSTEM_ != 0) {
    rtB.DiscreteTimeIntegrator2 = rtDW.DiscreteTimeIntegrator2_DSTATE;
  } else {
    rtB.DiscreteTimeIntegrator2 = 0.01F * (real32_T)HighLevelDesign_ELAPS_T
      * rtDW.DiscreteTimeIntegrator2_PREV_U +
      rtDW.DiscreteTimeIntegrator2_DSTATE;
  }

  /* End of DiscreteIntegrator: '<S29>/Discrete-Time Integrator2' */

  /* S-Function (get_rvec1): '<S69>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (rtB.UnitDelay), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        rtB.LookupRightVector_o1 = fy;
        rtB.LookupRightVector_o2 = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        rtB.LookupRightVector_o1 = cos(r);
        rtB.LookupRightVector_o2 = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* DiscreteIntegrator: '<S67>/Discrete-Time Integrator' */
  if (rtDW.DiscreteTimeIntegrator_SYSTEM_b != 0) {
    rtB.velocity = rtDW.DiscreteTimeIntegrator_DSTATE_c;
  } else {
    rtB.velocity = 0.01F * (real32_T)HighLevelDesign_ELAPS_T
      * rtDW.DiscreteTimeIntegrator_PREV_U_n +
      rtDW.DiscreteTimeIntegrator_DSTATE_c;
  }

  /* End of DiscreteIntegrator: '<S67>/Discrete-Time Integrator' */

  /* S-Function (VD_equation): '<S29>/S-Function Builder' */
  VD_equation_Outputs_wrapper(&rtB.Gain, &rtB.velocity,
    &rtB.DiscreteTimeIntegrator2, &rtB.SFunctionBuilder_o1_o,
    &rtB.SFunctionBuilder_o2_k, &rtB.SFunctionBuilder_o3_d,
    &rtConstP.SFunctionBuilder_P1, 1, &rtConstP.SFunctionBuilder_P2, 1,
    &rtConstP.pooled3, 1);

  /* S-Function (get_path1): '<S68>/Look up P' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (rtB.UnitDelay), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      rtB.LookupP_o1 = rs[i].data.straight.start[0] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      rtB.LookupP_o2 = rs[i].data.straight.start[1] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      rtB.LookupP_o1 = rs[i].data.const_curve.center[0] + rs[i].
        data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      rtB.LookupP_o2 = rs[i].data.const_curve.center[1] + rs[i].
        data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* Sum: '<S68>/Sum' */
  rtb_Gain_ie = rtDW.DiscreteTimeIntegrator_DSTATE - rtB.LookupP_o1;
  rtb_Sum1_o = rtDW.DiscreteTimeIntegrator1_DSTATE - rtB.LookupP_o2;

  /* S-Function (get_rvec1): '<S71>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (rtB.UnitDelay), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        rtB.LookupRightVector_o1_d = fy;
        rtB.LookupRightVector_o2_h = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        rtB.LookupRightVector_o1_d = cos(r);
        rtB.LookupRightVector_o2_h = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Product: '<S73>/Product' incorporates:
   *  Gain: '<S71>/Gain'
   */
  rtb_C_ib_idx_0 = rtb_Gain_ie * -rtB.LookupRightVector_o2_h;

  /* S-Function (get_rvec1): '<S68>/Look up Right Vector' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (rtB.UnitDelay), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        rtB.LookupRightVector_o1_j = fy;
        rtB.LookupRightVector_o2_j = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        rtB.LookupRightVector_o1_j = cos(r);
        rtB.LookupRightVector_o2_j = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* Product: '<S74>/Product' */
  rtb_Gain_ie *= rtB.LookupRightVector_o1_j;

  /* Sum: '<S74>/Sum1' incorporates:
   *  Product: '<S74>/Product'
   */
  rtb_Gain_ie += rtb_Sum1_o * rtB.LookupRightVector_o2_j;

  /* DataTypeConversion: '<S68>/Data  Type  Conversion' incorporates:
   *  Product: '<S73>/Product'
   *  Sum: '<S73>/Sum1'
   */
  rtb_DataTypeConversion = rtb_Sum1_o * rtB.LookupRightVector_o1_d +
    rtb_C_ib_idx_0;

  /* DiscreteStateSpace: '<S68>/Controller' */
  {
    rtb_dsdt = 0.38289220218870362*rtDW.Controller_DSTATE;
    rtb_dsdt += 150.12501387153085*rtb_DataTypeConversion;
  }

  /* Sum: '<S72>/Sum' incorporates:
   *  DataTypeConversion: '<S70>/Conversion'
   *  Gain: '<S72>/Gain'
   *  UnitDelay: '<S72>/Unit Delay'
   */
  rtDW.UnitDelay_DSTATE_d = 0.01F * (real32_T)rtb_dsdt + rtB.UnitDelay;

  /* Sum: '<S66>/Add' */
  rtb_Sum1_o = rtB.DiscreteTimeIntegrator2 + rtB.Gain;

  /* DotProduct: '<S66>/Dot Product' incorporates:
   *  Gain: '<S69>/Gain'
   *  Product: '<S66>/Product1'
   *  Product: '<S66>/Product2'
   *  Sum: '<S66>/Add1'
   *  Trigonometry: '<S66>/Cos'
   *  Trigonometry: '<S66>/Sin'
   */
  rtb_Sum1_o = (cosf(rtb_Sum1_o) * -rtB.LookupRightVector_o2 + sinf(rtb_Sum1_o) *
                rtB.LookupRightVector_o1) * rtB.velocity;

  /* Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_SYSTEM_E = 0U;
  rtDW.DiscreteTimeIntegrator_PREV_U = rtB.SFunctionBuilder_o1_o;

  /* Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' */
  rtDW.DiscreteTimeIntegrator1_SYSTEM_ = 0U;
  rtDW.DiscreteTimeIntegrator1_PREV_U = rtB.SFunctionBuilder_o2_k;

  /* Update for DiscreteIntegrator: '<S29>/Discrete-Time Integrator2' */
  rtDW.DiscreteTimeIntegrator2_SYSTEM_ = 0U;
  rtDW.DiscreteTimeIntegrator2_DSTATE = rtB.DiscreteTimeIntegrator2;
  rtDW.DiscreteTimeIntegrator2_PREV_U = rtB.SFunctionBuilder_o3_d;

  /* Update for DiscreteIntegrator: '<S67>/Discrete-Time Integrator' incorporates:
   *  Gain: '<S67>/Gain'
   *  Gain: '<S67>/Gain1'
   *  Sum: '<S67>/Subtract'
   */
  rtDW.DiscreteTimeIntegrator_SYSTEM_b = 0U;
  rtDW.DiscreteTimeIntegrator_DSTATE_c = rtB.velocity;
  rtDW.DiscreteTimeIntegrator_PREV_U_n = (rtB.Merge - 100.0F * rtB.velocity) *
    0.0005F;

  /* Update for DiscreteStateSpace: '<S68>/Controller' */
  {
    real_T xnew[1];
    xnew[0] = 1.0*rtDW.Controller_DSTATE;
    xnew[0] += 0.65292519369349644*rtb_DataTypeConversion;
    (void) memcpy(&rtDW.Controller_DSTATE, xnew,
                  sizeof(real_T)*1);
  }

  /* End of Outputs for SubSystem: '<S3>/Vehicle Dynamics' */

  /* S-Function (gpio_s32k14_input): '<S39>/Digital_Input' */

  /* GPIPORTE15 signal update */
  rtB.Digital_Input_p = (PINS_DRV_ReadPins(PTE) >> 15) & 0x01;

  /* DataTypeConversion: '<S42>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S39>/Data Type Conversion'
   */
  rtB.DataTypeConversion_o = rtB.Digital_Input_p;

  /* S-Function (gpio_s32k14_output): '<S42>/Digital_Output' */

  /* GPOPORTD0 Data Signal Update */
  if (rtB.DataTypeConversion_o) {
    PINS_DRV_SetPins(PTD, 1UL<<0);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<0);
  }

  /* DataTypeConversion: '<S42>/Data Type Conversion1' incorporates:
   *  S-Function (sfix_bitop): '<S42>/Bitwise Operator1'
   */
  rtB.DataTypeConversion1 = false;

  /* S-Function (gpio_s32k14_output): '<S42>/Digital_Output1' */

  /* GPOPORTD1 Data Signal Update */
  if (rtB.DataTypeConversion1) {
    PINS_DRV_SetPins(PTD, 1UL<<1);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<1);
  }

  /* DataTypeConversion: '<S42>/Data Type Conversion10' incorporates:
   *  S-Function (sfix_bitop): '<S42>/Bitwise Operator10'
   */
  rtB.DataTypeConversion10 = false;

  /* S-Function (gpio_s32k14_output): '<S42>/Digital_Output10' */

  /* GPOPORTD10 Data Signal Update */
  if (rtB.DataTypeConversion10) {
    PINS_DRV_SetPins(PTD, 1UL<<10);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<10);
  }

  /* DataTypeConversion: '<S42>/Data Type Conversion11' incorporates:
   *  S-Function (sfix_bitop): '<S42>/Bitwise Operator11'
   */
  rtB.DataTypeConversion11 = false;

  /* S-Function (gpio_s32k14_output): '<S42>/Digital_Output11' */

  /* GPOPORTD11 Data Signal Update */
  if (rtB.DataTypeConversion11) {
    PINS_DRV_SetPins(PTD, 1UL<<11);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<11);
  }

  /* DataTypeConversion: '<S42>/Data Type Conversion12' incorporates:
   *  S-Function (sfix_bitop): '<S42>/Bitwise Operator12'
   */
  rtB.DataTypeConversion12 = false;

  /* S-Function (gpio_s32k14_output): '<S42>/Digital_Output12' */

  /* GPOPORTD12 Data Signal Update */
  if (rtB.DataTypeConversion12) {
    PINS_DRV_SetPins(PTD, 1UL<<12);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<12);
  }

  /* DataTypeConversion: '<S42>/Data Type Conversion13' incorporates:
   *  S-Function (sfix_bitop): '<S42>/Bitwise Operator13'
   */
  rtB.DataTypeConversion13 = false;

  /* S-Function (gpio_s32k14_output): '<S42>/Digital_Output13' */

  /* GPOPORTD13 Data Signal Update */
  if (rtB.DataTypeConversion13) {
    PINS_DRV_SetPins(PTD, 1UL<<13);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<13);
  }

  /* DataTypeConversion: '<S42>/Data Type Conversion14' incorporates:
   *  S-Function (sfix_bitop): '<S42>/Bitwise Operator14'
   */
  rtB.DataTypeConversion14 = false;

  /* S-Function (gpio_s32k14_output): '<S42>/Digital_Output14' */

  /* GPOPORTD14 Data Signal Update */
  if (rtB.DataTypeConversion14) {
    PINS_DRV_SetPins(PTD, 1UL<<14);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<14);
  }

  /* DataTypeConversion: '<S42>/Data Type Conversion15' incorporates:
   *  DataTypeConversion: '<S39>/Data Type Conversion'
   *  DataTypeConversion: '<S42>/Data Type Conversion16'
   *  S-Function (sfix_bitop): '<S42>/Bitwise Operator15'
   */
  rtB.DataTypeConversion15 = ((int16_T)((int16_T)rtB.Digital_Input_p &
    MIN_int16_T) != 0);

  /* S-Function (gpio_s32k14_output): '<S42>/Digital_Output15' */

  /* GPOPORTD15 Data Signal Update */
  if (rtB.DataTypeConversion15) {
    PINS_DRV_SetPins(PTD, 1UL<<15);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<15);
  }

  /* DataTypeConversion: '<S42>/Data Type Conversion2' incorporates:
   *  S-Function (sfix_bitop): '<S42>/Bitwise Operator2'
   */
  rtB.DataTypeConversion2 = false;

  /* S-Function (gpio_s32k14_output): '<S42>/Digital_Output2' */

  /* GPOPORTD2 Data Signal Update */
  if (rtB.DataTypeConversion2) {
    PINS_DRV_SetPins(PTD, 1UL<<2);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<2);
  }

  /* DataTypeConversion: '<S42>/Data Type Conversion3' incorporates:
   *  S-Function (sfix_bitop): '<S42>/Bitwise Operator3'
   */
  rtB.DataTypeConversion3 = false;

  /* S-Function (gpio_s32k14_output): '<S42>/Digital_Output3' */

  /* GPOPORTD3 Data Signal Update */
  if (rtB.DataTypeConversion3) {
    PINS_DRV_SetPins(PTD, 1UL<<3);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<3);
  }

  /* DataTypeConversion: '<S42>/Data Type Conversion4' incorporates:
   *  S-Function (sfix_bitop): '<S42>/Bitwise Operator4'
   */
  rtB.DataTypeConversion4 = false;

  /* S-Function (gpio_s32k14_output): '<S42>/Digital_Output4' */

  /* GPOPORTD4 Data Signal Update */
  if (rtB.DataTypeConversion4) {
    PINS_DRV_SetPins(PTD, 1UL<<4);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<4);
  }

  /* DataTypeConversion: '<S42>/Data Type Conversion5' incorporates:
   *  S-Function (sfix_bitop): '<S42>/Bitwise Operator5'
   */
  rtB.DataTypeConversion5 = false;

  /* S-Function (gpio_s32k14_output): '<S42>/Digital_Output5' */

  /* GPOPORTD5 Data Signal Update */
  if (rtB.DataTypeConversion5) {
    PINS_DRV_SetPins(PTD, 1UL<<5);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<5);
  }

  /* DataTypeConversion: '<S42>/Data Type Conversion6' incorporates:
   *  S-Function (sfix_bitop): '<S42>/Bitwise Operator6'
   */
  rtB.DataTypeConversion6 = false;

  /* S-Function (gpio_s32k14_output): '<S42>/Digital_Output6' */

  /* GPOPORTD6 Data Signal Update */
  if (rtB.DataTypeConversion6) {
    PINS_DRV_SetPins(PTD, 1UL<<6);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<6);
  }

  /* DataTypeConversion: '<S42>/Data Type Conversion7' incorporates:
   *  S-Function (sfix_bitop): '<S42>/Bitwise Operator7'
   */
  rtB.DataTypeConversion7 = false;

  /* S-Function (gpio_s32k14_output): '<S42>/Digital_Output7' */

  /* GPOPORTD7 Data Signal Update */
  if (rtB.DataTypeConversion7) {
    PINS_DRV_SetPins(PTD, 1UL<<7);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<7);
  }

  /* DataTypeConversion: '<S42>/Data Type Conversion8' incorporates:
   *  S-Function (sfix_bitop): '<S42>/Bitwise Operator8'
   */
  rtB.DataTypeConversion8 = false;

  /* S-Function (gpio_s32k14_output): '<S42>/Digital_Output8' */

  /* GPOPORTD8 Data Signal Update */
  if (rtB.DataTypeConversion8) {
    PINS_DRV_SetPins(PTD, 1UL<<8);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<8);
  }

  /* DataTypeConversion: '<S42>/Data Type Conversion9' incorporates:
   *  S-Function (sfix_bitop): '<S42>/Bitwise Operator9'
   */
  rtB.DataTypeConversion9 = false;

  /* S-Function (gpio_s32k14_output): '<S42>/Digital_Output9' */

  /* GPOPORTD9 Data Signal Update */
  if (rtB.DataTypeConversion9) {
    PINS_DRV_SetPins(PTD, 1UL<<9);
  } else {
    PINS_DRV_ClearPins(PTD, 1UL<<9);
  }

  /* S-Function (get_rvec1): '<S48>/Look up Right Vector1' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (rtB.UnitDelay), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        rtB.LookupRightVector1_o1 = fy;
        rtB.LookupRightVector1_o2 = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        rtB.LookupRightVector1_o1 = cos(r);
        rtB.LookupRightVector1_o2 = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_path1): '<S48>/Look up P1' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (rtB.UnitDelay), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      rtB.LookupP1_o1 = rs[i].data.straight.start[0] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      rtB.LookupP1_o2 = rs[i].data.straight.start[1] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      rtB.LookupP1_o1 = rs[i].data.const_curve.center[0] + rs[i].
        data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      rtB.LookupP1_o2 = rs[i].data.const_curve.center[1] + rs[i].
        data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_rvec1): '<S55>/Look up Right Vector1' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (rtB.snpsiusCars16[0]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        rtB.LookupRightVector1_o1_j = fy;
        rtB.LookupRightVector1_o2_m = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        rtB.LookupRightVector1_o1_j = cos(r);
        rtB.LookupRightVector1_o2_m = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_path1): '<S55>/Look up P1' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (rtB.snpsiusCars16[0]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      rtB.LookupP1_o1_j = rs[i].data.straight.start[0] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      rtB.LookupP1_o2_m = rs[i].data.straight.start[1] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      rtB.LookupP1_o1_j = rs[i].data.const_curve.center[0] + rs[i].
        data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      rtB.LookupP1_o2_m = rs[i].data.const_curve.center[1] + rs[i].
        data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_rvec1): '<S56>/Look up Right Vector1' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (rtB.snpsiusCars16[4]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        rtB.LookupRightVector1_o1_i = fy;
        rtB.LookupRightVector1_o2_d = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        rtB.LookupRightVector1_o1_i = cos(r);
        rtB.LookupRightVector1_o2_d = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_path1): '<S56>/Look up P1' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (rtB.snpsiusCars16[4]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      rtB.LookupP1_o1_f = rs[i].data.straight.start[0] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      rtB.LookupP1_o2_p = rs[i].data.straight.start[1] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      rtB.LookupP1_o1_f = rs[i].data.const_curve.center[0] + rs[i].
        data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      rtB.LookupP1_o2_p = rs[i].data.const_curve.center[1] + rs[i].
        data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_rvec1): '<S57>/Look up Right Vector1' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (rtB.snpsiusCars16[8]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        rtB.LookupRightVector1_o1_a = fy;
        rtB.LookupRightVector1_o2_j = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        rtB.LookupRightVector1_o1_a = cos(r);
        rtB.LookupRightVector1_o2_j = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_path1): '<S57>/Look up P1' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (rtB.snpsiusCars16[8]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      rtB.LookupP1_o1_jz = rs[i].data.straight.start[0] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      rtB.LookupP1_o2_pi = rs[i].data.straight.start[1] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      rtB.LookupP1_o1_jz = rs[i].data.const_curve.center[0] + rs[i].
        data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      rtB.LookupP1_o2_pi = rs[i].data.const_curve.center[1] + rs[i].
        data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_rvec1): '<S58>/Look up Right Vector1' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (rtB.snpsiusCars16[12]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        rtB.LookupRightVector1_o1_c = fy;
        rtB.LookupRightVector1_o2_e = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        rtB.LookupRightVector1_o1_c = cos(r);
        rtB.LookupRightVector1_o2_e = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_path1): '<S58>/Look up P1' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (rtB.snpsiusCars16[12]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      rtB.LookupP1_o1_a = rs[i].data.straight.start[0] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      rtB.LookupP1_o2_l = rs[i].data.straight.start[1] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      rtB.LookupP1_o1_a = rs[i].data.const_curve.center[0] + rs[i].
        data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      rtB.LookupP1_o2_l = rs[i].data.const_curve.center[1] + rs[i].
        data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_rvec1): '<S59>/Look up Right Vector1' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (rtB.snpsiusCars16[16]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        rtB.LookupRightVector1_o1_iv = fy;
        rtB.LookupRightVector1_o2_f = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        rtB.LookupRightVector1_o1_iv = cos(r);
        rtB.LookupRightVector1_o2_f = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_path1): '<S59>/Look up P1' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (rtB.snpsiusCars16[16]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      rtB.LookupP1_o1_c = rs[i].data.straight.start[0] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      rtB.LookupP1_o2_e = rs[i].data.straight.start[1] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      rtB.LookupP1_o1_c = rs[i].data.const_curve.center[0] + rs[i].
        data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      rtB.LookupP1_o2_e = rs[i].data.const_curve.center[1] + rs[i].
        data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_rvec1): '<S60>/Look up Right Vector1' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (rtB.snpsiusCars16[20]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* if path is straight, then the "right" vector is normal to
       * the vector that points straight ahead */
      {
        double fx, fy;                 /* unit vector straight ahead */
        double length;                 /* length of vector from start to stop */
        fx = rs[i].data.straight.stop[0] - rs[i].data.straight.start[0];
        fy = rs[i].data.straight.stop[1] - rs[i].data.straight.start[1];
        length = sqrt(fx*fx + fy*fy);
        fx /= length;
        fy /= length;

        /* <x,y,0> =  <fx,fy,0> x <0,0,1> */
        rtB.LookupRightVector1_o1_je = fy;
        rtB.LookupRightVector1_o2_b = -fx;
        break;
      }

     case CONST_CURVE:
      {
        double r;                      /* right angle */
        if (rs[i].data.const_curve.dir > 0.0) {
          r = p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts;
        } else {
          r = -p/(rs[i].data.const_curve.r) + rs[i].data.const_curve.ts
            + 3.14159265358979;
        }

        rtB.LookupRightVector1_o1_je = cos(r);
        rtB.LookupRightVector1_o2_b = sin(r);
        break;
      }

     default :
      /* assign no value */
      break;
    }
  }

  /* S-Function (get_path1): '<S60>/Look up P1' */
  {
    extern struct road_seg_type rs[MAX_RS];
    real_T p, u_alt;
    int i;

    /* keep u within the range [0, PATH_LENGTH) */
    u_alt = fmod( (rtB.snpsiusCars16[20]), PATH_LENGTH);

    /* Find the segment in rs[] that the path distance u_alt lies within */
    for (i=0; i<MAX_RS; i++) {
      if (rs[i].p > u_alt) {
        i--;
        break;
      }
    }

    /* i is the segment in which u lies; p is the path length from the
     * beginning of segment i to u_alt */
    p = u_alt - rs[i].p;
    switch ( rs[i].type)
    {
     case STRAIGHT:
      /* If the path is straight, interpolate between start and stop */
      rtB.LookupP1_o1_g = rs[i].data.straight.start[0] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[0]-rs[i].
        data.straight.start[0]);
      rtB.LookupP1_o2_n = rs[i].data.straight.start[1] +
        (p/rs[i].data.straight.length)*(rs[i].data.straight.stop[1]-rs[i].
        data.straight.start[1]);
      break;

     case CONST_CURVE:
      rtB.LookupP1_o1_g = rs[i].data.const_curve.center[0] + rs[i].
        data.const_curve.r
        *cos( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      rtB.LookupP1_o2_n = rs[i].data.const_curve.center[1] + rs[i].
        data.const_curve.r
        *sin( (double)(rs[i].data.const_curve.dir)*p/(rs[i].data.const_curve.r)
             + rs[i].data.const_curve.ts );
      break;

     default :
      /* assign no value */
      break;
    }
  }

  /* SignalConversion: '<S46>/TmpSignal ConversionAtByte Packing Inport1' */
  rtB.TmpSignalConversionAtBytePackin[0] = rtB.UnitDelay;
  rtB.TmpSignalConversionAtBytePackin[1] = rtb_Gain_ie;

  /* S-Function (xpcbytepacking): '<S46>/Byte Packing ' */

  /* Byte Packing: <S46>/Byte Packing  */
  (void)memcpy((uint8_T*)&rtB.BytePacking_f[0] + 0, (uint8_T*)
               &rtB.TmpSignalConversionAtBytePackin[0], 8);

  /* S-Function (fcan_s32k14_send): '<S46>/FCAN_Send' incorporates:
   *  Constant: '<S46>/Constant'
   */
  {
    uint8_t* data = &rtB.BytePacking_f[0];
    flexcan_data_info_t txInfo = {
      .msg_id_type = FLEXCAN_MSG_ID_STD,
      .data_length = ((uint8_T)8U),
      .fd_enable = false,
      .fd_padding = 0x0,
      .enable_brs = false,
      .is_remote = false
    };

    FLEXCAN_DRV_ConfigTxMb(0, 0, &txInfo, 0x2D);
    FLEXCAN_DRV_Send(0, 0, &txInfo, 0x2D, data);
  }

  /* SignalConversion: '<S46>/TmpSignal ConversionAtByte Packing 1Inport1' */
  rtB.TmpSignalConversionAtBytePack_m[0] = rtB.DiscreteTimeIntegrator2;
  rtB.TmpSignalConversionAtBytePack_m[1] = rtb_Sum1_o;

  /* S-Function (xpcbytepacking): '<S46>/Byte Packing 1' */

  /* Byte Packing: <S46>/Byte Packing 1 */
  (void)memcpy((uint8_T*)&rtB.BytePacking1[0] + 0, (uint8_T*)
               &rtB.TmpSignalConversionAtBytePack_m[0], 8);

  /* S-Function (fcan_s32k14_send): '<S46>/FCAN_Send1' incorporates:
   *  Constant: '<S46>/Constant1'
   */
  {
    uint8_t* data = &rtB.BytePacking1[0];
    flexcan_data_info_t txInfo = {
      .msg_id_type = FLEXCAN_MSG_ID_STD,
      .data_length = ((uint8_T)8U),
      .fd_enable = false,
      .fd_padding = 0x0,
      .enable_brs = false,
      .is_remote = false
    };

    FLEXCAN_DRV_ConfigTxMb(0, 1, &txInfo, 0x2E);
    FLEXCAN_DRV_Send(0, 1, &txInfo, 0x2E, data);
  }

  /* Outputs for Enabled SubSystem: '<S3>/Subsystem' incorporates:
   *  EnablePort: '<S28>/Enable'
   */
  /* DataTypeConversion: '<S39>/Data Type Conversion' */
  if (rtB.Digital_Input_p) {
    if (!rtDW.Subsystem_MODE) {
      rtDW.Subsystem_RESET_ELAPS_T = true;
      rtDW.Subsystem_MODE = true;
    }

    if (rtDW.Subsystem_RESET_ELAPS_T) {
      HighLevelDesign_ELAPS_T = 0U;
    } else {
      HighLevelDesign_ELAPS_T = rtM->Timing.clockTick1 - rtDW.Subsystem_PREV_T;
    }

    rtDW.Subsystem_PREV_T = rtM->Timing.clockTick1;
    rtDW.Subsystem_RESET_ELAPS_T = false;

    /* SampleTimeMath: '<S65>/TSamp' incorporates:
     *  Gain: '<S63>/Gain2'
     *  SampleTimeMath: '<S64>/TSamp'
     *  Sum: '<S28>/Sum'
     *
     * About '<S65>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     *
     * About '<S64>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp_h = (real_T)HighLevelDesign_ELAPS_T * 0.01;
    rtb_TSamp = 0.0875F * rtb_Gain_ie / rtb_TSamp_h;

    /* Sum: '<S28>/Sum4' incorporates:
     *  Gain: '<S63>/Gain3'
     *  Sum: '<S28>/Sum'
     *  Sum: '<S63>/Sum1'
     *  Sum: '<S65>/Diff'
     *  UnitDelay: '<S65>/UD'
     *
     * Block description for '<S65>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S65>/UD':
     *
     *  Store in Global RAM
     */
    rtb_Sum4 = ((rtb_TSamp - rtDW.UD_DSTATE) + 13.4F * rtb_Gain_ie) - rtB.Gain;

    /* SampleTimeMath: '<S64>/TSamp' incorporates:
     *  Gain: '<S62>/Gain7'
     *
     * About '<S64>/TSamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_TSamp_h = 165.0 * rtb_Sum4 / rtb_TSamp_h;

    /* DataTypeConversion: '<S28>/Data Type Conversion' incorporates:
     *  Gain: '<S62>/Gain6'
     *  Sum: '<S62>/Sum5'
     *  Sum: '<S64>/Diff'
     *  UnitDelay: '<S64>/UD'
     *
     * Block description for '<S64>/Diff':
     *
     *  Add in CPU
     *
     * Block description for '<S64>/UD':
     *
     *  Store in Global RAM
     */
    rtB.DataTypeConversion = (real32_T)((rtb_TSamp_h - rtDW.UD_DSTATE_b) +
      1473.5 * rtb_Sum4);

    /* Update for UnitDelay: '<S65>/UD'
     *
     * Block description for '<S65>/UD':
     *
     *  Store in Global RAM
     */
    rtDW.UD_DSTATE = rtb_TSamp;

    /* Update for UnitDelay: '<S64>/UD'
     *
     * Block description for '<S64>/UD':
     *
     *  Store in Global RAM
     */
    rtDW.UD_DSTATE_b = rtb_TSamp_h;
  } else {
    if (rtDW.Subsystem_MODE) {
      rtDW.Subsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S3>/Subsystem' */

  /* Outputs for Atomic SubSystem: '<S3>/Vehicle Dynamics' */
  /* Sum: '<S61>/Sum' incorporates:
   *  Constant: '<S61>/Constant'
   *  Gain: '<S29>/Gain'
   *  Gain: '<S29>/Gain1'
   *  Gain: '<S3>/Gain'
   *  Gain: '<S61>/Gain'
   *  Product: '<S29>/Product'
   *  Sum: '<S27>/Sum1'
   */
  rtB.Saturation = ((0.0F - rtB.Gain * rtB.velocity * -100.0F * 0.2F) - 0.05F *
                    rtB.DataTypeConversion) * 0.0003162F + 0.5F;

  /* End of Outputs for SubSystem: '<S3>/Vehicle Dynamics' */

  /* Saturate: '<S61>/Saturation' */
  if (rtB.Saturation > 0.76F) {
    /* Sum: '<S61>/Sum' */
    rtB.Saturation = 0.76F;
  } else {
    if (rtB.Saturation < 0.24F) {
      /* Sum: '<S61>/Sum' */
      rtB.Saturation = 0.24F;
    }
  }

  /* End of Saturate: '<S61>/Saturation' */

  /* S-Function (ftm_s32k14_pwm_config): '<S47>/FTM_PWM_Config' incorporates:
   *  Constant: '<S47>/Constant'
   */
  {
    uint16_t dutyA = FTM_MAX_DUTY_CYCLE * rtB.Saturation;
    FTM_DRV_UpdatePwmChannel(FTM_PWM0, 0U, FTM_PWM_UPDATE_IN_DUTY_CYCLE, dutyA,
      0, true);
  }

  /* Update for UnitDelay: '<S3>/Unit Delay' */
  rtDW.UnitDelay_DSTATE[0] = rtB.UnitDelay;
  rtDW.UnitDelay_DSTATE[1] = rtb_Gain_ie;
  rtDW.UnitDelay_DSTATE[2] = rtB.DiscreteTimeIntegrator2;
  rtDW.UnitDelay_DSTATE[3] = rtb_Sum1_o;

  /* Update for UnitDelay: '<S43>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_b = rtb_DataTypeConversion_p;

  /* End of Outputs for S-Function (fcncallgen): '<Root>/Function-Call Top' */

  /* RateTransition: '<Root>/Rate Transition' incorporates:
   *  Product: '<S48>/Product'
   *  Product: '<S55>/Product'
   *  Product: '<S56>/Product'
   *  Product: '<S57>/Product'
   *  Product: '<S58>/Product'
   *  Product: '<S59>/Product'
   *  Product: '<S60>/Product'
   *  SignalConversion: '<S3>/OutportBufferForSerial'
   *  Sum: '<S48>/Sum'
   *  Sum: '<S55>/Sum'
   *  Sum: '<S56>/Sum'
   *  Sum: '<S57>/Sum'
   *  Sum: '<S58>/Sum'
   *  Sum: '<S59>/Sum'
   *  Sum: '<S60>/Sum'
   */
  if (rtM->Timing.RateInteraction.TID1_2) {
    /* S-Function (fcncallgen): '<Root>/Function-Call Top' incorporates:
     *  SubSystem: '<Root>/High Level Design'
     */
    rtB.RateTransition[0] = rtb_Gain_ie * rtB.LookupRightVector1_o1 +
      rtB.LookupP1_o1;
    rtB.RateTransition[1] = rtb_Gain_ie * rtB.LookupRightVector1_o2 +
      rtB.LookupP1_o2;
    rtB.RateTransition[2] = rtB.DiscreteTimeIntegrator2;
    rtB.RateTransition[3] = rtB.velocity;
    rtB.RateTransition[4] = rtB.snpsiusCars16[1] * rtB.LookupRightVector1_o1_j +
      rtB.LookupP1_o1_j;
    rtB.RateTransition[5] = rtB.snpsiusCars16[1] * rtB.LookupRightVector1_o2_m +
      rtB.LookupP1_o2_m;
    rtB.RateTransition[6] = rtB.snpsiusCars16[2];
    rtB.RateTransition[7] = rtB.snpsiusCars16[5] * rtB.LookupRightVector1_o1_i +
      rtB.LookupP1_o1_f;
    rtB.RateTransition[8] = rtB.snpsiusCars16[5] * rtB.LookupRightVector1_o2_d +
      rtB.LookupP1_o2_p;
    rtB.RateTransition[9] = rtB.snpsiusCars16[6];
    rtB.RateTransition[10] = rtB.snpsiusCars16[9] * rtB.LookupRightVector1_o1_a
      + rtB.LookupP1_o1_jz;
    rtB.RateTransition[11] = rtB.snpsiusCars16[9] * rtB.LookupRightVector1_o2_j
      + rtB.LookupP1_o2_pi;
    rtB.RateTransition[12] = rtB.snpsiusCars16[10];
    rtB.RateTransition[13] = rtB.snpsiusCars16[13] * rtB.LookupRightVector1_o1_c
      + rtB.LookupP1_o1_a;
    rtB.RateTransition[14] = rtB.snpsiusCars16[13] * rtB.LookupRightVector1_o2_e
      + rtB.LookupP1_o2_l;
    rtB.RateTransition[15] = rtB.snpsiusCars16[14];
    rtB.RateTransition[16] = rtB.snpsiusCars16[17] *
      rtB.LookupRightVector1_o1_iv + rtB.LookupP1_o1_c;
    rtB.RateTransition[17] = rtB.snpsiusCars16[17] * rtB.LookupRightVector1_o2_f
      + rtB.LookupP1_o2_e;
    rtB.RateTransition[18] = rtB.snpsiusCars16[18];
    rtB.RateTransition[19] = rtB.snpsiusCars16[21] *
      rtB.LookupRightVector1_o1_je + rtB.LookupP1_o1_g;
    rtB.RateTransition[20] = rtB.snpsiusCars16[21] * rtB.LookupRightVector1_o2_b
      + rtB.LookupP1_o2_n;
    rtB.RateTransition[21] = rtB.snpsiusCars16[22];

    /* End of Outputs for S-Function (fcncallgen): '<Root>/Function-Call Top' */
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  rtM->Timing.clockTick1++;
}

/* Model step function for TID2 */
void Final_project_step2(void)         /* Sample time: [0.05s, 0.0s] */
{
  /* S-Function (fcncallgen): '<S4>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S4>/Serial'
   */
  /* S-Function (xpcbytepacking): '<S75>/Byte Packing ' */

  /* Byte Packing: <S75>/Byte Packing  */
  (void)memcpy((uint8_T*)&rtB.BytePacking[0] + 0, (uint8_T*)&rtB.RateTransition
               [0], 88);

  /* Logic: '<S75>/NOT' incorporates:
   *  Delay: '<S75>/Delay'
   */
  rtDW.Delay_DSTATE_i = !rtDW.Delay_DSTATE_i;

  /* End of Outputs for S-Function (fcncallgen): '<S4>/Function-Call Generator1' */

  /* Update for RateTransition: '<S4>/RT' incorporates:
   *  Delay: '<S75>/Delay'
   */
  rtDW.RT_Buffer0 = rtDW.Delay_DSTATE_i;

  /* S-Function (fcncallgen): '<S4>/Function-Call Generator1' incorporates:
   *  SubSystem: '<S4>/Serial'
   */
  /* Update for RateTransition: '<S4>/RT1' incorporates:
   *  Constant: '<S75>/Constant2'
   *  Constant: '<S75>/Constant3'
   *  SignalConversion: '<S75>/OutportBufferFordata_out'
   */
  rtDW.RT1_Buffer0[0] = 115U;
  memcpy(&rtDW.RT1_Buffer0[1], &rtB.BytePacking[0], 88U * sizeof(uint8_T));
  rtDW.RT1_Buffer0[89] = 101U;

  /* End of Outputs for S-Function (fcncallgen): '<S4>/Function-Call Generator1' */
}

/* Model step wrapper function for compatibility with a static main program */
void Final_project_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Final_project_step0();
    break;

   case 1 :
    Final_project_step1();
    break;

   case 2 :
    Final_project_step2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Final_project_initialize(void)
{
  /* Start for S-Function (fcan_s32k14_config): '<Root>/FCAN_Config' */
  {
    const flexcan_user_config_t canCom0_InitConfig = {
      .fd_enable = false,
      .pe_clock = FLEXCAN_CLK_SOURCE_PERIPH,
      .max_num_mb = 32U,
      .num_id_filters = FLEXCAN_RX_FIFO_ID_FILTERS_8,
      .is_rx_fifo_needed = false,
      .flexcanMode = FLEXCAN_NORMAL_MODE,
      .payload = FLEXCAN_PAYLOAD_SIZE_8,

      /* Bitrate: 500000U and clock frequency: 80000000U*/
      .bitrate = {
        .propSeg = 7U,
        .phaseSeg1 = 4U,
        .phaseSeg2 = 1U,
        .preDivider = 9U,
        .rJumpwidth = 3U
      },
      .bitrate_cbt = {
        .propSeg = 6U,
        .phaseSeg1 = 3U,
        .phaseSeg2 = 3U,
        .preDivider = 9U,
        .rJumpwidth = 0U
      },
      .transfer_type = FLEXCAN_RXFIFO_USING_INTERRUPTS,
      .rxFifoDMAChannel = 0U
    };

    /* CAN RX pin config */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);
    PINS_DRV_SetMuxModeSel(PORTE, 4, PORT_MUX_ALT5);

    /* CAN TX pin config */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);
    PINS_DRV_SetMuxModeSel(PORTE, 5, PORT_MUX_ALT5);

    /* Enable CAN0 clock */
    PCC_SetClockMode(PCC, PCC_FlexCAN0_CLOCK, true);
    FLEXCAN_DRV_Init(0, &canCom0_State, &canCom0_InitConfig);
  }

  /* Start for S-Function (lpuart_s32k14_config): '<Root>/LPUART_Config' */
  {
    static lpuart_state_t lpuartState;

    /* Enable clock for PORTC */
    PCC_SetClockMode(PCC, PCC_PORTC_CLOCK, true);

    /* Configure pin for RX function */
    PINS_SetMuxModeSel(PORTC, 6, PORT_MUX_ALT2);

    /* Enable clock for PORTC */
    PCC_SetClockMode(PCC, PCC_PORTC_CLOCK, true);

    /* Configure pin for TX function */
    PINS_SetMuxModeSel(PORTC, 7, PORT_MUX_ALT2);

    /* Enable clock for PORTA */
    PCC_SetClockMode(PCC, PCC_PORTA_CLOCK, true);

    /* Configure pin for CTS function */
    PINS_SetMuxModeSel(PORTA, 6, PORT_MUX_ALT6);

    /* Enable clock for PORTA */
    PCC_SetClockMode(PCC, PCC_PORTA_CLOCK, true);

    /* Configure pin for RTS function */
    PINS_SetMuxModeSel(PORTA, 7, PORT_MUX_ALT6);

    /* Set LPUART clock source */
    PCC_SetPeripheralClockControl(PCC, PCC_LPUART1_CLOCK, true, CLK_SRC_SPLL, 0,
      0);

    /* Enable LPUART clock */
    PCC_SetClockMode(PCC, PCC_LPUART1_CLOCK, true);
    const lpuart_user_config_t lpuart1_config = {
      .transferType = LPUART_USING_INTERRUPTS,
      .baudRate = 115200U,
      .parityMode = LPUART_PARITY_DISABLED,
      .stopBitCount = LPUART_ONE_STOP_BIT,
      .bitCountPerChar = LPUART_8_BITS_PER_CHAR,
      .rxDMAChannel = 0U,
      .txDMAChannel = 0U,
    };

    /* Initializes a LPUART instance for operation */
    LPUART_DRV_Init(1, &lpuartState, &lpuart1_config);
  }

  /* Start for S-Function (fcan_s32k14_isr): '<S1>/FCAN_Isr' */
  FLEXCAN_DRV_InstallEventCallback(0, fcan0_s32k14_rx_isr, (void *)0);

  /* End of Start for S-Function (fcan_s32k14_isr): '<S1>/FCAN_Isr' */

  /* Start for S-Function (fcncallgen): '<Root>/Function-Call Top' incorporates:
   *  SubSystem: '<Root>/High Level Design'
   */

  /* Start for S-Function (gpio_s32k14_input): '<S38>/Digital_Input' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin14 = {
      .base = PORTE,
      .pinPortIdx = 14,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE14. */
    PINS_DRV_Init(1, &gpioPORTEPin14);
  }

  /* Start for S-Function (gpio_s32k14_input): '<S37>/Digital_Input' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin6 = {
      .base = PORTE,
      .pinPortIdx = 6,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE6. */
    PINS_DRV_Init(1, &gpioPORTEPin6);
  }

  /* Start for S-Function (gpio_s32k14_input): '<S37>/Digital_Input1' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin7 = {
      .base = PORTE,
      .pinPortIdx = 7,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE7. */
    PINS_DRV_Init(1, &gpioPORTEPin7);
  }

  /* Start for S-Function (gpio_s32k14_input): '<S37>/Digital_Input2' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin8 = {
      .base = PORTE,
      .pinPortIdx = 8,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE8. */
    PINS_DRV_Init(1, &gpioPORTEPin8);
  }

  /* Start for S-Function (gpio_s32k14_input): '<S37>/Digital_Input3' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin9 = {
      .base = PORTE,
      .pinPortIdx = 9,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE9. */
    PINS_DRV_Init(1, &gpioPORTEPin9);
  }

  /* Start for S-Function (gpio_s32k14_input): '<S37>/Digital_Input4' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin10 = {
      .base = PORTE,
      .pinPortIdx = 10,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE10. */
    PINS_DRV_Init(1, &gpioPORTEPin10);
  }

  /* Start for S-Function (gpio_s32k14_input): '<S37>/Digital_Input5' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin11 = {
      .base = PORTE,
      .pinPortIdx = 11,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE11. */
    PINS_DRV_Init(1, &gpioPORTEPin11);
  }

  /* Start for S-Function (gpio_s32k14_input): '<S37>/Digital_Input6' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin12 = {
      .base = PORTE,
      .pinPortIdx = 12,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE12. */
    PINS_DRV_Init(1, &gpioPORTEPin12);
  }

  /* Start for S-Function (gpio_s32k14_input): '<S37>/Digital_Input7' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin13 = {
      .base = PORTE,
      .pinPortIdx = 13,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE13. */
    PINS_DRV_Init(1, &gpioPORTEPin13);
  }

  /* Start for S-Function (ftm_s32k14_quadrature_decoder): '<S41>/Quadrature_Decoder' */

  /* Enable clock for PORTA */
  PCC_SetClockMode (PCC, PCC_PORTA_CLOCK, true);

  /* Pin is configured for FTM function */
  PINS_SetMuxModeSel(PORTA, 13, PORT_MUX_ALT6);

  /* Enable clock for PORTA */
  PCC_SetClockMode (PCC, PCC_PORTA_CLOCK, true);

  /* Pin is configured for FTM function */
  PINS_SetMuxModeSel(PORTA, 12, PORT_MUX_ALT6);

  {
    ftm_quad_decode_config_t quadParams = {
      FTM_QUAD_PHASE_ENCODE,           /* Quadrature decoder mode */
      0U,                              /* Initial counter value */
      0xFFFF,                          /* Maximum counter value */

      {
        false,                         /* Filter state */
        0,                             /* Filter value */
        FTM_QUAD_PHASE_NORMAL          /* Phase polarity */
      },

      {
        false,                         /* Filter state */
        0,                             /* Filter value */
        FTM_QUAD_PHASE_NORMAL          /* Phase polarity */
      }
    };

    FTM_DRV_QuadDecodeStart(2, &quadParams);
  }

  /* Start for S-Function (gpio_s32k14_input): '<S39>/Digital_Input' */
  {
    /* Enable clock for PORTE */
    PCC_SetClockMode(PCC, PCC_PORTE_CLOCK, true);

    /* Configure the input port init structure. */
    const pin_settings_config_t gpioPORTEPin15 = {
      .base = PORTE,
      .pinPortIdx = 15,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTE,
      .direction = GPIO_INPUT_DIRECTION,
    };

    /* Initialize GPIPORTE15. */
    PINS_DRV_Init(1, &gpioPORTEPin15);
  }

  /* Start for S-Function (gpio_s32k14_output): '<S42>/Digital_Output' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin0 = {
      .base = PORTD,
      .pinPortIdx = 0,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
    };

    /* Initialize GPIPORTD0. */
    PINS_DRV_Init(1, &gpioPORTDPin0);
  }

  /* Start for S-Function (gpio_s32k14_output): '<S42>/Digital_Output1' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin1 = {
      .base = PORTD,
      .pinPortIdx = 1,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
    };

    /* Initialize GPIPORTD1. */
    PINS_DRV_Init(1, &gpioPORTDPin1);
  }

  /* Start for S-Function (gpio_s32k14_output): '<S42>/Digital_Output10' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin10 = {
      .base = PORTD,
      .pinPortIdx = 10,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
    };

    /* Initialize GPIPORTD10. */
    PINS_DRV_Init(1, &gpioPORTDPin10);
  }

  /* Start for S-Function (gpio_s32k14_output): '<S42>/Digital_Output11' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin11 = {
      .base = PORTD,
      .pinPortIdx = 11,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
    };

    /* Initialize GPIPORTD11. */
    PINS_DRV_Init(1, &gpioPORTDPin11);
  }

  /* Start for S-Function (gpio_s32k14_output): '<S42>/Digital_Output12' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin12 = {
      .base = PORTD,
      .pinPortIdx = 12,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
    };

    /* Initialize GPIPORTD12. */
    PINS_DRV_Init(1, &gpioPORTDPin12);
  }

  /* Start for S-Function (gpio_s32k14_output): '<S42>/Digital_Output13' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin13 = {
      .base = PORTD,
      .pinPortIdx = 13,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
    };

    /* Initialize GPIPORTD13. */
    PINS_DRV_Init(1, &gpioPORTDPin13);
  }

  /* Start for S-Function (gpio_s32k14_output): '<S42>/Digital_Output14' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin14 = {
      .base = PORTD,
      .pinPortIdx = 14,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
    };

    /* Initialize GPIPORTD14. */
    PINS_DRV_Init(1, &gpioPORTDPin14);
  }

  /* Start for S-Function (gpio_s32k14_output): '<S42>/Digital_Output15' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin15 = {
      .base = PORTD,
      .pinPortIdx = 15,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
    };

    /* Initialize GPIPORTD15. */
    PINS_DRV_Init(1, &gpioPORTDPin15);
  }

  /* Start for S-Function (gpio_s32k14_output): '<S42>/Digital_Output2' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin2 = {
      .base = PORTD,
      .pinPortIdx = 2,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
    };

    /* Initialize GPIPORTD2. */
    PINS_DRV_Init(1, &gpioPORTDPin2);
  }

  /* Start for S-Function (gpio_s32k14_output): '<S42>/Digital_Output3' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin3 = {
      .base = PORTD,
      .pinPortIdx = 3,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
    };

    /* Initialize GPIPORTD3. */
    PINS_DRV_Init(1, &gpioPORTDPin3);
  }

  /* Start for S-Function (gpio_s32k14_output): '<S42>/Digital_Output4' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin4 = {
      .base = PORTD,
      .pinPortIdx = 4,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
    };

    /* Initialize GPIPORTD4. */
    PINS_DRV_Init(1, &gpioPORTDPin4);
  }

  /* Start for S-Function (gpio_s32k14_output): '<S42>/Digital_Output5' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin5 = {
      .base = PORTD,
      .pinPortIdx = 5,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
    };

    /* Initialize GPIPORTD5. */
    PINS_DRV_Init(1, &gpioPORTDPin5);
  }

  /* Start for S-Function (gpio_s32k14_output): '<S42>/Digital_Output6' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin6 = {
      .base = PORTD,
      .pinPortIdx = 6,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
    };

    /* Initialize GPIPORTD6. */
    PINS_DRV_Init(1, &gpioPORTDPin6);
  }

  /* Start for S-Function (gpio_s32k14_output): '<S42>/Digital_Output7' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin7 = {
      .base = PORTD,
      .pinPortIdx = 7,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
    };

    /* Initialize GPIPORTD7. */
    PINS_DRV_Init(1, &gpioPORTDPin7);
  }

  /* Start for S-Function (gpio_s32k14_output): '<S42>/Digital_Output8' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin8 = {
      .base = PORTD,
      .pinPortIdx = 8,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
    };

    /* Initialize GPIPORTD8. */
    PINS_DRV_Init(1, &gpioPORTDPin8);
  }

  /* Start for S-Function (gpio_s32k14_output): '<S42>/Digital_Output9' */
  {
    /* Enable clock for PORTD */
    PCC_SetClockMode(PCC, PCC_PORTD_CLOCK, true);

    /* Configure the output port init structure. */
    const pin_settings_config_t gpioPORTDPin9 = {
      .base = PORTD,
      .pinPortIdx = 9,
      .pullConfig = PORT_INTERNAL_PULL_NOT_ENABLED,
      .passiveFilter = false,
      .driveSelect = PORT_LOW_DRIVE_STRENGTH,
      .mux = PORT_MUX_AS_GPIO,
      .pinLock = false,
      .intConfig = PORT_DMA_INT_DISABLED,
      .clearIntFlag = true,
      .gpioBase = PTD,
      .direction = GPIO_OUTPUT_DIRECTION,
    };

    /* Initialize GPIPORTD9. */
    PINS_DRV_Init(1, &gpioPORTDPin9);
  }

  /* Start for S-Function (ftm_s32k14_pwm_config): '<S47>/FTM_PWM_Config' incorporates:
   *  Constant: '<S47>/Constant'
   */

  /* Enable clock for PORTB */
  PCC_SetClockMode (PCC, PCC_PORTB_CLOCK, true);

  /* Pin is configured for FTM function */
  PINS_SetMuxModeSel(PORTB, 12, PORT_MUX_ALT2);

  /* Set FTM_0 clock source */
  PCC_SetPeripheralClockControl (PCC, PCC_FTM0_CLOCK, true, CLK_SRC_SPLL, 0, 0);

  /* Enable clock for FTM_0 */
  PCC_SetClockMode (PCC, PCC_FTM0_CLOCK, true);

  /* PWM0 initialization */
  FTM_DRV_Init (FTM_PWM0, &flexTimer_pwm0_InitConfig, &ftmStateStruct0);
  FTM_DRV_InitPwm (FTM_PWM0, &flexTimer_pwm0_PwmConfig);
  FTM_DRV_SetChnTriggerCmd(FTM0, 1, false);

  /* End of Start for S-Function (fcncallgen): '<Root>/Function-Call Top' */

  /* Start for S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive' */
  {
    flexcan_msgbuff_id_type_t msg_id_type = FLEXCAN_MSG_ID_STD;
    flexcan_data_info_t rxInfo = {
      .msg_id_type = FLEXCAN_MSG_ID_STD,
      .data_length = 8,
      .fd_enable = false,
      .fd_padding = 0,
      .enable_brs = false,
      .is_remote = false
    };

    FLEXCAN_DRV_ConfigRxMb(0, 2, &rxInfo, 0x4b);
    FLEXCAN_DRV_SetRxIndividualMask(0, msg_id_type, 2, 0x0);
  }

  /* Start for S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive1' */
  {
    flexcan_msgbuff_id_type_t msg_id_type = FLEXCAN_MSG_ID_STD;
    flexcan_data_info_t rxInfo = {
      .msg_id_type = FLEXCAN_MSG_ID_STD,
      .data_length = 8,
      .fd_enable = false,
      .fd_padding = 0,
      .enable_brs = false,
      .is_remote = false
    };

    FLEXCAN_DRV_ConfigRxMb(0, 3, &rxInfo, 0x4c);
    FLEXCAN_DRV_SetRxIndividualMask(0, msg_id_type, 3, 0x0);
  }

  /* Start for S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive10' */
  {
    flexcan_msgbuff_id_type_t msg_id_type = FLEXCAN_MSG_ID_STD;
    flexcan_data_info_t rxInfo = {
      .msg_id_type = FLEXCAN_MSG_ID_STD,
      .data_length = 8,
      .fd_enable = false,
      .fd_padding = 0,
      .enable_brs = false,
      .is_remote = false
    };

    FLEXCAN_DRV_ConfigRxMb(0, 12, &rxInfo, 0x41);
    FLEXCAN_DRV_SetRxIndividualMask(0, msg_id_type, 12, 0x0);
  }

  /* Start for S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive11' */
  {
    flexcan_msgbuff_id_type_t msg_id_type = FLEXCAN_MSG_ID_STD;
    flexcan_data_info_t rxInfo = {
      .msg_id_type = FLEXCAN_MSG_ID_STD,
      .data_length = 8,
      .fd_enable = false,
      .fd_padding = 0,
      .enable_brs = false,
      .is_remote = false
    };

    FLEXCAN_DRV_ConfigRxMb(0, 13, &rxInfo, 0x42);
    FLEXCAN_DRV_SetRxIndividualMask(0, msg_id_type, 13, 0x0);
  }

  /* Start for S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive12' */
  {
    flexcan_msgbuff_id_type_t msg_id_type = FLEXCAN_MSG_ID_STD;
    flexcan_data_info_t rxInfo = {
      .msg_id_type = FLEXCAN_MSG_ID_STD,
      .data_length = 8,
      .fd_enable = false,
      .fd_padding = 0,
      .enable_brs = false,
      .is_remote = false
    };

    FLEXCAN_DRV_ConfigRxMb(0, 14, &rxInfo, 0x69);
    FLEXCAN_DRV_SetRxIndividualMask(0, msg_id_type, 14, 0x0);
  }

  /* Start for S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive13' */
  {
    flexcan_msgbuff_id_type_t msg_id_type = FLEXCAN_MSG_ID_STD;
    flexcan_data_info_t rxInfo = {
      .msg_id_type = FLEXCAN_MSG_ID_STD,
      .data_length = 8,
      .fd_enable = false,
      .fd_padding = 0,
      .enable_brs = false,
      .is_remote = false
    };

    FLEXCAN_DRV_ConfigRxMb(0, 15, &rxInfo, 0x6a);
    FLEXCAN_DRV_SetRxIndividualMask(0, msg_id_type, 15, 0x0);
  }

  /* Start for S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive14' */
  {
    flexcan_msgbuff_id_type_t msg_id_type = FLEXCAN_MSG_ID_STD;
    flexcan_data_info_t rxInfo = {
      .msg_id_type = FLEXCAN_MSG_ID_STD,
      .data_length = 8,
      .fd_enable = false,
      .fd_padding = 0,
      .enable_brs = false,
      .is_remote = false
    };

    FLEXCAN_DRV_ConfigRxMb(0, 16, &rxInfo, 0x0F);
    FLEXCAN_DRV_SetRxIndividualMask(0, msg_id_type, 16, 0x0);
  }

  /* Start for S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive15' */
  {
    flexcan_msgbuff_id_type_t msg_id_type = FLEXCAN_MSG_ID_STD;
    flexcan_data_info_t rxInfo = {
      .msg_id_type = FLEXCAN_MSG_ID_STD,
      .data_length = 8,
      .fd_enable = false,
      .fd_padding = 0,
      .enable_brs = false,
      .is_remote = false
    };

    FLEXCAN_DRV_ConfigRxMb(0, 17, &rxInfo, 0x10);
    FLEXCAN_DRV_SetRxIndividualMask(0, msg_id_type, 17, 0x0);
  }

  /* Start for S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive2' */
  {
    flexcan_msgbuff_id_type_t msg_id_type = FLEXCAN_MSG_ID_STD;
    flexcan_data_info_t rxInfo = {
      .msg_id_type = FLEXCAN_MSG_ID_STD,
      .data_length = 8,
      .fd_enable = false,
      .fd_padding = 0,
      .enable_brs = false,
      .is_remote = false
    };

    FLEXCAN_DRV_ConfigRxMb(0, 4, &rxInfo, 0x19);
    FLEXCAN_DRV_SetRxIndividualMask(0, msg_id_type, 4, 0x0);
  }

  /* Start for S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive3' */
  {
    flexcan_msgbuff_id_type_t msg_id_type = FLEXCAN_MSG_ID_STD;
    flexcan_data_info_t rxInfo = {
      .msg_id_type = FLEXCAN_MSG_ID_STD,
      .data_length = 8,
      .fd_enable = false,
      .fd_padding = 0,
      .enable_brs = false,
      .is_remote = false
    };

    FLEXCAN_DRV_ConfigRxMb(0, 5, &rxInfo, 0x1a);
    FLEXCAN_DRV_SetRxIndividualMask(0, msg_id_type, 5, 0x0);
  }

  /* Start for S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive4' */
  {
    flexcan_msgbuff_id_type_t msg_id_type = FLEXCAN_MSG_ID_STD;
    flexcan_data_info_t rxInfo = {
      .msg_id_type = FLEXCAN_MSG_ID_STD,
      .data_length = 8,
      .fd_enable = false,
      .fd_padding = 0,
      .enable_brs = false,
      .is_remote = false
    };

    FLEXCAN_DRV_ConfigRxMb(0, 6, &rxInfo, 0x23);
    FLEXCAN_DRV_SetRxIndividualMask(0, msg_id_type, 6, 0x0);
  }

  /* Start for S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive5' */
  {
    flexcan_msgbuff_id_type_t msg_id_type = FLEXCAN_MSG_ID_STD;
    flexcan_data_info_t rxInfo = {
      .msg_id_type = FLEXCAN_MSG_ID_STD,
      .data_length = 8,
      .fd_enable = false,
      .fd_padding = 0,
      .enable_brs = false,
      .is_remote = false
    };

    FLEXCAN_DRV_ConfigRxMb(0, 7, &rxInfo, 0x24);
    FLEXCAN_DRV_SetRxIndividualMask(0, msg_id_type, 7, 0x0);
  }

  /* Start for S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive6' */
  {
    flexcan_msgbuff_id_type_t msg_id_type = FLEXCAN_MSG_ID_STD;
    flexcan_data_info_t rxInfo = {
      .msg_id_type = FLEXCAN_MSG_ID_STD,
      .data_length = 8,
      .fd_enable = false,
      .fd_padding = 0,
      .enable_brs = false,
      .is_remote = false
    };

    FLEXCAN_DRV_ConfigRxMb(0, 8, &rxInfo, 0x2d);
    FLEXCAN_DRV_SetRxIndividualMask(0, msg_id_type, 8, 0x0);
  }

  /* Start for S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive7' */
  {
    flexcan_msgbuff_id_type_t msg_id_type = FLEXCAN_MSG_ID_STD;
    flexcan_data_info_t rxInfo = {
      .msg_id_type = FLEXCAN_MSG_ID_STD,
      .data_length = 8,
      .fd_enable = false,
      .fd_padding = 0,
      .enable_brs = false,
      .is_remote = false
    };

    FLEXCAN_DRV_ConfigRxMb(0, 9, &rxInfo, 0x2e);
    FLEXCAN_DRV_SetRxIndividualMask(0, msg_id_type, 9, 0x0);
  }

  /* Start for S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive8' */
  {
    flexcan_msgbuff_id_type_t msg_id_type = FLEXCAN_MSG_ID_STD;
    flexcan_data_info_t rxInfo = {
      .msg_id_type = FLEXCAN_MSG_ID_STD,
      .data_length = 8,
      .fd_enable = false,
      .fd_padding = 0,
      .enable_brs = false,
      .is_remote = false
    };

    FLEXCAN_DRV_ConfigRxMb(0, 10, &rxInfo, 0x37);
    FLEXCAN_DRV_SetRxIndividualMask(0, msg_id_type, 10, 0x0);
  }

  /* Start for S-Function (fcan_s32k14_receive): '<S5>/FCAN_Receive9' */
  {
    flexcan_msgbuff_id_type_t msg_id_type = FLEXCAN_MSG_ID_STD;
    flexcan_data_info_t rxInfo = {
      .msg_id_type = FLEXCAN_MSG_ID_STD,
      .data_length = 8,
      .fd_enable = false,
      .fd_padding = 0,
      .enable_brs = false,
      .is_remote = false
    };

    FLEXCAN_DRV_ConfigRxMb(0, 11, &rxInfo, 0x38);
    FLEXCAN_DRV_SetRxIndividualMask(0, msg_id_type, 11, 0x0);
  }

  /* Start for S-Function (ftm_s32k14_pwm_config): '<S2>/FTM_PWM_Config1' incorporates:
   *  Constant: '<S2>/Constant1'
   *  Constant: '<S2>/Constant2'
   */

  /* Enable clock for PORTB */
  PCC_SetClockMode (PCC, PCC_PORTB_CLOCK, true);

  /* Pin is configured for FTM function */
  PINS_SetMuxModeSel(PORTB, 8, PORT_MUX_ALT2);

  /* Set FTM_3 clock source */
  PCC_SetPeripheralClockControl (PCC, PCC_FTM3_CLOCK, true, CLK_SRC_SPLL, 0, 0);

  /* Enable clock for FTM_3 */
  PCC_SetClockMode (PCC, PCC_FTM3_CLOCK, true);

  /* PWM3 initialization */
  FTM_DRV_Init (FTM_PWM3, &flexTimer_pwm3_InitConfig, &ftmStateStruct3);
  FTM_DRV_InitPwm (FTM_PWM3, &flexTimer_pwm3_PwmConfig);
  FTM_DRV_SetChnTriggerCmd(FTM3, 1, false);

  /* Start for S-Function (adc_s32k14_config): '<Root>/ADC_Config' */
  {
    const adc_converter_config_t adc0_cfg = {
      .clockDivide = ADC_CLK_DIVIDE_1,
      .sampleTime = 12.0,
      .resolution = ADC_RESOLUTION_12BIT,
      .inputClock = ADC_CLK_ALT_1,
      .trigger = ADC_TRIGGER_SOFTWARE,
      .pretriggerSel = ADC_PRETRIGGER_SEL_PDB,
      .triggerSel = ADC_TRIGGER_SEL_TRGMUX,
      .dmaEnable = false,
      .voltageRef = ADC_VOLTAGEREF_VREF,
      .continuousConvEnable = false,
      .supplyMonitoringEnable = false
    };

    const adc_compare_config_t adc0_cmp_cfg = {
      .compareEnable = false,
      .compareGreaterThanEnable = false,
      .compareRangeFuncEnable = false,
      .compVal1 = 0,
      .compVal2 = 0
    };

    const adc_average_config_t adc0_avrg_cfg = {
      .hwAvgEnable = false,
      .hwAverage = ADC_AVERAGE_4
    };

    /* Enable ADC0 clock */
    PCC_SetClockMode(PCC, PCC_ADC0_CLOCK, false);

    /* Set ADC0 clock source */
    PCC_SetPeripheralClockControl(PCC, PCC_ADC0_CLOCK, true, CLK_SRC_SPLL, 0, 0);

    /* Enable ADC0 clock */
    PCC_SetClockMode(PCC, PCC_ADC0_CLOCK, true);
    ADC_DRV_Reset(0);

    /* Configure ADC0 */
    ADC_DRV_ConfigConverter(0, &adc0_cfg);
    ADC_DRV_SetSwPretrigger(0,ADC_SW_PRETRIGGER_DISABLED);
    ADC_DRV_ConfigHwCompare(0, &adc0_cmp_cfg);
    ADC_DRV_ConfigHwAverage(0, &adc0_avrg_cfg);

    /* Do calibration before initialize the ADC0. */
    //ADC_DRV_AutoCalibration(0);
  }

  rtPrevZCX.ResettableSubsystem_Reset_ZCE = UNINITIALIZED_ZCSIG;

  /* Enable for S-Function (fcncallgen): '<Root>/Function-Call Top' incorporates:
   *  SubSystem: '<Root>/High Level Design'
   */
  rtDW.HighLevelDesign_RESET_ELAPS_T = true;

  /* Enable for Atomic SubSystem: '<S3>/Vehicle Dynamics' */
  /* Enable for DiscreteIntegrator: '<S29>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  /* Enable for DiscreteIntegrator: '<S29>/Discrete-Time Integrator1' */
  rtDW.DiscreteTimeIntegrator1_SYSTEM_ = 1U;

  /* Enable for DiscreteIntegrator: '<S29>/Discrete-Time Integrator2' */
  rtDW.DiscreteTimeIntegrator2_SYSTEM_ = 1U;

  /* Enable for DiscreteIntegrator: '<S67>/Discrete-Time Integrator' */
  rtDW.DiscreteTimeIntegrator_SYSTEM_b = 1U;

  /* End of Enable for SubSystem: '<S3>/Vehicle Dynamics' */
  /* End of Enable for S-Function (fcncallgen): '<Root>/Function-Call Top' */
}

/* Model terminate function */
void Final_project_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
