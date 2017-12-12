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

void mmuhandler() {
  struct entry_s e;
  int faultaddr = _in(MMU_FAULT_ADDR);
  if(faultaddr < (int) virtual_memory || faultaddr > (int) virtual_memory + VM_SIZE - 1) {
    printf("Tentative d'accés illégal %x\n", faultaddr);
    exit(0);
  }
  /* Ignore les 12 bits de poids faibles de l'adresse pour obtenir son numero de page */
  e.vpage = (faultaddr >> 12) & 0xFFF;
  if((e.ppage = ppage_of_vpage(current_process, e.vpage)) == -1) {
    printf("Tentative d'accés illégal %x\n", faultaddr);
    exit(1);
  }
  e.access_x = e.access_r = e.access_w = 1;
  e.active = 1;
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

int main() {

  void *ptr;
  int res;

  init();

  IRQVECTOR[16] = switch_to_process0;
  IRQVECTOR[17] = switch_to_process1;
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
