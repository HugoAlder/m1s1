static int current_process;

struct entry_s {
  unsigned int RFU : 8;
  unsigned int vpage : 12;
  unsigned int ppage : 8;
  unsigned int access_x : 1;
  unsigned int access_w : 1;
  unsigned int access_r : 1;
  unsigned int active : 1;
};

int ppage_of_vpage(int process, int vpage);
