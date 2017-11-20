#include "fd.h"
#include "mbr.h"

/* Ouvre un fichier. Revient à initialiser un file_desc_s */
open_ifile(file_desc_t * fd, unsigned int number) {
  struct inodes_s inode;
  read_inode(inumber, &inode);
  fd->inumber = inum;
  fd->size = inode->size;
  fd->pos = 0;
  fd->dirty = 0;
  read_block(current_vol, vblock_of_fblock(inum, 0, 1), fd->buf);
}

/* Force a ecrire ce qu'il y a dans le fichier fd sur le disque */
void flush_ifile(file_desc_t * fd) {
  if(fd->dirty) {
    int block = fd->pos / SECTOR_SIZE;
    int vblock = vblock_of_fblock(fd->inumber, fblock, 1);
    write_block(current_vol, vblock, fd->buf);
    fd->dirty = 0;
  }
}

/* Lire un octet */
int readc_ifile(file_desc_t * fd) {
  int res;
  if(fd->pos >= fd->size) {
    return FILE_EOF;
  }
  res = fd->buf[pos % SECTOR_SIZE];
  seek_ifile(fd, 1);
  return res;
}

/* Ecrire un octet */
int writec_ifile(file_desc_t * fd, char c) {
  fd->buf[pos % SECTOR_SIZE] = c;
  seek_ifile(fd, 1);
}

/* Fermer un fichier */
void close_ifile(file_desc_t * fd) {
  flush_ifile(fd);
}
