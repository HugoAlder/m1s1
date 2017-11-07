void init_super(int vol, int serial, char * name);
int load_super(int vol);
void save_super();
int new_block();
void free_block(unsigned int block);
void format_vol(unsigned int vol);
