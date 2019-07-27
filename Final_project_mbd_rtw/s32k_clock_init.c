/*
 * Copyright (c) 2017, NXP.
 * All rights reserved.
 */

#include "s32k_clock_init.h"
#include "clock_manager.h"
#include "power_manager.h"
#if XTAL_FREQ == 8000000
#define PLL_PREDIV                     0U                        // div = 1
#elif XTAL_FREQ == 40000000
#define PLL_PREDIV                     4U                        // div = 5
#endif

#if CORE_CLK_FREQ == 80000000
#define PLL_MULT                       4U                        // mult = 20
#define POWER_MODE                     POWER_MANAGER_RUN
#define PLL_ASYNC_DIV2                 SCG_ASYNC_CLOCK_DIV_BY_4
#elif CORE_CLK_FREQ == 112000000
#define PLL_MULT                       12U                       // mult = 28
#define POWER_MODE                     POWER_MANAGER_HSRUN
#define PLL_ASYNC_DIV2                 SCG_ASYNC_CLOCK_DIV_BY_4
#endif

void Clock_Setup(void)
{
  /* Configuration structure for Clock Configuration */
  clock_manager_user_config_t clockMan1_InitConfig0 = {
    /* Configuration of SIRC */
    .scgConfig =
    {
      .sircConfig =
      {
        .initialize = true,            /* Initialize */

        /* SIRCCSR */
        .enableInStop = false,         /* SIRCSTEN  */
        .enableInLowPower = true,      /* SIRCLPEN  */
        .locked = false,               /* LK        */

        /* SIRCCFG */
        .range = SCG_SIRC_RANGE_HIGH,  /* RANGE - High range (8 MHz) */

        /* SIRCDIV */
        .div1 = SCG_ASYNC_CLOCK_DIV_BY_1,/* SIRCDIV1  */
        .div2 = SCG_ASYNC_CLOCK_DIV_BY_1,/* SIRCDIV2  */
      },
      .fircConfig =
      {
        .initialize = true,            /* Initialize */

        /* FIRCCSR */
        .regulator = true,             /* FIRCREGOFF */
        .locked = false,               /* LK         */

        /* FIRCCFG */
        .range = SCG_FIRC_RANGE_48M,   /* RANGE      */

        /* FIRCDIV */
        .div1 = SCG_ASYNC_CLOCK_DIV_BY_1,/* FIRCDIV1   */
        .div2 = SCG_ASYNC_CLOCK_DIV_BY_1,/* FIRCDIV2   */
      },
      .rtcConfig =
      {
        .initialize = true,            /* Initialize  */
        .rtcClkInFreq = 0U,            /* RTC_CLKIN   */
      },
      .soscConfig =
      {
        .initialize = true,            /* Initialize */
        .freq = XTAL_FREQ,             /* Frequency  */

        /* SOSCCSR */
        .monitorMode = SCG_SOSC_MONITOR_DISABLE,/* SOSCCM      */
        .locked = false,               /* LK          */

        /* SOSCCFG */
        .extRef = SCG_SOSC_REF_OSC,    /* EREFS       */
        .gain = SCG_SOSC_GAIN_LOW,     /* HGO         */
        .range = SCG_SOSC_RANGE_HIGH,  /* RANGE       */

        /* SOSCDIV */
        .div1 = SCG_ASYNC_CLOCK_DIV_BY_1,/* SOSCDIV1    */
        .div2 = SCG_ASYNC_CLOCK_DIV_BY_1,/* SOSCDIV2    */
      },
      .spllConfig =
      {
        .initialize = true,            /* Initialize */

        /* SPLLCSR */
        .monitorMode = SCG_SPLL_MONITOR_DISABLE,/* SPLLCM     */
        .locked = false,               /* LK         */

        /* SPLLCFG */
        .prediv = PLL_PREDIV,          /* PREDIV     */
        .mult = PLL_MULT,              /* MULT       */
        .src = 0U,                     /* SOURCE     */

        /* SPLLDIV */
        .div1 = SCG_ASYNC_CLOCK_DIV_BY_1,/* SPLLDIV1   */
        .div2 = PLL_ASYNC_DIV2,        /* SPLLDIV2   */
      },
      .clockOutConfig =
      {
        .initialize = true,            /* Initialize    */
        .source = SCG_CLOCKOUT_SRC_FIRC,/* SCG CLKOUTSEL     */
      },
      .clockModeConfig =
      {
        .initialize = true,            /* Initialize */
        .rccrConfig =                  /* RCCR - Run Clock Control Register          */
        {

#if CORE_CLK_FREQ == 80000000

          .src = SCG_SYSTEM_CLOCK_SRC_SYS_PLL,/* SCS        */
          .divCore = SCG_SYSTEM_CLOCK_DIV_BY_1,/* DIVCORE    */
          .divBus = SCG_SYSTEM_CLOCK_DIV_BY_2,/* DIVBUS     */
          .divSlow = SCG_SYSTEM_CLOCK_DIV_BY_4,/* DIVSLOW    */

#elif CORE_CLK_FREQ == 112000000

          .src = SCG_SYSTEM_CLOCK_SRC_FIRC,/* SCS        */
          .divCore = SCG_SYSTEM_CLOCK_DIV_BY_1,/* DIVCORE    */
          .divBus = SCG_SYSTEM_CLOCK_DIV_BY_2,/* DIVBUS     */
          .divSlow = SCG_SYSTEM_CLOCK_DIV_BY_2,/* DIVSLOW    */

#endif

        },
        .vccrConfig =                  /* VCCR - VLPR Clock Control Register         */
        {
          .src = SCG_SYSTEM_CLOCK_SRC_SIRC,/* SCS        */
          .divCore = SCG_SYSTEM_CLOCK_DIV_BY_2,/* DIVCORE    */
          .divBus = SCG_SYSTEM_CLOCK_DIV_BY_1,/* DIVBUS     */
          .divSlow = SCG_SYSTEM_CLOCK_DIV_BY_4,/* DIVSLOW    */
        },
        .hccrConfig =                  /* HCCR - HSRUN Clock Control Register        */
        {
          .src = SCG_SYSTEM_CLOCK_SRC_SYS_PLL,/* SCS        */
          .divCore = SCG_SYSTEM_CLOCK_DIV_BY_1,/* DIVCORE    */
          .divBus = SCG_SYSTEM_CLOCK_DIV_BY_2,/* DIVBUS     */
          .divSlow = SCG_SYSTEM_CLOCK_DIV_BY_4,/* DIVSLOW    */
        },
      },
    },
    .pccConfig =
    {
      .peripheralClocks = (void*)0,    /* Peripheral clock control configurations  */
      .count = 0,                      /* Number of the peripheral clock control configurations  */
    },
    .simConfig =
    {
      .clockOutConfig =                /* Clock Out configuration.           */
      {
        .initialize = true,            /* Initialize    */
        .enable = false,               /* CLKOUTEN      */
        .source = SIM_CLKOUT_SEL_SYSTEM_SCG_CLKOUT,/* CLKOUTSEL     */
        .divider = SIM_CLKOUT_DIV_BY_1,/* CLKOUTDIV     */
      },
      .lpoClockConfig =                /* Low Power Clock configuration.     */
      {
        .initialize = true,            /* Initialize    */
        .enableLpo1k = true,           /* LPO1KCLKEN    */
        .enableLpo32k = true,          /* LPO32KCLKEN   */
        .sourceLpoClk = SIM_LPO_CLK_SEL_LPO_128K,/* LPOCLKSEL     */
        .sourceRtcClk = SIM_RTCCLK_SEL_LPO_32K,/* RTCCLKSEL     */
      },
      .platGateConfig =                /* Platform Gate Clock configuration. */
      {
        .initialize = false,           /* Initialize    */
        .enableMscm = false,           /* CGCMSCM       */
        .enableMpu = false,            /* CGCMPU        */
        .enableDma = false,            /* CGCDMA        */
        .enableErm = false,            /* CGCERM        */
        .enableEim = false,            /* CGCEIM        */
      },
      .qspiRefClkGating =              /* Quad Spi Internal Reference Clock Gating. */
      {
        .enableQspiRefClk = false,     /* Qspi reference clock gating    */
      },
      .tclkConfig =                    /* TCLK CLOCK configuration. */
      {
        .initialize = false,           /* Initialize    */
        .tclkFreq[0] = 0U,             /* TCLK0         */
        .tclkFreq[1] = 0U,             /* TCLK1         */
        .tclkFreq[2] = 0U,             /* TCLK2         */
      },
      .traceClockConfig =              /* Debug trace Clock Configuration. */
      {
        .initialize = false,           /* Initialize    */
        .divEnable = false,            /* TRACEDIVEN    */
        .source = CLOCK_TRACE_SRC_CORE_CLK,/* TRACECLK_SEL  */
        .divider = 0U,                 /* TRACEDIV      */
        .divFraction = false,          /* TRACEFRAC     */
      },
    },
    .pmcConfig =
    {
      .lpoClockConfig =                /* Low Power Clock configuration.     */
      {
        .initialize = true,            /* Initialize             */
        .enable = true,                /* Enable/disable LPO     */
        .trimValue = 0,                /* Trimming value for LPO */
      },
    },
  };

  /* Array of pointers to User configuration structures */
  clock_manager_user_config_t const * g_clockManConfigsArr[] = {
    &clockMan1_InitConfig0
  };

  /* Array of pointers to User defined Callbacks configuration structures */
  clock_manager_callback_user_config_t * g_clockManCallbacksArr[] = { (void*)0 };

  CLOCK_SYS_Init(g_clockManConfigsArr, 1,
                 g_clockManCallbacksArr, 0);
  CLOCK_SYS_UpdateConfiguration(0U, CLOCK_MANAGER_POLICY_AGREEMENT);

  /* Power mode configuration */
  power_manager_user_config_t powerConfig = {
    .powerMode = POWER_MODE,
    .sleepOnExitValue = false,
  };

  /* Power mode configurations array */
  power_manager_user_config_t * powerConfigsArr[] = {
    &powerConfig,
  };

  /* Callback configuration structures array */
  power_manager_callback_user_config_t * powerCallbacksConfigsArr[] = { (void*)0
  };

  POWER_SYS_Init(&powerConfigsArr, 1U,
                 &powerCallbacksConfigsArr, 0U);
  POWER_SYS_SetMode(0,POWER_MANAGER_POLICY_AGREEMENT);
}

void UpdateSystickConfig(uint32_t ticks)
{
  S32_SysTick->RVR = S32_SysTick_RVR_RELOAD(ticks - 1);
  S32_SysTick->CVR = 0;
  S32_SysTick->CSR = S32_SysTick_CSR_ENABLE(1u) | S32_SysTick_CSR_TICKINT(1u) |
    S32_SysTick_CSR_CLKSOURCE(1u);
}
