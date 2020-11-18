#include <string.h>
#include <stdlib.h>
#include "LlstQ.h"

void exit_if_lq_not_allocated(void* obj) {
    if (obj == NULL) {
        exit(EXIT_FAILURE);
    }
}

bool is_Lq_empty(LlstQ* q) {
    return q->count == 0;
}

void enqueue_Lq(LlstQ* q, int value) {
    LlstQnode* newTail = (LlstQnode*)malloc(sizeof(LlstQnode));
    exit_if_lq_not_allocated(newTail);

    newTail->next = NULL;
    newTail->value = value;

    if (q->is_Lq_empty(q) == 1) {
        newTail->prev = NULL;
        q->head = newTail;
        q->tail = newTail;
    }
    else {
        q->tail->next = newTail;
        newTail->prev = q->tail;
        q->tail = newTail;
    }

    q->count++;
}

int dequeue_Lq(LlstQ* q) {
    if (q->is_Lq_empty(q) == 1)
    {
        exit(EXIT_FAILURE);
    }

    LlstQnode* temp = q->head;
    int oldVal = temp->value;
    if (q->head->next)
    {
        q->head = q->head->next;
        q->head->prev = NULL;
    }
    else
    {
        q->head = NULL;
    }

    q->count--;
    free(temp);
    return oldVal;
}

LlstQ* init_lq_queue() {
    LlstQ* q = (LlstQ*)malloc(sizeof(LlstQ));
    exit_if_lq_not_allocated(q);

    q->count = 0;
    q->head = NULL;
    q->tail = NULL;
    q->is_Lq_empty = &is_Lq_empty;
    q->enqueue_Lq = &enqueue_Lq;
    q->dequeue_Lq = &dequeue_Lq;
    
    return q;
}