#include <stdio.h>
#include <stdlib.h>

#include "inode.h"
#include "hardware.h"
#include "hconf.h"
#include "ifile.h"
#include "vol.h"
#include "mbr.h"

void empty_it(void){
  return;
}

void pfile(unsigned int inumber) {
  file_desc_t fd;
  int status;
  int c;

  status = open_ifile(&fd, inumber);
  if (status) {
    fprintf(stderr, "Unable to open file %d\n", inumber);
    exit(1);
  }

  while((c = readc_ifile(&fd)) != -1) {
    putchar(c);
  }

  close_ifile(&fd);
}

void usage(const char *prgm) {
  fprintf(stderr, "[%s] usage:\n\t"
          "%s [vol] inumber\n", prgm, prgm);
  exit(1);
}

int main(int argc, char **argv) {
  int i, vol;
  unsigned int inumber;

  if (argc == 2) {
    vol = 0;
    inumber = atoi(argv[1]);
  } else if (argc == 3) {
    vol = atoi(argv[1]);
    inumber = atoi(argv[2]);
  } else {
    usage(argv[0]);
  }

  if (init_hardware(HARDWARE_INI) == 0) {
      fprintf(stderr, "Error in hardware initialization\n");
      exit(1);
  }

  for (i = 0; i < 16; i++) {
    IRQVECTOR[i] = empty_it;
  }

  load_mbr();
  load_super(vol);
  pfile(inumber);
  save_mbr();

  exit(0);
}
