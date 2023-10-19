#include <stdio.h>

int main(void)
{
    int count = 0, e = 0, o = 0;
    printf("Enter number of total : ");
    scanf("%d", &count);
    int a[count];
    for(int i = 0; i < count; i++){
        printf("Enter number %d : ", i + 1);
        scanf("%d", &a[i]);
    }
    
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