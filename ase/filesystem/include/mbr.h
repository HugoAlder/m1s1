#define MAX_VOL    8
#define MAGIC_MBR  0x112233
#define MAGIC_SB   0x314159
#define BLOCK_NULL 0

enum vol_type { BASE, ANNEXE, OTHER };

struct volume_s {
  int fst_cyl, fst_sec, nblock;
  enum vol_type type;
};

struct mbr_s {
  int nvol, magic;
  struct volume_s vol[MAX_VOL];
};

struct superblock_s {
  int serial, magic, nblocks, nfreeblocks, fst_freeblock;
  char name[32];
};

struct freeblock_s {
  unsigned int next;
};

int current_vol;
struct mbr_s mbr;
struct superblock_s superblock;

void save_mbr();
void load_mbr();
void read_block(unsigned int vol, unsigned int nblock, unsigned char * buffer);
void write_block(unsigned int vol, unsigned int nblock, unsigned char * buffer);
void read_block_n(int vol, int block, unsigned char * buf, int size);
void write_block_n(int vol, int block, unsigned char * buf, int size);
int sec_of_block(int vol, int block);
int cyl_of_block(int vol, int block);
