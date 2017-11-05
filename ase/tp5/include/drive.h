void read_sector(unsigned int cylinder, unsigned int sector, unsigned char * buffer);
void write_sector(unsigned int cylinder, unsigned int sector, unsigned char * buffer);
void format_sector(unsigned int cylinder, unsigned int sector, unsigned int nsector, int value);
