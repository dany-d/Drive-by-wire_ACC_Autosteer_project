#ifndef FTM0_PWM_PARAMS_H
#define FTM0_PWM_PARAMS_H

/* MODULE flexTimer_pwm0.*/

/* Include inherited beans */
#include "ftm_pwm_driver.h"

/* Device instance number */
#define FTM_PWM0                       0U

/*fault configuration structure for FTM0*/
extern ftm_pwm_fault_param_t flexTimer_pwm0_FaultConfig;

/* PWM configuration for flexTimer_pwm0 */
extern ftm_pwm_param_t flexTimer_pwm0_PwmConfig;

/* Global configuration of flexTimer_pwm0 */
extern ftm_user_config_t flexTimer_pwm0_InitConfig;

/* Global state structure of flexTimer_pwm0 */
extern ftm_state_t ftmStateStruct0;

#endif
