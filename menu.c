#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "customer.h"
#include "welcome.h"
#include "payment.h"
#include "reservation.h"
#include "rekapitulasi.h"

int takeOrder(char *orderDetails) {
    int menuItem, quantity, totalPrice = 0;
    int continueOrder;

    strcpy(orderDetails, "");

    do {
        displayMenu();
        printf("Masukkan nomor menu yang ingin dipesan (atau 0 untuk selesai): ");
        scanf("%d", &menuItem);

        if (menuItem == 0) break;

        printf("Masukkan jumlah pesanan: ");
        scanf("%d", &quantity);

        switch (menuItem) {
            case 1:
                strcat(orderDetails, "Kopi Hitam x");
                totalPrice += quantity * 15000;
                break;
            case 2:
                strcat(orderDetails, "Latte x");
                totalPrice += quantity * 20000;
                break;
            case 3:
                strcat(orderDetails, "Cappuccino x");
                totalPrice += quantity * 25000;
                break;
            case 4:
                strcat(orderDetails, "Lemon Tea x");
                totalPrice += quantity * 12000;
                break;
            case 5:
                strcat(orderDetails, "Lychee Tea x");
                totalPrice += quantity * 14000;
                break;
            case 6:
                strcat(orderDetails, "Ice Tea x");
                totalPrice += quantity * 10000;
                break;
            case 7:
                strcat(orderDetails, "Nasi Goreng x");
                totalPrice += quantity * 30000;
                break;
            case 8:
                strcat(orderDetails, "Mie Bangladesh x");
                totalPrice += quantity * 25000;
                break;
            case 9:
                strcat(orderDetails, "Sandwich x");
                totalPrice += quantity * 20000;
                break;
            case 10:
                strcat(orderDetails, "Macaroni x");
                totalPrice += quantity * 15000;
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }

        char qty[5];
        sprintf(qty, "%d, ", quantity);
        strcat(orderDetails, qty);

        printf("Pesan lagi? (1 untuk Ya, 0 untuk Tidak): ");
        scanf("%d", &continueOrder);
    } while (continueOrder == 1);

    return totalPrice;
}