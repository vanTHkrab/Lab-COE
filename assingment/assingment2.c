# include <stdio.h>

int main(void) {
    int num = 0;
    while (num < 1 || num > 99) { // 1-99  ("||" is "or")
        printf("Enter the number (1-99): ");
        scanf("%d", &num);
    }

    if (num % 10 == 7 || num >= 70 && num <= 79) { // 7, 70-79 
        printf("BUZZ");
    }
    else if (num % 7 == 0){    // 49 % 7 = 0
        printf("BUZZ-BUZZ");
    }
    else {
        printf("%d", num);
    }
}