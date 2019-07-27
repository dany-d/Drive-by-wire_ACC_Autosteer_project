/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2018 NXP
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */
/*!
 * @file ftm_qd_driver.c
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 * @section [global]
 * Violates MISRA 2012 Required Rule 8.4, external symbol defined without a prior
 * declaration.
 * The symbols are declared in the driver common file as external; they are needed
 * at driver initialization to install the correct interrupt handler, but are not
 * a part of the public API.
 *
 * @section [global]
 * Violates MISRA 2012 Advisory Rule 8.7, External could be made static.
 * The function is defined for use by application code.
 */
#include "ftm_qd_driver.h"
#include "ftm_hw_access.h"

/*******************************************************************************
 * Code
 ******************************************************************************/

/*FUNCTION**********************************************************************
 *
 * Function Name : FTM_DRV_QuadDecodeStart
 * Description   : Configures the parameters needed and activates quadrature
 * decode mode.
 *
 * Implements    : FTM_DRV_QuadDecodeStart_Activity
 *END**************************************************************************/
status_t FTM_DRV_QuadDecodeStart(uint32_t instance,
  const ftm_quad_decode_config_t * config)
{
  DEV_ASSERT((instance == 1U) || (instance == 2U));
  DEV_ASSERT(config != NULL);
  FTM_Type * ftmBase = g_ftmBase[instance];
  ftm_state_t * state = ftmStatePtr[instance];
  status_t retStatus = STATUS_SUCCESS;
  if ((NULL != state) && (FTM_MODE_NOT_INITIALIZED == state->ftmMode)) {
    /* Disable Quadrature Decoder */
    FTM_DRV_SetQuadDecoderCmd(ftmBase, false);
    FTM_DRV_SetClockSource(ftmBase, FTM_CLOCK_SOURCE_NONE);

    /* Configure Quadrature Decoder */
    /* Set decoder mode Speed and direction or Phase A and Phase B encoding */
    FTM_DRV_SetQuadMode(ftmBase, config->mode);

    /* Set filter state for Phase A (enable/disable) */
    FTM_DRV_SetQuadPhaseAFilterCmd(ftmBase,
      config->phaseAConfig.phaseInputFilter);

    /* Set Phase A filter value if phase filter is enabled */
    if (config->phaseAConfig.phaseInputFilter) {
      FTM_DRV_SetChnInputCaptureFilter(ftmBase, CHAN0_IDX,
        config->phaseAConfig.phaseFilterVal);
    }

    /* Set filter state for Phase B (enable/disable) */
    FTM_DRV_SetQuadPhaseBFilterCmd(ftmBase,
      config->phaseBConfig.phaseInputFilter);

    /* Set Phase B filter value if phase filter is enabled */
    if (config->phaseBConfig.phaseInputFilter) {
      FTM_DRV_SetChnInputCaptureFilter(ftmBase, CHAN1_IDX,
        config->phaseBConfig.phaseFilterVal);
    }

    /* Set polarity for Phase A and Phase B */
    FTM_DRV_SetQuadPhaseAPolarity(ftmBase, config->phaseAConfig.phasePolarity);
    FTM_DRV_SetQuadPhaseBPolarity(ftmBase, config->phaseBConfig.phasePolarity);

    /* Configure counter (initial value and maximum value) */
    FTM_DRV_SetCounterInitVal(ftmBase, config->initialVal);
    FTM_DRV_SetMod(ftmBase, config->maxVal);
    FTM_DRV_SetCounter(ftmBase, config->initialVal);

    /* Enable Quadrature Decoder */
    FTM_DRV_SetQuadDecoderCmd(ftmBase, true);
    state->ftmMode = FTM_MODE_QUADRATURE_DECODER;
  } else {
    retStatus = STATUS_ERROR;
  }

  return retStatus;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FTM_DRV_QuadDecodeStop
 * Description   : De-activates quadrature decoder mode.
 *
 * Implements    : FTM_DRV_QuadDecodeStop_Activity
 *END**************************************************************************/
status_t FTM_DRV_QuadDecodeStop(uint32_t instance)
{
  DEV_ASSERT((instance == 1U) || (instance == 2U));
  FTM_Type * ftmBase = g_ftmBase[instance];
  ftm_state_t * state = ftmStatePtr[instance];

  /* Disable Quadrature decoder */
  FTM_DRV_SetQuadDecoderCmd(ftmBase, false);
  state->ftmMode = FTM_MODE_NOT_INITIALIZED;
  return STATUS_SUCCESS;
}

/*FUNCTION**********************************************************************
 *
 * Function Name : FTM_DRV_QuadGetState
 * Description   : Return the current quadrature decoder state
 * (counter value, overflow flag and overflow direction)
 *
 * Implements    : FTM_DRV_QuadGetState_Activity
 *END**************************************************************************/
ftm_quad_decoder_state_t FTM_DRV_QuadGetState(uint32_t instance)
{
  DEV_ASSERT((instance == 1U) || (instance == 2U));
  FTM_Type const * ftmBase = g_ftmBase[instance];
  ftm_quad_decoder_state_t state;
  state.counterDirection = FTM_DRV_GetQuadDir(ftmBase);
  state.overflowDirection = FTM_DRV_GetQuadTimerOverflowDir(ftmBase);
  state.overflowFlag = FTM_DRV_HasTimerOverflowed(ftmBase);
  state.counter = FTM_DRV_GetCounter(ftmBase);
  return state;
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
