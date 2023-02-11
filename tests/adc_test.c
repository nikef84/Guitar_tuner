#include <adc_lld.h>
#include "terminal_write.h"


// �������� ����� ��� ��������������


void adc_test(void) {

    halInit();
    chSysInit();
    debugStreamInit();
    // ������������� ���� � ����� �� ���� � ��������� ��� ������
    adcSimpleInit();
    uint16_t array[50] = {0};

    while (true) {
        adcSimpleRead(array, 50);
        dbgPrintf("%d\r\n", array[49]);
        chThdSleepMilliseconds(2000);
    }

}
