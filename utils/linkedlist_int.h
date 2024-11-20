#ifndef LINKEDLIST_INT_H
#define LINKEDLIST_INT_H

#include <stdbool.h>
#include <stdlib.h>

// Structure representing a node in the integer linked list
typedef struct IntNode {
    int data;
    struct IntNode* next;
} IntNode;

// Structure representing the integer linked list
typedef struct {
    IntNode* head;
} IntLinkedList;

// Function prototypes
IntLinkedList* createIntList();
IntNode* createIntNode(int data);
void appendInt(IntLinkedList* list, int data);
bool insertInt(IntLinkedList* list, int data, int position);
bool deleteInt(IntLinkedList* list, int data);
void displayIntList(const IntLinkedList* list);
void freeIntList(IntLinkedList* list);

#endif // LINKEDLIST_INT_H