extern void user_process();

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hardware.h"
#include "hconf.h"
#include "tlb.h"
#include "swap.h"

void empty_it() {
  return;
}

void mmuhandler() {
  struct entry_s e;
  int mapped_vpage = 1;
  int faultaddr = _in(MMU_FAULT_ADDR);
  if(faultaddr < (int) virtual_memory || faultaddr > (int) virtual_memory + VM_SIZE - 1) {
    fprintf("Tentative d'accés illégal %x\n", faultaddr);
    exit(1);
  }
  e.vpage = mapped_vpage;
  e.ppage = 1;
  store_to_swap(mapped_vpage, 1);
  _out(TLB_DEL_ENTRY, * (int *) &e);
  /* Ignore les 12 bits de poids faibles de l'adresse pour obtenir son numero de page */
  e.vpage = (faultaddr >> 12) & 0xFFF;
  fetch_from_swap(e.vpage, e.ppage);
  _out(TLB_ADD_ENTRY, * (int *) &e);
}

int init() {
  unsigned int i;

  /* init hardware */
  if(init_hardware(HARDWARE_INI) == 0) {
      fprintf(stderr, "Error in hardware initialization\n");
      exit(EXIT_FAILURE);
  }

  /* Interrupt handlers */
  for(i = 0; i < 16; i++)
      IRQVECTOR[i] = empty_it;

  /* Add mmu handler */
  IRQVECTOR[MMU_IRQ] = mmuhandler;

  /* Allows all IT */
  _mask(1);

  return 0;
}

int main(int argc, char **argv) {
    init();
    mmuhandler();
    _mask(0x1001);
    user_process();
    return 0;
}
