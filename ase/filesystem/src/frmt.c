#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "hconf.h"
#include "hardware.h"
#include "drive.h"

void empty_it(void) {
  return;
}

void frmt() {
  int cyl;
  for(cyl = 0; cyl < NB_CYL; cyl++) {
    format_sector(cyl, 0, NB_SEC, 0xAFAFAFAF);
  }
}

void reverse_frmt() {
  int cyl = NB_CYL - 1;
  int sec = NB_SEC - 1;
  for(; cyl >= 0; cyl--) {
    for(; sec >= 0; sec--) {
    	format_sector(cyl, sec, 1, 0xAFAFAFAF);
    }
  }
}

void usage(void) {
  printf("frmt [-r]\n");
}

int main(int argc, char **argv) {

  int i;

  if (argc != 1 && argc != 2) {
    usage();
    exit(EXIT_FAILURE);
  }

  if (argc == 2 && strcmp(argv[1], "-r") != 0) {
    usage();
    exit(EXIT_FAILURE);
  }

  if(init_hardware(HARDWARE_INI) == 0) {
    fprintf(stderr, "Error in hardware initialization\n");
    exit(EXIT_FAILURE);
  }

  for(i = 0; i < 16; i++) {
    IRQVECTOR[i] = empty_it;
  }

  if(argc == 2) {
    reverse_frmt();
  } else {
    frmt();
  }

  return 0;
}
