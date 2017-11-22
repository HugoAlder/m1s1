#include <rflpc17xx/rflpc17xx.h>

#include "generators.h"
#include "timers.h"
#include "channels.h"

#define LED MBED_DIP14
#define BTN MBED_DIP9

static int button = 3;

/*
<generator>
    <handlers init="init" doGet="doGet"/>
    <properties interaction="alert" persistence="volatile" channel="button_pressed"/>
</generator>
*/
static char doGet(struct args_t *args) {
  out_uint(button);
  return 1;
}

static char trigger_button(struct args_t *args) {
  uint32_t current = rflpc_gpio_get_pin(BTN);
  if (current != button) {
    button = current;
    server_push(&button_pressed);
  }
  return 1;
}

static char init() {
  rflpc_gpio_set_pin_mode_output(LED, 1);
  rflpc_gpio_set_pin_mode_input(BTN, RFLPC_PIN_MODE_RESISTOR_NONE);
  return set_timer(&trigger_button, 50);
}
