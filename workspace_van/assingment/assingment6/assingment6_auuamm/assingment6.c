# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct number *datanum;
struct number{
    int num;
    datanum next;
};

typedef struct Auu *Amm;
struct Auu
{
    int AuuAmm;
    Amm next;
};


datanum getnum(datanum num){
    datanum newnode;
    int n;
    do
    printf("Enter Number: ");
    {
        newnode = (datanum)malloc(sizeof(struct number));
        scanf("%d" ,&n);
        if (n == 0) break;
        newnode->num = n;
        newnode->next = num;
        num = newnode;
    }while (1);
    return num;
}

void display(datanum num){
    datanum pt;
    pt = num;
    printf("\n");
    while (pt != NULL){
        printf("%d ", pt->num);
        pt = pt->next;
    }
    
}

Amm search_AuuAmm(Amm AuuAmm, datanum num){
    datanum pt;
    Amm newnode;
    pt = num;
    while (pt != NULL){
        if (pt->num % 7 == 0 && pt->num > 0){
            newnode = (Amm)malloc(sizeof(struct Auu));
            newnode->AuuAmm = pt->num;
            newnode->next = AuuAmm;
            AuuAmm = newnode;
        }
        pt = pt->next;
    }
    return AuuAmm;
}

void display_AuuAmm(Amm AuuAmm){
    Amm pt;
    pt = AuuAmm;
    printf("\nlist of can divisible by 7:");
    while (pt != NULL){
        printf("%d ", pt->AuuAmm);
        pt = pt->next;
    }
}

int main(){
    datanum num;
    Amm AuuAmm;
    num = NULL;
    AuuAmm = NULL;
//------------------------------------------------------------
    num = getnum(num);
    AuuAmm = search_AuuAmm(AuuAmm, num);
    display(num);
    display_AuuAmm(AuuAmm);
}