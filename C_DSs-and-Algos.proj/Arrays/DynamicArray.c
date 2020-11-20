#include <string.h>
#include "DynamicArray.h"
#include <stdlib.h>

bool is_empty(DynamicArray* array) {
    return array->count == 0;
}

void clear(DynamicArray* array) {
    size_t old_count = array->count - 1;
    for (size_t i = 0; i < old_count; i++)
    {
        array->pop(array);
    }

    array->count = 0;
}

int index_of(DynamicArray* array, int item) {
    int* pointer = array->items;
    for (int i = 0; i < array->count; i++)
    {
        if (*pointer == item) return i;
        pointer++;
    }

    return -1;
}

void resize_array(DynamicArray* array, int capacitySize)
{
    int* items = array->items;
    if (!items) {
        exit(EXIT_FAILURE);
    }
    array->items = NULL;
    free(array->items);
    array->capacity = capacitySize;
    array->items = (int*)realloc(items, array->capacity * sizeof(int));
    if (!array->items) {
        exit(EXIT_FAILURE);
    }
    items = NULL;
    free(items);
}

void resize(DynamicArray* array) {
    if (array->count >= array->capacity)
    {
        resize_array(array, (array->capacity * 2));
    }
    else if (array->count <= (array->capacity / 4))
    {
        if ((array->capacity / 4) >= minCapacity)
        {
            resize_array(array, (array->capacity / 4));
        }
    }
}

void exit_on_invalid_index(DynamicArray* array, int index) {
    if (index > array->count - 1 && is_empty(array) == 0 || index < 0)
    {
        exit(EXIT_FAILURE);
    }
}

void remove_at(DynamicArray* array, int index) {
    exit_on_invalid_index(array, index);
    memmove(array->items + index, array->items + index + 1, (array->count - index) * sizeof(int));
    array->count--;
    resize(array);
}

void remove_item(DynamicArray* array, int item) {
    size_t old_count = array->count;
    for (size_t i = 0; i < old_count; i++)
    {
        if (*(array->items + i) == item)
        {
            remove_at(array, i);
            i--;
        }
    }
}

void push(DynamicArray* array, int item) {
    resize(array);
    int* pointer = array->items;
    pointer += array->count;
    *pointer = item;
    array->count++;
}

void insert_at(DynamicArray* array, int index, int item) {
    exit_on_invalid_index(array, index);
    if (is_empty(array) == 0) resize(array);
    else
    {
        push(array, item);
        return;
    }

    memmove(array->items + index + 1, array->items + index, (array->count - index) * sizeof(int));

    int* pointer = array->items + index;
    *pointer = item;

    array->count++;
}

void prepend(DynamicArray* array, int item) {
    insert_at(array, 0, item);
}

int get_at(DynamicArray* array, int index) {
    exit_on_invalid_index(array, index);

    int* pointer = array->items;
    pointer += index;
    return *pointer;
}

int get_size(DynamicArray* array) {
    return array->count;
}

int get_capacity(DynamicArray* array) {
    return array->capacity;
}

int pop(DynamicArray* array) {
    if (is_empty(array) == 0)
    {
        int return_value = *(array->items + array->count - 1);
        remove_at(array, array->count - 1);
        return return_value;
    }

    return -1;
}

DynamicArray* init(int capacity) {
    if (capacity < minCapacity) capacity = minCapacity;

    DynamicArray* array = (DynamicArray*)malloc(sizeof(DynamicArray));
    if (!array) {
        exit(EXIT_FAILURE);
    }
    array->count = 0;
    array->capacity = capacity;
    array->items = (int*)malloc(capacity * sizeof(int));
    if (!array->items) {
        exit(EXIT_FAILURE);
    }
    array->push = &push;
    array->pop = &pop;
    array->get_at = &get_at;
    array->insert_at = &insert_at;
    array->prepend = &prepend;
    array->remove_item = &remove_item;
    array->remove_at = &remove_at;
    array->get_size = &get_size;
    array->get_capacity = &get_capacity;
    array->is_empty = &is_empty;
    array->index_of = &index_of;
    array->clear = &clear;

    return array;
}

int main() { return 0; }