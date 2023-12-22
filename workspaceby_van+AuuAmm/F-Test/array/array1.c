#include <stdio.h>

int main(){
    int n[100], i = 0, a, e = 0, o = 0;
    while (1){
        printf("Enter number(Enter 0 to stop): ");
        scanf("%d", &a);
        if (a == 0) break;
        n[i] = a;
        i++;
    }
    printf("Even number: ");
    for (int j = 0; j < i; j++){
        if (n[j] % 2 == 0){
            printf("%d ", n[j]);
            e++;
        }
    }
    printf("\nTotal even number: %d", e);
    printf("\nOdd number: ");
    for (int j = 0; j < i; j++){
        if (n[j] % 2 != 0){
            printf("%d ", n[j]);
            o++;
        }
    }
    printf("\nTotal odd number: %d", o);
}