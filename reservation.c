#include <stdio.h>
#include <string.h>
#include "reservation.h"

void displayTables(char tables[][NAME_LENGTH]) {
    printf("\nDaftar Meja:\n");
    for (int i = 0; i < TOTAL_TABLES; i++) {
        if (strlen(tables[i]) == 0) {
            printf("Meja %d: Tersedia\n", i + 1);
        } else {
            printf("Meja %d: Dipesan oleh %s\n", i + 1, tables[i]);
        }
    }
}

void makeReservation(char tables[][NAME_LENGTH]) {
    int tableNumber;
    char customerName[NAME_LENGTH];

    printf("Masukkan nomor meja yang ingin dipesan (1-%d): \n", TOTAL_TABLES);
    printf("Ketik 0 untuk kembali ke Menu: \n");
    scanf("%d", &tableNumber);

    if (tableNumber == 0) {
        printf("Kembali ke menu utama.\n");
        return;
    }

    if (tableNumber < 1 || tableNumber > TOTAL_TABLES) {
        printf("Nomor meja tidak valid. Silakan coba lagi.\n");
        return;
    }

    if (strlen(tables[tableNumber - 1]) != 0) {
        printf("Meja %d sudah dipesan oleh %s.\n", tableNumber, tables[tableNumber - 1]);
        return;
    }

    printf("Masukkan nama pelanggan: ");
    getchar();
    fgets(customerName, NAME_LENGTH, stdin);
    customerName[strcspn(customerName, "\n")] = '\0';

    strcpy(tables[tableNumber - 1], customerName);
    printf("Reservasi berhasil untuk Meja %d atas nama %s.\n", tableNumber, customerName);
}
