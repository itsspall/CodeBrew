#ifndef CUSTOMER_H
#define CUSTOMER_H

#define MAX_CUSTOMERS 10
#define NAME_LENGTH 50
#define PASSWORD_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char password[PASSWORD_LENGTH];
    int balance;
} Customer;

extern Customer customers[MAX_CUSTOMERS];

int findCustomer(const char *name);
void inputPassword(char *password);
void login();

#endif