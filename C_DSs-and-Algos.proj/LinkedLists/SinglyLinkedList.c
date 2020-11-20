#include <string.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"

void exit_if_out_of_bounds(SinglyLinkedList* lst, int index) {
    if (index < 0 || index > lst->get_sllst_size(lst))
    {
        exit(EXIT_FAILURE);
    }
}

void exit_if_empty(SinglyLinkedList* lst) {
    if (lst->is_sllst_empty(lst))
    {
        exit(EXIT_FAILURE);
    }
}

void push_front(SinglyLinkedList* lst, int value) {
    SinglyLinkedNode* newHead = (SinglyLinkedNode*)malloc(sizeof(SinglyLinkedNode));
    if (!newHead) {
        exit(EXIT_FAILURE);
    }
    newHead->value = value;

    if (lst->first == NULL) lst->last = newHead;

    newHead->next = lst->first;
    lst->first = newHead;
    lst->length++;
}

int pop_front(SinglyLinkedList* lst) {
    exit_if_empty(lst);

    SinglyLinkedNode* oldHead = lst->first;
    int oldVal = oldHead->value;

    if (lst->first == lst->last) {
        lst->first = NULL;
        lst->last = NULL;
    }
    else lst->first = oldHead->next;

    free(oldHead);
    lst->length--;
    return oldVal;
}

void push_back(SinglyLinkedList* lst, int value) {
    SinglyLinkedNode* newTail = (SinglyLinkedNode*)malloc(sizeof(SinglyLinkedNode));
    if (!newTail) exit(EXIT_FAILURE);
    newTail->value = value;

    if (lst->first == NULL) {
        lst->first = newTail;
        lst->last = lst->first;
    }
    else {
        SinglyLinkedNode* oldTail = lst->last;
        oldTail->next = newTail;
        lst->last = newTail;
    }

    newTail->next = NULL;
    lst->length++;
}

int pop_back(SinglyLinkedList* lst) {
    exit_if_empty(lst);

    SinglyLinkedNode* secondLast = lst->first;
    SinglyLinkedNode* last = lst->last;
    int oldVal = last->value;

    if (secondLast != last) {
        while (true) {
            if (secondLast->next == last) break;
            secondLast = secondLast->next;
        }
        lst->last = secondLast;
        secondLast->next = NULL;
    }
    else {
        lst->last = NULL;
        lst->first = NULL;
    }

    free(last);
    lst->length--;
    return oldVal;
}

int get_front(SinglyLinkedList* lst) {
    exit_if_empty(lst);
    return lst->first->value;
}

int get_back(SinglyLinkedList* lst) {
    exit_if_empty(lst);
    return lst->last->value;
}

void insert_sllst_at(SinglyLinkedList* lst, int value, int index) {
    exit_if_out_of_bounds(lst, index);

    if (index == 0) {
        push_front(lst, value);
        return;
    }

    if (index == lst->get_sllst_size(lst)) {
        push_back(lst, value);
        return;
    }

    SinglyLinkedNode* newNode = (SinglyLinkedNode*)malloc(sizeof(SinglyLinkedNode));
    if (!newNode) exit(EXIT_FAILURE);
    newNode->value = value;

    SinglyLinkedNode* previous = lst->first;
    int counter = 1;
    while (counter != index)
    {
        previous = previous->next;
        counter++;
    }

    newNode->next = previous->next;
    previous->next = newNode;
    lst->length++;
}

int get_sllst_size(SinglyLinkedList* lst) {
    return lst->length;
}

bool is_sllst_empty(SinglyLinkedList* lst) {
    return get_sllst_size(lst) == 0;
}

int get_value_at_from_start(SinglyLinkedList* lst, int index) {
    exit_if_empty(lst);
    if (index >= lst->get_sllst_size(lst) || index < 0)
    {
        exit(EXIT_FAILURE);
    }

    SinglyLinkedNode* current = lst->first;
    int counter = 0;
    while (counter != index)
    {
        current = current->next;
        counter++;
    }

    return current->value;
}

int get_value_at_from_end(SinglyLinkedList* lst, int n) {
    exit_if_empty(lst);
    if (n >= lst->get_sllst_size(lst) || n < 0)
    {
        exit(EXIT_FAILURE);
    }

    SinglyLinkedNode* node = lst->first;
    int count = (lst->get_sllst_size(lst) - n) - 1;
    for (int i = 0; i < count; i++)
    {
        node = node->next;
    }

    return node->value;
}

void sllst_remove_at(SinglyLinkedList* lst, int index) {
    exit_if_empty(lst);
    if (index >= lst->get_sllst_size(lst) || index < 0)
    {
        exit(EXIT_FAILURE);
    }

    SinglyLinkedNode* nodeToRemove = lst->first;
    SinglyLinkedNode* previous = nodeToRemove;
    for (int i = 0; i < index; i++)
    {
        previous = nodeToRemove;
        nodeToRemove = nodeToRemove->next;
    }

    if (nodeToRemove == lst->first)
    {
        lst->first = nodeToRemove->next;
    }
    else {
        SinglyLinkedNode* next = nodeToRemove->next;
        previous->next = next;
    }

    nodeToRemove = NULL;
    free(nodeToRemove);
    lst->length--;
}

void remove_value(SinglyLinkedList* lst, int value) {
    SinglyLinkedNode* node = lst->first;
    int counter = 0;
    while (node != NULL) {
        if (node->value == value) {
            sllst_remove_at(lst, counter);
            break;
        }
        node = node->next;
        counter++;
    }
}

void reverse(SinglyLinkedList* lst) {
    exit_if_empty(lst);
    SinglyLinkedNode* first = lst->first;
    SinglyLinkedNode* second = lst->first->next;
    SinglyLinkedNode* third = second->next;

    first->next = NULL;

    while (true)
    {
        second->next = first;
        first = second;
        second = third;
        if (third->next == NULL) {
            third->next = first;
            lst->last = lst->first;
            lst->first = third;
            break;
        }
        third = third->next;
    }
}

SinglyLinkedList* initialize_singlyLinkedList() {
    SinglyLinkedList* lst = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    if (!lst) exit(EXIT_FAILURE);

    lst->first = NULL;
    lst->last = NULL;
    lst->length = 0;

    lst->push_front = &push_front;
    lst->pop_front = &pop_front;
    lst->push_back = &push_back;
    lst->pop_back = &pop_back;
    lst->get_front = &get_front;
    lst->get_back = &get_back;
    lst->insert_sllst_at = &insert_sllst_at;
    lst->get_sllst_size = &get_sllst_size;
    lst->is_sllst_empty = &is_sllst_empty;
    lst->get_value_at_from_start = &get_value_at_from_start;
    lst->get_value_at_from_end = &get_value_at_from_end;
    lst->sllst_remove_at = &sllst_remove_at;
    lst->remove_value = &remove_value;
    lst->reverse = &reverse;

    return lst;
}