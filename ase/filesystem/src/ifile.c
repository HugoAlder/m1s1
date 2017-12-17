#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#include "mbr.h"
#include "drive.h"
#include "inode.h"
#include "ifile.h"
#include "vol.h"

/* the file bloc number of a given character position in a file */
#define bloc_of_pos(pos) ((pos) / SECTOR_SIZE)
/* the index in a bloc of given character position in a file */
#define ibloc_of_pos(pos) ((pos) % SECTOR_SIZE)

unsigned int create_ifile(enum file_type_e type) {
    unsigned int inumber;

    inumber = create_inode(type);
    if(inumber == BLOCK_NULL) {
      fprintf(stderr, "Unable to create inode\n");
    }

    return inumber;
}

int delete_ifile(unsigned int inumber) {
    int status;

    status = delete_inode(inumber);
    if(status == BLOCK_NULL) {
      fprintf(stderr, "Unable to delete inode\n");
    }

    return status;
}

int open_ifile(file_desc_t * fd, unsigned int inumber) {
  struct inode_s inode;
  read_inode(inumber, &inode);
  fd->inumber = inumber;
  fd->size = inode.size;
  fd->pos = 0;
  fd->dirty = 0;
  read_block(current_vol, vblock_of_fblock(inumber, 0, 0), fd->buf);
  return 0;
}

void close_ifile(file_desc_t *fd) {
  struct inode_s inode;

  flush_ifile(fd);

  read_inode(fd->inumber, &inode);
  inode.size = fd->size;
  write_inode(fd->inumber, &inode);
}

void flush_ifile(file_desc_t * fd) {
  if(fd->dirty) {
    int fblock = fd->pos / SECTOR_SIZE;
    int vblock = vblock_of_fblock(fd->inumber, fblock, 1);
    write_block(current_vol, vblock, fd->buf);
    fd->dirty = 0;
  }
}

int readc_ifile(file_desc_t * fd) {
  int res;
  if(fd->pos >= fd->size) {
    return FILE_EOF;
  }
  res = fd->buf[fd->pos % SECTOR_SIZE];
  seek_ifile(fd, 1);
  return res;
}

int writec_ifile(file_desc_t *fd, char c) {
  fd->buf[fd->pos % SECTOR_SIZE] = c;

  if (!fd->dirty) {
    fd->dirty = 1;
  }

  if (fd->size < fd->pos) {
      fd->size = fd->pos;
  }

  seek_ifile(fd, 1);
  return fd->pos - 1;
}

void seek_ifile(file_desc_t *fd, int offset) {
  unsigned int old_pos = fd->pos;
  unsigned int fblock, vblock;

  /* update the position */
  fd->pos += offset;

  /* does the seek imply a jump in another bloc? */
  if (bloc_of_pos(fd->pos) != bloc_of_pos(old_pos)) {
  	/* flush */
  	flush_ifile(fd);

  	/* the bloc index of the new buffer */
  	fblock = bloc_of_pos(fd->pos);
  	vblock = vblock_of_fblock(fd->inumber, fblock, 0);

  	if (!vblock) {
	    /* the bloc #0 is full of zeros */
	    memset(fd->buf, 0, SECTOR_SIZE);
    } else {
	    /* load the bloc */
	    read_block(current_vol, vblock, fd->buf);
    }
  }
}
