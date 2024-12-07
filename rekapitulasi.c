#include <stdio.h>
#include <string.h>
#include "rekapitulasi.h"

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