#include "stack.h"

#include <stdlib.h>

struct stack *stack_push(struct stack *s, int e)
{
    struct stack *head = malloc(sizeof(struct stack));
    if (!head)
    {
        return NULL;
    }

    head->data = e;
    head->next = s;

    return head;
}

struct stack *stack_pop(struct stack *s)
{
    if (!s)
    {
        return NULL;
    }

    struct stack *next = s->next;
    s->next = NULL;
    free(s);

    return next;
}

int stack_peek(struct stack *s)
{
    return s->data;
}
