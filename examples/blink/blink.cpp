#include <activeLoopSwitch.h>
#include <Arduino.h>

unsigned long last_tick;
#ifdef ARDUINO_AVR_LILYPAD_USB
#define LED_PIN 11
#else
#define LED_PIN LED_BUILTIN
#endif

void led_on_idle (unsigned long tick);
void led_off_idle (unsigned long tick);

void led_on_idle (unsigned long tick) {
   if (tick-last_tick>1000) {
       last_tick=tick;
       digitalWrite(LED_PIN, LOW); 
       active_loop=led_off_idle;
   } 
}


void led_off_idle (unsigned long tick) {
    if (tick-last_tick>1000) {
        last_tick=tick;
        digitalWrite(LED_PIN, HIGH); 
        active_loop=led_on_idle;
    } 
}

void main_setup () {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);  
}

void main_loop (unsigned long tick) {
    // switch to off idle loop
    active_loop=led_off_idle;
}


