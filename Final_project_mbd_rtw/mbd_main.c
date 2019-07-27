/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mbd_main.c
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

/* Model's headers */
#include "device_registers.h"
#include "Final_project.h"
#include "ftm_hw_access.h"
#include "interrupt_manager.h"
#include "clock_manager.h"
#include "lpit_driver.h"
#include "lpit_hw_access.h"
#include "pcc_hw_access.h"
#include "s32k_clock_init.h"
#include "ftm2_qd_params.h"

ftm_state_t ftm2DriverState;
ftm_user_config_t ftm2DriverInfo = {
  .syncMethod = FTM_SYNC_SWSYNC_MASK,  /* Register sync options available in theftm_sync_method_t enumeration */
  .ftmMode = MODE_FTM2,                /* Mode of operation for FTM */
  .ftmPrescaler = PRESCALER_FTM2,      /* Register prescaler options */
  .ftmClockSource = FTM_CLOCK_SOURCE_SYSTEMCLK,/* Select clock source for FTM */
  .BDMMode = FTM_BDM_MODE_00,          /* FTM behavior in BDM mode */
  .isTofIsrEnabled = 0,
  .enableInitializationTrigger = 0,
};

void ftm_init()
{
  /* Set FLEXTMR_2 clock source */
  PCC_SetPeripheralClockControl(PCC, PCC_FTM2_CLOCK, true, CLK_SRC_SPLL, 0, 0);

  /* Enable clock for FLEXTMR_2 */
  PCC_SetClockMode (PCC, PCC_FTM2_CLOCK, true);

  /* Initialize FLEXTMR2 */
  FTM_DRV_Init(2, &ftm2DriverInfo, &ftm2DriverState);
}

void SYSTEM_INIT_TASK(void)
{
  /* Initialize model */
  Final_project_initialize();
}

void SYSTEM_TASK(void)
{
  boolean_T eventFlags[3];             /* Model has 3 rates */
  int_T i;

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.  The generated code includes function
   * writeCodeInfoFcn() which sets the rates
   * that need to run this time step.  The return values are 1 and 0
   * for true and false, respectively.
   */
  Final_project_SetEventsForThisBaseStep(eventFlags);

  /* Set model inputs associated with base rate here */
  Final_project_step(0);

  /* Get model outputs here */
  for (i = 1; i < 3; i++) {
    if (eventFlags[i]) {
      Final_project_step(i);

      /* Get model outputs here */
    }
  }
}

void LPIT0_Ch0_IRQHandler (void)
{
  SYSTEM_TASK();
  LPIT_DRV_ClearInterruptFlagTimerChannels(0, (1 << 0));
}

void lpit0_init()
{
  uint32_t busClock;

  /* Un-gate pit clock*/
  PCC_SetPeripheralClockControl(PCC, PCC_LPIT0_CLOCK, true, CLK_SRC_SPLL, 0, 0);

  /* Enable PIT module clock*/
  LPIT_Enable(LPIT0);

  /* Finally, update pit source clock frequency.*/
  CLOCK_SYS_GetFreq(PCC_LPIT0_CLOCK, &busClock);
  static const lpit_user_config_t lpitInit = {
    .enableRunInDebug = false,
    .enableRunInDoze = true
  };

  /* Initialize PIT, enable module clock, disable run in debug. */
  LPIT_DRV_Init(0, &lpitInit);
  static const lpit_user_channel_config_t lpit0InitStruct = {
    .timerMode = LPIT_PERIODIC_COUNTER,
    .periodUnits = LPIT_PERIOD_UNITS_COUNTS,
    .period = 10000,
    .triggerSource = LPIT_TRIGGER_SOURCE_INTERNAL,
    .triggerSelect = 1U,
    .enableReloadOnTrigger = false,
    .enableStopOnInterrupt = false,
    .enableStartOnTrigger = false,
    .chainChannel = false,
    .isInterruptEnabled = true
  };

  /* Initialize PIT timer channel. */
  LPIT_DRV_InitChannel(0, 0, &lpit0InitStruct);

  /* Set priority for LPIT ISR */
  INT_SYS_SetPriority(LPIT0_Ch0_IRQn, 15);
  INT_SYS_InstallHandler(LPIT0_Ch0_IRQn, LPIT0_Ch0_IRQHandler, (isr_t *)0);

  /* Start the timer. */
  LPIT_DRV_StartTimerChannels(0, LPIT0->SETTEN | (1 << 0));
}

void main(void)
{
  /* FPU ENABLE */
#ifdef __FPU_USED

  /* Enable CP10 and CP11 coprocessors */
  S32_SCB->CPACR |= (S32_SCB_CPACR_CP10_MASK | S32_SCB_CPACR_CP11_MASK);

#endif

  /* Disable all interrupts.*/
  INT_SYS_DisableIRQGlobal();

  /* Clock initialization */
  Clock_Setup();
  ftm_init();

  /* Initialize the processor. */
  SYSTEM_INIT_TASK();

  /* Initialize system timer */
  lpit0_init();

  /* Enable all interrupts.*/
  INT_SYS_EnableIRQGlobal();           /* interrupt_manager.c */
  while (1) {
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
