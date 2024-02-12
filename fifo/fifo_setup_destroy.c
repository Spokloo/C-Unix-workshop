#include <stdlib.h>

#include "fifo.h"

struct fifo *fifo_init(void)
{
    struct fifo *fifo = malloc(sizeof(struct fifo));
    if (!fifo)
    {
        return NULL;
    }

    fifo->head = NULL;
    fifo->tail = NULL;
    fifo->size = 0;

    return fifo;
}

void fifo_clear(struct fifo *fifo)
{
    struct list *tmp = fifo->head;

    while (tmp)
    {
        struct list *tmp2 = tmp;
        tmp = tmp->next;
        free(tmp2);
    }

    fifo->head = NULL;
    fifo->tail = NULL;
    fifo->size = 0;
}

void fifo_destroy(struct fifo *fifo)
{
    fifo_clear(fifo);
    free(fifo);
}
