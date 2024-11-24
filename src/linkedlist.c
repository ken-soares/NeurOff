// src/linkedlist.c
#include "linkedlist.h"
#include <stdio.h>

//Crée et initialise une nouvelle liste chaînée.
//return Pointeur vers la structure LinkedList nouvellement créée.
//Retourne NULL si l'allocation de mémoire échoue.
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

//Ajoute un nouveau nœud avec les données fournies à la fin de la liste chaînée.
//return 1 si l'opération est réussie, 0 sinon.
int appendLinkedList(LinkedList* list, void* data) {
    if (!list) {
        fprintf(stderr, "Erreur : LinkedList est NULL.\n");
        return 0;
    }

    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (!newNode) {
        fprintf(stderr, "Erreur : Impossible d'allouer de la mémoire pour ListNode.\n");
        return 0;
    }
    newNode->data = data;
    newNode->next = NULL;

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

//Libère tous les nœuds dans la liste chaînée et la liste elle-même.
//param list Pointeur vers la LinkedList à libérer.
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

//Trouve le premier nœud contenant les données spécifiées.
//param list Pointeur vers la LinkedList.
//param data Pointeur vers les données à rechercher.
//param compare Pointeur vers une fonction de comparaison.
//La fonction de comparaison doit retourner 0 si les données correspondent.
//return Pointeur vers le ListNode contenant les données.
//Retourne NULL si les données ne sont pas trouvées.
ListNode* findLinkedList(LinkedList* list, void* data, int (*compare)(void*, void*)) {
    if (!list || !compare) {
        return NULL;
    }

    ListNode* current = list->head;
    while (current) {
        if (compare(current->data, data) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

//Supprime le premier nœud contenant les données spécifiées.
//param list Pointeur vers la LinkedList.
//param data Pointeur vers les données à supprimer.
//param compare Pointeur vers une fonction de comparaison.
//La fonction de comparaison doit retourner 0 si les données correspondent.
//return 1 si un nœud a été supprimé, 0 sinon.
int removeLinkedList(LinkedList* list, void* data, int (*compare)(void*, void*)) {
    if (!list || !compare) {
        return 0;
    }

    ListNode* current = list->head;
    ListNode* previous = NULL;

    while (current) {
        if (compare(current->data, data) == 0) {
            if (previous) {
                previous->next = current->next;
            } else {
                // Suppression du head
                list->head = current->next;
            }

            if (current == list->tail) {
                // Suppression du tail
                list->tail = previous;
            }

            free(current);
            return 1;
        }
        previous = current;
        current = current->next;
    }

    return 0;
}

//Fonction utilitaire pour itérer sur la liste chaînée et appliquer une fonction à chaque donnée des nœuds.
//param list Pointeur vers la LinkedList.
//param func Pointeur vers une fonction qui prend un argument void*.
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