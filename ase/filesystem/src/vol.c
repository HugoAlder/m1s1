#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "mbr.h"
#include "drive.h"
#include "hconf.h"

void init_super(int vol, int serial, char * name) {
  int i;
  struct freeblock_s freeblock;
  superblock.magic = MAGIC_SB;
  superblock.serial = serial;
  strncpy(superblock.name, name, 32);
  superblock.nblocks = BLOCK_NULL;
  superblock.nfreeblocks = mbr.vol[vol].nblock - 1;
  superblock.fst_freeblock = 1;

  for(i = 1; i < mbr.vol[vol].nblock - 1; i++){
    freeblock.next = i + 1;
    write_block_n(vol, i, (unsigned char *) &freeblock, sizeof(freeblock));
  }

  freeblock.next = BLOCK_NULL;
  write_block_n(vol, i, (unsigned char *) &freeblock, sizeof(freeblock));

  current_vol = vol;
  save_super();
}

int load_super(int vol) {
  if(vol >= mbr.nvol)
    return 0;
  read_block_n(vol, 0, (unsigned char *) &superblock, sizeof(superblock));
  if(superblock.magic != MAGIC_SB)
    return 0;
  current_vol = vol;
  return 1;
}

void format_block(unsigned int vol, unsigned int nblock) {
    unsigned char buffer[SECTOR_SIZE];
    unsigned int i;

    for (i = 0; i < SECTOR_SIZE; i++)
        buffer[i] = 0;

    write_block(vol, nblock, buffer);
}


void save_super() {
  write_block_n(current_vol, 0, (unsigned char *) &superblock, sizeof(superblock));
}

int new_block() {
  int res;
  struct freeblock_s freelist;

  assert(superblock.magic == MAGIC_SB);
  res = superblock.fst_freeblock;
  if(res == BLOCK_NULL) {
    return res;
  }
  read_block_n(current_vol, res, (unsigned char *) &freelist, sizeof(freelist));
  superblock.fst_freeblock = freelist.next;
  superblock.nfreeblocks--;
  save_super();
  return res;
}

void free_block(unsigned int block) {
  struct freeblock_s fb;
  assert(superblock.magic == MAGIC_SB);

  if (block == BLOCK_NULL){
    return;
  }

  fb.next = superblock.fst_freeblock;
  write_block_n(current_vol, block, (unsigned char *) &fb, sizeof(struct freeblock_s));
  superblock.nfreeblocks++;
  superblock.fst_freeblock = block;
  save_super();
}
