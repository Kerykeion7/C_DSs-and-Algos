#include <stdbool.h>
#include "SinglyLinkedNode.h"


typedef struct SinglyLinkedList {
    struct SinglyLinkedNode* first;
    struct SinglyLinkedNode* last;

    int (*get_sllst_size)(struct SinglyLinkedList*);
    bool (*is_sllst_empty)(struct SinglyLinkedList*);
    int (*get_value_at_from_start)(struct SinglyLinkedList*, int index);
    void (*push_front)(struct SinglyLinkedList*, int value);
    int (*pop_front)(struct SinglyLinkedList*);
    void (*push_back)(struct SinglyLinkedList*, int value);
    int (*pop_back)(struct SinglyLinkedList*);
    int (*get_front)(struct SinglyLinkedList*);
    int (*get_back)(struct SinglyLinkedList*);
    void (*insert_sllst_at)(struct SinglyLinkedList*, int value, int index);
    void (*sllst_remove_at)(struct SinglyLinkedList*, int index);
    int (*get_value_at_from_end)(struct SinglyLinkedList*, int n);
    void (*reverse)(struct SinglyLinkedList*);
    void (*remove_value)(struct SinglyLinkedList*, int value);

} SinglyLinkedList;
