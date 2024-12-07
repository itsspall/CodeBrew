#include <stdio.h>
#include <string.h>
#include "customer.h"
#include "reservation.h"
#include "payment.h"
#include "menu.h"
#include "welcome.h"
#include "rekapitulasi.h"
#include <time.h>

#define TOTAL_TABLES 10
#define NAME_LENGTH 50

int main() {
    int userChoice, adminChoice, customerChoice;
    int choice, totalPrice;
    char orderDetails[500], customerName[50];
    char tables[TOTAL_TABLES][NAME_LENGTH] = {""};
    time_t orderTime; // Waktu simulasi pesanan

    do {
        printf("========= Selamat Datang di CodeBrew =========\n");
        printf("1. Admin\n");
        printf("2. Pelanggan\n");
        printf("3. Keluar\n");
        printf("Pilih jenis pengguna: ");
        scanf("%d", &userChoice);

        if (userChoice == 1) {
            login(); // Login admin
            do {
                welcomeScreen();
                printf("1. Pilih Menu\n");
                printf("2. Reservasi Meja\n");
                printf("3. Rekapitulasi\n");
                printf("4. Keluar\n");
                printf("Pilih opsi: ");
                scanf("%d", &adminChoice);

                switch (adminChoice) {
                    case 1:
                        printf("Masukkan nama pelanggan: ");
                        scanf(" %[^\n]", customerName);
                        totalPrice = takeOrder(orderDetails);
                        time(&orderTime); // Simpan waktu pesanan dibuat
                        displayPayment(totalPrice, customerName, orderDetails);
                        break;
                    case 2:
                        displayTables(tables);
                        makeReservation(tables);
                        break;
                    case 3:
                        rekapitulasi();
                        break;
                    case 4:
                        printf("Keluar dari menu admin.\n");
                        break;
                    default:
                        printf("Pilihan tidak valid. Coba lagi.\n");
                }
            } while (adminChoice != 4);

        } else if (userChoice == 2) {
            do {
                printf("========= Menu Pelanggan =========\n");
                printf("1. Lihat Menu Digital\n");
                printf("2. Status Pesanan\n");
                printf("3. Kembali\n");
                printf("Pilih opsi: ");
                scanf("%d", &customerChoice);

                switch (customerChoice) {
                    case 1:
                        displayMenu();
                        break;
                    case 2:
                        displayOrderStatus(orderTime);
                        break;
                    case 3:
                        printf("Kembali ke menu utama.\n");
                        break;
                    default:
                        printf("Pilihan tidak valid. Coba lagi.\n");
                }
            } while (customerChoice != 3);

        } else if (userChoice == 3) {
            printf("Terima kasih telah menggunakan CodeBrew!\n");
        } else {
            printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (userChoice != 3);

    return 0;
}