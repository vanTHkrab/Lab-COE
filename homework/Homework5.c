// // Write a program to use commands to input customer information from the keyboard and store it.
// // Array variables of struct can then be written command to display data stored in an array variable of
// // // struct on the screen and design the program. Able to work the program as sub-functions
// Mass Bank would like to open deposit accounts for customers of the bank. The bank will collect information about each customer.
// People like this:
// - Customer ID
// - Customer name
// - Customer's last name
// - 10 designated deposit account numbers
// and store customer deposit account information as follows
// - Deposit account number
// - Account type (1 means savings account, 2 means current account)
// - Account deposit balance
// - Credit limit (current account only)
// Write a program that receiving customer information and customer deposit accounts, each customer can open an account
// You can deposit no more than 10 accounts per person. Then you can deposit-withdraw any number of deposit accounts of anyone and
// Report all customer information and the status of each deposit account.

#include <stdio.h>
#include <string.h>

typedef struct account_bank account;
struct account_bank
{
    char balance[100];
    char credit_limit[100];
};

typedef struct credit_bank credit;
struct credit_bank
{
    char creditID[10];
    char type[10];
    struct account_bank;
};

typedef struct data_bank bank;
struct data_bank
{
    char Customer_ID[100];
    char name[100];
    char lastname[100];
    struct credit_bank;
};

void customer_ID(bank *customer)
{
    printf("Enter Customer ID : ");
    scanf("%s", customer->Customer_ID);
    printf("Enter Customer name : ");
    scanf("%s", customer->name);
    printf("Enter Customer lastname : ");
    scanf("%s", customer->lastname);
}

void create_credit(credit *credit, account *account) {
    char account_number;
    printf("Enter Credit ID: ");
    scanf("%s", credit->creditID);

    do {
        printf("Enter Account type ('1' Savings, '2' Daily Current): ");
        scanf(" %c", &account_number); // Added a space before %c to consume the newline character.

    } while (account_number != '1' && account_number != '2'); // Changed || to &&

    if (account_number == '1') {
        printf("Enter Account balance: ");
        scanf("%s", account->balance);
        strcpy(credit->type, "Savings"); // Changed to a string
    } else if (account_number == '2') {
        printf("Enter Account balance: ");
        scanf("%s", account->balance);
        printf("Enter Credit limit: ");
        scanf("%s", account->credit_limit);
        strcpy(credit->type, "Daily Current"); // Changed to a string
    }
}

int main(){
    bank customer[100];
    account account[100];
    credit credit[100];
    int i, j, k, l, m;
    for (j = 0; j < i; j++)
    {
        customer_ID(&customer[j]);
        printf("Enter number of account : ");
        scanf("%d", &k);
        for (l = 0; l < k; l++)
        {
            create_credit(&credit[l], &account[l]);
        }
    }
    for (m = 0; m < i; m++)
    {
        printf("Customer ID : %s\n", customer[m].Customer_ID);
        printf("Customer name : %s\n", customer[m].name);
        printf("Customer lastname : %s\n", customer[m].lastname);
        printf("Credit ID : %s\n", credit[m].creditID);
        printf("Account type : %s\n", credit[m].type);
        printf("Account balance : %s\n", account[m].balance);
        printf("Credit limit : %s\n", account[m].credit_limit);
    }
    return 0;
}