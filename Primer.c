#include <stdio.h>

// Fungsi prototipe
void welcomeScreen();
void displayMenu();
void takeOrder();
void payment();
void reserveTable();

int main() {
    int choice;
    do {
        welcomeScreen();
        printf("1. Lihat Menu\n");
        printf("2. Pesan Makanan\n");
        printf("3. Pembayaran\n");
        printf("4. Reservasi Meja\n");
        printf("5. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMenu();
                break;
            case 2:
                takeOrder();
                break;
            case 3:
                payment();
                break;
            case 4:
                reserveTable();
                break;
            case 5:
                printf("Terima kasih telah menggunakan CodeBrew!\n");
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
        }
    } while (choice != 5);

    return 0;
}

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

void takeOrder() {
    int menuItem, quantity;
    printf("Masukkan nomor menu yang ingin dipesan: ");
    scanf("%d", &menuItem);
    printf("Masukkan jumlah pesanan: ");
    scanf("%d", &quantity);
    printf("Pesanan telah dicatat!\n");
}

void payment() {
    int total = 100000; // Contoh total harga
    int paid;
    printf("Total yang harus dibayar: Rp %d\n", total);
    printf("Masukkan jumlah pembayaran: ");
    scanf("%d", &paid);

    if (paid >= total) {
        printf("Pembayaran sukses! Kembalian Anda: Rp %d\n", paid - total);
    } else {
        printf("Pembayaran gagal! Uang Anda kurang.\n");
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
