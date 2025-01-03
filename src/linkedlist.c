#include "linkedlist.h"
#include <stdio.h>

// Crée et initialise une nouvelle liste chaînée.
// Retourne un pointeur vers la structure LinkedList nouvellement créée.
// Retourne NULL si l'allocation de mémoire échoue.
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (!list) {
        fprintf(stderr, "Erreur : Impossible d'allouer de la mémoire pour LinkedList.\n");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Ajoute un nouveau nœud avec les données fournies à la fin de la liste chaînée.
// Paramètre list : Pointeur vers la LinkedList.
// Paramètre data : Pointeur vers les données à stocker dans le nouveau nœud.
// Retourne 1 si l'opération est réussie, 0 sinon.
int appendLinkedList(LinkedList* list, void* data) {
    if (!list) {
        fprintf(stderr, "Erreur : LinkedList est NULL.\n");
        return 0;
    }

    // Crée un nouveau nœud
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (!newNode) {
        fprintf(stderr, "Erreur : Impossible d'allouer de la mémoire pour ListNode.\n");
        return 0;
    }
    newNode->data = data;
    newNode->next = NULL;

    // Ajoute le nœud à la fin de la liste
    if (list->tail) {
        // La liste n'est pas vide
        list->tail->next = newNode;
    } else {
        // La liste est vide
        list->head = newNode;
    }
    list->tail = newNode;

    return 1;
}

// Libère tous les nœuds dans la liste chaînée et la liste elle-même.
// Paramètre list : Pointeur vers la LinkedList à libérer.
void freeLinkedList(LinkedList* list) {
    if (!list) {
        return;
    }

    ListNode* current = list->head;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        free(temp);
    }

    free(list);
}

// Fonction utilitaire pour itérer sur la liste chaînée et appliquer une fonction à chaque donnée des nœuds.
// Paramètre list : Pointeur vers la LinkedList.
// Paramètre func : Pointeur vers une fonction qui prend un argument void*.
void iterateLinkedList(LinkedList* list, void (*func)(void*)) {
    if (!list || !func) {
        return;
    }

    ListNode* current = list->head;
    while (current) {
        func(current->data);
        current = current->next;
    }
}