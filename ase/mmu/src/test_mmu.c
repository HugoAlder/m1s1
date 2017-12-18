#include <stdio.h>
#include <stdlib.h>

#include "hardware.h"
#include "hconf.h"

void empty_it() {
  return;
}

static void mmuhandler() {
  int faultaddr = _in(MMU_FAULT_ADDR);
  printf("Tentative d'accés illégal %x\n", faultaddr);
  exit(-1);
}

int init() {
  unsigned int i;

  /* init hardware */
  if(init_hardware(HARDWARE_INI) == 0) {
      fprintf(stderr, "Error in hardware initialization\n");
      exit(EXIT_FAILURE);
  }

  /* Interrupt handlers */
  for(i = 0; i < 16; i++) {
      IRQVECTOR[i] = empty_it;
  }

  /* Add mmu handler */
  IRQVECTOR[MMU_IRQ] = mmuhandler;

  /* Allows all IT */
  _mask(1);

  return 0;
}

/* Doit renvoyer une tentative d'accés illégal */
int main() {
  char * ptr = (char *) 0;
  init();
  *ptr = 'c';
  return 0;
}
