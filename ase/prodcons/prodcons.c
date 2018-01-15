#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "sem.h"

static int obj;
struct sem_s mutex, empty, full;

void rmv_obj(void) {
  printf("Removing object\n");
  obj--;
}

void put_obj(void) {
  printf("Putting object\n");
  obj++;
}

void prod(void * args) {
  while (1) {
    sem_down(&empty);
    sem_down(&mutex);
    put_obj();
    sem_up(&mutex);
    sem_up(&full);
  }
}

void cons(void * args) {
  while (1) {
    sem_down(&full);
    sem_down(&mutex);
    rmv_obj();
    sem_up(&mutex);
    sem_up(&empty);
  }
}

int main(int argc, char *argv[]) {
  sem_init(&mutex, 1);
  sem_init(&empty, 10);
  sem_init(&full, 0);
  create_ctx(16384, prod, NULL);
  create_ctx(16384, cons, NULL);
  start_scheduler();
  return 0;
}
