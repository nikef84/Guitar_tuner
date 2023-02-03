#include <common.h>
#include <terminal_write.h>

void terminal_write_test(void){
  halInit();
  chSysInit();
  debugStreamInit();
  palSetPadMode(GPIOC, GPIOC_LED, PAL_MODE_OUTPUT_OPENDRAIN);
  uint16_t num = 0;
  while (true) {
    dbgPrintf("NUM = %d\r\n", num);
    palTogglePad(GPIOC, GPIOC_LED);
    num = num + 1;
    chThdSleepMilliseconds(1000);
  }
}
