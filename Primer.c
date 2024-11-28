#include <stdio.h>
#include <string.h>

// Fungsi prototipe
void welcomeScreen();
void displayMenu();
void takeOrder();
void reserveTable();
void displayPayment();
void displayTables();
void cancelReservation();
void makeReservation();
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

    int paymentChoice;
    printf("Pilih metode pembayaran: ");
    scanf("%d", &paymentChoice);

    switch (paymentChoice) {
        case 1:
            processCashPayment(totalPrice);
            break;
        case 2:
            printf("Pembayaran berhasil menggunakan metode cashless.\n");
            break;
        default:
            printf("Metode pembayaran tidak valid. Kembali ke menu utama.\n");
    }
}

void displayPayment() {
    printf("========= Pembayaran =========\n");
    printf("1. Cash\n");
    printf("2. Cashless\n");
    printf("==============================\n");
}

void processCashPayment(int totalPrice) {
    int cash, change;

    printf("Silakan masukkan jumlah tunai: ");
    scanf("%d", &cash);

    if (cash < totalPrice) {
        printf("Uang yang Anda masukkan kurang Rp %d. Silakan ulangi pembayaran.\n", totalPrice - cash);
        
        (totalPrice);
    } else {
        change = cash - totalPrice;
        if (change > 0) {
            printf("Pembayaran berhasil. Kembalian Anda: Rp %d\n", change);
        } else {
            printf("Pembayaran berhasil. Tidak ada kembalian.\n");
        }
        void displayTables(const vector<string>& tables) {
    cout << "Daftar Meja:\n";
    for (size_t i = 0; i < tables.size(); ++i) {
        cout << "Meja " << i + 1 << ": " 
             << (tables[i].empty() ? "Tersedia" : "Dipesan oleh " + tables[i]) 
             << endl;
    }
}


void makeReservation(vector<string>& tables) {
    int tableNumber;
    string customerName;

    cout << "Masukkan nomor meja yang ingin dipesan: ";
    cin >> tableNumber;


    if (tableNumber < 1 || tableNumber > tables.size()) {
        cout << "Nomor meja tidak valid.\n";
        return;
    }

    
    if (!tables[tableNumber - 1].empty()) {
        cout << "Meja " << tableNumber << " sudah dipesan oleh " << tables[tableNumber - 1] << ".\n";
        return;
    }

    cin.ignore(); 
    cout << "Masukkan nama pelanggan: ";
    getline(cin, customerName);

    
    tables[tableNumber - 1] = customerName;
    cout << "Reservasi berhasil untuk Meja " << tableNumber << ".\n";
}


void cancelReservation(vector<string>& tables) {
    int tableNumber;

    cout << "Masukkan nomor meja yang ingin dibatalkan: ";
    cin >> tableNumber;

    
    if (tableNumber < 1 || tableNumber > tables.size()) {
        cout << "Nomor meja tidak valid.\n";
        return;
    }

    
    if (tables[tableNumber - 1].empty()) {
        cout << "Meja " << tableNumber << " belum dipesan.\n";
        return;
    }

    
    tables[tableNumber - 1].clear();
    cout << "Reservasi untuk Meja " << tableNumber << " berhasil dibatalkan.\n";
}


int main() {
    const int numberOfTables = 10; 
    vector<string> tables(numberOfTables, ""); 

    while (true) {
        cout << "\n=== Sistem Reservasi Meja ===\n";
        cout << "1. Lihat daftar meja\n";
        cout << "2. Buat reservasi\n";
        cout << "3. Batalkan reservasi\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                displayTables(tables);
                break;
            case 2:
                makeReservation(tables);
                break;
            case 3:
                cancelReservation(tables);
                break;
            case 4:
                cout << "Terima kasih telah menggunakan sistem reservasi.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    }

    return 0;
}
    }
}
