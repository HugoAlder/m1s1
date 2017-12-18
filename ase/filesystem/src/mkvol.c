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
  printf("mkvol <cyl> <sec> <size> <type> <name>\n");
}

int main (int argc, char ** argv) {
  int i;
  int e;

  if(init_hardware(HARDWARE_INI) == 0) {
    fprintf(stderr, "Error in hardware initialization\n");
    return 0;
  }

  for(i = 0; i < 16; i++) {
    IRQVECTOR[i] = empty_it;
  }

  if(argc != 6) {
    usage();
    return 1;
  }

  printf("Loading MBR\n");
  load_mbr();

  mbr.vol[mbr.nvol].fst_cyl = atoi(argv[1]);
  mbr.vol[mbr.nvol].fst_sec = atoi(argv[2]);
  mbr.vol[mbr.nvol].nblock = atoi(argv[3]);

  switch(atoi(argv[4])) {
    case 0 :
      e = BASE;
      break;
    case 1 :
      e = ANNEXE;
      break;
    default :
      e = OTHER;
      break;
  }

  mbr.vol[mbr.nvol].type = e;

  printf("Saving MBR\n");

  printf("Initializating superblock\n");
  init_super(mbr.nvol, 0x1234, argv[5]);

  mbr.nvol++;
  save_mbr();

  printf("Volume %d added successfully\n", mbr.nvol);

  return 0;
}
