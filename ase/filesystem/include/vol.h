#ifndef VOL_H
#define VOL_H

#define MAGIC_SB   0x445566
#define BLOCK_NULL 0

enum vol_type { BASE, ANNEXE, OTHER };

struct volume_s {
  int fst_cyl, fst_sec, nblock;
  enum vol_type type;
};

struct superblock_s {
  int serial, magic, nblocks, nfreeblocks, fst_freeblock;
  char name[32];
};

struct freeblock_s {
  unsigned int next;
};

int current_vol;
struct superblock_s superblock;

int load_super(int vol);
void init_super(int vol, int serial, char * name);
void save_super();
int new_block();
void free_block(unsigned int block);
void format_block(unsigned int vol, unsigned int nblock);

#endif
