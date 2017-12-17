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
  int i;
  unsigned int inumber;
  struct inode_s inode;

  inode.magic = MAGIC_INODE;
  inode.type = type;
  inode.size = 0;
  inode.indirect = BLOCK_NULL;
  inode.indirect2 = BLOCK_NULL;
  for (i = 0; i < NB_DIRECT; i++) {
    inode.direct[i] = BLOCK_NULL;
  }

  inumber = new_block();
  if (!inumber) {
    return BLOCK_NULL;
  }
  write_inode(inumber, &inode);
  return inumber;
}

int delete_inode(unsigned int inumber) {
  struct inode_s inode;
  unsigned int t[NB_INDIRECT];
  int i;

  read_inode(inumber, &inode);

  for (i = 0; i < NB_DIRECT; i++) {
    if (inode.direct[i] != BLOCK_NULL) {
      free_block(inode.direct[i]);
    }
  }

  free_indirect(inode.indirect);

  if (inode.indirect2) {
    read_block_n(current_vol, inode.indirect2, (unsigned char*) &t, sizeof(t));
    for (i = 0; i < NB_INDIRECT; i++) {
      free_indirect(t[i]);
    }
    free_block(inode.indirect2);
  }
  free_block(inumber);

  return inumber;
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

unsigned int vblock_of_fblock(unsigned int inumber, unsigned int fbloc, int do_allocate) {
    struct inode_s inode;
    unsigned int t[NB_INDIRECT];
    int index2, index1;

    read_inode(inumber, &inode);
    if (fbloc < NB_DIRECT) {
        if (do_allocate && inode.direct[fbloc] == BLOCK_NULL) {
            inode.direct[fbloc] = new_block();
            format_block(current_vol, inode.direct[fbloc]);
            write_inode(inumber, &inode);
        }

        return inode.direct[fbloc];
    }

    fbloc -= NB_DIRECT;
    if (fbloc < NB_INDIRECT) {
        /* TODO: do_allocate */
        if (inode.indirect == BLOCK_NULL) return BLOCK_NULL;
        read_block(current_vol, inode.indirect, (unsigned char *) t);
        /* TODO: do_allocate */
        return t[fbloc];
    }

    fbloc -= NB_INDIRECT;

    /* TODO: do_allocate in indirect2 */

    if (!inode.indirect2) return BLOCK_NULL;

    index2 = fbloc / NB_INDIRECT;
    index1 = fbloc % NB_INDIRECT;
    read_block(current_vol, inode.indirect2, (unsigned char *) t);
    if (!t[index2]) return BLOCK_NULL;
    read_block(current_vol, t[index2], (unsigned char *) t);
    if (!t[index1]) return BLOCK_NULL;
    return t[index1];
}
