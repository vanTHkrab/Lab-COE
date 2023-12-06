#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct datacredit *idcredit;
struct datacredit {
    char id[10];
    char creditid[10];
    char type[5], pin[10];
    float limit;
    float balance;
    idcredit creditnext;
};

typedef struct datacustomer *idcustomer;
struct datacustomer {
    char id[10];
    char name[30];
    char lastname[30];
    int num;
    struct datacredit *credit;
    idcustomer next;
};

idcustomer createcustomer(idcustomer customer) {
    idcustomer newnode;
    idcustomer temp = customer;
    char id[10];
    printf("Enter Customer ID: ");
    scanf("%s", id);
    while (temp != NULL) {
        if (strcmp(temp->id, id) == 0) {
            printf("ID already exists\n");
            return customer;
        }
        temp = temp->next;
    }
    newnode = (idcustomer)malloc(sizeof(struct datacustomer));
    strcpy(newnode->id, id);
    printf("Enter Customer name: ");
    scanf("%s", newnode->name);
    printf("Enter Customer lastname: ");
    scanf("%s", newnode->lastname);
    newnode->num = 0;
    newnode->credit = NULL;
    newnode->next = customer;
    customer = newnode;
    return customer;
}

idcustomer createcredit(idcustomer customer) {
    idcredit newnode, tempcredit;
    idcustomer temp = customer;
    char id[10], cid[10];
    int k;
    if (temp->id == NULL){
        printf("No anyone customer\n");
        return customer;
    }
    printf("Enter Customer ID: ");
    scanf("%s", id);
    while (temp != NULL){
        if (strcmp(temp->id, id) == 0){
            printf("How many credit accounts do you want to create? (not more than 10): ");
            scanf("%d", &k);
            if (temp->num + k > 10){
                printf("You can't create more than 10 accounts\n");
                return customer;
            }
            for (int i = 0; i < k; i++){
                printf("Enter Credit ID: ");
                scanf("%s", cid);
                tempcredit = temp->credit;
                while (tempcredit != NULL){
                    if (strcmp(tempcredit->creditid, cid) == 0){
                        printf("Credit ID already exists\n");
                        return customer;
                    }
                    tempcredit = tempcredit->creditnext;
                }
                newnode = (idcredit)malloc(sizeof(struct datacredit));
                temp->num++;
                strcpy(newnode->id, id);
                strcpy(newnode->creditid, cid);
                do{
                    printf("Enter Credit Type ('1' saving, '2' Daily Current): ");
                    scanf("%s", newnode->type);
                }while(strcmp(newnode->type, "1") != 0 && strcmp(newnode->type, "2") != 0);
                do {
                    printf("Enter Credit PIN (length 6): ");
                    scanf("%s", newnode->pin);
                } while (strlen(newnode->pin) != 6);
                if (strcmp(newnode->type, "1") == 0){
                    printf("Enter Credit balance: ");
                    scanf("%f", &newnode->balance);
                }
                else if (strcmp(newnode->type, "2") == 0){
                    int l;
                    printf("Credit limit\n1. 10000\n2. 50000\n3. 100000\n4. 500000\n5. 1000000\n-> ");
                    scanf("%d", &l);
                    switch (l)
                    {
                    case 1:
                        newnode->limit = 10000;
                        break;
                    case 2:
                        newnode->limit = 50000;
                        break;
                    case 3:
                        newnode->limit = 100000;
                        break;
                    case 4:
                        newnode->limit = 500000;
                        break;
                    case 5:
                        newnode->limit = 1000000;
                        break;
                    default:
                        printf("Input 1-5\n");
                    }
                }
                newnode->creditnext = temp->credit;
                temp->credit = newnode;
                printf("____________________________________________________\n");
            }
            return customer;
        }
        temp = temp->next;
    }
    printf("Customer ID not found\n");
    return customer;
}

void money(idcustomer customer) {
    idcredit tempcredit;
    idcustomer temp = customer;
    char id[10], cid[10], pin[10];
    int t;
    float money;
    if (temp == NULL){
        printf("No anyone customer\n");
        return;
    }
    else if (temp->credit == NULL){
        printf("No anyone credit\n");
        return;
    }
    printf("Enter Customer ID: ");
    scanf("%s", id);
    while (temp != NULL){
        if (strcmp(temp->id, id) == 0){
            printf("Enter Credit ID: ");
            scanf("%s", cid);
            tempcredit = temp->credit;
            while (tempcredit != NULL){
                if (strcmp(tempcredit->creditid, cid) == 0){
                    int i = 0;
                    while (i < 3){
                        printf("Enter Credit PIN: ");
                        scanf("%s", pin);
                        if (strcmp(tempcredit->pin, pin) == 0){
                            break;
                        }
                        else if (i == 2){
                            printf("Wrong PIN 3 times\n");
                            return;
                        }
                        printf("Wrong PIN\n");
                        i++;
                    }
                    printf("1. Deposit\n2. Withdraw\n3. Exit\n-> ");
                    scanf("%d", &t);
                    switch (t)
                    {
                    case 1:
                        if (strcmp(tempcredit->type, "1") == 0){
                            printf("Your balance: %.2f\n", tempcredit->balance);
                            printf("Enter money you want deposit: ");
                            scanf("%f", &money);
                            tempcredit->balance += money;
                            printf("Deposit success, your balance now: %.2f\n", tempcredit->balance);
                            return;
                        }
                        else if (strcmp(tempcredit->type, "2") == 0){
                            printf("Your type cann't deposit money\n");
                            return;
                        }
                    case 2:
                        if (strcmp(tempcredit->type, "1") == 0){
                            printf("Your balance: %.2f\n", tempcredit->balance);
                            printf("Enter money: ");
                            scanf("%f", &money);
                            if (money > tempcredit->balance){
                                printf("Not enough money\n");
                                return;
                            }
                            tempcredit->balance -= money;
                            printf("Withdraw success, your balance now: %.2f\n", tempcredit->balance);
                            return;
                        }
                        else if (strcmp(tempcredit->type, "2") == 0){
                            printf("Your remaining credit limit: %.2f\n", tempcredit->limit);
                            printf("Enter money: ");
                            scanf("%f", &money);
                            if (money > tempcredit->limit){
                                printf("Not enough money\n");
                                return;
                            }
                            tempcredit->limit -= money;
                            printf("Withdraw success, your remaining credit limit: %.2f\n", tempcredit->limit);
                        }
                    case 3:
                        return;
                    default:
                        printf("Input 1-3\n");
                    }
                }
                tempcredit = tempcredit->creditnext;
            }
            printf("Credit ID not found\n");
        }
        temp = temp->next;
    }
    printf("Customer ID not found\n");
    return;
}

void display(idcustomer customer) {
    idcredit tempcredit;
    idcustomer temp = customer;
    char id[10], name[30], lastname[30];
    if (temp == NULL){
        printf("No anyone customer\n");
        return;
    }
    else if (temp->credit == NULL){
        printf("No anyone credit\n");
        return;
    }
    printf("Enter Customer ID: ");
    scanf("%s", id);
    while (temp != NULL){
        if (strcmp(temp->id, id) == 0){
            if (temp->num == 0){
                printf("No anyone credit\n");
                return;
            }
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter Lastname: ");
            scanf("%s", lastname);
            if (strcmp(temp->name, name) != 0 || strcmp(temp->lastname, lastname) != 0){
                printf("Name or Lastname not match\n");
                return;
            }
            tempcredit = temp->credit;
            while (tempcredit != NULL){
                printf("Customer ID: %s\n", tempcredit->id);
                printf("Credit ID: %s\n", tempcredit->creditid);
                printf("Credit Type: %s\n", tempcredit->type);
                printf("Credit Balance: %.2f\n", tempcredit->balance);
                if (strcmp(tempcredit->type, "2") == 0){
                    printf("Credit Limit: %.2f\n", tempcredit->limit);
                }
                return;
                tempcredit = tempcredit->creditnext;
            }
            printf("Credit ID not found\n");
        }
        temp = temp->next;
    }
    printf("Customer ID not found\n");
    return;
}

void displayall(idcustomer customer){
    idcredit tempcredit;
    idcustomer temp = customer;
    char admin[50];
    printf("Enter admin password: ");
    scanf("%s", admin);
    if (strcmp(admin, "12") != 0) {
        printf("You are not admin\n");
        return;
    }

    if (temp == NULL) {
        printf("No customers\n");
        return;
    }

    while (temp != NULL){
        printf("Customer ID: %s\n", temp->id);
        printf("Customer Name: %s\n", temp->name);
        printf("Customer Lastname: %s\n", temp->lastname);
        tempcredit = temp->credit;
        if (tempcredit == NULL) {
            printf("No credits for this customer\n");
            return;
        } else
        while (tempcredit != NULL){
            printf("Credit ID: %s\n", tempcredit->creditid);
            printf("Credit Type: %s\n", tempcredit->type);
            printf("Credit Balance: %.2f\n", tempcredit->balance);
            if (strcmp(tempcredit->type, "2") == 0){
                printf("Credit Limit: %.2f\n", tempcredit->limit);
            }
            printf("------------------------------------\n");
            tempcredit = tempcredit->creditnext;
        }
        printf("____________________________________________________\n");
        temp = temp->next;
    }
    return;
}

void testdisplay(idcustomer customer) {
    idcustomer temp = customer;
    while (temp != NULL) {
        printf("%s %s %s\n", temp->id, temp->name, temp->lastname);
        temp = temp->next;
    }
}

int main() {
    idcustomer customer = NULL;
    int k;
    printf("Welcome to Bank\n");
    while (1) {
        printf("1. Create Customer\n2. Create Credit (not more than 10 accounts)\n3. Deposit/Withdraw\n4. Display your account\n5. Display all(admin)\n6. Exit\n-> ");
        scanf("%d", &k);
        switch (k) {
            case 0:
                testdisplay(customer);
                break;
            case 1:
                customer = createcustomer(customer);
                break;
            case 2:
                customer = createcredit(customer);
                break;
            case 3:
                money(customer);
                break;
            case 4:
                display(customer);
                break;
            case 5:
                displayall(customer);
                break;
            case 6:
                free(customer);
                return 0;
            default:
                printf("Input 1-6\n");
        }
        printf("\n");
    }
    return 0;   
}