#include "HashTableEntry.h"
#include <stdbool.h>

typedef struct HashTable {
    int capacity;
    int count;
    int lp_factor;
    float max_load_factor;
    int resize_treshold;
    HashTableEntry* entries;

    void (*add)(struct HashTable*, int key, char* value);
    void (*remove_key_value_pair)(struct HashTable*, int key);
    char* (*get)(struct HashTable*, int key);
    bool (*exists)(struct HashTable*, int key);
}HashTable;
