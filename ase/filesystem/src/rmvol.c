#include <stdio.h>
#include <stdlib.h>

#include "drive.h"
#include "mbr.h"
#include "hardware.h"
#include "hconf.h"
#include "vol.h"

void usage() {
  printf("rmvol <vol>\n");
}

int main(int argc, char **argv) {

  if (argc != 2) {
    usage();
    exit(EXIT_FAILURE);
  }

  format_vol((unsigned int) argv[1]);


  return 0;
}
