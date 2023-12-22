# include <stdio.h>

int main(){
    int n[100][100];
    int row, col;
    printf("Enter row and column: ");
    scanf("%d %d", &row, &col);
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("Enter number: ");
            scanf("%d", &n[i][j]);
        }
    }
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%d  ", n[i][j]);
        }
        printf("\n");
    }
}