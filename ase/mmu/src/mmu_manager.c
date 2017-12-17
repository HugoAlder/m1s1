extern void user_process();

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hardware.h"
#include "hconf.h"
#include "tlb.h"
#include "swap.h"

static int mapped_pages = 1;
static struct vm_mapping_s vm_mapping[VM_PAGES];
static struct pm_mapping_s pm_mapping[PM_PAGES];

void empty_it() {
  return;
}

void mmuhandler() {
  struct entry_s entry;
  int vpage = -1;
  int ppage = -1;
  int faultaddr = _in(MMU_FAULT_ADDR);

  /* En cas d'erreur */
  if(faultaddr < (int) virtual_memory || faultaddr > (int) virtual_memory + VM_SIZE - 1) {
    fprintf(stderr, "Tentative d'accés illégal %x\n", faultaddr);
    exit(1);
  }

  /* Numéro de page virtuelle */
  vpage = (faultaddr >> 12) & 0xFFF;

  if(vm_mapping[vpage].is_mapped) {
    ppage = vm_mapping[vpage].ppage;
  } else {

    /* Changer de page de mémoire physique */
    if(mapped_pages >= PM_PAGES) {
      mapped_pages = 1;
    }

    if(pm_mapping[ppage].is_mapped) {
      store_to_swap(pm_mapping[ppage].vpage, ppage);
      vm_mapping[pm_mapping[ppage].vpage].is_mapped = 0;
    }

    entry.ppage = ppage;
    _out(TLB_DEL_ENTRY, * (int *) &entry);

    fetch_from_swap(vpage, ppage);

    /* Maj vm_mapping et pm_mapping */
    vm_mapping[vpage].ppage = ppage;
    pm_mapping[ppage].vpage = vpage;
    vm_mapping[vpage].is_mapped = pm_mapping[ppage].is_mapped = 1;

    mapped_pages++;

  }

  /* Maj TLB */
  entry.ppage = ppage;
  entry.vpage = vpage;
  entry.access_r = entry.access_w = entry.access_x = 1;
  _out(TLB_ADD_ENTRY, * (int *) &entry);
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
    init_swap();
    _mask(0x1001);
    user_process();
    return 0;
}
