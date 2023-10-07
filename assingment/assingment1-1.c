# include <stdio.h>

int main(void){
    float b, h, area;
    printf("Enter the base: ");
    scanf("%f", &b);
    printf("Enter the height: ");
    scanf("%f", &h);
    area = b * h / 2;
    printf("The Triangle Area is %.2f\n", area);
}