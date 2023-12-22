#include<stdio.h>
int main(){
    int num[100][100] , a , n = 0, e = 0, o = 0;
    printf("Enter number(Enter 0 to stop): ");
    while(1){
        scanf("%d", &a);
        if (a == 0) break;
        num[n][0] = a;
        if (a % 2 == 0){
            num[e][1] = a;
            e++;
        }
        else{
            num[o][2] = a;
            o++;
        }
    }
    printf("Even number: ");
    for (int i = 0; i < e; i++){
        printf("%d ", num[i][1]);
    }
    printf("\nTotal even number: %d", e);
    printf("\nOdd number: ");
    for (int i = 0; i < o; i++){
        printf("%d ", num[i][2]);
    }
    printf("\nTotal odd number: %d", o);
}