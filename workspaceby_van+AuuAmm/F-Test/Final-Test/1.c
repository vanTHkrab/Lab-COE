# include <stdio.h>

void math(float n){
    n = 3.14 * n * n;
    return n;
}

int main(){
    float m;
    printf("Enter num: ");
    scanf("%f", &m);
    m = math(m);
    printf("Sum: %.2f", m);
}
