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
  return mbr.vol[vol].fst_cyl + (mbr.vol[vol].fst_sec + block) / NB_SEC;
}

int sec_of_block(int vol, int block) {
  return (mbr.vol[vol].fst_sec + block) % NB_SEC;
}

void read_block(unsigned int vol, unsigned int block, unsigned char * buf) {
  read_sector(cyl_of_block(vol, block), sec_of_block(vol, block), buf);
}

void write_block(unsigned int vol, unsigned int block, unsigned char * buf) {
  write_sector(cyl_of_block(vol, block), sec_of_block(vol, block), buf);
}

void read_block_n(int vol, int block, unsigned char * buf, int size) {
  read_sector_n(cyl_of_block(vol, block), sec_of_block(vol, block), size, buf);
}

void write_block_n(int vol, int block, unsigned char * buf, int size) {
  write_sector_n(cyl_of_block(vol, block), sec_of_block(vol, block), size, buf);
}
