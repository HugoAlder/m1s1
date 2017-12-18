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

static void cfile(unsigned int sinumber) {
  unsigned int inumber;
  file_desc_t sfd, dfd;
  int status;
  int c;

  inumber = create_ifile(FILE_FILE);
  if(!inumber) {
    fprintf(stderr, "Unable to create file\n");
    exit(0);
  }

  printf("Copy file %d into file %d\n", sinumber, inumber);

  status = open_ifile(&dfd, inumber);
  if(status) {
    fprintf(stderr, "Unable to open file %d\n", inumber);
    exit(EXIT_FAILURE);
  }

  status = open_ifile(&sfd, sinumber);
  if(status) {
    fprintf(stderr, "Unable to open source file %d\n", sinumber);
    exit(0);
  }

  while ((c = readc_ifile(&sfd)) != -1) {
    writec_ifile(&dfd, c);
  }

  close_ifile(&dfd);
  close_ifile(&sfd);
}

static void usage(const char *prgm) {
    fprintf(stderr, "[%s] usage:\n\t"
            "%s inumber\n", prgm, prgm);
    exit(0);
}

int main (int argc, char *argv[]) {
  int i, vol;
  unsigned int inumber;

  if (argc == 2) {
    vol = 0;
    inumber = atoi(argv[1]);
  } else if (argc == 3) {
    vol = atoi(argv[1]);
    inumber = atoi(argv[2]);
  } else
      usage(argv[0]);

  if (init_hardware(HARDWARE_INI) == 0) {
    fprintf(stderr, "Error in hardware initialization\n");
    exit(0);
  }

  for(i = 0; i < 16; i++) {
    IRQVECTOR[i] = empty_it;
  }

  load_mbr();
  load_super(vol);
  cfile(inumber);
  save_super();

  exit(1);
}
