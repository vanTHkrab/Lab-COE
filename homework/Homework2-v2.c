# include <stdio.h>

int main(void) {
// input
    int count = 0, a[100000];
    printf("Enter number : ");
    do {
        scanf("%d", &a[count]);
        count++;
    } while (getchar() != '\n');
    a[count];
//-----------------------------------------------------------------------
    int min = a[0], max = a[count];
    for (int i = 0; i < count; i++) {
        if (a[i] < min) {
            min = a[i];
        }
        else if (a[i] > max){
            max = a[i];
        }
    }
    printf("%d %d\n", max ,min);
//-----------------------------------------------------------------------
    int time = 0;
    for (min, max; min <= max;min++){
        for (int j = 0; j < count; j++){
            if (min == a[j]){
                time++;
            }
        }
    if (time > 0){
       printf("%d occurs %d time at ", min, time);
       for (int at = 0; at< count; at++){
            if (min == a[at]){
                printf("%d" , at + 1);
                if (time > 1){
                    printf(", ");
                    time--;
                }
            }
       }
    printf("\n");
    time = 0;
    }
    }
}