# include <stdio.h>
# include <math.h>

int main(void) {
    float oil, WRate;
    printf("Enter the oil capacity (liter): ");
    scanf("%f", &oil);
    printf("Enter the oil consumption rate (km/liter): ");
    scanf("%f", &WRate);
    float distance = abs((float)oil * WRate);

    printf("The distance is %.2f km\n", distance);
    if (distance < 100) {
        printf("City A");
    } 
    else if (distance >= 100 && distance < 250) {
        printf("City B");
    } 
    else if (distance >= 250 && distance < 500) {
        printf("City C");
    }
    else if (distance >= 500) {
        printf("City D");
    }
    return 0;
}