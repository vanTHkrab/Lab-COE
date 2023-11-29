#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data_member *datamember;
struct data_member {
    char customer_ID[10];
    char name[30];
    char lastname[30];
    datamember next;
};

typedef struct data_credit *datacredit;
struct data_credit {
    int n;
    char creditID[15];
    char type[15];
    float balance;
    float credit_limit;
    datacredit next;
};


datamember newmember(datamember customer){
    datamember newnode = customer;
    char id[10];
    printf("Enter customer ID: ");
    scanf("%s", id);
    while(newnode != NULL){
        if(strcmp(newnode->customer_ID, id) == 0){
            printf("This customer ID is already exist.\n\n");
            return customer;
        }
        newnode = newnode->next;
    }
    newnode = (datamember)malloc(sizeof(struct data_member));
    strcpy(newnode->customer_ID, id);
    printf("Enter name: ");
    scanf("%s", newnode->name);
    printf("Enter lastname: ");
    scanf("%s", newnode->lastname);
    newnode->next = customer;
    customer = newnode;
    return customer;
}

datacredit newcredit(datacredit credit, datamember customer){
    datacredit newnode = credit;
    datamember pt;
    pt = customer;
    char id[10], f = 0;
    printf("Enter customer ID: ");
    scanf("%d", &id);
    while(pt != NULL){
            if(id == pt->customer_ID){
                f = 1;
                break;
            }
            pt = pt->next;
        }
    if(f == 0){ 
        printf("This customer ID is not exist.\n\n");
        return credit;
    }
    if(f == 1){
        printf("Found customer ID.\n\n");

    }
    return credit;
}

int main(){
    datamember customer = NULL;
    datacredit credit = NULL;
    int choice;
    do{
        printf("1. creat new member\n");
        printf("2. creat new credit\n");
        printf("3. Show all member\n");
        printf("4. Show all credit\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                customer = newmember(customer);
                break;
            case 2:
                credit = newcredit(credit, customer);
                break;
        }
    }while(choice != 5);
    return 0;
}