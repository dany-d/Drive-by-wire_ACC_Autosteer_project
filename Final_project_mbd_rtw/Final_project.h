/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Final_project.h
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

#ifndef RTW_HEADER_Final_project_h_
#define RTW_HEADER_Final_project_h_
#include <string.h>
#include <math.h>
#ifndef Final_project_COMMON_INCLUDES_
# define Final_project_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "pcc_hw_access.h"
#include "pins_driver.h"
#include "adc_driver.h"
#include "ftm_qd_driver.h"
#include "clock_manager.h"
#include "pins_port_hw_access.h"
#include "flexcan_hw_access.h"
#include "ftm_pwm_driver.h"
#include "ftm_hw_access.h"
#include "ftm3_pwm_params.h"
#include "ftm0_pwm_params.h"
#include "lpuart_driver.h"
#include "device_registers.h"
#include "flexcan_driver.h"
#include "lpuart_hw_access.h"
#include "interrupt_manager.h"
#include "fcan0_s32k14_rx_isr.h"
#endif                                 /* Final_project_COMMON_INCLUDES_ */

#include "Final_project_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define Final_project_M                (rtM)

/* user code (top of header file) */
#include <math.h>

/* Block states (default storage) for system '<S7>/Switch Case Action Subsystem2' */
typedef struct {
  int_T ByteUnpacking_IWORK[4];        /* '<S13>/Byte Unpacking ' */
} DW_SwitchCaseActionSubsystem2;

/* Block states (default storage) for system '<S7>/Switch Case Action Subsystem3' */
typedef struct {
  int_T ByteUnpacking_IWORK[4];        /* '<S14>/Byte Unpacking ' */
} DW_SwitchCaseActionSubsystem3;

/* Block signals (default storage) */
typedef struct {
  uint32_T FCAN_Isr_o3;                /* '<S1>/FCAN_Isr' */
  uint32_T ADC_Start;                  /* '<S40>/ADC_Start' */
  real32_T RateTransition[22];         /* '<Root>/Rate Transition' */
  real32_T snpsiusCars16[24];          /* '<S3>/s,n,psi,us (Cars 1-6)' */
  real32_T TmpSignalConversionAtSFunctionB[7];
  real32_T TmpSignalConversionAtSFunctio_m[7];
  real32_T SFunctionBuilder_o1;        /* '<S25>/S-Function Builder' */
  real32_T SFunctionBuilder_o2;        /* '<S25>/S-Function Builder' */
  real32_T SFunctionBuilder_o3;        /* '<S25>/S-Function Builder' */
  real32_T Merge;                      /* '<S25>/Merge' */
  real32_T Gain;                       /* '<S26>/Gain' */
  real32_T LookupRightVector1_o1;      /* '<S48>/Look up Right Vector1' */
  real32_T LookupRightVector1_o2;      /* '<S48>/Look up Right Vector1' */
  real32_T LookupP1_o1;                /* '<S48>/Look up P1' */
  real32_T LookupP1_o2;                /* '<S48>/Look up P1' */
  real32_T LookupRightVector1_o1_j;    /* '<S55>/Look up Right Vector1' */
  real32_T LookupRightVector1_o2_m;    /* '<S55>/Look up Right Vector1' */
  real32_T LookupP1_o1_j;              /* '<S55>/Look up P1' */
  real32_T LookupP1_o2_m;              /* '<S55>/Look up P1' */
  real32_T LookupRightVector1_o1_i;    /* '<S56>/Look up Right Vector1' */
  real32_T LookupRightVector1_o2_d;    /* '<S56>/Look up Right Vector1' */
  real32_T LookupP1_o1_f;              /* '<S56>/Look up P1' */
  real32_T LookupP1_o2_p;              /* '<S56>/Look up P1' */
  real32_T LookupRightVector1_o1_a;    /* '<S57>/Look up Right Vector1' */
  real32_T LookupRightVector1_o2_j;    /* '<S57>/Look up Right Vector1' */
  real32_T LookupP1_o1_jz;             /* '<S57>/Look up P1' */
  real32_T LookupP1_o2_pi;             /* '<S57>/Look up P1' */
  real32_T LookupRightVector1_o1_c;    /* '<S58>/Look up Right Vector1' */
  real32_T LookupRightVector1_o2_e;    /* '<S58>/Look up Right Vector1' */
  real32_T LookupP1_o1_a;              /* '<S58>/Look up P1' */
  real32_T LookupP1_o2_l;              /* '<S58>/Look up P1' */
  real32_T LookupRightVector1_o1_iv;   /* '<S59>/Look up Right Vector1' */
  real32_T LookupRightVector1_o2_f;    /* '<S59>/Look up Right Vector1' */
  real32_T LookupP1_o1_c;              /* '<S59>/Look up P1' */
  real32_T LookupP1_o2_e;              /* '<S59>/Look up P1' */
  real32_T LookupRightVector1_o1_je;   /* '<S60>/Look up Right Vector1' */
  real32_T LookupRightVector1_o2_b;    /* '<S60>/Look up Right Vector1' */
  real32_T LookupP1_o1_g;              /* '<S60>/Look up P1' */
  real32_T LookupP1_o2_n;              /* '<S60>/Look up P1' */
  real32_T TmpSignalConversionAtBytePackin[2];
  real32_T TmpSignalConversionAtBytePack_m[2];
  real32_T Saturation;                 /* '<S61>/Saturation' */
  real32_T UnitDelay;                  /* '<S72>/Unit Delay' */
  real32_T DiscreteTimeIntegrator2;    /* '<S29>/Discrete-Time Integrator2' */
  real32_T LookupRightVector_o1;       /* '<S69>/Look up Right Vector' */
  real32_T LookupRightVector_o2;       /* '<S69>/Look up Right Vector' */
  real32_T velocity;                   /* '<S67>/Discrete-Time Integrator' */
  real32_T SFunctionBuilder_o1_o;      /* '<S29>/S-Function Builder' */
  real32_T SFunctionBuilder_o2_k;      /* '<S29>/S-Function Builder' */
  real32_T SFunctionBuilder_o3_d;      /* '<S29>/S-Function Builder' */
  real32_T LookupP_o1;                 /* '<S68>/Look up P' */
  real32_T LookupP_o2;                 /* '<S68>/Look up P' */
  real32_T LookupRightVector_o1_d;     /* '<S71>/Look up Right Vector' */
  real32_T LookupRightVector_o2_h;     /* '<S71>/Look up Right Vector' */
  real32_T LookupRightVector_o1_j;     /* '<S68>/Look up Right Vector' */
  real32_T LookupRightVector_o2_j;     /* '<S68>/Look up Right Vector' */
  real32_T DataTypeConversion;         /* '<S28>/Data Type Conversion' */
  real32_T ByteUnpacking_o1;           /* '<S24>/Byte Unpacking ' */
  real32_T ByteUnpacking_o2;           /* '<S24>/Byte Unpacking ' */
  real32_T ByteUnpacking_o1_p;         /* '<S23>/Byte Unpacking ' */
  real32_T ByteUnpacking_o2_k;         /* '<S23>/Byte Unpacking ' */
  real32_T ByteUnpacking_o1_m;         /* '<S22>/Byte Unpacking ' */
  real32_T ByteUnpacking_o2_c;         /* '<S22>/Byte Unpacking ' */
  real32_T ByteUnpacking_o1_mf;        /* '<S21>/Byte Unpacking ' */
  real32_T ByteUnpacking_o2_e;         /* '<S21>/Byte Unpacking ' */
  real32_T ByteUnpacking_o1_b;         /* '<S20>/Byte Unpacking ' */
  real32_T ByteUnpacking_o2_i;         /* '<S20>/Byte Unpacking ' */
  real32_T ByteUnpacking_o1_n;         /* '<S19>/Byte Unpacking ' */
  real32_T ByteUnpacking_o2_e4;        /* '<S19>/Byte Unpacking ' */
  real32_T ByteUnpacking_o1_a;         /* '<S18>/Byte Unpacking ' */
  real32_T ByteUnpacking_o2_n;         /* '<S18>/Byte Unpacking ' */
  real32_T ByteUnpacking_o1_o;         /* '<S17>/Byte Unpacking ' */
  real32_T ByteUnpacking_o2_c0;        /* '<S17>/Byte Unpacking ' */
  real32_T ByteUnpacking_o1_f;         /* '<S16>/Byte Unpacking ' */
  real32_T ByteUnpacking_o2_cw;        /* '<S16>/Byte Unpacking ' */
  real32_T ByteUnpacking_o1_e;         /* '<S15>/Byte Unpacking ' */
  real32_T ByteUnpacking_o2_n0;        /* '<S15>/Byte Unpacking ' */
  real32_T ByteUnpacking_o1_a2;        /* '<S14>/Byte Unpacking ' */
  real32_T ByteUnpacking_o2_c5;        /* '<S14>/Byte Unpacking ' */
  real32_T ByteUnpacking_o1_l;         /* '<S13>/Byte Unpacking ' */
  real32_T ByteUnpacking_o2_in;        /* '<S13>/Byte Unpacking ' */
  uint16_T FCAN_Isr_o6;                /* '<S1>/FCAN_Isr' */
  int16_T Quadrature_Decoder;          /* '<S41>/Quadrature_Decoder' */
  uint8_T RT1[90];                     /* '<S4>/RT1' */
  uint8_T FCAN_Isr_o2;                 /* '<S1>/FCAN_Isr' */
  uint8_T FCAN_Isr_o4[8];              /* '<S1>/FCAN_Isr' */
  uint8_T FCAN_Isr_o5;                 /* '<S1>/FCAN_Isr' */
  uint8_T IndexVector;                 /* '<S76>/Index Vector' */
  uint8_T BytePacking[88];             /* '<S75>/Byte Packing ' */
  uint8_T BytePacking_f[8];            /* '<S46>/Byte Packing ' */
  uint8_T BytePacking1[8];             /* '<S46>/Byte Packing 1' */
  boolean_T RT_f;                      /* '<S4>/RT' */
  boolean_T Digital_Input;             /* '<S38>/Digital_Input' */
  boolean_T Digital_Input_m;           /* '<S37>/Digital_Input' */
  boolean_T Digital_Input1;            /* '<S37>/Digital_Input1' */
  boolean_T Digital_Input2;            /* '<S37>/Digital_Input2' */
  boolean_T Digital_Input3;            /* '<S37>/Digital_Input3' */
  boolean_T Digital_Input4;            /* '<S37>/Digital_Input4' */
  boolean_T Digital_Input5;            /* '<S37>/Digital_Input5' */
  boolean_T Digital_Input6;            /* '<S37>/Digital_Input6' */
  boolean_T Digital_Input7;            /* '<S37>/Digital_Input7' */
  boolean_T Digital_Input_p;           /* '<S39>/Digital_Input' */
  boolean_T DataTypeConversion_o;      /* '<S42>/Data Type Conversion' */
  boolean_T DataTypeConversion1;       /* '<S42>/Data Type Conversion1' */
  boolean_T DataTypeConversion10;      /* '<S42>/Data Type Conversion10' */
  boolean_T DataTypeConversion11;      /* '<S42>/Data Type Conversion11' */
  boolean_T DataTypeConversion12;      /* '<S42>/Data Type Conversion12' */
  boolean_T DataTypeConversion13;      /* '<S42>/Data Type Conversion13' */
  boolean_T DataTypeConversion14;      /* '<S42>/Data Type Conversion14' */
  boolean_T DataTypeConversion15;      /* '<S42>/Data Type Conversion15' */
  boolean_T DataTypeConversion2;       /* '<S42>/Data Type Conversion2' */
  boolean_T DataTypeConversion3;       /* '<S42>/Data Type Conversion3' */
  boolean_T DataTypeConversion4;       /* '<S42>/Data Type Conversion4' */
  boolean_T DataTypeConversion5;       /* '<S42>/Data Type Conversion5' */
  boolean_T DataTypeConversion6;       /* '<S42>/Data Type Conversion6' */
  boolean_T DataTypeConversion7;       /* '<S42>/Data Type Conversion7' */
  boolean_T DataTypeConversion8;       /* '<S42>/Data Type Conversion8' */
  boolean_T DataTypeConversion9;       /* '<S42>/Data Type Conversion9' */
} B;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S77>/Delay' */
  real_T Controller_DSTATE;            /* '<S68>/Controller' */
  real_T UD_DSTATE;                    /* '<S65>/UD' */
  real_T UD_DSTATE_b;                  /* '<S64>/UD' */
  real32_T UnitDelay_DSTATE[4];        /* '<S3>/Unit Delay' */
  real32_T UnitDelay1_DSTATE;          /* '<S43>/Unit Delay1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S29>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_DSTATE;/* '<S29>/Discrete-Time Integrator1' */
  real32_T UnitDelay_DSTATE_d;         /* '<S72>/Unit Delay' */
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<S29>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator_DSTATE_c;/* '<S67>/Discrete-Time Integrator' */
  real32_T UnitDelay_DSTATE_e;         /* '<S36>/Unit Delay' */
  real32_T DiscreteTimeIntegrator_PREV_U;/* '<S29>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator1_PREV_U;/* '<S29>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator2_PREV_U;/* '<S29>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator_PREV_U_n;/* '<S67>/Discrete-Time Integrator' */
  uint32_T HighLevelDesign_PREV_T;     /* '<Root>/High Level Design' */
  uint32_T Subsystem_PREV_T;           /* '<S3>/Subsystem' */
  int_T BytePacking_IWORK[2];          /* '<S75>/Byte Packing ' */
  int_T BytePacking_IWORK_o[2];        /* '<S46>/Byte Packing ' */
  int_T BytePacking1_IWORK[2];         /* '<S46>/Byte Packing 1' */
  uint16_T UnitDelay_DSTATE_b;         /* '<S43>/Unit Delay' */
  boolean_T Delay_DSTATE_i;            /* '<S75>/Delay' */
  uint8_T RT1_Buffer0[90];             /* '<S4>/RT1' */
  uint8_T ShiftArithmetic1_HasIssuedWarni;/* '<S37>/Shift Arithmetic1' */
  uint8_T ShiftArithmetic2_HasIssuedWarni;/* '<S37>/Shift Arithmetic2' */
  uint8_T ShiftArithmetic3_HasIssuedWarni;/* '<S37>/Shift Arithmetic3' */
  uint8_T ShiftArithmetic4_HasIssuedWarni;/* '<S37>/Shift Arithmetic4' */
  uint8_T ShiftArithmetic5_HasIssuedWarni;/* '<S37>/Shift Arithmetic5' */
  uint8_T ShiftArithmetic6_HasIssuedWarni;/* '<S37>/Shift Arithmetic6' */
  uint8_T ShiftArithmetic7_HasIssuedWarni;/* '<S37>/Shift Arithmetic7' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S29>/Discrete-Time Integrator' */
  uint8_T DiscreteTimeIntegrator1_SYSTEM_;/* '<S29>/Discrete-Time Integrator1' */
  uint8_T DiscreteTimeIntegrator2_SYSTEM_;/* '<S29>/Discrete-Time Integrator2' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_b;/* '<S67>/Discrete-Time Integrator' */
  uint8_T is_active_c3_Final_project;  /* '<S25>/Chart' */
  uint8_T is_c3_Final_project;         /* '<S25>/Chart' */
  boolean_T RT_Buffer0;                /* '<S4>/RT' */
  boolean_T HighLevelDesign_RESET_ELAPS_T;/* '<Root>/High Level Design' */
  boolean_T Subsystem_RESET_ELAPS_T;   /* '<S3>/Subsystem' */
  boolean_T Subsystem_MODE;            /* '<S3>/Subsystem' */
  DW_SwitchCaseActionSubsystem3 SwitchCaseActionSubsystem3_aw;/* '<S12>/Switch Case Action Subsystem3' */
  DW_SwitchCaseActionSubsystem2 SwitchCaseActionSubsystem2_l;/* '<S12>/Switch Case Action Subsystem2' */
  DW_SwitchCaseActionSubsystem3 SwitchCaseActionSubsystem3_b;/* '<S11>/Switch Case Action Subsystem3' */
  DW_SwitchCaseActionSubsystem2 SwitchCaseActionSubsystem2_o;/* '<S11>/Switch Case Action Subsystem2' */
  DW_SwitchCaseActionSubsystem3 SwitchCaseActionSubsystem3_i;/* '<S10>/Switch Case Action Subsystem3' */
  DW_SwitchCaseActionSubsystem2 SwitchCaseActionSubsystem2_k;/* '<S10>/Switch Case Action Subsystem2' */
  DW_SwitchCaseActionSubsystem3 SwitchCaseActionSubsystem3_e;/* '<S9>/Switch Case Action Subsystem3' */
  DW_SwitchCaseActionSubsystem2 SwitchCaseActionSubsystem2_d;/* '<S9>/Switch Case Action Subsystem2' */
  DW_SwitchCaseActionSubsystem3 SwitchCaseActionSubsystem3_a;/* '<S8>/Switch Case Action Subsystem3' */
  DW_SwitchCaseActionSubsystem2 SwitchCaseActionSubsystem2_e;/* '<S8>/Switch Case Action Subsystem2' */
  DW_SwitchCaseActionSubsystem3 SwitchCaseActionSubsystem3_p;/* '<S7>/Switch Case Action Subsystem3' */
  DW_SwitchCaseActionSubsystem2 SwitchCaseActionSubsystem2_m;/* '<S7>/Switch Case Action Subsystem2' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState ResettableSubsystem_Reset_ZCE;/* '<S76>/Resettable Subsystem' */
} PrevZCX;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: 1.6
   * Referenced by: '<S29>/S-Function Builder'
   */
  real_T SFunctionBuilder_P1;

  /* Expression: 0.8
   * Referenced by: '<S29>/S-Function Builder'
   */
  real_T SFunctionBuilder_P2;

  /* Pooled Parameter (Expression: 2000)
   * Referenced by:
   *   '<S29>/S-Function Builder'
   *   '<S40>/Constant'
   */
  real_T pooled3;
} ConstP;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick1;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID0_2;
      boolean_T TID1_2;
    } RateInteraction;
  } Timing;
};

/* Block signals (default storage) */
extern B rtB;

/* Block states (default storage) */
extern DW rtDW;

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* External function called from main */
extern void Final_project_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Final_project_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void Final_project_initialize(void);
extern void Final_project_step(int_T tid);
extern void Final_project_terminate(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S64>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Shift Arithmetic' : Eliminated trivial shift
 * Block '<S38>/Shift Arithmetic' : Eliminated trivial shift
 * Block '<S39>/Shift Arithmetic' : Eliminated trivial shift
 * Block '<S47>/Data Type Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Final_project'
 * '<S1>'   : 'Final_project/Can Network Inputs'
 * '<S2>'   : 'Final_project/Filter PWM '
 * '<S3>'   : 'Final_project/High Level Design'
 * '<S4>'   : 'Final_project/Serial Sim Out to Virtual Sim'
 * '<S5>'   : 'Final_project/Can Network Inputs/CAN Message Mailbox Setup'
 * '<S6>'   : 'Final_project/Can Network Inputs/Extract CAN data1'
 * '<S7>'   : 'Final_project/Can Network Inputs/Extract CAN data1/Data to s,n,psi,us '
 * '<S8>'   : 'Final_project/Can Network Inputs/Extract CAN data1/Data to s,n,psi,us 1'
 * '<S9>'   : 'Final_project/Can Network Inputs/Extract CAN data1/Data to s,n,psi,us 2'
 * '<S10>'  : 'Final_project/Can Network Inputs/Extract CAN data1/Data to s,n,psi,us 3'
 * '<S11>'  : 'Final_project/Can Network Inputs/Extract CAN data1/Data to s,n,psi,us 4'
 * '<S12>'  : 'Final_project/Can Network Inputs/Extract CAN data1/Data to s,n,psi,us 5'
 * '<S13>'  : 'Final_project/Can Network Inputs/Extract CAN data1/Data to s,n,psi,us /Switch Case Action Subsystem2'
 * '<S14>'  : 'Final_project/Can Network Inputs/Extract CAN data1/Data to s,n,psi,us /Switch Case Action Subsystem3'
 * '<S15>'  : 'Final_project/Can Network Inputs/Extract CAN data1/Data to s,n,psi,us 1/Switch Case Action Subsystem2'
 * '<S16>'  : 'Final_project/Can Network Inputs/Extract CAN data1/Data to s,n,psi,us 1/Switch Case Action Subsystem3'
 * '<S17>'  : 'Final_project/Can Network Inputs/Extract CAN data1/Data to s,n,psi,us 2/Switch Case Action Subsystem2'
 * '<S18>'  : 'Final_project/Can Network Inputs/Extract CAN data1/Data to s,n,psi,us 2/Switch Case Action Subsystem3'
 * '<S19>'  : 'Final_project/Can Network Inputs/Extract CAN data1/Data to s,n,psi,us 3/Switch Case Action Subsystem2'
 * '<S20>'  : 'Final_project/Can Network Inputs/Extract CAN data1/Data to s,n,psi,us 3/Switch Case Action Subsystem3'
 * '<S21>'  : 'Final_project/Can Network Inputs/Extract CAN data1/Data to s,n,psi,us 4/Switch Case Action Subsystem2'
 * '<S22>'  : 'Final_project/Can Network Inputs/Extract CAN data1/Data to s,n,psi,us 4/Switch Case Action Subsystem3'
 * '<S23>'  : 'Final_project/Can Network Inputs/Extract CAN data1/Data to s,n,psi,us 5/Switch Case Action Subsystem2'
 * '<S24>'  : 'Final_project/Can Network Inputs/Extract CAN data1/Data to s,n,psi,us 5/Switch Case Action Subsystem3'
 * '<S25>'  : 'Final_project/High Level Design/ACC State Logic'
 * '<S26>'  : 'Final_project/High Level Design/Inputs'
 * '<S27>'  : 'Final_project/High Level Design/Outputs'
 * '<S28>'  : 'Final_project/High Level Design/Subsystem'
 * '<S29>'  : 'Final_project/High Level Design/Vehicle Dynamics'
 * '<S30>'  : 'Final_project/High Level Design/ACC State Logic/Chart'
 * '<S31>'  : 'Final_project/High Level Design/ACC State Logic/Find S of each vehicle(1-6)'
 * '<S32>'  : 'Final_project/High Level Design/ACC State Logic/Position Ctrl'
 * '<S33>'  : 'Final_project/High Level Design/ACC State Logic/Speed Ctrl'
 * '<S34>'  : 'Final_project/High Level Design/ACC State Logic/Subsystem'
 * '<S35>'  : 'Final_project/High Level Design/ACC State Logic/Speed Ctrl/PI'
 * '<S36>'  : 'Final_project/High Level Design/ACC State Logic/Speed Ctrl/PI/My Discrete Integrator'
 * '<S37>'  : 'Final_project/High Level Design/Inputs/Select Speed (GPI 122-129)'
 * '<S38>'  : 'Final_project/High Level Design/Inputs/Subsystem'
 * '<S39>'  : 'Final_project/High Level Design/Inputs/Subsystem1'
 * '<S40>'  : 'Final_project/High Level Design/Inputs/Throttle (Potentiometer)'
 * '<S41>'  : 'Final_project/High Level Design/Inputs/get wheel position'
 * '<S42>'  : 'Final_project/High Level Design/Inputs/Subsystem1/Write 16 Bits'
 * '<S43>'  : 'Final_project/High Level Design/Inputs/get wheel position/Subsystem'
 * '<S44>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi'
 * '<S45>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)'
 * '<S46>'  : 'Final_project/High Level Design/Outputs/Tx CAN'
 * '<S47>'  : 'Final_project/High Level Design/Outputs/write torque'
 * '<S48>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi/s,n to x,y'
 * '<S49>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi'
 * '<S50>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi1'
 * '<S51>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi2'
 * '<S52>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi3'
 * '<S53>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi4'
 * '<S54>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi5'
 * '<S55>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi/s,n to x,y'
 * '<S56>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi1/s,n to x,y'
 * '<S57>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi2/s,n to x,y'
 * '<S58>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi3/s,n to x,y'
 * '<S59>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi4/s,n to x,y'
 * '<S60>'  : 'Final_project/High Level Design/Outputs/Extract x,y,psi (Cars 1 - 6)/Extract x,y,psi5/s,n to x,y'
 * '<S61>'  : 'Final_project/High Level Design/Outputs/write torque/Subsystem2'
 * '<S62>'  : 'Final_project/High Level Design/Subsystem/Inner Loop PD Control'
 * '<S63>'  : 'Final_project/High Level Design/Subsystem/Outer loop PD Control'
 * '<S64>'  : 'Final_project/High Level Design/Subsystem/Inner Loop PD Control/Discrete Derivative'
 * '<S65>'  : 'Final_project/High Level Design/Subsystem/Outer loop PD Control/Discrete Derivative'
 * '<S66>'  : 'Final_project/High Level Design/Vehicle Dynamics/Compute Us'
 * '<S67>'  : 'Final_project/High Level Design/Vehicle Dynamics/velocity calculation1'
 * '<S68>'  : 'Final_project/High Level Design/Vehicle Dynamics/x,y to s,n'
 * '<S69>'  : 'Final_project/High Level Design/Vehicle Dynamics/Compute Us/Look up Forward Vector'
 * '<S70>'  : 'Final_project/High Level Design/Vehicle Dynamics/x,y to s,n/Data Type Conversion Inherited'
 * '<S71>'  : 'Final_project/High Level Design/Vehicle Dynamics/x,y to s,n/Look up the Forward Vector'
 * '<S72>'  : 'Final_project/High Level Design/Vehicle Dynamics/x,y to s,n/My Discrete Integrator'
 * '<S73>'  : 'Final_project/High Level Design/Vehicle Dynamics/x,y to s,n/My Dot Product1'
 * '<S74>'  : 'Final_project/High Level Design/Vehicle Dynamics/x,y to s,n/My Dot Product2'
 * '<S75>'  : 'Final_project/Serial Sim Out to Virtual Sim/Serial'
 * '<S76>'  : 'Final_project/Serial Sim Out to Virtual Sim/UART Iteration'
 * '<S77>'  : 'Final_project/Serial Sim Out to Virtual Sim/UART Iteration/Resettable Subsystem'
 */
#endif                                 /* RTW_HEADER_Final_project_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
