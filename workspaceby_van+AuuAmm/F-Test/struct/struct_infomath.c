#include <stdio.h>
#include <string.h>

typedef struct struct_office
{
    char day[10], month[10], year[10];
} office;

typedef struct data_infomath
{
    char id[10], name[30], lastname[30], height[10], weight[10];
    struct struct_office office;
} infomath;

void create(int n, infomath infomath[]) {


    for (int i = 0; i < n; i++) {
        printf("\nEnter ID: ");
        scanf("%s", infomath[i].id);
        printf("Enter Name: ");
        scanf("%s", infomath[i].name);
        printf("Enter Lastname: ");
        scanf("%s", infomath[i].lastname);
        printf("Enter Height: ");
        scanf("%s", infomath[i].height);
        printf("Enter Weight: ");
        scanf("%s", infomath[i].weight);
        printf("Office Date\n");
        printf("Enter Day: ");
        scanf("%s", infomath[i].office.day);
        printf("Enter Month: ");
        scanf("%s", infomath[i].office.month);
        printf("Enter Year: ");
        scanf("%s", infomath[i].office.year);
    }
    return;
}

void display(int n, infomath infomath[]) {
    for (int i = 0; i < n; i++) {
        printf("\nID: %s\n", infomath[i].id);
        printf("Name: %s\n", infomath[i].name);
        printf("Lastname: %s\n", infomath[i].lastname);
        printf("Height: %s\n", infomath[i].height);
        printf("Weight: %s\n", infomath[i].weight);
        printf("Day: %s\n", infomath[i].office.day);
        printf("Month: %s\n", infomath[i].office.month);
        printf("Year: %s\n", infomath[i].office.year);
    }
    return;
}

int main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    infomath infomath[n];
    create(n, infomath);
    display(n, infomath);
}
