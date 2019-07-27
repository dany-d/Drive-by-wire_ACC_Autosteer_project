#ifndef _S32K_CLOCK_INIT_H
#define _S32K_CLOCK_INIT_H
#include <stdint.h>
#define XTAL_FREQ                      8000000UL
#define CORE_CLK_FREQ                  80000000UL

void Clock_Setup(void);
void UpdateSystickConfig(uint32_t ticks);

#endif
