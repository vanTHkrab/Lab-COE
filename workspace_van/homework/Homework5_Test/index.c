#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct datacredit *idcredit;

struct datacredit {
    char id[10];
    char creditid[10];
    char type[15], pin[10];
    int num;
    float limit;
    float balance;
};

typedef struct datacustomer *idcustomer;

struct datacustomer {
    char id[10];
    char name[30];
    char lastname[30];
    struct datacredit *credit;
};

void createcustomer(idcustomer customer) {
    printf("Enter Customer ID: ");
    scanf("%s", customer->id);
    printf("Enter Customer name: ");
    scanf("%s", customer->name);
    printf("Enter Customer lastname: ");
    scanf("%s", customer->lastname);
}

void createcredit(idcustomer customer) {
    int type;
    char creditid[10], id[10];

    printf("Enter Customer ID: ");
    scanf("%s", id);

    while (strcmp(id, customer->id) != 0) {
        printf("Customer ID not found. Please try again.\n");
    }

    if (customer->credit == NULL) {
        customer->credit = (idcredit)malloc(sizeof(struct datacredit));
        customer->credit->num = 0;
    }

    idcredit credit = customer->credit;
    printf("Enter Credit ID: ");
    scanf("%s", creditid);

    for (int i = 0; i < credit->num; i++) {
        if (strcmp(creditid, credit[i].creditid) == 0) {
            printf("Credit ID already exists. Please try again.\n");
            return;
        }
    }

    credit->num++;

    if (credit->num > 10) {
        printf("Cannot create more than 10 accounts.\n");
        return;
    }
    strcpy(credit[credit->num - 1].id, customer->id);
    strcpy(credit[credit->num - 1].creditid, creditid);

    do {
        printf("Enter Account type ('1' Savings, '2' Daily Current): ");
        scanf("%d", &type);
    } while (type != 1 && type != 2);

    if (type == 1) {
        printf("Enter Credit balance: ");
        scanf("%f", &credit[credit->num - 1].balance);
        credit[credit->num - 1].limit = 0;
        strcpy(credit[credit->num - 1].type, "Savings");
        printf("Credit limit: -\n");
        printf("Enter PIN: ");
        scanf("%s", credit[credit->num - 1].pin);
    }

    if (type == 2) {
        printf("Enter Credit limit: ");
        scanf("%f", &credit[credit->num - 1].limit);
        printf("Enter Credit balance: ");
        scanf("%f", &credit[credit->num - 1].balance);
        strcpy(credit[credit->num - 1].type, "Daily Current");
        printf("Enter PIN: ");
        scanf("%s", credit[credit->num - 1].pin);
    }
}

void money(idcustomer customer) {
    float money;
    int t;
    char creditid[10], id[11];
    if (customer->credit == NULL) {
        printf("No credit information available. Please create credit first.\n");
        return;
    }
    printf("Enter Customer ID: ");
    scanf("%s", id);
    while (strcmp(id, customer->id) != 0) {
        printf("Customer ID not found. Please try again.\n");
    }
    idcredit credit = customer->credit;
    printf("Enter Credit ID: ");
    scanf("%s", creditid);
    printf("Enter PIN: ");
    scanf("%s", id);
    for (int i = 0; i < credit->num; i++) {
        if (strcmp(creditid, credit[i].creditid) == 0) {
            if (strcmp(id, credit[i].pin) == 0)
                break;
            else {
                printf("PIN incorrect. Please try again.\n");
                return;
            }
        }
    }
    int i;
    for (i = 0; i < credit->num; i++) {
        if (strcmp(creditid, credit[i].creditid) == 0)
            break;
    }

    if (i == credit->num) {
        printf("Credit ID not found. Please try again.\n");
        return;
    }
    do{ 
    printf("1. Deposit\n2. Withdraw\n3. Exit\n->");
    scanf("%d", &t);
    if (t == 3) return;
    }while(t != 1 && t != 2);
    if (t == 1) {
        printf("Enter money: ");
        scanf("%f", &money);
        credit[i].balance += money;
        printf("Balance: %.2f\n", credit[i].balance);
    }
    else if (t == 2) {
        printf("Enter money: ");
        scanf("%f", &money);
        credit[i].balance -= money;
        printf("Balance: %.2f\n", credit[i].balance);
    }
}

void display(idcustomer customer)
{
    int i;
    if (customer->credit == NULL) {
        printf("No credit information available. Please create credit first.\n");
        return;
    }
    printf("Customer ID: %s\n", customer->id);
    printf("Customer name: %s\n", customer->name);
    printf("Customer lastname: %s\n", customer->lastname);
    idcredit credit = customer->credit;
    for (i = 0; i < credit->num; i++) {
        printf("Credit ID: %s\n", credit[i].creditid);
        printf("Credit type: %s\n", credit[i].type);
        printf("Credit balance: %.2f\n", credit[i].balance);
        printf("Credit limit: %.2f\n", credit[i].limit);
        printf("Credit PIN: %s\n", credit[i].pin);
        if (i < credit->num - 1) {
            printf("\n");
        }
    }
    printf("-------------------------------\n");
}

int main() {
    idcustomer customer;
    customer = (idcustomer)malloc(sizeof(struct datacustomer));
    customer->credit = NULL;
    int k;
    while (1) {
        printf("1. Create Customer\n2. Create Credit (not more than 10 accounts)\n3. Deposit/Withdraw\n4. Display\n5. Exit\n-> ");
        scanf("%d", &k);
        switch (k) {
        case 1:
            createcustomer(customer);
            break;
        case 2:
            createcredit(customer);
            break;
        case 3:
            money(customer);
            break;
        case 4:
            display(customer);
            break;
        case 5:
            free(customer->credit);
            free(customer);
            exit(0);
            break;
        }
        printf("\n");
    }
    return 0;
}
