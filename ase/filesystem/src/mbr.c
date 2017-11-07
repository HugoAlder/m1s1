#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
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
  return (mbr.vol[vol].fst_cyl + mbr.vol[vol].fst_sec + block) % NB_SEC;
}

int sec_of_block(int vol, int block) {
  return (mbr.vol[vol].fst_sec + block) % SECTOR_SIZE;
}

void read_block(unsigned int vol, unsigned int nblock, unsigned char * buffer) {
  read_sector_n(cyl_of_block(vol, nblock), mbr.vol[vol].fst_sec, nblock, buffer);
}

void write_block(unsigned int vol, unsigned int nblock, const unsigned char * buffer) {
  write_sector_n(cyl_of_block(vol, nblock), mbr.vol[vol].fst_sec, nblock, buffer);
}

void read_block_n(int vol, int block, unsigned char * buf, int size) {
  read_sector_n(cyl_of_block(vol, block), sec_of_block(vol, block), size, buf);
}

void write_block_n(int vol, int block, unsigned char * buf, int size) {
  write_sector_n(cyl_of_block(vol, block), sec_of_block(vol, block), size, buf);
}
