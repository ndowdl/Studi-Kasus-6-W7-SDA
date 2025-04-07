#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    struct node* prev;
    struct node* next;
    char Bonquet[50];
    int harga;
} list;

int isEmpty(list * cek);
list * createNode(char * newdata, int harga);
void insertFirst(list ** awal, char * newdata, int harga);
void insertLast(list ** awal, char * newdata, int harga);
void insertBetween(list ** awal, char * newdata, int location, int harga);
void removeFirst(list ** awal);
void removeLast(list ** awal);
void removeBetween(list ** awal, int location);

#endif