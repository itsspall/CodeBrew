#include <stdio.h>
#include <string.h>
#include "payment.h"
#include "customer.h"
#include <conio.h>
#include <time.h>

// Fungsi pembayaran
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
        processCashPayment(totalPrice, customerName, orderDetails);
    } else if (paymentMethod == 2) {
        processCashlessPayment(totalPrice, orderDetails);
    } else {
        printf("Metode pembayaran tidak valid.\n");
    }
}

//fungsi pembayaran non tunai
void processCashlessPayment(int totalPrice, const char *orderDetails) {
    char customerName[NAME_LENGTH], password[PASSWORD_LENGTH];
    int customerIndex;

    printf("Masukkan nama pelanggan: ");
    getchar();
    fgets(customerName, NAME_LENGTH, stdin);
    customerName[strcspn(customerName, "\n")] = '\0';
    customerIndex = findCustomer(customerName);
    if (customerIndex == -1) {
        printf("Pelanggan tidak ditemukan. Pastikan Anda terdaftar di aplikasi.\n");
        return;
    }

    inputPassword(password);

    if (strcmp(customers[customerIndex].password, password) != 0) {
        printf("Password salah. Pembayaran gagal.\n");
        return;
    }

    if (customers[customerIndex].balance < totalPrice) {
        printf("Saldo tidak mencukupi. Pembayaran gagal.\n");
        return;
    }

    customers[customerIndex].balance -= totalPrice;
    printf("Pembayaran berhasil! Sisa saldo Anda: Rp %d\n", customers[customerIndex].balance);

    saveTransaction(customers[customerIndex].name, orderDetails, totalPrice);
}

// Fungsi pembayaran tunai
void processCashPayment(int totalPrice, const char *customerName, const char *orderDetails) {
    int cash, change;

    printf("Masukkan jumlah tunai: ");
    scanf("%d", &cash);

    if (cash >= totalPrice) {
        change = cash - totalPrice;
        if (change > 0) printf("Kembalian Anda: Rp %d\n", change);
        saveTransaction(customerName, orderDetails, totalPrice);
    } else {
        printf("Uang kurang. Silakan ulangi pembayaran.\n");
        processCashPayment(totalPrice, customerName, orderDetails);
    }
}

// Fungsi menyimpan transaksi
void saveTransaction(const char *customerName, const char *orderDetails, int totalPrice) {
    FILE *file = fopen("rekapitulasi.txt", "a");
    if (!file) {
        printf("Gagal membuka file.\n");
        return;
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    fprintf(file, "Nama: %s\nWaktu: %02d-%02d-%04d %02d:%02d:%02d\nPesanan: %s\nTotal: Rp %d\n\n",
            customerName, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,
            tm.tm_hour, tm.tm_min, tm.tm_sec, orderDetails, totalPrice);
    fclose(file);
}