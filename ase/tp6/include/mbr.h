#define MAX_VOL 8
#define MAGIC 0x112233

enum vol_type { BASE, ANNEXE, OTHER };

struct volume_s {
  int fst_cyl, fst_sec, nblock;
  enum vol_type type;
};

struct mbr_s {
  int nvol, magic;
  struct volume_s vol[MAX_VOL];
};

static struct mbr_s mbr;

void save_mbr();
void load_mbr();
void read_block(int vol, int block, unsigned char nb, int size);
int sec_of_block(int vol, int block);
int cyl_of_block(int vol, int block);
