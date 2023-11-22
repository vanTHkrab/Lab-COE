#include <stdio.h>

int main() {
    int sally, hans;

    do {
        printf("Enter values for sally and hans: ");
        scanf("%d %d", &sally, &hans);
        if (sally > hans) {
            printf("sally must be less than hans. Please enter again.\n");
        }
    } while (sally > hans);
    int count = 0;

    while (1) {
        sally += 10;
        hans -= 100;
        count++;
        if (sally == hans) {
            printf("At: %d\n", sally);
            printf("count: %d", count);
            break;
        }
        if (sally > hans) {
            printf("No solution");
            break;
        }
    }
    return 0;
}