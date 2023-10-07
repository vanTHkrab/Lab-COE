# include <stdio.h>

int main(void) {
    int num;
    printf("Enter the number (1-100): ");
    scanf("%d", &num);
    while (num < 1 || num > 100) {
        printf("Enter the number (1-100): ");
        scanf("%d", &num);
    }
    if (num % 10 == 7 || num >= 70 && num <= 79) {
        printf("BUZZ");
    }
    else if (num / 7 == 0){
        printf("BUZZ-BUZZ");
    }
    else {
        printf("%d", num);
    }
}