# include <stdio.h>
# include <stdlib.h>

typedef struct datanum *num;
struct datanum {
    int n;
    num next;
};

typedef struct dataRenum *Rnum;
struct dataRenum {
    int Rn;
    Rnum next;
};

num getnum(num number){
    num newnode;
    int a;
    printf("Enter num: ");
    scanf("%d", &a);
    if (a == 0) exit(0);
    if (a < 1){
        return number;
    }
    while (a > 0){
        newnode = (num)malloc(sizeof(struct datanum));
        newnode->n = a % 10;
        a /= 10;
        newnode->next = number;
        number = newnode;
    }
    return number;
}

Rnum getRnum(num number, Rnum Rnumber){
    num temp = number;
    Rnum newnode;
    while (temp != NULL){
        newnode = (Rnum)malloc(sizeof(struct dataRenum));
        newnode->Rn = temp->n;
        newnode->next = Rnumber;
        Rnumber = newnode;
        temp = temp->next;
    }
    return Rnumber;
}

void display(num number){
    num temp = number;
    printf("Not reverse: ");
    while (temp != NULL){
        printf("%d ", temp->n);
        temp = temp->next;
    }
    printf("\n");
}

void displayR(Rnum Rnumber){
    Rnum temp = Rnumber;
    printf("Reverse: ");
    while (temp != NULL){
        printf("%d ", temp->Rn);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int z;
    while (1)
    {
        num number = NULL;
        Rnum Rnumber = NULL;
        number = getnum(number);
        Rnumber = getRnum(number, Rnumber);
        display(number);
        displayR(Rnumber);
    }
    return 0;
}