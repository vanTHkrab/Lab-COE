# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct number *datanum;
struct number {
    int num;
    int position;
    datanum next;
};

typedef struct odd *odd;
struct odd {
    int numodd, positionodd;
    odd next;
};

datanum getdatanum(datanum num) {
    datanum newnode;
    int n;
    int position = 1;
    printf("Enter a number (Stop enter -1): ");
    do{
        newnode = (datanum)malloc(sizeof(struct number));
        scanf("%d", &newnode->num);
        if (newnode->num == -1) {
            break;
        }
        newnode->position = position++;
        newnode->next = num;
        num = newnode;
    }while (newnode->num != -1);
    return num;
}

void display(datanum num) {
    datanum temp;
    temp = num;
    printf("List of number: ");
    while (temp != NULL) {
        printf("%d ", temp->num);
        temp = temp->next;
    }
    printf("\n");
}

odd search_odd(odd numodd, datanum num) {
    datanum temp; 
    temp = num;
    odd newnode;
    while (temp != NULL) {
        if (temp->num % 2 != 0) {
            newnode = (odd)malloc(sizeof(struct odd));
            newnode->numodd = temp->num;
            newnode->positionodd = temp->position;
            newnode->next = numodd;
            numodd = newnode;
        }
    temp = temp->next;
    }
    return numodd;
}

void display_odd(odd numodd) {
    odd pr;
    pr = numodd;
    printf("List of odd number: ");
    while (pr != NULL) {
        printf("%d ", pr->numodd);
        pr = pr->next;
    }
    while (pr != NULL) {
        printf("%d ", pr->positionodd);
        pr = pr->next;
    }
    printf("\n");
}

int main() {
    datanum num;
    odd numodd;
    numodd = NULL;
    num = NULL;
    num = getdatanum(num);
    display(num);
    numodd = search_odd(numodd, num);
    display_odd(numodd);
    return 0;
}