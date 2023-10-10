# include <stdio.h>

int main(void) {
    int num;
    printf("Input number :");
    scanf("%d", &num);
    for (int i = 0; i < num; i++ ) {
        printf("*");
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}