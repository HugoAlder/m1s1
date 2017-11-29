#include <rflpc17xx/rflpc17xx.h>

#include "pins.h"
#include "generators.h"
#include "timers.h"
#include "channels.h"

#define RMT ADC0

static int button = 3;
static int i = 0;

/*
<generator>
    <handlers init="init" doGet="doGet"/>
    <properties interaction="alert" persistence="volatile" channel="remote_used"/>
</generator>
*/
static char doGet(struct args_t *args) {
  out_uint(i);
  return 1;
}

static char trigger_remote(struct args_t *args) {
  if(rflpc_gpio_get_pin(RMT) == 0) {
    i++;
  }
  out_uint(i);
  server_push(&remote_used);
  return 1;
}

static char init() {
  rflpc_gpio_set_pin_mode_input(RMT, RFLPC_PIN_MODE_RESISTOR_NONE);
  return set_timer(&trigger_remote, 100);
}
