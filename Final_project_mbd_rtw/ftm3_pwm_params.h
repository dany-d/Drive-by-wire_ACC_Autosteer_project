#ifndef FTM3_PWM_PARAMS_H
#define FTM3_PWM_PARAMS_H

/* MODULE flexTimer_pwm3.*/

/* Include inherited beans */
#include "ftm_pwm_driver.h"

/* Device instance number */
#define FTM_PWM3                       3U

/*fault configuration structure for FTM3*/
extern ftm_pwm_fault_param_t flexTimer_pwm3_FaultConfig;

/* PWM configuration for flexTimer_pwm3 */
extern ftm_pwm_param_t flexTimer_pwm3_PwmConfig;

/* Global configuration of flexTimer_pwm3 */
extern ftm_user_config_t flexTimer_pwm3_InitConfig;

/* Global state structure of flexTimer_pwm3 */
extern ftm_state_t ftmStateStruct3;

#endif
