# include <stdio.h>

int main(void) {
    int num[10000], max = 0, p, i = 0; // array
    printf("Enter the number of elements: ");
    scanf("%d", &p);
    while (i < p) {  
        printf("Enter the num %d: ", i+1);
        scanf("%d", &num[i]);
        i++;
    }
    for (int a = 0; a < p; a++) {
        if (num[a] > max) {
            max = num[a];
        }
    }
    printf("Max: %d", max);
}