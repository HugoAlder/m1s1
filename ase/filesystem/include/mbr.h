#include "vol.h"

#define MAX_VOL    8
#define MAGIC_MBR  0x112233

struct mbr_s {
  int nvol, magic;
  struct volume_s vol[MAX_VOL];
};

struct mbr_s mbr;

void save_mbr();
void load_mbr();
void read_block(unsigned int vol, unsigned int nblock, unsigned char * buffer);
void write_block(unsigned int vol, unsigned int nblock, unsigned char * buffer);
void read_block_n(int vol, int block, unsigned char * buf, int size);
void write_block_n(int vol, int block, unsigned char * buf, int size);
int sec_of_block(int vol, int block);
int cyl_of_block(int vol, int block);
