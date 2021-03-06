#include "ctx.h"

struct sem_s {
  unsigned int cpt;
  struct ctx_s * head_ctx;
  struct ctx_s * tail_ctx;
};

void sem_init(struct sem_s * sem, unsigned int val);
void sem_down(struct sem_s * sem);
void sem_up(struct sem_s * sem);
void start_scheduler();
