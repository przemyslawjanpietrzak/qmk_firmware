#include "ch.h"
#include "hal.h"
#include "wait.h"

// Use TIM4 to allow for waits of less than 1ms. For more information:
// https://techoverflow.net/2015/09/09/accurate-short-long-delays-on-microcontrollers-using-chibios/
static const GPTConfig gpt1cfg = {
  100000, // 1 MHz timer clock.
  NULL, // No callback
  0, 0
};

void wait_us(uint64_t us) {
    /* this works:
    if (us != 0) {
        chThdSleepMicroseconds(us);
    }
    */
    if (us != 0) {
        gptStart(&GPTD1, &gpt1cfg);
        gptPolledDelay(&GPTD1, us);
    }
}
