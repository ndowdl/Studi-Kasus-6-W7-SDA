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

int isEmpty(list * cek) {
    if (cek != NULL){
        return 0;
    } else {
        return 1;
    }
}

list * createNode(char * newdata, int harga) {
    struct node * new = malloc(sizeof(list));

    if (isEmpty(new) == 1) {
        printf("Gagal alokasi wak!");
        exit(1);
    }

    new->prev = NULL;
    strcpy(new->Bonquet, newdata);
    new->harga = harga;
    new->next = NULL; 
    return new;
}

void insertFirst(list ** awal, char * newdata, int harga) {
    list * new = createNode(newdata, harga);
    struct node * temp = *awal;

    if(isEmpty(temp) == 1) {
        *awal = new;
        return;
    }

    new->next = temp;
    temp->prev = new;
}

void insertLast(list ** awal, char * newdata, int harga) {
    list * new = createNode(newdata, harga);
    struct node * temp = *awal;

    if(isEmpty(temp) == 1) {
        *awal = new;
        return;
    }

    while(temp != NULL) {
        temp = temp->next;
    }

    temp->next = new;
    new->prev = temp;
    new->next = NULL;
}

void insertBetween(list ** awal, char * newdata, int location, int harga) {
    list * new = createNode(newdata, harga);
    struct node * temp = *awal;
    
    if(isEmpty(temp) == 1) {
        *awal = new;
        return;
    }
    if(location == 1){
        new->next = *awal;
        (*awal)->prev = new;
        *awal = new;
        return;
    }

    location--;
    while (location != 1){
        temp = temp->next;
        location--;
    }

    new->prev = temp;
    new->next = temp->next;

    if (temp->next != NULL){
        temp->next->prev = new;
    }
    temp->next = new;
}

void removeFirst(list ** awal) {
    struct node * temp = *awal;

    if(isEmpty(temp) == 1) {
        printf("List sudah kosong!");
        return;
    } else {
        *awal = (*awal)->next;
        free(temp);
        temp = NULL;
        (*awal)->prev = NULL;
        return;
    }
}

void removeLast(list ** awal) {
    struct node * temp = *awal;
    struct node * temp2;
    
    if(isEmpty(temp) == 1) {
        printf("List sudah kosong!");
        return;
    }

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp2 = temp->prev; 
    temp2->next = NULL;
    free(temp);
    return;
}

void removeBetween(list ** awal, int location) {
    struct node * temp = *awal;
    struct node * temp2;

    if(isEmpty(temp) == 1) {
        printf("List sudah kosong!");
        return;
    }
    if (location == 1){
        *awal = (*awal)->next;
        free(temp);
        temp = NULL;
        (*awal)->prev = NULL;
        return;
    }
    else {
        location--;
        while (location != 1){
            temp = temp->next;
            location--;
        }    

        temp2 = temp->prev;
        temp2->next = temp->next;
        temp2->next->prev = temp2;
        free(temp);
        return;
    }
}

#endif