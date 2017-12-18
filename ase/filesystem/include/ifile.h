#include "hconf.h"

#define FILE_EOF -1

struct file_desc_s {
  unsigned int pos;
  unsigned int inumber;
  unsigned char buf[SECTOR_SIZE];
  /* Vrai = changements à faire */
  unsigned int dirty;
  unsigned int size;
};

typedef struct file_desc_s file_desc_t;

unsigned int create_ifile(enum file_type_e type);
int delete_ifile(unsigned int inumber);

int open_ifile(file_desc_t *fd, unsigned int inumber);
void close_ifile(file_desc_t *fd);

void flush_ifile(file_desc_t *fd);

void seek_ifile(file_desc_t *fd, int r_offset);
void seek2_ifile(file_desc_t *fd, int a_offset);

int readc_ifile(file_desc_t *fd);
int writec_ifile(file_desc_t *fd, char c);
int read_ifile(file_desc_t *fd, void *buf, unsigned int nbyte);
int write_ifile(file_desc_t *fd, const void *buf, unsigned int nbyte);
