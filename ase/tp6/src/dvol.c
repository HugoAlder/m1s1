#include <stdio.h>
#include "drive.h"
#include "mbr.h"
#include "hardware.h"
#include "hconf.h"

void empty_it(void){
  return;
}

int main() {
  int i;
  int nvol = mbr.nvol;

  if(init_hardware(HARDWARE_INI) == 0) {
    fprintf(stderr, "Error in hardware initialization\n");
    return 0;
  }

  for(i = 0; i < 16; i++) {
    IRQVECTOR[i] = empty_it;
  }

  load_mbr();

  printf("Volume(s) on the disk : %d\n", nvol);
  for(i = 0; i < nvol; i++) {
    struct volume_s current_vol = mbr.vol[i];
    int t = current_vol.type;
    char * type;
    printf("\n");
    if(t == 0) {
      type = "Base";
    } else if(t == 1) {
      type = "Annexe";
    } else {
      type = "Other";
    }
    printf("Volume : %d\nCylinder : %d\nBlock : %d\nSize : %d\nType : %s\n", i, current_vol.fst_cyl, current_vol.fst_sec, current_vol.nblock, type);
  }
  return 0;
}
