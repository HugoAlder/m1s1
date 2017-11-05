#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define MAGIC 0xCAFEBABE

typedef int (func_t) (int);

struct ctx_s ctx_ping;
struct ctx_s ctx_pong;

void f_ping(void *arg);
void f_pong(void *arg);

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

struct ctx_s * current_ctx = NULL;

void start_current_ctx() {
  current_ctx->state = CTX_RUNNING;
  current_ctx->entrypoint(current_ctx->arg);
  current_ctx->state = CTX_TERMINATED;
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

int main(int argc, char *argv[])
{
    init_ctx(&ctx_ping, 16384, f_ping, NULL);
    init_ctx(&ctx_pong, 16384, f_pong, NULL);
    switch_to_ctx(&ctx_ping);

    exit(EXIT_SUCCESS);
}

void f_ping(void *args)
{
    while(1) {
        printf("A");
        switch_to_ctx(&ctx_pong);
        printf("B");
        switch_to_ctx(&ctx_pong);
        printf("C");
        switch_to_ctx(&ctx_pong);
    }
}

void f_pong(void *args)
{
    while(1) {
        printf("1");
        switch_to_ctx(&ctx_ping);
        printf("2");
        switch_to_ctx(&ctx_ping);
    }
};
