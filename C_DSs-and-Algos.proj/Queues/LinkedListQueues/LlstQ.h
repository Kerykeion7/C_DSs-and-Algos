#include <stdbool.h>
#include "LlstQnode.h"

typedef struct LlstQ {
    int count;
    struct LlstQnode* head;
    struct LlstQnode* tail;

    void (*enqueue_Lq)(struct LlstQ*, int value);
    int (*dequeue_Lq)(struct LlstQ*);
    bool (*is_Lq_empty)(struct LlstQ*);
}LlstQ;