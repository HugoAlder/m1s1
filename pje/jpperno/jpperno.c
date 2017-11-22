#include <rflpc17xx/rflpc17xx.h>

#include "generators.h"
#include "timers.h"
#include "channels.h"

#define RMT MBED_DIP15

/*
<generator>
    <handlers init="init" doGet="doGet"/>
    <properties interaction="alert" persistence="volatile" channel="remote_used"/>
</generator>
*/
static char doGet(struct args_t *args) {
  uint32_t current = rflpc_gpio_get_pin(RMT);
  out_uint(current);
  return 1;
}

static char trigger_remote(struct args_t *args) {
  server_push(&remote_used);
  return 1;
}

static char init() {
  rflpc_gpio_set_pin_mode_input(RMT, RFLPC_PIN_MODE_RESISTOR_NONE);
  return set_timer(&trigger_remote, 1000);
}
