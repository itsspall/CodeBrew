#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Variabel global untuk menyimpan status pesanan
char orderStatus[100] = "Belum ada pesanan.";

// Fungsi untuk memperbarui status pesanan
void updateOrderStatus(const char *status) {
    strncpy(orderStatus, status, sizeof(orderStatus) - 1);
    orderStatus[sizeof(orderStatus) - 1] = '\0'; // Pastikan null-terminated
}


// Fungsi untuk menampilkan status pesanan
void trackOrder() {
    printf("===== Status Pesanan =====\n");
    printf("Status: %s\n", orderStatus);
    printf("===========================\n");
}


// Deklarasi Fungsi
void reserveTable();
int takeOrder(char *orderDetails);
void displayPayment(int totalPrice, const char *customerName, const char *orderDetails);
void welcomeScreen();
void displayMenu();
void processCashPayment(int totalPrice, const char *customerName, const char *orderDetails);
void login();
void saveTransaction(const char *customerName, const char *orderDetails, int totalPrice);
void rekapitulasi();

int main() {
    int choice, Adminchoice, totalPrice;
    char orderDetails[500], customerName[50];

    do {
             //Pilihan User
        printf("============== Pilihan User =============\n");
        printf("1. Admin\n");
        printf("2. Pelanggan\n");
        printf("3. Keluar\n");
        printf("Pilih Opsi: ");
        scanf("%d", &choice);

        if (choice == 1){
            login();
            do{
                 welcomeScreen();
                printf("1. Pilih Menu\n");
                printf("2. Reservasi Meja\n");
                printf("3. Rekapitulasi\n");
                printf("4. Keluar\n");
                printf("Pilih opsi: ");
                scanf("%d", &Adminchoice);

                switch (Adminchoice){
                    case 1:
                        printf("Masukkan nama pelanggan: ");
                        scanf(" %[^\n]", customerName);
                        totalPrice = takeOrder(orderDetails);
                        displayPayment(totalPrice, customerName, orderDetails);
                        break;
                    case 2:
                        reserveTable();
                        break;
                    case 3:
                        rekapitulasi();
                        break;
                    case 4:
                        printf("Keluar dari Menu Admin\n");
                        break;
                    default:
                        printf("Pilihan tidak valid. Coba lagi.\n");
                }
            } while (Adminchoice != 4);
        }else if (choice == 2) {
            int customerChoice;
        do {
            printf("=== Menu Pelanggan ===\n");
            printf("1. Lihat Menu\n");
            printf("2. Lacak Pesanan\n");
            printf("3. Keluar\n");
            printf("Pilih opsi: ");
            scanf("%d", &customerChoice);
            if (customerChoice == 1) {
                displayMenu();
            } else if (customerChoice == 2) {
                trackOrder();
            } else if (customerChoice == 3) {
                printf("Terima kasih telah menggunakan layanan kami.\n");
            } else {
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
            }
        } while (customerChoice != 3);  
    } else if (choice == 3) {
        printf("Terima kasih telah menggunakan sistem kami.\n");
    } else {
        printf("Pilihan tidak valid. Silakan coba lagi.\n");
    }
    }while (choice != 3);
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
    printf("4. Lemon Tea    - Rp 12.000\t10. Macaroni         - Rp 16.000\n");
    printf("5. Lychee Tea   - Rp 14.000\t11. Ice Cream        - Rp 18.000\n");
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
                sprintf(orderDetails + strlen(orderDetails), "Kopi Hitam x%d, ", quantity);
                totalPrice += quantity * 15000;
                break;
            case 2:
                sprintf(orderDetails + strlen(orderDetails), "Latte x%d, ", quantity);
                totalPrice += quantity * 20000;
                break;
            case 3:
                sprintf(orderDetails + strlen(orderDetails), "Cappuccino x%d, ", quantity);
                totalPrice += quantity * 25000;
                break;
            case 4:
                sprintf(orderDetails + strlen(orderDetails), "Lemon Tea x%d, ", quantity);
                totalPrice += quantity * 12000;
                break;
            case 5:
                sprintf(orderDetails + strlen(orderDetails), "Lychee Tea x%d, ", quantity);
                totalPrice += quantity * 14000;
                break;
            case 6:
                sprintf(orderDetails + strlen(orderDetails), "Ice Tea x%d, ", quantity);
                totalPrice += quantity * 10000;
                break;
            case 7:
                sprintf(orderDetails + strlen(orderDetails), "Nasi Goreng x%d, ", quantity);
                totalPrice += quantity * 30000;
                break;
            case 8:
                sprintf(orderDetails + strlen(orderDetails), "Mie Bangladesh x%d, ", quantity);
                totalPrice += quantity * 25000;
                break;
            case 9:
                sprintf(orderDetails + strlen(orderDetails), "Sandwich x%d, ", quantity);
                totalPrice += quantity * 20000;
                break;
            case 10:
                sprintf(orderDetails + strlen(orderDetails), "Macaroni x%d, ", quantity);
                totalPrice += quantity * 16000;
                break;
            case 11:
                sprintf(orderDetails + strlen(orderDetails), "Ice Cream x%d, ", quantity);
                totalPrice += quantity * 18000;
                break;
            case 12:
                sprintf(orderDetails + strlen(orderDetails), "Salad Buah x%d, ", quantity);
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

    updateOrderStatus("Pesanan sedang diproses.");
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
        updateOrderStatus("Pesanan telah selesai dan siap disajikan."); 
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
        updateOrderStatus("Pesanan telah selesai dan siap disajikan.");
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

// Fungsi reservasi meja
// Fungsi reservasi meja
void reserveTable() {
    char tableStatus[10][10] = {"Kosong", "Kosong", "Kosong", "Kosong", "Kosong", 
                                "Kosong", "Kosong", "Kosong", "Kosong", "Kosong"};
    char customerName[50];
    char tableNumber[3];
    int hour, minute, countdownTime;

    printf("===== Reservasi Meja =====\n");
    printf("Masukkan nama pelanggan: ");
    scanf(" %[^\n]", customerName);

    // Tampilkan status meja
    printf("\nStatus Meja:\n");
    for (int i = 0; i < 10; i++) {
        printf("Meja A%d: %s\n", i + 1, tableStatus[i]);
    }

    printf("\nMasukkan nomor meja yang ingin dipesan (A1-A10): ");
    scanf("%s", tableNumber);

    // Validasi nomor meja
    int tableIndex = atoi(&tableNumber[1]) - 1;
    if (tableNumber[0] != 'A' || tableIndex < 0 || tableIndex >= 10) {
        printf("Nomor meja tidak valid. Silakan coba lagi.\n");
        return;
    }

    if (strcmp(tableStatus[tableIndex], "Kosong") != 0) {
        printf("Meja %s sudah dipesan. Silakan pilih meja lain.\n", tableNumber);
        return;
    }

    printf("Masukkan jam booking (format 24-jam, HH MM): ");
    scanf("%d %d", &hour, &minute);

    printf("Meja %s berhasil dipesan untuk %02d:%02d.\n", tableNumber, hour, minute);
    strncpy(tableStatus[tableIndex], "Dipesan", sizeof(tableStatus[tableIndex]));

    // Hitungan mundur hingga waktu booking
    printf("\nHitungan Mundur:\n");
    countdownTime = (hour * 60 + minute) - (localtime(&(time_t){time(NULL)})->tm_hour * 60 +
                                            localtime(&(time_t){time(NULL)})->tm_min);
    if (countdownTime <= 0) {
        printf("Waktu booking sudah lewat. Silakan pilih waktu yang valid.\n");
        strncpy(tableStatus[tableIndex], "Kosong", sizeof(tableStatus[tableIndex]));
        return;
    }

    while (countdownTime > 0) {
        printf("Sisa waktu: %d menit\n", countdownTime);
        countdownTime--;
        sleep(60); // Tunggu 1 menit
    }

    printf("Waktu reservasi meja %s telah tiba!\n", tableNumber);

    // Perbarui status meja
    strncpy(tableStatus[tableIndex], "Kosong", sizeof(tableStatus[tableIndex]));
}
