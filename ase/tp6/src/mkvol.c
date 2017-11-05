#include <stdio.h>
#include <stdlib.h>
#include "drive.h"
#include "mbr.h"
#include "hardware.h"
#include "hconf.h"

void empty_it(void){
  return;
}

void usage() {
  printf("mkvol <cyl> <sec> <size> \n");
}

int main (int argc, char ** argv) {
  int i;

  if(init_hardware(HARDWARE_INI) == 0) {
    fprintf(stderr, "Error in hardware initialization\n");
    return 0;
  }

  for(i = 0; i < 16; i++) {
    IRQVECTOR[i] = empty_it;
  }

  if(argc != 4) {
    usage();
    return 1;
  }

  load_mbr();

  mbr.vol[mbr.nvol].fst_cyl = atoi(argv[1]);
  mbr.vol[mbr.nvol].fst_sec = atoi(argv[2]);
  mbr.vol[mbr.nvol].nblock = atoi(argv[3]);
  mbr.vol[mbr.nvol].type = ANNEXE;
  mbr.nvol++;

  save_mbr();

  return 0;
}
