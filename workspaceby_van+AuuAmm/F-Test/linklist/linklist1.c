#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct struct_office office;
struct struct_office
{
    char day[10], month[10], year[10];
};

typedef struct data_infomath *infomath;
struct data_infomath
{
    char id[10], name[30], lastname[30], height[10], weight[10];
    struct struct_office office;
    infomath next;
};

infomath create(infomath info){
    infomath newnode;
    printf("How many want create: ");
    int n;
    scanf("%d", &n);
    while(n--){
        newnode = (infomath)malloc(sizeof(struct data_infomath));
        printf("\nEnter ID: ");
        scanf("%s", newnode->id);
        printf("Enter Name: ");
        scanf("%s", newnode->name);
        printf("Enter Lastname: ");
        scanf("%s", newnode->lastname);
        printf("Enter Height: ");
        scanf("%s", newnode->height);
        printf("Enter Weight: ");
        scanf("%s", newnode->weight);
        printf("Office Date\n");
        printf("Enter Day: ");
        scanf("%s", newnode->office.day);
        printf("Enter Month: ");
        scanf("%s", newnode->office.month);
        printf("Enter Year: ");
        scanf("%s", newnode->office.year);
        newnode->next = info;
        info = newnode;
    }
    return info;
}

void display(infomath info){
    infomath temp = info;
    while(temp != NULL){
        printf("\nID: %s\n", temp->id);
        printf("Name: %s\n", temp->name);
        printf("Lastname: %s\n", temp->lastname);
        printf("Height: %s\n", temp->height);
        printf("Weight: %s\n", temp->weight);
        printf("Day: %s\n", temp->office.day);
        printf("Month: %s\n", temp->office.month);
        printf("Year: %s\n", temp->office.year);
        temp = temp->next;
    }
    return;
}

int main(){
    infomath info = NULL;
    info = create(info);
    display(info);
    return 0;
}