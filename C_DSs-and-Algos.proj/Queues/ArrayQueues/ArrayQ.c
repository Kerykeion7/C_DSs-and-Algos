#include <string.h>
#include <stdlib.h>
#include "ArrayQ.h"

bool is_arrayQ_empty(ArrayQ* q) {
    return q->count == 0;
}

bool is_full(ArrayQ* q) {
    return q->count == q->max_cap;
}

void enqueue(ArrayQ* q, int value) {
    if (q->is_full(q))
    {
        exit(EXIT_FAILURE);
    }

    *(q->items + q->count) = value;
    q->count++;
}

int dequeue(ArrayQ* q) {
    if (q->is_arrayQ_empty(q) == 1)
    {
        exit(EXIT_FAILURE);
    }

    int oldVal = *(q->items);
    memmove(q->items, q->items + 1, q->max_cap * sizeof(int));
    exit_if_arrayQ_not_allocated(q->items);

    q->count--;
    return oldVal;
}

ArrayQ* init_array_q() {
    ArrayQ* q = (ArrayQ*)malloc(sizeof(ArrayQ));
    if (!q) exit(EXIT_FAILURE);

    q->count = 0;
    q->max_cap = 6;
    q->items = (int*)malloc(q->max_cap * sizeof(int));
    exit_if_arrayQ_not_allocated(q->items);
    q->is_arrayQ_empty = &is_arrayQ_empty;
    q->is_full = &is_full;
    q->enqueue = &enqueue;
    q->dequeue = &dequeue;
    return q;
}