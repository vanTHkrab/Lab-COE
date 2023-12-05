#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct datacredit *idcredit;
struct datacredit {
    char id[10];
    char creditid[10];
    char type[15], pin[10];
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
    char id[10], name[30], lastname[30];
    printf("Enter Customer ID: ");
    scanf("%s", id);
    while (temp != NULL) {
        if (strcmp(temp->id, id) == 0) {
            printf("ID already exists\n");
            return customer;
        }
        temp = temp->next;
    }
    printf("Enter Customer name: ");
    scanf("%s", name);
    printf("Enter Customer lastname: ");
    scanf("%s", lastname);
    newnode = (idcustomer)malloc(sizeof(struct datacustomer));
    strcpy(newnode->id, id);
    strcpy(newnode->name, name);
    strcpy(newnode->lastname, lastname);
    newnode->num = 0;
    newnode->credit = NULL;
    newnode->next = customer;
    customer = newnode;
    return customer;
}

idcredit createcredit(idcustomer customer, idcredit credit) {
    char id[10], type[15], pin[10], cid[10];
    idcredit newnode = credit;
    idcustomer temp = customer;
    if (temp->id == NULL) {
        printf("No customer\n");
        return credit;
    }
    printf("Enter Customer ID: ");
    scanf("%s", id);
    while (strcpy(temp->id, id) != 0) {
        if (temp->next == NULL) {
            printf("No customer\n");
            return credit;
        }
        temp = temp->next;
    }
    while (temp != NULL) {
        if (strcmp(temp->id, id) == 0) {
            printf("Enter Credit ID: ");
            scanf("%s", newnode->creditid);
            if (temp->num >= 10) {
                printf("Cannot create more than 10 accounts\n");
                return credit;
            }
            newnode = (idcredit)malloc(sizeof(struct datacredit));
        }
        temp = temp->next;
    }
}


void money(idcustomer customer) {

}

void display(idcustomer customer)
{

}

void testdisplay(idcustomer customer)
{
    idcustomer temp = customer;
    while (temp != NULL) {
        printf("%s %s %s\n", temp->id, temp->name, temp->lastname);
        temp = temp->next;
    }
}

int main() {
    idcustomer customer = NULL;
    idcredit credit = NULL;
    int k;
    while (1) {
        printf("1. Create Customer\n2. Create Credit (not more than 10 accounts)\n3. Deposit/Withdraw\n4. Display\n5. Exit\n-> ");
        scanf("%d", &k);
        switch (k) {
        case 0:
            testdisplay(customer);
            break;
        case 1:
            customer = createcustomer(customer);
            break;
        case 2:
            credit = createcredit(customer, credit);
            break;
        }
        printf("\n");
    }
    return 0;
}
