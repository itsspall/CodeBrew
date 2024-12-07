#ifndef MENU_H
#define MENU_H
#include <time.h>

#define TOTAL_TABLES 10
#define NAME_LENGTH 50

int takeOrder(char *orderDetails);
void displayOrderStatus(time_t orderTime); // Baru

#endif   