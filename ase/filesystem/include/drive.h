void read_sector(unsigned int cylinder, unsigned int sector, unsigned char * buffer);
void read_sector_n(unsigned int cyl, unsigned int sec, unsigned int n, unsigned char * buffer);
void write_sector(unsigned int cylinder, unsigned int sector, unsigned char * buffer);
void write_sector_n(unsigned int cyl, unsigned int sec, unsigned int n, unsigned char * buffer);
void format_sector(unsigned int cylinder, unsigned int sector, unsigned int nsector, int value);
