#include <assert.h>

#include "mbr.h"
#include "inode.h"

void read_inode(unsigned int inumber, struct inode_s * inode) {
  assert(superblock.magic == MAGIC_SB);
  read_block_n(current_vol, inumber, (unsigned char *) inode, sizeof(struct inode_s));
  assert(inode->magic == MAGIC_INODE);
}

void write_inode(unsigned int inumber, struct inode_s * inode) {
  assert(superblock.magic == MAGIC_SB);
  write_block_n(current_vol, inumber, (unsigned char *) inode, sizeof(struct inode_s));
  assert(inode->magic == MAGIC_INODE);
}

unsigned int create_inode(enum file_type_e type) {
  int i, inumber;
  struct inode_s inode;

  inode.magic = MAGIC_INODE;
  inode.type = type;
  inode.size = 0;
  inode.indirect = BLOCK_NULL;
  inode.indirect2 = BLOCK_NULL;

  for(i = 0; i < NB_INDIRECT; i++) {
    inode.direct[i] = BLOCK_NULL;
  }

  inumber = new_block();
  if(!inumber) {
    return BLOCK_NULL;
  }

  write_inode(inumber, &inode);
  return inumber;
}

int delete_inode(unsigned int inumber) {
  int i;
  struct inode_s inode;

  read_inode(inumber, &inode);

  for(i = 0; i < NB_INDIRECT; i++) {
    if(inode.direct[i] != BLOCK_NULL) {
      free_block(inode.direct[i]);
    }
  }

  free_indirect(inode.indirect);

  /* TO DO */
  return 0;
}

void free_indirect(unsigned int indirect) {
  int i;
  unsigned int t[NB_DIRECT];

  if(indirect == BLOCK_NULL) {
    return;
  }
  read_block_n(current_vol, NB_INDIRECT, (unsigned char *) t, sizeof(int));

  for(i = 0; i < NB_INDIRECT; i++) {
    if(t[i] != BLOCK_NULL) {
      free_block(t[i]);
    }
  }
  free_block(indirect);
}

unsigned int vlobck_of_fblock(unsigned int inumber, unsigned int fblock) {
  struct inode_s inode;
  unsigned int t[NB_INDIRECT];
  int index1, index2;

  read_inode(inumber, &inode);
  if (fblock < NB_DIRECT) {
    return inode.direct[fblock];
  }

  fblock -= NB_INDIRECT;

  if (fblock < NB_INDIRECT) {
    if (inode.indirect == BLOCK_NULL) {
      return BLOCK_NULL;
    }
    read_block(current_vol, inode.indirect, (unsigned char *) t);
    return t[fblock];
  }

  fblock -= NB_INDIRECT;

  if (!inode.indirect2) {
    return BLOCK_NULL;
  }

  index2 = fblock / NB_INDIRECT;
  index1 = fblock % NB_INDIRECT;
  read_block(current_vol, inode.indirect2, (unsigned char *) t);

  if (!t[index2]) {
    return BLOCK_NULL;
  }

  read_block(current_vol, t[index2], (unsigned char *) t);

  if (!t[index1]) {
    return BLOCK_NULL;
  }

  return t[index1];
}
