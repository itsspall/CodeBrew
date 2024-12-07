#include <stdio.h>
#include <string.h>
#include "admin.h"

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