#include <stdio.h>
#include <string.h>
#include "customer.h"
#include "reservation.h"
#include "payment.h"
#include "menu.h"
#include "welcome.h"
#include "rekapitulasi.h"

#define TOTAL_TABLES 10
#define NAME_LENGTH 50

int main() {
    int choice, totalPrice;
    char orderDetails[500], customerName[50];
    char tables[TOTAL_TABLES][NAME_LENGTH] = {""};
    int startTimes[TOTAL_TABLES] = {0};
    int endTimes[TOTAL_TABLES] = {0};

    login();

    do {
        welcomeScreen();
        printf("1. Pilih Menu\n");
        printf("2. Reservasi Meja\n");
        printf("3. Rekapitulasi\n");
        printf("4. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan nama pelanggan: ");
                scanf(" %[^\n]", customerName);
                totalPrice = takeOrder(orderDetails);
                displayPayment(totalPrice, customerName, orderDetails);
                break;
            case 2:
                displayTables(tables, startTimes, endTimes, TOTAL_TABLES);
                makeReservation(tables, startTimes, endTimes, TOTAL_TABLES);
                break;
            case 3:
                rekapitulasi();
                break;
            case 4:
                printf("Terima kasih telah menggunakan CodeBrew!\n");
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (choice != 4);

    return 0;
}
