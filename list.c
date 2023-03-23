#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List *listaEnlazada = (List *) malloc(sizeof(List));
  if (listaEnlazada == NULL)
      return NULL;
  
  listaEnlazada->head = NULL;
  listaEnlazada->tail = NULL;
  listaEnlazada->current = NULL;
  
  return listaEnlazada;
}

void * firstList(List * list) {
  if (list->head == NULL)
    return NULL;
  
  list->current = list->head;
  
  return list->current->data;
}

void * nextList(List * list) {
  if (list->current == NULL || list->current->next == NULL)
    return NULL;
  
  list->current = list->current->next;
  
  return list->current->data;
}

void * lastList(List * list) {
  if (list->tail == NULL)
    return NULL;
  
  list->current = list->tail;
  
    return list->current->data;
}

void * prevList(List * list) {
  if (list->current == NULL || list->current->prev == NULL)
    return NULL;

  list->current = list->current->prev;
  
  return list->current->data;
}

void pushFront(List * list, void * data) {
  Node *nuevoNodo = createNode(data);
  
  if (list->head == NULL)
  {
    nuevoNodo->next = nuevoNodo;
    nuevoNodo->prev = nuevoNodo;
    list->head = nuevoNodo;
  }
  
  nuevoNodo->next = list->head;
  if (list->head)
    list->head->prev = nuevoNodo;
  
  list->head = nuevoNodo;
  
  nuevoNodo->prev=NULL;
  
  list->tail = nuevoNodo;
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node *nuevoNodo = createNode(data);
  if (list->head == NULL)
  { 
    pushFront(list, data);
    return;
  }
  if (list->current == list->tail)
  {
    list->tail->next = nuevoNodo;
    nuevoNodo->next = list->head;
    nuevoNodo->prev = list->tail;
    list->tail = nuevoNodo;
    list->head->prev = nuevoNodo;
    return;
  }
  
  nuevoNodo->prev = list->current;
  list->current->next = nuevoNodo;
  nuevoNodo->next = list->current->next;
  list->current->next->prev = nuevoNodo;
  
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  if ()
  
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}