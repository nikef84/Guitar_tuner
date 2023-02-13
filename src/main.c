#include <common.h>


static inline void testRoutines(void) {
#if(PROGRAM_ROUTINE == BLINK_TEST)
    blink_test();
#elif(PROGRAM_ROUTINE == STEPPER_MOTOR_TEST)
    stepper_motor_test();
#elif(PROGRAM_ROUTINE == TERMINAL_WRITE_TEST)
    terminal_write_test();
#elif(PROGRAM_ROUTINE == ADC_TEST)
    adc_test();
#elif(PROGRAM_ROUTINE == SIGNAL_RECORDING_TEST)
    signal_recording_test();
#elif(PROGRAM_ROUTINE == FFT_TEST)
    fft_test();
#endif
}



int main(void) {
#if(PROGRAM_ROUTINE != MAIN_ROUTINE)
    testRoutines();

#else
    chSysInit();
    halInit();

    while(1);

#endif
}
