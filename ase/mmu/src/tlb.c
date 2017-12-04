#include <stdlib.h>
#include <stdio.h>

#include "hardware.h"
#include "hconf.h"
#include "tlb.h"

int ppage_of_vpage(int process, int vpage) {
  return (vpage < 127) ? vpage + 0x80 * process + 1 : -1;
}

void mmuhandler() {
  struct entry_s e;
  /* int faultaddr = _in(MMU_FAULT_ADDR); */
  int faultaddr = 1;
  if(faultaddr < virtualaddr || faultaddr > virtualaddr + VM_SIZE - 1) {
    printf("Tentative d'accés illégal %x\n", faultaddr);
    exit(0);
  }
  /* Ignore les 12 bits de poids faibles de l'adresse pour obtenir son numero de page */
  e.vpage = (faultaddr >> 12) & 0x00000FFF;
  if((e.ppage = ppage_of_vpage(current_process, e.vpage)) == -1) {
    printf("Tentative d'accés illégal %x\n", faultaddr);
    exit(1);
  }
  e.access_x = e.access_r = e.access_w = 1;
  e.active = 1;
  _out(TLB_ADD_ENTRY, * (int *) &e);
}
