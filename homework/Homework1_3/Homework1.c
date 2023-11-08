# include <stdio.h>

int main(void) {
    float oil, WRate, distance;
    printf("Enter the oil capacity (liter): ");
    scanf("%f", &oil);
    printf("Enter the oil consumption rate (km/liter): ");
    scanf("%f", &WRate);
    distance = oil * WRate;
    if (distance < 0) {
        distance = distance * -1;
    }

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
}