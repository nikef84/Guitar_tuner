#include <common.h>

void blink_test(){
  halInit();
  chSysInit();
  palSetPadMode(GPIOC, GPIOC_LED, PAL_MODE_OUTPUT_OPENDRAIN);
  while (true) {
     palTogglePad(GPIOC, GPIOC_LED);
     chThdSleepMilliseconds(1000);
  }
}
