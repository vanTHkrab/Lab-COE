#include <stdio.h>

void getdata(float *money, float *AIR, int *time) {
    printf("Money: ");
    scanf("%f", money);
    printf("Annual interest rate(%%): ");
    scanf("%f", AIR);
    printf("Time: ");
    scanf("%d", time);
}

void math(float money, float AIR, int time, float *sum) {
    *sum = money + (money * AIR / 100) / time;
}

void display(float sum) {
    printf("Sum: %.2f\n", sum);
}

int main() {
    float money, AIR, sum;
    int time;
    getdata(&money, &AIR, &time);
    math(money, AIR, time, &sum);
    display(sum);
    return 0;
}