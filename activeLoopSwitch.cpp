#include <activeLoopSwitch.h>

void (*active_loop)(unsigned long) = main_loop;
void setup () {
  main_setup();
}
void loop () {
    active_loop(millis());
}

