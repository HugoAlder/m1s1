#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "sem.h"

static int obj;
struct sem_s mutex;

void test1(void) {
    printf("This is test1\n");
}

void test2(void) {
    printf("This is test2\n");
}

void cons1(void * args) {
    test1();
    sem_down(&mutex);
    printf(">> cpt1.1 %d\n", mutex.cpt);
    sem_up(&mutex);
    printf(">> cpt1.2 %d\n", mutex.cpt);
}

void cons2(void * args) {
    test2();
    sem_down(&mutex);
    printf(">> cpt2.1 %d\n", mutex.cpt);
    sem_up(&mutex);
    printf(">> cpt2.2 %d\n", mutex.cpt);
}

int main(int argc, char *argv[]) {
    sem_init(&mutex, 0);
    create_ctx(16384, cons1, NULL);
    create_ctx(16384, cons2, NULL);
    start_scheduler();
    return 0;
}
