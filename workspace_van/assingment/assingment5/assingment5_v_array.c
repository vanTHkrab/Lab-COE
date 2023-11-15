# include <stdio.h>
# include <string.h>

typedef struct number datanum;
struct number {
    int num, odd, even, position;
};

void getnum(datanum ){
    datanum n;
    int p = 0;
    printf("Enter a number (Stop enter -1): ");
    do{
        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        n[p].num = n;
        n[p].position = p++;
    }while (n != -1);
}

// void display(datanum num[100], datanum position[100]){
//     printf("List of number: ");
//     int t;
//     for (int i = 0; i < position; i++) {
//         printf("%d ", num[i].num);
//     }
//     printf("\n");

// }

int main() {
    datanum num[100];
    getnum(num);
    // display(num);
    return 0;
}