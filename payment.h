#ifndef PAYMENT_H
#define PAYMENT_H

#define NAME_LENGTH 50
#define PASSWORD_LENGTH 20

typedef struct 
{
    char name[NAME_LENGTH];
    char password[PASSWORD_LENGTH];
} Account;


void displayPayment(int totalPrice, const char *customerName, const char *orderDetails);
void processCashlessPayment(int totalPrice, const char *orderDetails);
void processCashPayment(int totalPrice, const char *payment, const char *customerName, const char *orderDetails);
void saveTransaction(const char *customerName, const char *orderDetails, int totalPrice, const char *payment, const char *accountName);

#endif