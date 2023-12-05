# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct test2 *num2;
struct test2 {
    int n2;
    num2 next2;
};

typedef struct test1 *num1;
struct test1 {
    int n1;
    num1 next1;
    num2 num2;
};

num1 test1(num1 n1){
    num1 newnode;
    int a1;
    while (1){
        printf("Enter Num / 1: ");
        scanf("%d", &a1);
        if (a1 == 0) break;
        newnode = (num1)malloc(sizeof(struct test1));
        newnode->n1 = a1;
        newnode->next1 = n1;
        newnode->num2 = NULL;
        n1 = newnode;
    }
    return n1;
}

num1 test2(num1 n1){
    num1 temp = n1;
    int a1, a2;
    printf("\nEnter Num / 1: ");
    scanf("%d", &a1);
    while (temp != NULL){
        if (temp->n1 == a1){
            while (1){
                printf("Enter Num / 2 (0 to stop): ");
                scanf("%d", &a2);
                if (a2 == 0) break;
                num2 newnode2 = (num2)malloc(sizeof(struct test2));
                newnode2->n2 = a2;
                newnode2->next2 = temp->num2;
                temp->num2 = newnode2;
            }
        }
        temp = temp->next1;
    }
    return n1;
}

void print_test1(num1 n1){
    num1 temp = n1;
    num2 temp2;
    while (temp != NULL){
        printf("%d ", temp->n1);
        temp2 = temp->num2;
        while (temp2 != NULL){
            printf("%d ", temp2->n2);
            temp2 = temp2->next2;
        }
        printf("\n");
        temp = temp->next1;
    }
}

int main(){
    num1 n1 = NULL;
    n1 = test1(n1);
    n1 = test2(n1);
    print_test1(n1);
    return 0;
}