# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct datatest2 *test_2;
struct datatest2 {
    int num;
    test_2 next2;
};

typedef struct datatest1 *test_1;
struct datatest1 {
    int danum;
    test_1 next1;
    struct datatest2 *num2;
};

test_1 create_test1(test_1 test1) {
    test_1 newnode;
    test_2 newnode2;
    test_1 temp = test1;
    test_2 temp2;
    int danum, num;
    printf("Enter danum: ");
    scanf("%d", &danum);
    while (danum != 0) {
        newnode = (test_1)malloc(sizeof(struct datatest1));
        newnode->danum = danum;
        newnode->next1 = NULL;
        newnode->num2 = NULL;
        if (test1 == NULL) {
            test1 = newnode;
            temp = test1;
        } else {
            temp->next1 = newnode;
            temp = temp->next1;
        }
        printf("Enter num: ");
        scanf("%d", &num);
        while (num != 0) {
            newnode2 = (test_2)malloc(sizeof(struct datatest2));
            newnode2->num = num;
            newnode2->next2 = NULL;
            if (newnode->num2 == NULL) {
                newnode->num2 = newnode2;
                temp2 = newnode->num2;
            } else {
                temp2->next2 = newnode2;
                temp2 = temp2->next2;
            }
            printf("Enter num: ");
            scanf("%d", &num);
        }
        printf("Enter danum: ");
        scanf("%d", &danum);
    }
    return test1;
}

void print_test1(test_1 test1) {
    test_1 temp = test1;
    test_2 temp2;
    while (temp != NULL) {
        printf("%d ", temp->danum);
        temp2 = temp->num2;
        while (temp2 != NULL) {
            printf("%d ", temp2->num);
            temp2 = temp2->next2;
        }
        printf("\n");
        temp = temp->next1;
    }
}

int main() {
    test_1 test1 = NULL;
    test_2 test2 = NULL;
    test1 = create_test1(test1);
    print_test1(test1);
    return 0;
}
