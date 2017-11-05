#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "hconf.h"
#include "mbr.h"
#include "drive.h"

void save_mbr() {
  write_sector_n(0, 0, sizeof(mbr), (unsigned char *) &mbr);
}

void load_mbr() {
  read_sector_n(0, 0, sizeof(mbr), (unsigned char *) &mbr);
  if(mbr.magic != MAGIC_MBR) {
    mbr.magic = MAGIC_MBR;
    mbr.nvol = 0;
  }
}

int cyl_of_block(int vol, int block) {
  return mbr.vol[vol].fst_cyl + ((mbr.vol[vol].fst_sec + block) / NB_SEC);
}

int sec_of_block(int vol, int block) {
  return (mbr.vol[vol].fst_sec + block) % NB_SEC;
}

void read_block_n(int vol, int block, unsigned char * buf, int size) {
  read_sector_n(cyl_of_block(vol, block), sec_of_block(vol, block), size, buf);
}

void write_block_n(int vol, int block, unsigned char * buf, int size) {
  write_sector_n(cyl_of_block(vol, block), sec_of_block(vol, block), size, buf);
}

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
    write_block_n(vol, i, (unsigned char) &freeblock, sizeof(freeblock));
  }

  freeblock.next = BLOCK_NULL;
  write_block_n(vol, i, (unsigned char) &freeblock, sizeof(freeblock));

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

void save_super() {
  write_block_n(current_vol, 1, (unsigned char *) &superblock, sizeof(superblock));
}
