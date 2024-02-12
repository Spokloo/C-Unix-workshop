#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

int dlist_get(const struct dlist *list, size_t index)
{
    if (list->size == 0)
    {
        return -1;
    }

    size_t i = 0;
    struct dlist_item *tmp = list->head;

    while (tmp->next)
    {
        if (i == index)
        {
            break;
        }

        i++;
        tmp = tmp->next;
    }

    if (i == index)
    {
        return tmp->data;
    }

    return -1;
}

int dlist_insert_edge(struct dlist *list, int element, size_t index)
{
    if (index == list->size)
    {
        dlist_push_back(list, element);
        return 1;
    }

    if (index == 0)
    {
        dlist_push_front(list, element);
        return 1;
    }

    return 0;
}

struct dlist_item *dlist_init_elm(int element)
{
    if (element < 0)
    {
        return NULL;
    }

    struct dlist_item *elm = malloc(sizeof(struct dlist_item));
    if (!elm)
    {
        return NULL;
    }

    elm->data = element;
    elm->next = NULL;
    elm->prev = NULL;

    return elm;
}

int dlist_insert_at(struct dlist *list, int element, size_t index)
{
    if (dlist_insert_edge(list, element, index))
    {
        return 1;
    }

    if (index > list->size)
    {
        return -1;
    }

    struct dlist_item *elm = dlist_init_elm(element);
    if (!elm)
    {
        return -1;
    }

    if (index == 0 && list->size == 0)
    {
        list->size = 1;
        list->head = elm;
        list->tail = elm;
        return 1;
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
        elm->next = tmp;
        elm->prev = prev;
        prev->next = elm;
        tmp->prev = elm;
        list->size++;
        return 1;
    }

    return -1;
}

int dlist_find(const struct dlist *list, int element)
{
    if (list->size == 0)
    {
        return -1;
    }

    size_t i = 0;
    struct dlist_item *tmp = list->head;

    while (tmp->next)
    {
        if (element == tmp->data)
        {
            break;
        }

        i++;
        tmp = tmp->next;
    }

    if (element == tmp->data)
    {
        return i;
    }

    return -1;
}

int dlist_remove_get(struct dlist *list, size_t i)
{
    if (i == 0)
    {
        list->head = list->head->next;
        if (list->head)
        {
            list->head->prev = NULL;
        }

        if (list->size == 1)
        {
            list->tail = NULL;
        }

        list->size--;
        return 1;
    }

    if (i == list->size - 1)
    {
        list->tail = list->tail->prev;
        if (list->tail)
        {
            list->tail->next = NULL;
        }

        if (list->size == 1)
        {
            list->head = NULL;
        }

        list->size--;
        return 1;
    }

    return 0;
}

int dlist_remove_at(struct dlist *list, size_t index)
{
    if (list->size == 0)
    {
        return -1;
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
        if (dlist_remove_get(list, i))
        {
            int temp = tmp->data;
            free(tmp);
            return temp;
        }

        prev->next = tmp->next;
        tmp->next->prev = prev;

        list->size--;
        int temp = tmp->data;
        free(tmp);
        return temp;
    }

    return -1;
}

void dlist_clear(struct dlist *list)
{
    if (!list)
    {
        return;
    }

    struct dlist_item *tmp = list->head;

    while (tmp)
    {
        struct dlist_item *prev = tmp;
        tmp = tmp->next;
        free(prev);
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
