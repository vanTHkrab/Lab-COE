# include <stdio.h>
# include <string.h>

typedef struct number datanum;
struct number {
    int num, odd, even, position;
};

void getnum(datanum num[], int *n) {
    int i;
    printf("Enter a number (Stop enter -1): ");
    for (i = 0; i < 100; i++) {
        scanf("%d", &num[i].num);
        if (num[i].num == -1) {
            break;
        }
        num[i].position = i + 1;
        *n = *n + 1;
    }
}

int main() {
    datanum num[100];
    int n = 0;
    getnum(num, &n);
    printf("List of number: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", num[i].num);
    }
    printf("\n");
    return 0;
}