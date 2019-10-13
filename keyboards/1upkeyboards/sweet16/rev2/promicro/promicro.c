#include "promicro.h"
#include "encoder.h"

#ifdef ENCODER_ENABLED
void encoder_update_kb(int8_t index, bool clockwise) {
    encoder_update_user(index, clockwise);
}
#endif

void matrix_init_kb(void) {
    /*
    for (uint8_t i = 0; i < 256; i++) {
        
    }
    */
}
