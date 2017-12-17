struct vm_mapping_s {
  unsigned int is_mapped : 1;
  unsigned int ppage : 8;
};

struct pm_mapping_s {
  unsigned int is_mapped : 1;
  unsigned int vpage : 12;
};

int init_swap(void);
int store_to_swap(int vpage, int ppage);
int fetch_from_swap(int vpage, int ppage);
