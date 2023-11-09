#include <stdio.h>
#include <string.h>

typedef struct account_in_bank account;
struct account_in_bank
{
    char balance[100];
    char credit_limit[100];
};

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
    } while (account_number - '0' != 1 && account_number - '0' != 2); 

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
    bank customer[100];
    account account[100];
    credit credit[100];
    int k, p = 0;
    int mk[100];
    char ch;
    FILE *fp;
    while (1){
        do{
        printf("\nWant create new account? (y/n) : ");
        scanf("%c", &ch);
        }while(ch != 'y' && ch != 'n');
        if (ch == 'n') break;
        customer_user(&customer[p]);
        printf("No more than 10 account\n");
        do{
        printf("How many account do you have? : ");
        scanf("%d", &k);
        }while(k > 10 || k < 0);
        for (int l = 0; l < k; l++)
        {   
            printf("\naccount number %d\n", l + 1);
            create_credit(&credit[l], &account[l]);
        }
        mk[p] = k;
        p++;
    }
    fp = fopen("data_customer.txt", "w");
    for (int i = 0; i < p; i++){
    printf("\nCustomer ID : %s\n", customer[i].Customer_ID);
    printf("Customer name : %s\n", customer[i].name);
    printf("Customer lastname : %s\n\n", customer[i].lastname);
    fprintf(fp, "Customer ID : %s\n", customer[i].Customer_ID);
    fprintf(fp, "Customer name : %s\n", customer[i].name);
    fprintf(fp, "Customer lastname : %s\n\n", customer[i].lastname);
    for (int m = 0; m < mk[i]; m++)
    {
        printf("Credit ID : %s\n", credit[m].creditID);
        printf("Account type : %s\n", credit[m].type);
        printf("Account balance : %s\n", account[m].balance);
        printf("Credit limit : %s\n", account[m].credit_limit);
        printf("\n");
        fprintf(fp, "Credit ID : %s\n", credit[m].creditID);
        fprintf(fp, "Account type : %s\n", credit[m].type);
        fprintf(fp, "Account balance : %s\n", account[m].balance);
        fprintf(fp, "Credit limit : %s\n\n", account[m].credit_limit);
    }
    printf("__________________________________________________________\n");
    }
    fclose(fp);
    return 0;
}