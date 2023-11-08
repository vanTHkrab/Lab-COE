# include <stdio.h>

int main(void) {
    float r, h, volume;
    printf("Enter the radius: ");
    scanf("%f", &r);
    printf("Enter the height: ");
    scanf("%f", &h);
    volume = 3.14 * r * r * h;
    printf("The Cylinder Volume is %.2f\n", volume);
}