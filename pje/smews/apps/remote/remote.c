#include <rflpc17xx/rflpc17xx.h>
#include "i2c.h"

/* #include "pins.h" */
#include "generators.h"
#include "timers.h"
#include "channels.h"

#define RMT RFLPC_I2C_PORT2

static int cpt = 0;
static uint16_t i;

void sleep(uint32_t ms) {
  uint32_t delay, counter;
  for (delay = (16000 * ms), counter = 0; counter < delay; ++counter)
    asm("");
}

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

  uint8_t ir_sensor_addr = 0x90;
  uint8_t status;

  /* Init i2c mode */
  if(rflpc_i2c_init(RMT, RFLPC_I2C_MODE_MASTER, 0) == -1) {
    return 0;
  }

  /* Reading value and putting it in i by getting MSB from rflpc_i2c_read*/
  i = rflpc_i2c_read(RMT, ir_sensor_addr, &cpt, 1, 1);
  /* Checking the status of rflpc_i2c_read */
  status = (i & FF00) >> 8;
  if(status == RFLPC_I2C_SLAVE_TRANSMITTED_DATA) {
    /* LED control */
    rflpc_led_binary_value(cpt);
    cpt++;
    if(cpt > 15)
      cpt = 0;
  }

  /* Sending the value of i */
  out_uint(i);
  server_push(&remote_used);
  return 1;
}

static char init() {
  rflpc_gpio_set_pin_mode_input(RMT, RFLPC_PIN_MODE_RESISTOR_NONE);
  return set_timer(&trigger_remote, 100);
}
