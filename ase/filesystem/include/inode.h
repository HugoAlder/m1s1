#include "hconf.h"

#define NB_DIRECT ((SECTOR_SIZE - sizeof(int) * 4 - sizeof(enum file_type_e)) / sizeof(int))
#define NB_INDIRECT (SECTOR_SIZE / sizeof(int))
#define MAGIC_INODE 0x12345678

enum file_type_e { FILE_FILE, FILE_DIRECTORY };

struct inode_s {
  int size, magic;
  enum file_type_e type;
  unsigned int direct[NB_DIRECT];
  unsigned int indirect, indirect2;
};

void read_inode(unsigned int inumber, struct inode_s * inode);
void write_inode(unsigned int inumber, struct inode_s * inode);
unsigned int create_inode(enum file_type_e type);
int delete_inode(unsigned int inumber);
void free_indirect(unsigned int indirect);
unsigned int vblock_of_fblock(unsigned int inumber, unsigned int fblock, int do_allocate);
