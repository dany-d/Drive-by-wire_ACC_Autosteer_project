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
 * @file ftm_qd_driver.h
 *
 * @page misra_violations MISRA-C:2012 violations
 *
 */
#ifndef FTM_QD_DRIVER_H
#define FTM_QD_DRIVER_H
#include "ftm_common.h"

/*!
 * @addtogroup ftm_qd_driver
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief FlexTimer quadrature decoder channel parameters
 *
 * Implements : ftm_phase_params_t_Class
 */
typedef struct {
  bool phaseInputFilter;               /*!< True: disable phase filter,
                                        *   False: enable phase filter */
  uint8_t phaseFilterVal;              /*!< Filter value (if input filter is enabled)*/
  ftm_quad_phase_polarity_t phasePolarity;/*!< Phase polarity */
} ftm_phase_params_t;

/*!
 * @brief FTM quadrature configure structure
 *
 * Implements : ftm_quad_decode_config_t_Class
 */
typedef struct {
  ftm_quad_decode_mode_t mode;         /*!< FTM_QUAD_PHASE_ENCODE or FTM_QUAD_COUNT_AND_DIR */
  uint16_t initialVal;                 /*!< Initial counter value*/
  uint16_t maxVal;                     /*!< Maximum counter value*/
  ftm_phase_params_t phaseAConfig;     /*!< Configuration for the input phase a */
  ftm_phase_params_t phaseBConfig;     /*!< Configuration for the input phase b */
} ftm_quad_decode_config_t;

/*!
 * @brief FTM quadrature state(counter value and flags)
 *
 * Implements : ftm_quad_decoder_state_t_Class
 */
typedef struct {
  uint16_t counter;                    /*!< Counter value */
  bool overflowFlag;                   /*!< True if overflow occurred,
                                        *   False if overflow doesn't occurred */
  bool overflowDirection;              /*!< False if overflow occurred at minimum value,
                                        *   True if overflow occurred at maximum value */
  bool counterDirection;               /*!< False FTM counter is decreasing,
                                        *   True FTM counter is increasing */
} ftm_quad_decoder_state_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)

extern "C" {

#endif

  /*!
   * @brief Configures the quadrature mode and starts measurement
   *
   * @param [in] instance Instance number of the FTM module.
   * @param [in] config   Configuration structure(quadrature decode mode, polarity for both phases,
   *                      initial and maximum value for the counter, filter configuration).
   * @return success
   *        - STATUS_SUCCESS : Completed successfully.
   *        - STATUS_ERROR : Error occurred.
   */
  status_t FTM_DRV_QuadDecodeStart(uint32_t instance,
    const ftm_quad_decode_config_t * config);

  /*!
   * @brief De-activates the quadrature decode mode.
   *
   * @param [in] instance Instance number of the FTM module.
   * @return success
   *        - STATUS_SUCCESS : Completed successfully.
   *        - STATUS_ERROR : Error occurred.
   */
  status_t FTM_DRV_QuadDecodeStop(uint32_t instance);

  /*!
   * @brief Return the current quadrature decoder state (counter value, overflow flag and
   * overflow direction)
   *
   * @param [in] instance Instance number of the FTM module.
   * @return The current state of quadrature decoder
   */
  ftm_quad_decoder_state_t FTM_DRV_QuadGetState(uint32_t instance);

#if defined(__cplusplus)

}
#endif

/*! @}*/

/*! @}*/
/* End of addtogroup ftm_qd_driver */
#endif                                 /* FTM_QD_DRIVER_H */

/*******************************************************************************
 * EOF
 ******************************************************************************/
