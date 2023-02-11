#include <adc_lld.h>
#include "terminal_write.h"


// Выделяем буфер под преобразование


void adc_test(void) {

    halInit();
    chSysInit();
    debugStreamInit();
    // Устанавливаем ногу в режим на вход и запускаем АЦП модуль
    adcSimpleInit();
    uint16_t array[50] = {0};

    while (true) {
        adcSimpleRead(array, 50);
        dbgPrintf("%d\r\n", array[49]);
        chThdSleepMilliseconds(2000);
    }

}
