#include "dlist.h"

void swap(struct dlist_item *e1, struct dlist_item *e2)
{
    int tmp = e1->data;
    e1->data = e2->data;
    e2->data = tmp;
}

void dlist_sort(struct dlist *list)
{
    if (list->size == 0)
    {
        return;
    }

    for (size_t i = 0; i < list->size - 1; i++)
    {
        size_t j = 0;
        struct dlist_item *tmp2 = list->head;
        while (tmp2->next && j < list->size - i - 1)
        {
            if (tmp2->data > tmp2->next->data)
            {
                swap(tmp2, tmp2->next);
            }

            j++;
            tmp2 = tmp2->next;
        }
    }
}

void dlist_merge(struct dlist *list1, struct dlist *list2)
{
    struct dlist_item *tmp1 = list1->head;
    struct dlist_item *tmp2 = list2->head;

    size_t i = 0;
    while (tmp1 && tmp2)
    {
        if (tmp2->data > tmp1->data)
        {
            tmp1 = tmp1->next;
        }
        else
        {
            dlist_insert_at(list1, tmp2->data, i);
            tmp2 = tmp2->next;
        }

        i++;
    }

    while (tmp2)
    {
        dlist_push_back(list1, tmp2->data);
        tmp2 = tmp2->next;
    }

    dlist_clear(list2);
}
