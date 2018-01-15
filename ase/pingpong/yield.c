#include <stdio.h>
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#define MAGIC 0xCAFEBABE

typedef int (func_t) (int);
struct ctx_s * current_ctx = NULL;
struct ctx_s * head_ctx = NULL;

enum state_e {
  CTX_RDY,
  CTX_RUNNING,
  CTX_TERMINATED
};

struct ctx_s {
  void * ebp;
  void * esp;
  int magic;
  char * stack;
  func_t * entrypoint;
  char * arg;
  enum state_e state;
  struct ctx_s * next;
  struct ctx_s * prev;
};

int init_ctx(struct ctx_s * ctx, int stack_size, func_t f, void * args) {
  ctx->stack = malloc(sizeof(char) * stack_size);
  ctx->entrypoint = f;
  ctx->arg = args;
  ctx->state = CTX_RDY;
  ctx->magic = MAGIC;
  ctx->esp = ctx->stack + stack_size - sizeof(void *);
  ctx->ebp = ctx->esp;
  return ctx->stack != NULL;
};

int create_ctx(int stack_size, func_t f, void * args) {
  struct ctx_s * ctx = malloc(sizeof(struct ctx_s));
  if(!init_ctx(ctx, stack_size, f, args)) {
    free(ctx);
    return NULL;
  }
  if(current_ctx == NULL) {
    current_ctx = ctx;
    current_ctx->next = ctx;
    current_ctx->prev = ctx;
    head_ctx = current_ctx;
  } else {
    ctx->next = head_ctx;
    current_ctx->next = ctx;
    ctx->prev = current_ctx;
    head_ctx->prev = ctx;
    current_ctx = ctx;
  }
  return ctx;
}

void start_current_ctx() {
  current_ctx->state = CTX_RUNNING;
  current_ctx->entrypoint(current_ctx->arg);
  current_ctx->state = CTX_TERMINATED;
  exit(0);
}

void switch_to_ctx(struct ctx_s * ctx) {
  assert(ctx->magic == MAGIC);
  if(current_ctx != NULL) {
    asm("mov %%esp, %0" : "=r" (current_ctx->esp)::);
    asm("mov %%ebp, %0" : "=r" (current_ctx->ebp)::);
  }
  current_ctx = ctx;
  asm("mov %0, %%esp" :: "r" (current_ctx->esp):);
  asm("mov %0, %%ebp" :: "r" (current_ctx->ebp):);
  if(current_ctx->state == CTX_RDY) {
    start_current_ctx();
    exit(0);
  }
};

void yield() {
  static struct ctx_s * tmp_ctx;
  tmp_ctx = current_ctx;
  if(current_ctx->state == CTX_TERMINATED) {
    current_ctx->prev->next = current_ctx->next;
    current_ctx->next->prev = current_ctx->prev;
  }
  switch_to_ctx(tmp_ctx->next);
}

void doit(void * arg) {
  char * str = arg;
  int i;
  for(i=0; str[i]!='\0'; i++) {
    putchar(str[i]);
    yield();
  }
  current_ctx->state = CTX_TERMINATED;
  yield();
}

int main(int argc, char ** argv) {
  create_ctx(65536, doit, "ABCDEFGH");
  create_ctx(65536, doit, "1234567890");
  create_ctx(65536, doit, "Hello");
  create_ctx(65536, doit, "Bye Bye");
  yield();
  return 0;
}
