#include <stdlib.h>
#include <stdio.h>

#include "hardware.h"
#include "sem.h"

#define INIFILENAME "hwconfig.ini"

void sem_init(struct sem_s * sem, unsigned int val) {
  sem->cpt = val;
  sem->wctx = NULL;
}

void sem_down(struct sem_s * sem) {
  irq_disable();
    sem->cpt--;
    if (sem->cpt < 0) {
        current_ctx->state = CTX_TERMINATED;
        current_ctx->next = sem->wctx;
        sem->wctx = current_ctx;
        _mask(1);
        yield();
    }
    irq_enable();
}

void sem_up(struct sem_s * sem) {
  irq_disable();
  sem->cpt++;
  if(sem->cpt <= 0) {
    if(sem->wctx != NULL) {
      struct ctx_s * ctx = sem->wctx;
      sem->wctx = ctx->next;
      ctx->next = current_ctx->next;
      current_ctx->next = ctx;
    }
  }
  irq_enable();
}

void empty_it(void) {
    return;
}

void start_scheduler() {
  if (init_hardware(INIFILENAME) == 0) {
	   fprintf(stderr, "Error in hardware initialization\n");
	   exit(EXIT_FAILURE);
  }
  int i;
  for (i = 0; i < 16; ++i)
      IRQVECTOR[i] = empty_it;

  IRQVECTOR[TIMER_IRQ] = yield;
  _out(TIMER_PARAM, 128 + 64 + 32 + 8);
  _out(TIMER_ALARM, 0xFFFFFFFE);

  irq_enable();

  for (i = 0; i < (1 << 28); ++i);

}
