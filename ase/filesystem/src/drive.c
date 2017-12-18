#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "drive.h"
#include "hardware.h"
#include "hconf.h"

void read_sector(unsigned int cyl, unsigned int sec, unsigned char * buffer) {
  int i;

  assert(cyl <= NB_CYL);
  assert(sec <= NB_SEC);

  _out(0x110, (cyl >> 8) & 0xFF);
  _out(0x111, cyl & 0xFF);
  _out(0x112, (sec >> 8) & 0xFF);
  _out(0x113, sec  & 0xFF);
  _out(HDA_CMDREG, 2);
  _sleep(14);

  _out(0x110, 0);
  _out(0x111, 1);
  _out(HDA_CMDREG, 4);
  _sleep(14);

  for (i = 0; i < SECTOR_SIZE; i++) {
    buffer[i] = MASTERBUFFER[i];
  }
}

void read_sector_n(unsigned int cyl, unsigned int sec, unsigned char * buffer, unsigned int n) {
  int i;

  assert(cyl <= NB_CYL);
  assert(sec <= NB_SEC);
  assert(n <= SECTOR_SIZE);

  _out(0x110, (cyl >> 8) & 0xFF);
  _out(0x111, cyl & 0xFF);
  _out(0x112, (sec >> 8) & 0xFF);
  _out(0x113, sec  & 0xFF);
  _out(HDA_CMDREG, 2);
  _sleep(14);

  _out(0x110, 0);
  _out(0x111, 1);
  _out(HDA_CMDREG, 4);
  _sleep(14);

  for (i = 0; i < n; i++) {
    buffer[i] = MASTERBUFFER[i];
  }
}

void write_sector(unsigned int cyl, unsigned int sec, unsigned char * buffer) {

  assert(cyl <= NB_CYL);
  assert(sec <= NB_SEC);

  _out(0x110, (cyl >> 8) & 0xFF);
  _out(0x111, cyl & 0xFF);
  _out(0x112, (sec >> 8) & 0xFF);
  _out(0x113, sec  & 0xFF);
  _out(HDA_CMDREG, 2);
  _sleep(14);

  _out(0x110, 0);
  _out(0x111, 1);

  memcpy(MASTERBUFFER, buffer, SECTOR_SIZE);

  _out(HDA_CMDREG, 6);
  _sleep(14);
}

void write_sector_n(unsigned int cyl, unsigned int sec, unsigned char * buffer, unsigned int n) {
  int i;

  assert(cyl <= NB_CYL);
  assert(sec <= NB_SEC);
  assert(n <= SECTOR_SIZE);

  _out(0x110, (cyl >> 8) & 0xFF);
  _out(0x111, cyl & 0xFF);
  _out(0x112, (sec >> 8) & 0xFF);
  _out(0x113, sec  & 0xFF);
  _out(HDA_CMDREG, 2);
  _sleep(14);

  _out(0x110, 0);
  _out(0x111, 1);

  for (i = 0; i < n; i++) {
    MASTERBUFFER[i] = buffer[i];
  }

  _out(HDA_CMDREG, 6);
  _sleep(14);
}

void format_sector(unsigned int cyl, unsigned int sec, unsigned int nsec, int value) {

  assert(cyl <= NB_CYL);
  assert(sec <= NB_SEC);
  assert(nsec <= SECTOR_SIZE);

  for(; sec < nsec; sec++) {
    _out(0x110, (cyl >> 8) & 0xFF);
    _out(0x111, cyl & 0xFF);
    _out(0x112, (sec >> 8) & 0xFF);
    _out(0x113, sec  & 0xFF);
    _out(HDA_CMDREG, 2);
    _sleep(14);

    _out(0x110, 0);
    _out(0x111, 1);
    _out(0x112, (value >> 24) & 0xFF);
    _out(0x113, (value >> 16) & 0xFF);
    _out(0x114, (value >> 8) & 0xFF);
    _out(0x115, value & 0xFF);
    _out(HDA_CMDREG, 8);
    _sleep(14);
  }
}
