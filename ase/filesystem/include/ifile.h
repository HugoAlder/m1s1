#define FILE_EOF -1

struct file_desc_s {
  unsigned int pos;
  unsigned int inumber;
  unsigned char buf[SECTOR_SIZE];
  /* Vrai = changements à faire */
  unsigned int dirty;
  unsigned int size;
}

/* Utiliser typedef quand il n'y a pas de raisons de modifier les champs de la structure */
typedef struct file_desc_s file_desc_t;

int open_ifile(file_desc_t * fd, unsigned int number);
void flush_ifile(file_desc_t * fd);
int readc_ifile(file_desc_t * fd);
int writec_ifile(file_desc_t * fd, char c);
/* TODO : Seek relatif */
void seek_ifile(file_desc_t * fd, int r_offset);
void close_ifile(file_desc_t * fd);
