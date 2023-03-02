#include "ch.h"
#include "hal.h"
#include "common.h"


static PWMDriver *pwm1Driver = &PWMD1;

PWMConfig pwm1conf = {
    .frequency = 500000,
    .period    = 10000,
    .callback  = NULL,
    .channels  = {
                  {.mode = PWM_OUTPUT_ACTIVE_HIGH, .callback = NULL},
                  {.mode = PWM_OUTPUT_DISABLED,    .callback = NULL},
                  {.mode = PWM_OUTPUT_DISABLED,    .callback = NULL},
                  {.mode = PWM_OUTPUT_DISABLED,    .callback = NULL}
                  },
    .cr2        = 0,
    .dier       = 0
};

/*
 * A8 - step
 * A9 - dir
 */
void pwm_test(void)
{
    chSysInit();
    halInit();
    palSetPadMode( GPIOA, 8,  PAL_MODE_STM32_ALTERNATE_PUSHPULL );
    palSetPadMode(GPIOA, 9, PAL_MODE_OUTPUT_PUSHPULL);
    palSetPad(GPIOA, 9);
    pwmStart( pwm1Driver, &pwm1conf );
    pwmEnableChannel( &PWMD1, 0, 5000 );
    palSetPadMode(GPIOC, GPIOC_LED, PAL_MODE_OUTPUT_OPENDRAIN);

    while (true){
      palTogglePad(GPIOC, GPIOC_LED);
      chThdSleepMilliseconds(100);
    }
}

