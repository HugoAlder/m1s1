#include "vol.h"
#include "mbr.h"
#include "drive.h"

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
  save_super();
  return res;
}

void free_block(unsigned int block) {
  return;
}

void format_vol(unsigned int vol) {
  int i, j;
  unsigned int cyl = cyl_of_block(int vol, int nblock);
  signed int sec = mbr.vol[vol].fst_sec;
  unsigned int lim = mbr.vol[vol].nblock;
  if(sec + nblock < NB_SEC) {
    format_sector(cyl, sec, sec + nblock, 0);
  } else {
    // First sectors of the first cylinder
    int i = NB_SEC - sec;
    format_sector(cyl, sec, i, 0);

    // Removing the previous sectors already formated
    lim = lim - i;

    // Number of cylinders
    int ncyl = lim / NB_SEC;
    for(j = cyl + 1; j < ncyl; j++) {
      // Sectors of the cylinders
      format_sector(j, 0, NB_SEC, 0);
    }

    // Last sectors of the last cylinder of the volume
    int more = lim % NB_SEC;
      format_sector(j + 1, 0, more, 0);
  }
}
