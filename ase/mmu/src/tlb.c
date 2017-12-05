#include <stdlib.h>
#include <stdio.h>

#include "hardware.h"
#include "hconf.h"
#include "tlb.h"

int ppage_of_vpage(int process, int vpage) {
  return (vpage < 127) ? vpage + 0x80 * process + 1 : -1;
}
