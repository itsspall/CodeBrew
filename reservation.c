#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "reservation.h"

void displayTables(char tables[][NAME_LENGTH], int startTimes[], int endTimes[], int totalTables) {
    printf("\nDaftar Meja:\n");

    time_t now = time(NULL);
    struct tm *currentTime = localtime(&now);
    int currentMinutes = currentTime->tm_hour * 60 + currentTime->tm_min;

    for (int i = 0; i < totalTables; i++) {
        if (strlen(tables[i]) == 0) {
            printf("Meja %d: Tersedia\n", i + 1);
        } else if (currentMinutes < startTimes[i]) {
            printf("Meja %d: Sudah dipesan oleh %s (Mulai: %02d:%02d, Selesai: %02d:%02d)\n",
                   i + 1, tables[i], startTimes[i] / 60, startTimes[i] % 60, endTimes[i] / 60, endTimes[i] % 60);
        } else if (currentMinutes >= startTimes[i] && currentMinutes < endTimes[i]) {
            int remainingTime = endTimes[i] - currentMinutes;
            printf("Meja %d: Sedang dipesan oleh %s (Sisa Waktu: %d menit, Selesai: %02d:%02d)\n",
                   i + 1, tables[i], remainingTime, endTimes[i] / 60, endTimes[i] % 60);
        } else {
            printf("Meja %d: Tersedia (Reservasi sebelumnya selesai)\n", i + 1);
            strcpy(tables[i], "");
            startTimes[i] = 0;
            endTimes[i] = 0;
        }
    }
}


void makeReservation(char tables[][NAME_LENGTH], int startTimes[], int endTimes[], int totalTables) {
    int tableNumber, startHour, startMinute, endHour, endMinute, startTime, endTime;
    char customerName[NAME_LENGTH];

    printf("Masukkan nomor meja yang ingin dipesan (1-%d): \n", totalTables);
    printf("Ketik 0 untuk kembali ke Menu: \n");
    scanf("%d", &tableNumber);

    if (tableNumber == 0) {
        printf("Kembali ke menu utama.\n");
        return;
    }

    if (tableNumber < 1 || tableNumber > totalTables) {
        printf("Nomor meja tidak valid. Silakan coba lagi.\n");
        return;
    }

    if (strlen(tables[tableNumber - 1]) != 0) {
        printf("Meja %d sudah dipesan oleh %s.\n", tableNumber, tables[tableNumber - 1]);
        return;
    }

    printf("Masukkan nama pelanggan: \n");
    getchar();
    fgets(customerName, NAME_LENGTH, stdin);
    customerName[strcspn(customerName, "\n")] = '\0';

    printf("Masukkan waktu mulai reservasi (format 24-jam, HH MM): ");
    scanf("%d %d", &startHour, &startMinute);

    printf("Masukkan waktu selesai reservasi (format 24-jam, HH MM): ");
    scanf("%d %d", &endHour, &endMinute);

    // Konversi waktu ke menit untuk validasi
    startTime = startHour * 60 + startMinute;
    endTime = endHour * 60 + endMinute;

    time_t now = time(NULL);
    struct tm *currentTime = localtime(&now);
    int currentMinutes = currentTime->tm_hour * 60 + currentTime->tm_min;

    if (startTime <= currentMinutes) {
        printf("Waktu mulai reservasi tidak valid (harus di masa depan). Silakan coba lagi.\n");
        return;
    }

    if (endTime <= startTime) {
        printf("Waktu selesai harus lebih besar dari waktu mulai. Silakan coba lagi.\n");
        return;
    }

    strcpy(tables[tableNumber - 1], customerName);
    startTimes[tableNumber - 1] = startTime;
    endTimes[tableNumber - 1] = endTime;

    printf("Reservasi berhasil untuk Meja %d atas nama %s dari pukul %02d:%02d hingga %02d:%02d.\n",
           tableNumber, customerName, startHour, startMinute, endHour, endMinute);
}
