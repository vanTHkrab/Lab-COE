#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct account_in_bank account;
struct account_in_bank
{
    char balance[100];
    char credit_limit[100];
};

// struct account_in_bank
// {
//     char balance[100];
//     char credit_limit[100];
// }account[100];


typedef struct credit_bank credit;
struct credit_bank
{
    char creditID[10];
    char type[10];
    struct account_in_bank;
};

typedef struct data_bank bank;
struct data_bank
{
    char Customer_ID[100];
    char name[100];
    char lastname[100];
    struct credit_bank;
};

void customer_user(bank *customer)
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
        scanf(" %c", &account_number); 
    } while (account_number != '1' && account_number != '2'); 

    if (account_number == '1') {
        printf("Enter Account balance: ");
        scanf("%s", account->balance);
        strcpy(credit->type, "Savings"); 
        strcpy(account->credit_limit, "-");
    } 
    else if (account_number == '2') {
        printf("Enter Account balance: ");
        scanf("%s", account->balance);
        printf("Enter Credit limit: ");
        scanf("%s", account->credit_limit);
        strcpy(credit->type, "Daily Current"); 
    }
}

// void check_credit(){
//     FILE *cfp;
//     cfp = fopen("data_customer.txt", "r");
//     char ch;
//     while ((ch = fgetc(cfp)) != EOF)
//     {
//         printf("%c", ch);
//     }
// }

int main(){
    bank customer;
    account account;
    credit credit;
    int k;
    char ch;
    FILE *fp, *cfp;
    while (1){
        do{
        printf("\nWant create new account? (y/n) : ");
        scanf("%c", &ch);
        }while(ch != 'y' && ch != 'n');
        if (ch == 'n') break;
        customer_user(&customer);
        cfp = fopen("aa.txt", "a");
        fprintf(cfp, "Customer ID : %s\n", customer.Customer_ID);
        fprintf(cfp, "Customer name : %s\n", customer.name);
        fprintf(cfp, "Customer lastname : %s\n\n", customer.lastname);
        printf("No more than 10 account\n");
        do{
        printf("How many account do you have? : ");
        scanf("%d", &k);
        }while(k > 10 || k < 0);
        for (int l = 0; l < k; l++)
        {   
            printf("\naccount number %d\n", l + 1);
            create_credit(&credit, &account);
            fprintf(cfp, "Credit ID : %s\n", credit.creditID);
            fprintf(cfp, "Account type : %s\n", credit.type);
            fprintf(cfp, "Account balance : %s\n", account.balance);
            fprintf(cfp, "Credit limit : %s\n\n", account.credit_limit);
        }
        fprintf(cfp, "------------------------------------------\n\n");
    }
    fclose(cfp);
    cfp = fopen("aa.txt", "r");
    fp = fopen("data_customer.txt", "a");
    while ((ch = fgetc(cfp)) != EOF)
    {
        printf("%c", ch);
        fprintf(fp, "%c", ch);
    }
    fclose(fp);
    fclose(cfp);
    cfp = fopen("aa.txt", "w");
    cfp = NULL;
    fclose(cfp);
    return 0;
}