#include <stdio.h>

int main(void)
{
    int count = 0, a[100000], e = 0, o = 0;
    do {
        printf("Enter number : ");
        scanf("%d", &a[count]);
        count++;
    } while (getchar() != '\n');

    // printf("%d\n", count);
	printf("Even number are :\n");
    for (int i = 0; i < count; i++) {
        if (a[i] % 2 == 0){
            printf("%d\n", a[i]);
            e++;
        }
    }
    printf("Number of even = %d\n", e);
    printf("Odd number are :\n");
    for (int i = 0; i < count; i++) {
        if (a[i] % 2 != 0){
            printf("%d\n", a[i]);
            o++;
        }
    }
    printf("Number of odd = %d\n", o);
    return 0;
}