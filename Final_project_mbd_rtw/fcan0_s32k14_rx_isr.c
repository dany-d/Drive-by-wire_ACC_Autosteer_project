/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: fcan0_s32k14_rx_isr.c
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

#include "flexcan_driver.h"
#include "fcan0_s32k14_rx_isr.h"
#include "Final_project.h"
#include "Final_project_private.h"

void fcan0_s32k14_rx_isr(uint8_t instance, flexcan_event_type_t eventType,
  uint32_t buffIdx, flexcan_state_t *flexcanState)
{
  if (eventType == FLEXCAN_EVENT_RX_COMPLETE) {
    uint8_t i;
    flexcan_msgbuff_t* mb_message = flexcanState->mbs[buffIdx].mb_message;
    rtB.FCAN_Isr_o2 = buffIdx;
    rtB.FCAN_Isr_o3 = mb_message->msgId;
    rtB.FCAN_Isr_o5 = mb_message->dataLen;
    for (i = 0; i < mb_message->dataLen; i++) {
      (&rtB.FCAN_Isr_o4[0])[i] = mb_message->data[i];
    }

    rtB.FCAN_Isr_o6 = (mb_message->cs & CAN_CS_TIME_STAMP_MASK) >>
      CAN_CS_TIME_STAMP_SHIFT;

    /* Output and update for function-call system: '<S1>/Extract CAN data1' */

    /* If: '<S7>/If' incorporates:
     *  Sum: '<S7>/Subtract'
     */
    if ((real_T)rtB.FCAN_Isr_o3 - 10.0 == 5.0) {
      /* Outputs for IfAction SubSystem: '<S7>/Switch Case Action Subsystem2' incorporates:
       *  ActionPort: '<S13>/Action Port'
       */
      SwitchCaseActionSubsystem2(rtB.FCAN_Isr_o4, &rtB.ByteUnpacking_o1_l,
        &rtB.ByteUnpacking_o2_in);

      /* End of Outputs for SubSystem: '<S7>/Switch Case Action Subsystem2' */
    } else {
      if ((real_T)rtB.FCAN_Isr_o3 - 10.0 == 6.0) {
        /* Outputs for IfAction SubSystem: '<S7>/Switch Case Action Subsystem3' incorporates:
         *  ActionPort: '<S14>/Action Port'
         */
        SwitchCaseActionSubsystem3(rtB.FCAN_Isr_o4, &rtB.ByteUnpacking_o1_a2,
          &rtB.ByteUnpacking_o2_c5);

        /* End of Outputs for SubSystem: '<S7>/Switch Case Action Subsystem3' */
      }
    }

    /* End of If: '<S7>/If' */

    /* If: '<S8>/If' incorporates:
     *  Sum: '<S8>/Subtract'
     */
    if ((real_T)rtB.FCAN_Isr_o3 - 20.0 == 5.0) {
      /* Outputs for IfAction SubSystem: '<S8>/Switch Case Action Subsystem2' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      SwitchCaseActionSubsystem2(rtB.FCAN_Isr_o4, &rtB.ByteUnpacking_o1_e,
        &rtB.ByteUnpacking_o2_n0);

      /* End of Outputs for SubSystem: '<S8>/Switch Case Action Subsystem2' */
    } else {
      if ((real_T)rtB.FCAN_Isr_o3 - 20.0 == 6.0) {
        /* Outputs for IfAction SubSystem: '<S8>/Switch Case Action Subsystem3' incorporates:
         *  ActionPort: '<S16>/Action Port'
         */
        SwitchCaseActionSubsystem3(rtB.FCAN_Isr_o4, &rtB.ByteUnpacking_o1_f,
          &rtB.ByteUnpacking_o2_cw);

        /* End of Outputs for SubSystem: '<S8>/Switch Case Action Subsystem3' */
      }
    }

    /* End of If: '<S8>/If' */

    /* If: '<S9>/If' incorporates:
     *  Sum: '<S9>/Subtract'
     */
    if ((real_T)rtB.FCAN_Isr_o3 - 30.0 == 5.0) {
      /* Outputs for IfAction SubSystem: '<S9>/Switch Case Action Subsystem2' incorporates:
       *  ActionPort: '<S17>/Action Port'
       */
      SwitchCaseActionSubsystem2(rtB.FCAN_Isr_o4, &rtB.ByteUnpacking_o1_o,
        &rtB.ByteUnpacking_o2_c0);

      /* End of Outputs for SubSystem: '<S9>/Switch Case Action Subsystem2' */
    } else {
      if ((real_T)rtB.FCAN_Isr_o3 - 30.0 == 6.0) {
        /* Outputs for IfAction SubSystem: '<S9>/Switch Case Action Subsystem3' incorporates:
         *  ActionPort: '<S18>/Action Port'
         */
        SwitchCaseActionSubsystem3(rtB.FCAN_Isr_o4, &rtB.ByteUnpacking_o1_a,
          &rtB.ByteUnpacking_o2_n);

        /* End of Outputs for SubSystem: '<S9>/Switch Case Action Subsystem3' */
      }
    }

    /* End of If: '<S9>/If' */

    /* If: '<S10>/If' incorporates:
     *  Sum: '<S10>/Subtract'
     */
    if ((real_T)rtB.FCAN_Isr_o3 - 40.0 == 5.0) {
      /* Outputs for IfAction SubSystem: '<S10>/Switch Case Action Subsystem2' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      SwitchCaseActionSubsystem2(rtB.FCAN_Isr_o4, &rtB.ByteUnpacking_o1_n,
        &rtB.ByteUnpacking_o2_e4);

      /* End of Outputs for SubSystem: '<S10>/Switch Case Action Subsystem2' */
    } else {
      if ((real_T)rtB.FCAN_Isr_o3 - 40.0 == 6.0) {
        /* Outputs for IfAction SubSystem: '<S10>/Switch Case Action Subsystem3' incorporates:
         *  ActionPort: '<S20>/Action Port'
         */
        SwitchCaseActionSubsystem3(rtB.FCAN_Isr_o4, &rtB.ByteUnpacking_o1_b,
          &rtB.ByteUnpacking_o2_i);

        /* End of Outputs for SubSystem: '<S10>/Switch Case Action Subsystem3' */
      }
    }

    /* End of If: '<S10>/If' */

    /* If: '<S11>/If' incorporates:
     *  Sum: '<S11>/Subtract'
     */
    if ((real_T)rtB.FCAN_Isr_o3 - 50.0 == 5.0) {
      /* Outputs for IfAction SubSystem: '<S11>/Switch Case Action Subsystem2' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      SwitchCaseActionSubsystem2(rtB.FCAN_Isr_o4, &rtB.ByteUnpacking_o1_mf,
        &rtB.ByteUnpacking_o2_e);

      /* End of Outputs for SubSystem: '<S11>/Switch Case Action Subsystem2' */
    } else {
      if ((real_T)rtB.FCAN_Isr_o3 - 50.0 == 6.0) {
        /* Outputs for IfAction SubSystem: '<S11>/Switch Case Action Subsystem3' incorporates:
         *  ActionPort: '<S22>/Action Port'
         */
        SwitchCaseActionSubsystem3(rtB.FCAN_Isr_o4, &rtB.ByteUnpacking_o1_m,
          &rtB.ByteUnpacking_o2_c);

        /* End of Outputs for SubSystem: '<S11>/Switch Case Action Subsystem3' */
      }
    }

    /* End of If: '<S11>/If' */

    /* If: '<S12>/If' incorporates:
     *  Sum: '<S12>/Subtract'
     */
    if ((real_T)rtB.FCAN_Isr_o3 - 60.0 == 5.0) {
      /* Outputs for IfAction SubSystem: '<S12>/Switch Case Action Subsystem2' incorporates:
       *  ActionPort: '<S23>/Action Port'
       */
      SwitchCaseActionSubsystem2(rtB.FCAN_Isr_o4, &rtB.ByteUnpacking_o1_p,
        &rtB.ByteUnpacking_o2_k);

      /* End of Outputs for SubSystem: '<S12>/Switch Case Action Subsystem2' */
    } else {
      if ((real_T)rtB.FCAN_Isr_o3 - 60.0 == 6.0) {
        /* Outputs for IfAction SubSystem: '<S12>/Switch Case Action Subsystem3' incorporates:
         *  ActionPort: '<S24>/Action Port'
         */
        SwitchCaseActionSubsystem3(rtB.FCAN_Isr_o4, &rtB.ByteUnpacking_o1,
          &rtB.ByteUnpacking_o2);

        /* End of Outputs for SubSystem: '<S12>/Switch Case Action Subsystem3' */
      }
    }

    /* End of If: '<S12>/If' */
    return;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
