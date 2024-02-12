#include <stdio.h>
#include <stdlib.h>

#include "fifo.h"

size_t fifo_size(struct fifo *fifo)
{
    return fifo->size;
}

void fifo_push(struct fifo *fifo, int elt)
{
    struct list *list = malloc(sizeof(struct list));
    if (!list)
    {
        return;
    }

    list->data = elt;

    if (!fifo->head)
    {
        list->next = NULL;
        fifo->tail = list;
        fifo->head = list;
        fifo->size = 1;
        return;
    }

    list->next = NULL;
    fifo->tail->next = list;
    fifo->size++;
}

int fifo_head(struct fifo *fifo)
{
    return fifo->head->data;
}

void fifo_pop(struct fifo *fifo)
{
    if (!fifo->head)
    {
        return;
    }

    if (!fifo->head->next)
    {
        struct list *tmp = fifo->head;
        fifo->head = NULL;
        fifo->tail = NULL;
        fifo->size--;
        free(tmp);
        return;
    }

    struct list *tmp = fifo->head;
    fifo->head = tmp->next;
    fifo->size--;
    free(tmp);
}

void fifo_print(const struct fifo *fifo)
{
    struct list *tmp = fifo->head;
    while (tmp)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}
