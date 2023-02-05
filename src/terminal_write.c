#include <terminal_write.h>

static const SerialConfig sd_st_cfg = {
  .speed = 115200,
  .cr1 = 0, .cr2 = 0, .cr3 = 0
};

static SerialDriver         *debug_serial = &SD1;
static BaseSequentialStream *debug_stream = NULL;

void debugStreamInit( void )
{
    sdStart( debug_serial, &sd_st_cfg );
    palSetPadMode( GPIOA, 9, PAL_MODE_STM32_ALTERNATE_PUSHPULL); // TX
    palSetPadMode( GPIOA, 10, PAL_MODE_INPUT_PULLUP); // RX

    debug_stream = (BaseSequentialStream *)debug_serial;
}

void dbgPrintf( const char* format, ... )
{
    if ( !debug_stream )
        return;

    va_list ap;
    va_start(ap, format);
    chvprintf(debug_stream, format, ap);
    va_end(ap);
}


