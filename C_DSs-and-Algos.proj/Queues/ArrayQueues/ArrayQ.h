#include <stdbool.h>

typedef struct ArrayQ {
    int max_cap;
    int count;
    int* items;

    void (*enqueue)(struct ArrayQ*, int value);
    int (*dequeue)(struct ArrayQ*);
    bool (*is_arrayQ_empty)(struct ArrayQ*);
    bool (*is_full)(struct ArrayQ*);
} ArrayQ;
