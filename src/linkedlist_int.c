#include "linkedlist_int.h"
#include <stdio.h>

// Create a new integer linked list
IntLinkedList* createIntList() {
    IntLinkedList* list = (IntLinkedList*)malloc(sizeof(IntLinkedList));
    if (!list) {
        fprintf(stderr, "Memory allocation failed for IntLinkedList.\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    return list;
}

// Create a new integer node
IntNode* createIntNode(int data) {
    IntNode* newNode = (IntNode*)malloc(sizeof(IntNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed for IntNode.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Append a node to the end of the integer list
void appendInt(IntLinkedList* list, int data) {
    IntNode* newNode = createIntNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    IntNode* current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Insert a node at a specific position in the integer list
bool insertInt(IntLinkedList* list, int data, int position) {
    if (position < 0) {
        return false;
    }
    IntNode* newNode = createIntNode(data);
    if (position == 0) {
        newNode->next = list->head;
        list->head = newNode;
        return true;
    }
    IntNode* current = list->head;
    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }
    if (current == NULL) {
        free(newNode);
        return false;
    }
    newNode->next = current->next;
    current->next = newNode;
    return true;
}

// Delete a node by value from the integer list
bool deleteInt(IntLinkedList* list, int data) {
    if (list->head == NULL) {
        return false;
    }
    if (list->head->data == data) {
        IntNode* temp = list->head;
        list->head = list->head->next;
        free(temp);
        return true;
    }
    IntNode* current = list->head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    if (current->next == NULL) {
        return false;
    }
    IntNode* temp = current->next;
    current->next = current->next->next;
    free(temp);
    return true;
}

// Display the integer linked list
void displayIntList(const IntLinkedList* list) {
    IntNode* current = list->head;
    printf("IntLinkedList: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Free all nodes in the integer linked list
void freeIntList(IntLinkedList* list) {
    IntNode* current = list->head;
    while (current != NULL) {
        IntNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}
