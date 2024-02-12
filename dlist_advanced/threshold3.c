#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

void dlist_map_square(struct dlist *list)
{
    struct dlist_item *tmp = list->head;

    while (tmp)
    {
        tmp->data = tmp->data * tmp->data;
        tmp = tmp->next;
    }
}

void dlist_reverse(struct dlist *list)
{
    struct dlist_item *tmp = list->head;

    while (tmp)
    {
        struct dlist_item *temp = tmp->next;

        struct dlist_item *tmp2 = tmp->next;
        tmp->next = tmp->prev;
        tmp->prev = tmp2;

        tmp = temp;
    }

    struct dlist_item *tmp2 = list->head;
    list->head = list->tail;
    list->tail = tmp2;
}

struct dlist *dlist_split_check(struct dlist *list, struct dlist *list2,
                                size_t index)
{
    if (list->size == 0)
    {
        return list2;
    }

    if (index == 0)
    {
        list2->head = list->head;
        list2->tail = list->tail;
        list2->size = list->size;

        list->head = NULL;
        list->tail = NULL;
        list->size = 0;
        return list2;
    }

    return NULL;
}

void modify_l2(struct dlist *list, struct dlist *list2, struct dlist_item *tmp,
               size_t index)
{
    list2->head = tmp;
    list2->head->prev = NULL;
    list2->tail = list->tail;
    list2->size = list->size - index;
}

struct dlist *dlist_split_at(struct dlist *list, size_t index)
{
    if (index >= list->size)
    {
        return NULL;
    }

    struct dlist *list2 = malloc(sizeof(struct dlist));
    if (!list2)
    {
        return NULL;
    }

    struct dlist *temp = dlist_split_check(list, list2, index);
    if (temp)
    {
        return temp;
    }

    size_t i = 0;
    struct dlist_item *prev = list->head;
    struct dlist_item *tmp = list->head;

    while (tmp->next)
    {
        if (i == index)
        {
            break;
        }

        i++;
        prev = tmp;
        tmp = tmp->next;
    }

    if (i == index)
    {
        modify_l2(list, list2, tmp, index);

        if (list->size == 1)
        {
            list->tail = NULL;
            list->head = NULL;
            list->size = 0;
            return list2;
        }

        list->tail = prev;
        list->tail->next = NULL;
        list->size -= list2->size;

        return list2;
    }

    return NULL;
}

void dlist_concat(struct dlist *list1, struct dlist *list2)
{
    if (list1->size == 0)
    {
        if (list2->size == 0)
        {
            return;
        }

        list1->head = list2->head;
        list1->tail = list2->tail;
        list1->size = list2->size;

        list2->head = NULL;
        list2->tail = NULL;
        list2->size = 0;
        return;
    }

    if (list2->size == 0)
    {
        return;
    }

    list1->tail->next = list2->head;
    list1->tail->next->prev = list1->tail;
    list1->tail = list2->tail;
    list1->size += list2->size;

    list2->head = NULL;
    list2->tail = NULL;
    list2->size = 0;
}
