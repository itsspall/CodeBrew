#include <stdio.h>
#include <string.h>
#include "menu.h"

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
    printf("5. Lychee Tea   - Rp 14.000\t11. Salad            - Rp 15.000\n");
    printf("6. Ice Tea      - Rp 10.000\t12. Salad Buah       - Rp 15.000\n");
    printf("===========================\t=================================\n");
}