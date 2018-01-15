#include "rflpc17xx/rflpc17xx.h"
#include "generators.h"
#include "timers.h"
#include "channels.h"

#define J16 MBED_DIP15 // RIR en J16
static char init_get();
static char direction = 'z';

/*
<generator>
    <handlers init="init" doGet="doGet"/>
    <properties interaction="alert" persistence="volatile" channel="remote_changed"/>
</generator>
*/
static char doGet(struct args_t *args) {
  printf("%c\n\r ", direction);
  out_str(direction);
  init_get();
}

void sleep(uint32_t micros) {
  uint32_t delay, counter;
  for (delay = (16 * micros), counter = 0; counter < delay; ++counter)
  asm("");
}

int get_val() {
  int accu = 0;
  int k;

  for (k = 29; k >= 0; k--) {
    sleep(600);
    accu = accu | (rflpc_gpio_get_pin(J16) << k);
  }

  return accu;
}

static char init_get() {
  int accu = 0;
  char tmp_dir = 'z';

  while(1) {
    if (!rflpc_gpio_get_pin(J16)) {
      accu = get_val();
      printf("accu : %x\n\r", accu);
      if (accu == 0xFF) {
        get_val();
        get_val();
        switch (accu = get_val()) {
          case 0x1e7b6de5:
          case 0x1e7b69e5:
          case 0x1e7b69ed:
          case 0x1e7b69e4:
            tmp_dir = 'l';
            break;
          case 0x1e7b69e7 :
            tmp_dir = 'u';
            break;
          case 0x1e7b793d :
            tmp_dir = 'r';
            break;
          case 0x1e7b7927:
          case 0x1e7b792f:
            tmp_dir = 'd';
            break;
          default :
            printf("default: accu=%x\n\r", accu);
            break;
        }
        if(direction != tmp_dir){
          direction = tmp_dir;
          printf("%c\n\r ", direction);
          server_push(&remote_changed);
          return 0;
        }
      }
    }
    return 0;
  }
}

static char init() {
    rflpc_led_init();
    rflpc_uart_init(RFLPC_UART0);
    rflpc_gpio_set_pin_mode_input(J16,RFLPC_PIN_MODE_RESISTOR_PULL_DOWN);
    init_get();
}
