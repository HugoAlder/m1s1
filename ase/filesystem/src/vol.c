#include "vol.h"
#include "mbr.h"
#include "drive.h"

void read_block(unsigned int vol, unsigned int nblock, unsigned char * buffer) {
  unsigned int cyl = cyl_of_block(int vol, int nblock);
  signed int sec = mbr.vol[vol].fst_sec;
  read_sector_n(cyl, sec, nblock, buffer);
}

void write_block(unsigned int vol, unsigned int nblock, const unsigned char * buffer) {
  unsigned int cyl = cyl_of_block(int vol, int nblock);
  signed int sec = mbr.vol[vol].fst_sec;
  write_sector_n(cyl, sec, nblock, buffer);
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
