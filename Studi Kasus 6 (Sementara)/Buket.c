#ifndef BUKET_H
#define BUKET_H

#include "DLinkedlist.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void buatBuket(list **awal, int idbuket) {
    char buket[50];
    sprintf(buket, "Buket %d", idbuket);
    
    list *new = createNode(buket, 0);
    
    if (isEmpty(*awal)) {
        *awal = new;
        return;
    }
    
    list *current = *awal;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = new;
    new->prev = current;
}

void tampilkanBuket(list *awal) {
    if (isEmpty(awal)) {
        printf("Lemari buket kosong!\n");
        return;
    }
    
    list *currentBuket = awal;
    while (currentBuket != NULL) {
        printf("\n=== %s ===\n", currentBuket->Bonquet);
        
        list *currentBunga = currentBuket->next;
        while (currentBunga != NULL && strstr(currentBunga->Bonquet, "Buket") == NULL) {
            printf("- %s (Rp %d)\n", currentBunga->Bonquet, currentBunga->harga);
            currentBunga = currentBunga->next;
        }
        
        currentBuket = currentBunga;
    }
}

void hancurkanBuket(list **awal, int posbuket) {
    if (isEmpty(*awal)) {
        printf("Lemari buket kosong!\n");
        return;
    }
    
    list *currentBuket = *awal;
    int count = 1;
    
    while (currentBuket != NULL && count < posbuket) {
        currentBuket = currentBuket->next;
        while (currentBuket != NULL && strstr(currentBuket->Bonquet, "Buket") == NULL) {
            currentBuket = currentBuket->next;
        }
        count++;
    }
    
    if (currentBuket == NULL) {
        printf("Buket tidak ditemukan!\n");
        return;
    }
    
    list *nextBuket = currentBuket->next;
    while (nextBuket != NULL && strstr(nextBuket->Bonquet, "Buket") == NULL) {
        list *temp = nextBuket;
        nextBuket = nextBuket->next;
        free(temp);
    }
    
    if (currentBuket == *awal) {
        *awal = nextBuket;
        if (nextBuket != NULL) {
            nextBuket->prev = NULL;
        }
    } else {
        currentBuket->prev->next = nextBuket;
        if (nextBuket != NULL) {
            nextBuket->prev = currentBuket->prev;
        }
    }
    
    free(currentBuket);
    printf("Buket berhasil dihancurkan!\n");
}

void tambahBungaKeBuket(list **awal, char *bunga, int harga, int posbuket) {
    if (isEmpty(*awal)) {
        printf("Lemari buket kosong!\n");
        return;
    }
    
    list *currentBuket = *awal;
    int count = 1;
    
    while (currentBuket != NULL && count < posbuket) {
        currentBuket = currentBuket->next;
        while (currentBuket != NULL && strstr(currentBuket->Bonquet, "Buket") == NULL) {
            currentBuket = currentBuket->next;
        }
        count++;
    }
    
    if (currentBuket == NULL) {
        printf("Buket tidak ditemukan!\n");
        return;
    }
    
    list *newBunga = createNode(bunga, harga);
    
    list *nextBuket = currentBuket->next;
    while (nextBuket != NULL && strstr(nextBuket->Bonquet, "Buket") == NULL) {
        nextBuket = nextBuket->next;
    }
    
    if (nextBuket == NULL) {
        list *last = currentBuket;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newBunga;
        newBunga->prev = last;
    } else {
        list *lastBunga = nextBuket->prev;
        newBunga->next = nextBuket;
        newBunga->prev = lastBunga;
        lastBunga->next = newBunga;
        nextBuket->prev = newBunga;
    }
    
    printf("Bunga berhasil ditambahkan ke dalam buket!\n");
}

#endif