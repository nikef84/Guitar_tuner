#include <common.h>


static inline void testRoutines(void) {
#if(PROGRAM_ROUTINE == STEP_ENGINE_TEST)
    blink_test();
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
