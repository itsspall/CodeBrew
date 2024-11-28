#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Fungsi prototipe
void takeOrder();
void reserveTable();
void displayPayment();
void welcomeScreen();
void displayMenu();
void processCashPayment(int totalPrice);
void login();

int main() {
    int choice;
    login();
    do {
        welcomeScreen();
        printf("1. Pilih Menu\n");
        printf("2. Reservasi Meja\n");
        printf("3. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                takeOrder();
                break;
            case 2:
                reserveTable();
                break;
            case 3:
                printf("Terima kasih telah menggunakan CodeBrew!\n");
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (choice != 3);

    return 0;
}

// Fungsi-fungsi
void welcomeScreen() {
    printf("=================================\n");
    printf("     Selamat Datang di CodeBrew  \n");
    printf("=================================\n");
}

void displayMenu() {
    printf("========== Menu ==========\n");
    printf("1. Kopi Hitam   - Rp 15.000\n");
    printf("2. Latte        - Rp 20.000\n");
    printf("3. Cappuccino   - Rp 25.000\n");
    printf("4. Kue Brownies - Rp 10.000\n");
    printf("==========================\n");
}

void login() {
    char username[20], password[20];

    printf("=== Selamat Datang di CodeBrew ===\n");
    printf("Silakan login terlebih dahulu.\n");

    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "1234") == 0) {
        printf("Login berhasil!\n\n");
    } else {
        printf("Username atau password salah. Silakan coba lagi.\n\n");
        login();
    }
}

void takeOrder() {
    int menuItem, quantity;
    int totalPrice = 0;
    int continueOrder;

    do {
        displayMenu();
        printf("Masukkan nomor menu yang ingin dipesan (atau 0 untuk kembali): ");
        scanf("%d", &menuItem);

        if (menuItem == 0) {
            printf("Kembali ke menu utama...\n");
            return;
        }

        switch (menuItem) {
            case 1:
                printf("Anda memilih Kopi Hitam.\n");
                printf("Masukkan jumlah pesanan: ");
                scanf("%d", &quantity);
                totalPrice += quantity * 15000;
                break;
            case 2:
                printf("Anda memilih Latte.\n");
                printf("Masukkan jumlah pesanan: ");
                scanf("%d", &quantity);
                totalPrice += quantity * 20000;
                break;
            case 3:
                printf("Anda memilih Cappuccino.\n");
                printf("Masukkan jumlah pesanan: ");
                scanf("%d", &quantity);
                totalPrice += quantity * 25000;
                break;
            case 4:
                printf("Anda memilih Kue Brownies.\n");
                printf("Masukkan jumlah pesanan: ");
                scanf("%d", &quantity);
                totalPrice += quantity * 10000;
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }

        printf("Apakah Anda ingin memesan lagi? (1 untuk Ya, 0 untuk Tidak): ");
        scanf("%d", &continueOrder);
    } while (continueOrder == 1);

    printf("Total harga pesanan Anda: Rp %d\n", totalPrice);
    displayPayment();
}

void displayPayment(int totalPrice) {
    int paymentMethod, cash, change;
    printf("========= Pembayaran =========\n");
    printf("1. Cash\n");
    printf("2. Cashless\n");
    printf("==============================\n");
    printf("Pilih metode pembayaran: ");
    scanf("%d", &paymentMethod);

    switch (paymentMethod) {
        case 1:
            processCashPayment(totalPrice);
            break;
        case 2: {
            char cashlessCode[10];
            sprintf(cashlessCode, "CB%04d", rand() % 10000);
            printf("Kode pembayaran Anda: %s\n", cashlessCode);
            printf("Gunakan kode ini untuk pembayaran melalui aplikasi.\n");
            break;
        }
        default:
            printf("Metode pembayaran tidak valid.\n");
    }

    getchar();
}

void processCashPayment(int totalPrice) {
    int cash, change;

    printf("Silakan masukkan jumlah tunai: ");
    scanf("%d", &cash);

    if (cash < totalPrice) {
        printf("Uang yang Anda masukkan kurang Rp %d. Silakan ulangi pembayaran.\n", totalPrice - cash);
        processCashPayment(totalPrice);
    } else {
        change = cash - totalPrice;
        if (change > 0) {
            printf("Pembayaran berhasil. Kembalian Anda: Rp %d\n", change);
        } else {
            printf("Pembayaran berhasil. Tidak ada kembalian.\n");
        }
    }
}

void reserveTable() {
    int tableNumber;
    printf("Masukkan nomor meja yang ingin dipesan (1-10): ");
    scanf("%d", &tableNumber);
    if (tableNumber >= 1 && tableNumber <= 10) {
        printf("Meja %d berhasil dipesan!\n", tableNumber);
    } else {
        printf("Nomor meja tidak valid.\n");
    }
}
