#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define TOTAL_TABLES 10
#define NAME_LENGTH 50

// Deklarasi Fungsi
void displayTables(char tables[][NAME_LENGTH]);
void makeReservation(char tables[][NAME_LENGTH]);
int takeOrder(char *orderDetails);
void displayPayment(int totalPrice, const char *customerName, const char *orderDetails);
void welcomeScreen();
void displayMenu();
void processCashPayment(int totalPrice, const char *customerName, const char *orderDetails);
void login();
void saveTransaction(const char *customerName, const char *orderDetails, int totalPrice);
void rekapitulasi();

int main() {
    int choice, totalPrice;
    char orderDetails[500], customerName[50];
    char tables[TOTAL_TABLES][NAME_LENGTH] = {""};

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
                displayTables(tables);
                makeReservation(tables);
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

// Fungsi login
void login() {
    char username[20], password[20];

    printf("========== Silakan Login ==========\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "1234") == 0) {
        printf("Login berhasil!\n\n");
    } else {
        printf("Username atau password salah. Silakan coba lagi.\n");
        login();
    }
}

// Fungsi untuk menampilkan layar utama
void welcomeScreen() {
    printf("==========================\n");
    printf("   Selamat Datang di CodeBrew  \n");
    printf("==========================\n");
}

// Fungsi untuk menampilkan menu
void displayMenu() {
    printf("======= Menu Minuman ======\t========= Menu Makanan =========\n");
    printf("1. Kopi Hitam   - Rp 15.000\t7.  Nasi Goreng      - Rp 30.000\n");
    printf("2. Latte        - Rp 20.000\t8.  Mie Bangladesh   - Rp 25.000\n");
    printf("3. Cappuccino   - Rp 25.000\t9.  Sandwich         - Rp 20.000\n");
    printf("4. Lemon Tea    - Rp 12.000\t10. Macaroni         - Rp 15.000\n");
    printf("5. Lychee Tea   - Rp 14.000\t11. Salad Buah       - Rp 15.000\n");
    printf("6. Ice Tea      - Rp 10.000\t12. Salad Buah       - Rp 15.000\n");
    printf("===========================\t=================================\n");
}

// Fungsi untuk memesan menu
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
        printf("Gunakan kode pembayaran untuk transaksi.\n");
        saveTransaction(customerName, orderDetails, totalPrice);
    } else {
        printf("Metode pembayaran tidak valid.\n");
    }
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

// Fungsi melihat rekapitulasi
void rekapitulasi() {
    FILE *file = fopen("rekapitulasi.txt", "r");
    if (!file) {
        printf("Belum ada rekapitulasi.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    fclose(file);
}

<<<<<<< HEAD
// Fungsi untuk menampilkan status meja
=======
// Fungsi reservasi meja
>>>>>>> 3542191f94ab230876f7a86c74ab8641d5926528
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

// Fungsi untuk membuat reservasi meja
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
