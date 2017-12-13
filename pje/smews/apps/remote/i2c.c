#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "pins.h"
#include "channels.h"
#include "timers.h"
#include "generators.h"
#include "rflpc17xx/rflpc17xx.h"
#include "rflpc17xx/tinylibc/printf.h"

static char direction = 'k';

/*
<generator>
  <handlers init="init" doGet="doGet"/>
	<properties interaction="alert" persistence="volatile" channel="pilap"/>
</generator>
*/

void sleep(uint32_t micros) {
  uint32_t delay, counter;
  for (delay = (16 * micros), counter = 0; counter < delay; ++counter)
    asm("");
}

int get_val() {
  int k;
  int accu = 0;
  for (k = 29; k >= 0; k--) {
    sleep(600);
    accu = accu | (rflpc_gpio_get_pin(J16) << k);
  }
  return accu;
}

static char doGet(struct args_t *args) {
  out_uint(res);
  return 1;
}

static char rir(struct args_t *args) {
  int something = 0;
  int k = 0;
  if (!rflpc_gpio_get_pin(ADC0)) {
    for (k = 29; k >= 0; k--) {
      sleep(600);
      something = something | (rflpc_gpio_get_pin(ADC0) << k);
    }
    res = something;
    server_push(&pilap);
  }
  return 0;
}

static char init() {
  rflpc_led_init();
  rflpc_uart_init(RFLPC_UART0);
  rflpc_gpio_set_pin_mode_input(ADC0, RFLPC_PIN_MODE_RESISTOR_PULL_DOWN);
  return set_timer(&rir, 30);
}
