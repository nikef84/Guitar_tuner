#include "adc_lld.h"
#include "terminal_write.h"

#define ARRAY_LENGTH        5000
static uint16_t array[ARRAY_LENGTH] = {0};

void adc_test(void) {

    halInit();
    chSysInit();
    debugStreamInit();
    dbgPrintf("start\r\n");
    adcSimpleInit();
    systime_t begin = chVTGetSystemTime();
    while (true) {
        adcSimpleRead(array, ARRAY_LENGTH);
        systime_t end = chVTGetSystemTime();
        dbgPrintf("time = %d\r\n", end - begin);
        begin = chVTGetSystemTime();

    }

}
