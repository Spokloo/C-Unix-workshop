#include "list.h"

#include <stdlib.h>
#include <string.h>

struct list *list_prepend(struct list *list, const void *value,
                          size_t data_size)
{
    struct list *head = malloc(sizeof(struct list));
    if (!head)
        return NULL;

    head->data = malloc(sizeof(void *));
    if (!head->data)
        return NULL;

    memcpy(head->data, value, data_size);
    head->next = list;

    return head;
}

size_t list_length(struct list *list)
{
    if (!list)
    {
        return 0;
    }

    size_t len = 0;
    struct list *tmp = list;

    while (tmp)
    {
        len++;
        tmp = tmp->next;
    }

    return len;
}

void list_destroy(struct list *list)
{
    if (!list)
    {
        return;
    }

    struct list *tmp;
    void *tmp_data;
    while (list)
    {
        tmp = list;
        tmp_data = list->data;
        list = list->next;
        free(tmp_data);
        free(tmp);
    }
}
