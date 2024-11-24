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

//Crée et initialise une nouvelle liste chaînée.
//return Pointeur vers la structure LinkedList nouvellement créée.
//return NULL si l'allocation de mémoire échoue.
LinkedList* createLinkedList();

//Ajoute un nouveau nœud avec les données fournies à la fin de la liste chaînée.
//param list Pointeur vers la LinkedList.
//param data Pointeur vers les données à stocker dans le nouveau nœud.
//return 1 si l'opération est réussie, 0 sinon.
int appendLinkedList(LinkedList* list, void* data);

//Libère tous les nœuds dans la liste chaînée et la liste elle-même.
//param list Pointeur vers la LinkedList à libérer.
void freeLinkedList(LinkedList* list);

//Trouve le premier nœud contenant les données spécifiées.
//param list Pointeur vers la LinkedList.
//param data Pointeur vers les données à rechercher.
//param compare Pointeur vers une fonction de comparaison.
//La fonction de comparaison doit retourner 0 si les données correspondent.
//return Pointeur vers le ListNode contenant les données.
//return NULL si les données ne sont pas trouvées.
ListNode* findLinkedList(LinkedList* list, void* data, int (*compare)(void*, void*));

//Supprime le premier nœud contenant les données spécifiées.
//param list Pointeur vers la LinkedList.
//param data Pointeur vers les données à supprimer.
//param compare Pointeur vers une fonction de comparaison.
//La fonction de comparaison doit retourner 0 si les données correspondent.
//return 1 si un nœud a été supprimé, 0 sinon.
int removeLinkedList(LinkedList* list, void* data, int (*compare)(void*, void*));
int removeLinkedList(LinkedList* list, void* data, int (*compare)(void*, void*));

//Fonction utilitaire pour itérer sur la liste chaînée et appliquer une fonction à chaque donnée des nœuds.
//param list Pointeur vers la LinkedList.
//param func Pointeur vers une fonction qui prend un argument void*.
void iterateLinkedList(LinkedList* list, void (*func)(void*));

#endif // LINKEDLIST_H