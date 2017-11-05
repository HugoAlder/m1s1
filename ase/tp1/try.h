#define MAGIC 0xdeadbeef

typedef int (func_t)(int);

struct ctx_s {
  void * esp;
  void * ebp;
  int magic;
};

int try (struct ctx_s *ctx, func_t *f, int arg);
int throw (struct ctx_s *ctx, int r);

