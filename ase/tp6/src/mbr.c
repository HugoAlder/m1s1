#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "hconf.h"
#include "mbr.h"
#include "drive.h"

void save_mbr() {
  unsigned char * buf = malloc(SECTOR_SIZE);
  memcpy(buf, &mbr, sizeof(mbr));
  write_sector(0, 0, buf);
}

void load_mbr() {
  unsigned char * buf = malloc(SECTOR_SIZE);
  memcpy(buf, &mbr, sizeof(mbr));
  read_sector(0, 0, buf);
  if(mbr.magic != MAGIC) {
    mbr.magic = MAGIC;
    mbr.nvol = 0;
  }
}

int cyl_of_block(int vol, int block) {
  return mbr.vol[vol].fst_cyl + ((mbr.vol[vol].fst_sec + block) / NB_SEC);
}

int sec_of_block(int vol, int block) {
  return (mbr.vol[vol].fst_sec + block) % NB_SEC;
}

void read_block(int vol, int block, unsigned char buf, int size) {
  read_sector_n(cyl_of_block(vol, block), sec_of_block(vol, block), size, &buf);
}
