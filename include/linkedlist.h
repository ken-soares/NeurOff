// include/linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>

// Structure représentant un seul nœud dans la liste chaînée
typedef struct ListNode {
    void *data;               // Pointeur vers les données stockées dans le nœud
    struct ListNode *next;    // Pointeur vers le nœud suivant dans la liste
} ListNode;

// Structure représentant la liste chaînée
typedef struct LinkedList {
    ListNode *head;           // Pointeur vers le premier nœud dans la liste
    ListNode *tail;           // Pointeur vers le dernier nœud dans la liste
} LinkedList;

// Crée et initialise une nouvelle liste chaînée.
// Retourne un pointeur vers la structure LinkedList nouvellement créée.
// Retourne NULL si l'allocation de mémoire échoue.
LinkedList* createLinkedList();

// Ajoute un nouveau nœud avec les données fournies à la fin de la liste chaînée.
// Paramètre list : Pointeur vers la LinkedList.
// Paramètre data : Pointeur vers les données à stocker dans le nouveau nœud.
// Retourne 1 si l'opération est réussie, 0 sinon.
int appendLinkedList(LinkedList* list, void* data);

// Libère tous les nœuds dans la liste chaînée et la liste elle-même.
// Paramètre list : Pointeur vers la LinkedList à libérer.
void freeLinkedList(LinkedList* list);


// Fonction utilitaire pour itérer sur la liste chaînée et appliquer une fonction à chaque donnée des nœuds.
// Paramètre list : Pointeur vers la LinkedList.
// Paramètre func : Pointeur vers une fonction qui prend un argument void*.
void iterateLinkedList(LinkedList* list, void (*func)(void*));

#endif // LINKEDLIST_H