# include <stdio.h>

int main(void) {
    int count = 0, a[100000];
    printf("Enter number : ");
    do {
        scanf("%d", &a[count]);
        count++;
    } while (getchar() != '\n');
    int c[count];
    a[count];
//-----------------------------------------------------------------------
    for (int i = 0; i < count; i++){
        c[i] = a[i];
    }
//-----------------------------------------------------------------------
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
    int z = 0;
    int d[count];
    for (int i = 1; i < count; i++){
        d[0] = a[0];
        if (a[i-1] != a[i]){
            z++;
            d[z] = a[i];
        }
    }
//-----------------------------------------------------------------------
    int t = 0, time[z];
    for(int i = 0; i < z + 1; i++){
        for (int j = 0; j < count; j++){
            if (d[i] == a[j]){
                t++;
            }
        }
    time[i] = t;
    t = 0;
    }
//-----------------------------------------------------------------------
    for (int i = 0; i < z + 1; i++){
        printf("%d occurs %d time at ", d[i], time[i]);
        for (int j = 0; j < count; j++){
            if (d[i] == c[j]){
                printf("%d", j + 1);
                if (time[i] > 1 ){
                    printf(", ");
                    time[i]--;
                }
            }
        }
    printf("\n");
    }
}