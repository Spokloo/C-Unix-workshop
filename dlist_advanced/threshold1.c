#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

struct dlist *dlist_init(void)
{
    struct dlist *list = malloc(sizeof(struct dlist));
    if (!list)
    {
        return NULL;
    }

    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

int dlist_push_front(struct dlist *list, int element)
{
    if (element < 0)
    {
        return 0;
    }

    struct dlist_item *elm = malloc(sizeof(struct dlist_item));
    if (!elm)
    {
        return 0;
    }

    elm->data = element;
    elm->prev = NULL;

    if (list->size == 0)
    {
        elm->next = NULL;

        list->size = 1;
        list->head = elm;
        list->tail = elm;
        return 1;
    }

    elm->next = list->head;
    list->head = elm;
    list->head->next->prev = elm;
    list->size++;

    return 1;
}

void dlist_print(const struct dlist *list)
{
    struct dlist_item *tmp = list->head;

    while (tmp)
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}

int dlist_push_back(struct dlist *list, int element)
{
    if (element < 0)
    {
        return 0;
    }

    struct dlist_item *elm = malloc(sizeof(struct dlist_item));
    if (!elm)
    {
        return 0;
    }

    elm->data = element;
    elm->next = NULL;

    if (list->size == 0)
    {
        elm->prev = NULL;

        list->size = 1;
        list->head = elm;
        list->tail = elm;
        return 1;
    }

    elm->prev = list->tail;
    list->tail = elm;
    list->tail->prev->next = elm;
    list->size++;

    return 1;
}

size_t dlist_size(const struct dlist *list)
{
    return list->size;
}
