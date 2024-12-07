#ifndef RESERVATION_H
#define RESERVATION_H

#define TOTAL_TABLES 10
#define NAME_LENGTH 50

void displayTables(char tables[][NAME_LENGTH], int startTimes[], int endTimes[], int totalTables);
void makeReservation(char tables[][NAME_LENGTH], int startTimes[], int endTimes[], int totalTables);

#endif
