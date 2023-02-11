#include <adc_lld.h>

/*
 * @brief   Setting the timer configuration to start the adc conversion with some period.
 *
 * @note    The timer makes the TRGO event which is used to start the adc conversion.
 *
 * @note    It helps starting the adc conversion with some frequency.
 *
 * @note    GPTD3 is used.
 */
static const GPTConfig tim3_conf = {
    .frequency = GPT_CONFIG_FREQUENCY, // Sets the timer frequency.
    .callback = NULL,
    .cr2 = TIM_CR2_MMS_1, // Sets the TRGO events.
    .dier = 0
};

/*
 * @brief   Setting the adc configuration.
 *
 * @note    The ADC conversion is started by the timer.
 *
 * @note    ADC1 is used.
 *
 * @note    The channel 0 from the ADC1 is used.
 */
static ADCConversionGroup adc0_conf = {
    .circular = false, // Non-continuous mode.

    .num_channels = 1, // Used only one channel.

    .end_cb = NULL,
    .error_cb = NULL,

    .cr1 = 0,
    .cr2 = ADC_CR2_EXTTRIG | ADC_CR2_EXTSEL_SRC(0b100), // Sets the TRGO event.

    .smpr1 = 0,
    .smpr2 = ADC_SMPR2_SMP_AN0(ADC_SAMPLE_239P5), // 239.5 cycles sampling time.

    .sqr1 = ADC_SQR1_NUM_CH(1), // Number of channels.
    .sqr2 = 0,
    .sqr3 = ADC_SQR3_SQ1_N(ADC_CHANNEL_IN0) // Which channel is used.
};

/*
 * @brief   Inits the adc conversion by the timer and sets the leg to analog mode.
 *
 * @note    ADC1 is used.
 *
 * @note    The channel 0 from the ADC1 is used.
 *
 * @note    GPTD3 is used.
 */
void adcSimpleInit(void){
    gptStart(GPT_3, &tim3_conf);
    adcStart(ADC_1, NULL);
    palSetLineMode(ADC_LINE_CH0, PAL_MODE_INPUT_ANALOG);
    gptStartContinuous(GPT_3, 1000);
}

/*
 * @brief   Stops timer and ADC.
 *
 * @note    ADC1 is used.
 *
 * @note    GPTD3 is used.
 */
void adcSimpleUninit(void){
    gptStop(GPT_3);
    adcStop(ADC_1);
}

/*
 * @bried       Reads data from the ADC and writes it to the array.
 *
 * @param[in]   buf                 An array in which data will be write from the adc.
 *              numberOfSamples     Number of the adc conversion which will be write to the array.
 *                                  This number is equal to lenght of input array (buf).
 */
void adcSimpleRead(uint16_t *buf, uint16_t numberOfSamples){
    adcConvert(ADC_1, &adc0_conf, buf, numberOfSamples);
}


