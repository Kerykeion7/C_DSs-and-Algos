#pragma once
#include <stdbool.h>

const int minCapacity = 6;

typedef struct DynamicArray {
    int capacity;
    int count;
    int* items;
    void (*push)(struct DynamicArray*, int item);
    int (*pop)(struct DynamicArray*);
    int (*get_at)(struct DynamicArray*, int index);
    void (*insert_at)(struct DynamicArray*, int index, int item);
    void (*prepend)(struct DynamicArray*, int item);
    void (*remove_at)(struct DynamicArray*, int index);
    void (*remove_item)(struct DynamicArray*, int item);
    void (*clear)(struct DynamicArray*);
    int (*index_of)(struct DynamicArray*, int item);
    int (*get_size)(struct DynamicArray*);
    int (*get_capacity)(struct DynamicArray*);
    bool (*is_empty)(struct DynamicArray*);
} DynamicArray;