#include <stdio.h>

long int * local_stack;

void dump_stack() {
  int local = 0xfacade;
  printf("local_stack = %p - *local_stack = %p\n", local_stack, *local_stack);
  while (*local_stack-- != 0xfacade) {
    printf("local_stack = %p - *local_stack = %p\n", local_stack, *local_stack);
  }
}

void rec(long int depth) {
  long int rec_local = 0xcafebabe;

  if(depth > 10)
    dump_stack();
  else
    rec(depth + 1);
}

int main(void) {
  long int local = 0xdeadbeef;

  local_stack = &local;
  printf("%p : local_base\n", local_stack);
  printf("%p : global_base\n", &local_stack);
  printf("%p : main\n", main);
  printf("%p : rec\n", rec);
  printf("%p : dump_stack\n", dump_stack);
  rec(0);
}
