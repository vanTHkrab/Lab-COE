# include <stdio.h>


int func(int a){
    if (a > 0) {
        printf("%d\n", a);
        return a * func(a-1);
    }
    else {
        return 1;
    }
}

int main(){
    int sum = func(5);
    printf("\n%d", sum);
    return 0;
}