# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct datanumber *num;
struct datanumber{
    int num;
    num next;
};

typedef struct dataseven *seven;
struct dataseven{
    int numseven;
    seven next;
};

num getnum(num n) {
    num newnode;
    int number;
    printf("Enter Number ('0' to stop): ");
    do {
        newnode = (num)malloc(sizeof(struct datanumber));
        scanf("%d", &number);
        if (number == 0) break;
        newnode->num = number;
        newnode->next = n;
        n = newnode;
    } while (1);
    return n;
}

seven search_seven(seven s, num n) {
    num pt;
    seven newnode;
    pt = n;
    while (pt != NULL) {
        if (pt->num % 7 == 0 && pt->num > 0) {
            newnode = (seven)malloc(sizeof(struct dataseven));
            newnode->numseven = pt->num;
            newnode->next = s;
            s = newnode;
        }
        pt = pt->next;
    }
    return s;
}

void display(num n) {
    num pt;
    pt = n;
    int count = 0;
    printf("Number all: ");
    while (pt != NULL) {
        printf("%d ", pt->num);
        pt = pt->next;
        count++;
    }
    printf("\nNumber of all: %d", count);
}

void display_seven(seven s) {
    seven pt = s;
    int count = 0;
    printf("Divisible by 7: ");
    while (pt != NULL) {
        printf("%d ", pt->numseven);
        count++;
        pt = pt->next;
    }
    printf("\nNumber of multiples of 7: %d", count);
}

int main(){
    num n = NULL;
    seven s = NULL;
    int a;
    while(1){
        printf("1. Add Number\n2. Display check number\n3. Display number divisible by 7\n4. Clear number\n5. Exit\n->");
        scanf("%d", &a);
        if (a != 1 && n == NULL){
            printf("Pls add number\n_____________________\n");
            continue;
        }
        switch (a){
            case 1:
                n = getnum(n);
                s = search_seven(s, n);
                break;
            case 2:
                display(n);
                break;
            case 3:
                display_seven(s);
                break;
            case 4:
                n = NULL;
                s = NULL;
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Enter 1-5 only\n");
                break;
        }
        printf("\n_____________________\n");
    }
    free(n);
    free(s);
    return 0;
}