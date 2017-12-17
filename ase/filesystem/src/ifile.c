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

/* Ouvre un fichier. Revient à initialiser un file_desc_s */
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

/* Fermer un fichier */
void close_ifile(file_desc_t *fd) {
  struct inode_s inode;

  /* if the buffer is dirty, flush the file */
  flush_ifile(fd);

  /* update the inode information (size) */
  read_inode(fd->inumber, &inode);
  inode.size = fd->size;
  write_inode(fd->inumber, &inode);
}

/* Force a ecrire ce qu'il y a dans le fichier fd sur le disque */
void flush_ifile(file_desc_t * fd) {
  if(fd->dirty) {
    int fblock = fd->pos / SECTOR_SIZE;
    int vblock = vblock_of_fblock(fd->inumber, fblock, 1);
    write_block(current_vol, vblock, fd->buf);
    fd->dirty = 0;
  }
}

void seek_ifile(file_desc_t *fd, int offset) {
    unsigned int old_pos = fd->pos;
    unsigned int fbloc, vbloc;

    /* update the position */
    fd->pos += offset;

    /* does the seek imply a jump in another bloc? */
    if (bloc_of_pos(fd->pos) != bloc_of_pos(old_pos)) {
	/* flush */
	flush_ifile(fd);

	/* the bloc index of the new buffer */
	fbloc = bloc_of_pos(fd->pos);
	vbloc = vblock_of_fblock(fd->inumber, fbloc, 0);

	if (! vbloc)
	    /* the bloc #0 is full of zeros */
	    memset(fd->buf, 0, SECTOR_SIZE);
	else
	    /* load the bloc */
	    read_block(current_vol, vbloc, fd->buf);
    }
}

void seek2_ifile(file_desc_t *fd, int offset) {
    seek_ifile(fd, offset - fd->pos);
}

/* Lire un octet */
int readc_ifile(file_desc_t * fd) {
  int res;
  if(fd->pos >= fd->size) {
    return FILE_EOF;
  }
  res = fd->buf[fd->pos % SECTOR_SIZE];
  seek_ifile(fd, 1);
  return res;
}

/*------------------------------
  Write a char in a file
  ------------------------------------------------------------*/

/* return the  pos in the file ; -1 in case of error */
int writec_ifile(file_desc_t *fd, char c) {
    unsigned int ibloc;

    /* write the char in the buffer */
    fd->buf[ibloc_of_pos(fd->pos)] = c;

    /* first write in the bloc ? ensure the data bloc allocation */
    if (! fd->dirty) {
        ibloc = vblock_of_fblock(fd->inumber, bloc_of_pos(fd->pos), 1);
        if (! ibloc)
            return 1;
        fd->dirty = 1;
    }

    /* is the buffer full? */
    if (ibloc_of_pos(fd->pos) == SECTOR_SIZE-1) {
	/* write the buffer */
        ibloc = vblock_of_fblock(fd->inumber, bloc_of_pos(fd->pos), 0);
	write_block(current_vol, ibloc, fd->buf);
	/* read the new buffer */
	ibloc = vblock_of_fblock(fd->inumber, bloc_of_pos(fd->pos+1), 0);
	if (! ibloc)
	    memset(fd->buf, 0, SECTOR_SIZE);
	else
	    read_block(current_vol, ibloc, fd->buf);
	fd->dirty = 0;
    }

    /* update the file cursor and size */
    if (fd->size < fd->pos)
	fd->size = fd->pos;
    fd->pos++;

    /* the position of the written char */
    return fd->pos - 1;
}

/*------------------------------
  Read from file
  ------------------------------------------------------------*/
int read_ifile(file_desc_t *fd, void *buf, unsigned int nbyte) {
    unsigned int i;
    int c;

    /* eof? */
    if (fd->pos >= fd->size)
	return FILE_EOF;

    /* read one by one */
    for (i = 0; i < nbyte; i++) {
	if ((c = readc_ifile(fd)) == FILE_EOF) {
	    return i;
	}
	*((char *)buf+i) = c;
    }

    return i;
}

/*------------------------------
  Write to file
  ------------------------------------------------------------*/
int write_ifile(file_desc_t *fd, const void *buf, unsigned int nbyte) {
    int i;

    /* write one by one */
    for (i = 0; i < nbyte; i++) {
	if (writec_ifile(fd, *((char *)buf+i)) == -1)
	    return -1;
    }

    return nbyte;
}
