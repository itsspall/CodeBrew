#include <stdio.h>
#include <string.h>
#include "customer.h"
#include <conio.h>

// Inisialisasi data pelanggan
Customer customers[MAX_CUSTOMERS] = {
    {"Salma", "1234", 100000},
    {"Hapiss", "abcd", 75000},
    {"Nopell", "5678", 200000}
};

int findCustomer(const char *name) {
    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        if (strcmp(customers[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void inputPassword(char *password) {
    char ch;
    int i = 0;

    printf("Masukkan password: ");
    while ((ch = getch()) != '\r') {
        if (ch == '\b' && i > 0) {
            printf("\b \b");
            i--;
        } else if (i < PASSWORD_LENGTH - 1 && ch != '\b') {
            printf("*");
            password[i++] = ch;
        }
    }
    password[i] = '\0';
    printf("\n");
}
