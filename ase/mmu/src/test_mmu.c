#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hardware.h"
#include "hconf.h"
#include "tlb.h"

#define N 256

void empty_it() {
    return;
}

static int sum(void *ptr) {
    int i;
    int sum = 0;

    for(i = 0; i < PAGE_SIZE * N/2 ; i++)
        sum += ((char*)ptr)[i];
    return sum;
}

static void switch_to_process0(void) {
    current_process = 0;
    _out(MMU_CMD, MMU_RESET);
}

static void switch_to_process1(void) {
    current_process = 1;
    _out(MMU_CMD, MMU_RESET);
}

int main() {

  unsigned int i;
  void *ptr;
  int res;

  /* init hardware */
  if(init_hardware(HARDWARE_INI) == 0) {
      fprintf(stderr, "Error in hardware initialization\n");
      exit(EXIT_FAILURE);
  }

  /* Interrupt handlers */
  for(i=0; i<16; i++)
      IRQVECTOR[i] = empty_it;

  /* Allows all IT */
  _mask(1);

  IRQVECTOR[16] = switch_to_process0;
  IRQVECTOR[17] = switch_to_process1;
  IRQVECTOR[MMU_IRQ] = mmuhandler;
  _mask(0x1001);

  ptr = virtual_memory;
  _int(16);
  memset(ptr, 1, PAGE_SIZE * N/2);
  _int(17);

  memset(ptr, 3, PAGE_SIZE * N/2);

  _int(16);
  res = sum(ptr);

  printf("Resultat du processus 0 : %d\n",res);
  _int(17);

  res = sum(ptr);
  printf("Resultat processus 1 : %d\n",res);

  exit(EXIT_SUCCESS);

}
