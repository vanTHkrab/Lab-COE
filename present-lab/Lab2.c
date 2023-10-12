# include <stdio.h>
# include <math.h>


int main(void) {
    int num;
    printf("Input the binary number: ");
    scanf("%d", &num);
    int binary = abs(num);
    int i = 0, sum = 0, t = 1;
    for (int i = num ; i > 0; i /= 10) {
        if (num % 10 == 1) {
            sum += t;
        }
        else if (num % 10 == 0) {
            sum = sum;
        }
        else {
            printf("Invalid input\n");
            return 0;
        }
        num /= 10;
        t *= 2;
    }
    printf("This Binary Code \"%d\" And The equivalent Decimal Number is : %d\n", binary, sum);
}