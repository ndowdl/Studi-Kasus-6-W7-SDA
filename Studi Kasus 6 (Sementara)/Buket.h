#ifndef BUKET_H
#define BUKET_H

#include "DLinkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buatBuket(list **awal, int idbuket);
void tampilkanBuket(list *awal);
void hancurkanBuket(list **awal, int posbuket);
void tambahBungaKeBuket(list **awal, char * bunga, int harga, int posbuket);

#endif