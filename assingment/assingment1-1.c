# include <stdio.h>
# include <math.h>

int main(void){
    float b, h;
    printf("Enter the base: ");
    scanf("%f", &b);
    printf("Enter the height: ");
    scanf("%f", &h);
    printf("The Triangle Area is %.2f\n", abs(b * h / 2));
}