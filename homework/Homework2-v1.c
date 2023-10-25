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
// copy array
    int c[count];
    for (int i = 0; i < count; i++){
        c[i] = a[i];
    }
//-----------------------------------------------------------------------
// lower to higher
    int b;
    for (int i = 0; i < count; i++){
        for (int j = i + 1; j < count; j++){
            if (a[i] > a[j]){
                b = a[i];
                a[i] = a[j];
                a[j] = b;
            }
        }
    }
//-----------------------------------------------------------------------
// remove duplicate
    int z = 0, d[count];
    for (int i = 1; i < count; i++){
        d[0] = a[0];
        if (a[i-1] != a[i]){
            z++;
            d[z] = a[i];
        }
    }
//-----------------------------------------------------------------------
// count number of each number
//-----------------------------------------------------------------------
// print
    int time = 0, on;
    for (int i = 0; i < z + 1; i++){
        for (int j = 0; j < count; j++){
            if (d[i] == a[j]){
                time++;
            }
        }
        on = time;
        printf("%d occurs %d time at ", d[i], time);
        for (int j = 0; j < count; j++){
            if (d[i] == c[j]){
                printf("%d", j + 1);
                if (on > 1 ){
                    printf(", ");
                    on--;
                }
            }
        }
    time = 0;
    printf("\n");
    }
}