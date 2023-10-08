# include <stdio.h>

int main(void) {
    int n = 0;
    while (n != 3) { 
        int num;
        printf("Input the binary number: ");
        scanf("%d", &num);
        int i = 0, sum = 0, t = 1;
        for (int i = 1; i < 8; i++) {
            if (num % 10 == 1) {
                sum += t;
                num /= 10;
                t *= 2;
            }
            else if (num % 10 == 0) {
                num /= 10;
                t *= 2;
            }
            else {
                printf("Invalid input\n");
                return 0;
            }
        }
        printf("The equivalent Decimal Number is : %d\n", sum);
    }
}