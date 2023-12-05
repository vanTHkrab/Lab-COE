# include <stdio.h>

int main(){
    int a, i = 0, count = 0;
    while(1){
        printf("Enter number: ");
        scanf("%d", &a);
        if (a == 0){
            break;
        }
        if (a % 7 == 0){
            i++;
        }
        count++;
    }
    printf("Number of multiples of 7: %d\n", i);
    printf("All Number is: %d\n", count);
}