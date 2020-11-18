#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "HashTable.h"

void exit_if_not_allocated(void* obj) {
    if (obj == NULL) {
        exit(EXIT_FAILURE);
    }
}

int linear_probe(HashTable* table, int multiplier) {
    return table->lp_factor * multiplier;
}

int hash(int key, int tableCap) {
    return ((key * 2) + (key + 10)) % tableCap;
}

bool exists(HashTable* table, int key) {
    for (int i = 0; i < table->capacity; i++)
    {
        if ((table->entries + i)->value)
            if ((table->entries + i)->key == key)
                return true;
    }

    return false;
}

HashTableEntry* get_entry(HashTable* table, int key) {
    if (!exists(table, key)) return NULL;

    int hashed = hash(key, table->capacity);
    int counter = 0;
    while ((table->entries + hashed)->key != key) {
        hashed += linear_probe(table, counter);
        counter++;
    }

    return (table->entries + hashed);
}

char* get(HashTable* table, int key) {
    HashTableEntry* entry = get_entry(table, key);
    if (entry) return entry->value;

    return NULL;
}

HashTableEntry* set_entries(int capacity) {
    HashTableEntry* entries = (HashTableEntry*)malloc(capacity * sizeof(HashTableEntry));
    exit_if_not_allocated(entries);
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
    table->resize_treshold = floor(table->capacity * table->max_load_factor);
}

void insert(HashTable* table, HashTableEntry entry) {
    int hashed = hash(entry.key, table->capacity);
    int counter = 0;
    while ((table->entries + hashed)->value)
    {
        hashed += linear_probe(table, counter);
        counter++;
    }

    *(table->entries + hashed) = entry;
    table->count++;
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

    HashTableEntry entry;
    entry.key = key;
    entry.value = value;

    insert(table, entry);
    if (table->count == table->resize_treshold) resize_hashtable(table, (table->capacity * 2));
}

void remove_key_value_pair(HashTable* table, int key) {
    HashTableEntry* entry = get_entry(table, key);
    if (entry) {
        free(entry->value);
        free(entry);
        entry->value = NULL;
        entry = NULL;
        table->count--;
    }
}

HashTable* init_hashtable() {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    exit_if_not_allocated(table);
    set_props(table, 10);
    table->entries = set_entries(table->capacity);
    table->get = &get;
    table->add = &add;
    table->exists = &exists;
    table->remove_key_value_pair = &remove_key_value_pair;

    return table;
}