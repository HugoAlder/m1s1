#include <stdlib.h>
#include <stdio.h>

#include "hconf.h"
#include "hardware.h"
#include "drive.h"
#include "mbr.h"
#include "vol.h"

void empty_it() {
  return;
}

int main(int argc, char **argv) {

  struct volume_s cv = mbr.vol[current_vol];
  int i, max, res;

  /* Init hardware */
  if(init_hardware(HARDWARE_INI) == 0) {
    fprintf(stderr, "Error in hardware initialization\n");
    return 0;
  }

  /* Interreupt handlers */
  for(i = 0; i < 16; i++) {
    IRQVECTOR[i] = empty_it;
  }

  load_mbr();

  printf("Volume : %d\nCylinder : %d\nBlock : %d\nSize : %d\n\n", current_vol, cv.fst_cyl, cv.fst_sec, cv.nblock);

  init_super(0, 9999, "Test_vol");

  max = superblock.nfreeblocks;
  for(i = 0; i < max + 1; i++){
    res = new_block();
  	printf("Block %d allocated\n" , res);
  }

  printf("\nTotal free blocks : %d\n", superblock.nfreeblocks);

  printf("Freeing block 0\n");
  free_block(1);
  printf("Free blocks available : %d\n\n", superblock.nfreeblocks);

  printf("Freeing block 2\n");
  free_block(4);
  printf("Free blocks available : %d\n\n", superblock.nfreeblocks);

  printf("Adding new block\n");
  res = new_block();
  printf("Free blocks available : %d\n\n", superblock.nfreeblocks);

  return 0;

}
