# include <stdio.h>

typedef struct data_car car;
struct data_car
{
    char name[100];
    char model[100];
    char color[100];
    char price[100];
};

int main(void) {
    car car;
    printf("Name of car: ");
    scanf("%s", car.name);
    printf("Model of %s: ", car.name);
    scanf("%s", car.model);
    printf("Color of %s: ", car.name);
    scanf("%s", car.color);
    printf("Price of %s: ", car.name);
    scanf("%s", car.price);

    printf("\nName: %s\n", car.name);
    printf("Model: %s\n", car.model);
    printf("Color: %s\n", car.color);
    printf("Price: %s\n", car.price);
}