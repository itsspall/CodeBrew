#include <stdio.h>
#include <string.h>
#include "payment.h"
#include "customer.h"
#include <conio.h>
#include <time.h>

// Fungsi pembayaran utama
void displayPayment(int totalPrice, const char *customerName, const char *orderDetails) {
    int paymentMethod;

    printf("========= Pembayaran =========\n");
    printf("Total harga: Rp %d\n", totalPrice);
    printf("1. Cash\n");
    printf("2. Cashless\n");
    printf("==============================\n");
    printf("Pilih metode pembayaran: ");
    scanf("%d", &paymentMethod);

    if (paymentMethod == 1) {
        processCashPayment(totalPrice, "cash", customerName, orderDetails);
    } else if (paymentMethod == 2) {
        processCashlessPayment(totalPrice, orderDetails);
    } else {
        printf("Metode pembayaran tidak valid. Silakan coba lagi.\n");
    }
}

// Fungsi pembayaran non-tunai 
void processCashlessPayment(int totalPrice, const char *orderDetails) {
    char accountName[NAME_LENGTH], password[PASSWORD_LENGTH];
    int customerIndex;
    int attempts = 0;

    while (1) {
        printf("Masukkan nama akun pembayaran: ");
        getchar();
        fgets(accountName, NAME_LENGTH, stdin);
        accountName[strcspn(accountName, "\n")] = '\0';

        customerIndex = findCustomer(accountName);
        if (customerIndex == -1) {
            printf("Nama akun pembayaran tidak ditemukan. Silakan coba lagi.\n");
        } else {
            break;
        }
    }

    while (attempts < 3) {
        attempts++;

        inputPassword(password);

        if (strcmp(customers[customerIndex].password, password) == 0) {
            if (customers[customerIndex].balance < totalPrice) {
                int choice;
                printf("Saldo tidak mencukupi. Anda memiliki dua opsi:\n");
                printf("1. Batalkan pesanan\n");
                printf("2. Ubah metode pembayaran menjadi cash\n");
                printf("Pilih opsi Anda (1/2): ");
                scanf("%d", &choice);

                if (choice == 1) {
                    printf("Pesanan telah dibatalkan.\n");
                    return;
                } else if (choice == 2) {
                    printf("Mengubah metode pembayaran menjadi cash...\n");
                    processCashPayment(totalPrice, "cash", customers[customerIndex].name, orderDetails);
                    return;
                } else {
                    printf("Opsi tidak valid. Pesanan dibatalkan secara otomatis.\n");
                    return;
                }
            }

            customers[customerIndex].balance -= totalPrice;
            printf("Pembayaran berhasil menggunakan cashless! Sisa saldo Anda: Rp %d\n", customers[customerIndex].balance);

            saveTransaction(customers[customerIndex].name, orderDetails, totalPrice, "cashless", accountName);
            return;
        } else {
            printf("Password salah. Percobaan %d/3.\n", attempts);
        }
    }

    printf("Percobaan password habis. Pesanan gagal.\n");
}

// Fungsi pembayaran tunai
void processCashPayment(int totalPrice, const char *payment, const char *customerName, const char *orderDetails) {
    int cash, change;

    while (1) {
        printf("Masukkan jumlah tunai: ");
        scanf("%d", &cash);

        if (cash >= totalPrice) {
            change = cash - totalPrice;
            if (change > 0) {
                printf("Kembalian Anda: Rp %d\n", change);
            }
            printf("Pembayaran berhasil menggunakan %s!\n", payment);

            saveTransaction(customerName, orderDetails, totalPrice, payment, NULL);
            return;
        } else {
            printf("Uang kurang. Silakan ulangi pembayaran.\n");
        }
    }
}

// Fungsi menyimpan transaksi
void saveTransaction(const char *customerName, const char *orderDetails, int totalPrice, const char *payment, const char *accountName) {
    FILE *file = fopen("rekapitulasi.txt", "a");
    if (!file) {
        printf("Gagal membuka file rekapitulasi.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    fprintf(file, "Nama Pelanggan: %s\n", customerName);
    fprintf(file, "Waktu: %02d-%02d-%04d %02d:%02d:%02d\n",
            tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
    fprintf(file, "Pesanan: %s\n", orderDetails);
    fprintf(file, "Total Harga: Rp %d\n", totalPrice);

    if (strcmp(payment, "cashless") == 0) {
        fprintf(file, "Metode Pembayaran: %s\n", payment);
        fprintf(file, "Nama Akun Pembayaran: %s\n", accountName);
    } else {
        fprintf(file, "Metode Pembayaran: %s\n", payment);
    }

    fprintf(file, "====================================\n");

    fclose(file);
    printf("Transaksi berhasil disimpan ke rekapitulasi.\n");
}
