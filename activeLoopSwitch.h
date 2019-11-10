#include <Arduino.h>

extern void main_loop(unsigned long);
extern void main_setup();
extern void (*active_loop)(unsigned long);
