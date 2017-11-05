#include <stdio.h>
#include <assert.h>
#include "try.h"

static struct ctx_s ctx = {0};

int try (struct ctx_s *ctx, func_t *f, int arg) {
  ctx->magic = MAGIC;
  asm("movl %%esp, %0":"=r"(ctx->esp):);
  asm("movl %%ebp, %0":"=r"(ctx->ebp):);
  return f(arg);
}

int throw (struct ctx_s *ctx, int r) {
  static int a = 0;
  a = r;
  assert(ctx->magic == MAGIC);
  asm("movl %0, %%esp"::"r"(ctx->esp));
  asm("movl %0, %%ebp"::"r"(ctx->ebp));
  return a;
}

int mul(int depth) {
  int i;
  switch (scanf("%d", &i)) {
  case EOF:
    return 1; /* neutral element */
  case 0:
    return mul(depth+1); /* erroneous read */
  case 1:
    if (i)
      return i * mul(depth+1);
    else
      return throw(&ctx, 0);
  }
}

int main(void) {
  int res = try(&ctx, &mul, 0);
  printf("%d\n", res);
  return 0;
}
