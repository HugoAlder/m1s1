#include <stdlib.h>
#include <stdio.h>

#include "hardware.h"
#include "sem.h"

#define INIFILENAME "hwconfig.ini"

void sem_init(struct sem_s * sem, unsigned int val) {
    sem->cpt = val;
    sem->head_ctx = NULL;
    sem->tail_ctx = NULL;
}

void sem_down(struct sem_s * sem) {
    int tmp;
    irq_disable();
    sem->cpt--;
    tmp = sem->cpt;
    /* Si sa valeur est négative, le contexte appelant se bloque dans la file d’attente */
    if (tmp < 0) {
        /* Si le sémahpore est vide, il faut indiquer que la head est égale au contexte actuel */
        if (sem->head_ctx == NULL) {
            sem->head_ctx = current_ctx;
        }
        /* La tail est toujours le contexte actuel */
        sem->tail_ctx = current_ctx;
        irq_enable();
        yield();
    }
    irq_enable();
}

void sem_up(struct sem_s * sem) {
    int tmp;
    irq_disable();
    sem->cpt++;
    tmp = sem->cpt;
    /* Si le compteur est négatif ou nul, un contexte est choisi dans la file d’attente et devient actif */
    if(tmp <= 0) {
        if(sem->head_ctx != NULL) {
            struct ctx_s * tmp_ctx = sem->head_ctx;
            /* Actualisation de la tête de liste */
            sem->head_ctx = tmp_ctx->next;
            /* Le contexte actuel devient donc l'ancienne tête de la file d'attente */
            current_ctx = tmp_ctx;
        }
    }
    irq_enable();
    yield();
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
