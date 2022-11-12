#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_


void seven_segment_led_driver(void);
void traffic_LED(uint8_t value);
uint8_t update_7_segment_led_buffer(uint8_t val, uint8_t idx);

#endif
