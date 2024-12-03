#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TOTAL_TABLES 10
#define NAME_LENGTH 50

// Fungsi prototipe
void welcomeScreen();
void displayMenu();
int takeOrder();
void displayPayment(int totalPrice);
void processCashPayment(int totalPrice);
void login();
void displayTables(char tables[][NAME_LENGTH]);
void makeReservation(char tables[][NAME_LENGTH]);

int main() {
    char tables[TOTAL_TABLES][NAME_LENGTH] = {""}; // Inisialisasi semua meja kosong
    int choice, totalPrice = 0;

    login();

    do {
        welcomeScreen();
        printf("1. Pilih Menu Dulu nih\n");
        printf("2. Reservasi Meja lu\n");
        printf("3. Keluar??\n");
        printf("Pilih opsi: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                totalPrice = takeOrder();
                displayPayment(totalPrice);
                break;
            case 2:
                makeReservation(tables);
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

void welcomeScreen() {
    printf("\n===================================\n");
    printf("     Selamat Datang di CodeBrew  \n");
    printf("===================================\n");
}

void displayMenu() {
    printf("\n========== Menu ==========\n");
    printf("Makanan:\n");
    printf("1. Cookies         - Rp 10000\n");
    printf("2. Noodle          - Rp 15000\n");
    printf("3. Cup Cake        - Rp 15000\n");
    printf("4. Pancake         - Rp 15000\n");
    printf("5. Nasi Goreng     - Rp 15000\n");
    printf("\nMinuman:\n");
    printf("6. Latte           - Rp 20000\n");
    printf("7. Teh Manis       - Rp 10000\n");
    printf("8. Kopi Hitam      - Rp 15000\n");
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

int takeOrder() {
    int menuItem, quantity, totalPrice = 0, continueOrder;

    do {
        displayMenu();
        printf("Masukkan nomor menu yang ingin dipesan (atau 0 untuk kembali): ");
        scanf("%d", &menuItem);

        if (menuItem == 0) {
            printf("Kembali ke menu utama...\n");
            return totalPrice;
        }

        printf("Lu mau pesen berapa nih : ");
        scanf("%d", &quantity);

        switch (menuItem) {
            case 1:
                totalPrice += quantity * 10000;
                break;
            case 2:
                totalPrice += quantity * 15000;
                break;
            case 3:
                totalPrice += quantity * 15000;
                break;
            case 4:
                totalPrice += quantity * 15000;
                break;
            case 5:
                totalPrice += quantity * 15000;
                break;
            case 6:
                totalPrice += quantity * 20000;
                break;
            case 7:
                totalPrice += quantity * 10000;
                break;
            case 8:
                totalPrice += quantity * 15000;
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }

        printf("MAu pesen lagi? (1 untuk Ya, 0 untuk Tidak): ");
        scanf("%d", &continueOrder);
    } while (continueOrder == 1);

    return totalPrice;
}

void displayPayment(int totalPrice) {
    int paymentMethod;
    printf("\n========= Pembayaran =========\n");
    printf("Total harga pesanan Anda: Rp %d\n", totalPrice);
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
            printf("Kode pembayaran Anda: %s\nGunakan kode ini untuk pembayaran melalui aplikasi.\n", cashlessCode);
            break;
        }
        default:
            printf("Metode pembayaran tidak valid.\n");
    }
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
        printf("Pembayaran berhasil. Kembalian Anda: Rp %d\n", change);
    }
}

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

    printf("Masukin nomor meja lu yang mau dipesan (1-%d): ", TOTAL_TABLES);
    scanf("%d", &tableNumber);

    if (tableNumber < 1 || tableNumber > TOTAL_TABLES) {
        printf("Nomor meja tidak valid.\n");
        return;
    }

    if (strlen(tables[tableNumber - 1]) != 0) {
        printf(" Sayang Banget Meja %d sudah dipesan sama %s. Lu telat sih\n", tableNumber, tables[tableNumber - 1]);
        return;
    }

    printf("Masukin Nama lu Nih ");
    getchar();
    fgets(customerName, NAME_LENGTH, stdin);
    customerName[strcspn(customerName, "\n")] = '\0';

    strcpy(tables[tableNumber - 1], customerName);
    printf("Reservasi berhasil untuk Meja %d atas nama %s.\n", tableNumber, customerName);

