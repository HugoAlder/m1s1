#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "drive.h"
#include "mbr.h"
#include "hardware.h"
#include "hconf.h"

void empty_it() {
    return;
}

void usage() {
  printf("rmvol <vol>\n");
}

int main(int argc, char **argv) {

  int vol, i;
  struct volume_s empty_vol;
  memset(&empty_vol, 0, sizeof(empty_vol));

  if (argc != 2) {
    usage();
    exit(EXIT_FAILURE);
  }

  if(init_hardware(HARDWARE_INI) == 0) {
    fprintf(stderr, "Error in hardware initialization\n");
    return 0;
  }

  for(i = 0; i < 16; i++) {
    IRQVECTOR[i] = empty_it;
  }

  vol = atoi(argv[1]);

  if(vol > mbr.nvol) {
    fprintf(stderr, "Error : volume doesn't exists\n");
    return 0;
  }

  printf("Loading MBR\n");
  load_mbr();

  for(i = vol; i < mbr.nvol - 1; i++) {
    mbr.vol[i] = mbr.vol[i+1];
  }
  mbr.vol[i] = empty_vol;

  printf("Saving MBR\n");
  mbr.nvol--;
  save_mbr();

  printf("Volume %d removed successfully\n", vol);

  return 0;
}
