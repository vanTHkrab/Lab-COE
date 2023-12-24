# include <stdio.h>
# include <stdlib.h>

void getdata(float *money, float *AIR, int *time) {
    printf("Money(Enter 0 to stop): ");
    scanf("%f", money);
    if (*money == 0) exit(0);
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
    while(1){
        getdata(&money, &AIR, &time);
        math(money, AIR, time, &sum);
        display(sum);
    }
    return 0;
}