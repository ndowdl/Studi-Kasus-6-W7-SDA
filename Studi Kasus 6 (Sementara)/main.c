#include "DLinkedlist.h"
#include "Buket.h"

int main() {
    list *lemaribuket = NULL;
    int idbuket = 1;

    menu:
        printf("Masukan opsi anda dengan angka\n");
        printf("1. Membuat buket\n");
        printf("2. Tambah Bunga\n");
        printf("3. Hancurkan Bunga\n");
        printf("4. Tampilkan Bunga\n");
        printf("5. Keluar\n");
        printf("Pilih menu: "); 
        int pilihan;
        scanf("%d", &pilihan);
        if (pilihan == 1) {
            buatBuket(&lemaribuket, idbuket);
            idbuket++;
            goto menu;
        }

        if (pilihan == 2 && lemaribuket != NULL) {
            printf("Masukan bunga yang ingin anda tambahkan: ");
            char bunga[50];
            scanf("%s", bunga);
            printf("Masukan harga bunga: ");
            int harga;
            scanf("%d", &harga);
            tampilkanBuket(lemaribuket);
            printf("Masukan ke buket yang diinginkan: ");
            int pos1;
            scanf("%d", &pos1);
            tambahBungaKeBuket(&lemaribuket, bunga, harga, pos1);
            goto menu;
        } 

        else{
            printf("Tidak ada buket yang tersedia!\n");
        }
        if (pilihan == 3 && lemaribuket != NULL) {
            printf("Masukan posisi buket yang ingin dihancurkan: ");
            tampilkanBuket(lemaribuket);
            int pos2;
            scanf("%d", &pos2);
            hancurkanBuket(&lemaribuket, pos2);
            goto menu;
        }

        else{
            printf("Tidak ada buket yang tersedia!\n");
        }

        if (pilihan == 4 && lemaribuket != NULL) {
            printf("Tampilan bunga:\n");
            tampilkanBuket(lemaribuket);
            goto menu;
        }
        
        else{
            printf("Tidak ada buket yang tersedia!\n");
        }

        if (pilihan == 5) {
            printf("Terima kasih telah menggunakan aplikasi kami!\n");
            exit(0);
        }
        else{
            printf("Pilihan tidak valid!\n");
            goto menu;
        }
}
