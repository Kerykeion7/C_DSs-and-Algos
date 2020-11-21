#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "HashTable.h"

int linear_probe(HashTable* table, int multiplier) {
    return table->lp_factor * multiplier;
}

int hash(int key, int tableCap) {
    return ((key * 2) + (key + 10)) % tableCap;
}

int index_of(HashTable* table, int key) {
    int hashed = hash(key, table->capacity);
    int index = hashed;
    int counter = 1;
    while (true)
    {
        if (!(table->entries + index) || (table->entries + index)->value == NULL) return -1;
        if ((table->entries + index)->key == key) return index;
        index = (hashed + linear_probe(table, counter)) % table->capacity;
        counter++;
    }
}

HashTableEntry* get_entry(HashTable* table, int key) {
    int index = index_of(table, key);
    if (index == -1) {
        return NULL;
    }

    return (table->entries + index);
}

bool exists(HashTable* table, int key) {
    if (get_entry(table, key)) return true;
    return false;
}

char* get(HashTable* table, int key) {
    HashTableEntry* entry = get_entry(table, key);
    if (entry) return entry->value;

    return NULL;
}

HashTableEntry* set_entries(int capacity) {
    HashTableEntry* entries = (HashTableEntry*)malloc(capacity * sizeof(HashTableEntry));
    if (!entries) exit(EXIT_FAILURE);
    for (int i = 0; i < capacity; i++)
    {
        (entries + i)->value = NULL;
    }
    return entries;
}

void set_props(HashTable* table, int capacity) {
    table->count = 0;
    table->capacity = capacity;
    table->lp_factor = 1;
    table->max_load_factor = 2.0F / 3.0F;
    table->resize_treshold = table->capacity * table->max_load_factor;
}

void resize_hashtable(HashTable* table, int new_capacity) {
    int old_capacity = table->capacity;
    HashTableEntry* oldEntries = table->entries;

    set_props(table, new_capacity);
    HashTableEntry* newEntries = set_entries(table->capacity);

    table->entries = newEntries;

    for (int i = 0; i < old_capacity; i++)
    {
        if ((oldEntries + i)->value) {
            table->add(table, (oldEntries + i)->key, (oldEntries + i)->value);
        }
    }

    free(oldEntries);
}

void add(HashTable* table, int key, char* value) {
    if (exists(table, key))
    {
        get_entry(table, key)->value = value;
        return;
    }

    int hashed = hash(key, table->capacity);
    int index = hashed;
    int counter = 1;
    while ((table->entries + index)->value)
    {
        index = (hashed + linear_probe(table, counter)) % table->capacity;
        counter++;
    }

    (table->entries + index)->key = key;
    (table->entries + index)->value = value;
    table->count++;
    if (table->count == table->resize_treshold) resize_hashtable(table, (table->capacity * 2));
}

void remove_key_value_pair(HashTable* table, int key) {
    int index = index_of(table, key);
    if (index != -1) {
        (table->entries + index)->key = 0;
        (table->entries + index)->value = NULL;
        free((table->entries + index)->value);
        table->count--;
    }
}

HashTable* init_hashtable() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    if (!table) exit(EXIT_FAILURE);
    set_props(table, 10);
    table->entries = set_entries(table->capacity);
    table->get = &get;
    table->add = &add;
    table->exists = &exists;
    table->remove_key_value_pair = &remove_key_value_pair;

    return table;
}