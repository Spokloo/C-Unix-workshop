#include <stdlib.h>

#include "dlist.h"

void dlist_shift(struct dlist *list, int offset)
{
    if (list->size == 0)
    {
        return;
    }

    list->head->prev = list->tail;
    list->tail->next = list->head;

    while (offset < 0)
    {
        offset += list->size;
    }
    offset %= list->size;

    int i = 0;

    struct dlist_item *tmp = list->head;
    while (i != offset)
    {
        i++;
        tmp = tmp->prev;
    }

    list->head = tmp;
    list->tail = tmp->prev;
    list->head->prev = NULL;
    list->tail->next = NULL;
}

int dlist_add_sort(struct dlist *list, int element)
{
    if (element < 0)
    {
        return -1;
    }

    if (list->size == 0)
    {
        return !dlist_push_front(list, element) ? -1 : 1;
    }

    size_t i = 0;
    struct dlist_item *tmp = list->head;
    while (tmp && tmp->data < element)
    {
        i++;
        tmp = tmp->next;
    }

    return dlist_insert_at(list, element, i);
}

int dlist_remove_eq(struct dlist *list, int element)
{
    int i = dlist_find(list, element);
    if (i == -1)
    {
        return 0;
    }

    return dlist_remove_at(list, i) == -1 ? 0 : 1;
}

struct dlist *dlist_copy(const struct dlist *list)
{
    struct dlist *copy = malloc(sizeof(struct dlist));
    if (!copy)
    {
        return NULL;
    }

    copy->size = list->size;
    if (list->size == 0)
    {
        copy->head = NULL;
        copy->tail = NULL;
        return copy;
    }

    struct dlist_item *copy_head = malloc(sizeof(struct dlist_item));
    if (!copy_head)
    {
        return NULL;
    }

    copy_head->data = list->head->data;
    copy_head->prev = NULL;
    copy->head = copy_head;

    struct dlist_item *tmp = list->head->next;
    struct dlist_item *curr = copy_head;
    while (tmp)
    {
        struct dlist_item *elm = malloc(sizeof(struct dlist_item));
        if (!elm)
        {
            return NULL;
        }

        elm->data = tmp->data;
        elm->prev = curr;
        curr->next = elm;
        curr = elm;

        tmp = tmp->next;
    }
    copy->tail = curr;
    copy->tail->next = NULL;

    return copy;
}
