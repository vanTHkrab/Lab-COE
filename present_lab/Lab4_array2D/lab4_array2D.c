// https://onedrive.live.com/edit?id=CA02FAB35D91D925!157&resid=CA02FAB35D91D925!157&ithint=file%2cxlsx&ct=1699272857360&wdOrigin=OFFICECOM-WEB.MAIN.EDGEWORTH&wdPreviousSessionSrc=HarmonyWeb&wdPreviousSession=a34d863f-5cf5-4490-a1ef-3647e0841be8&wdo=2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

int main() {
    FILE *file;
    char data[1000][6][100]; 
    int row = 0, col = 0;

    file = fopen("data_genshinv1.txt", "r");
    while (fscanf(file, "%s", data[row][col]) != EOF) {
        col++;
    }
    fclose(file);
    printf(" ________________________________________________________________________________________________________________\n");
    printf("|  # |    %s     |  %s |  %s |  %s |  %s  |\n", data[0][0], data[0][1], data[0][2], data[0][3], data[0][4]);
    printf("|----+--------------+--------------------------+----------------------+------------------------+-----------------|\n");
    col = 0, row = 1;
    file = fopen("data_genshinv2.txt", "r");
    while (fscanf(file, "%s", data[row][col]) != EOF) {
        if (col == 4) {
            row++;
            col = 0;
        }
        else col++;
    }
    fclose(file);
    int num = 1;
    for (int i = 1; i < row; i++) {
        if (num < 10) printf("|  %d ", num);
        else printf("| %d ", num);
        for(int k = 0; k < 5; k++) {
            for (int t = 0; t < 6; t++){
                if (t == 5) printf("| ");
            } 
            if (k != 4){
            int str_head[5] = {5, 18, 16, 18, 0};
            for (strlen(data[i][k]) , str_head[4];strlen(data[i][k]) < str_head[k];str_head[k]--){
                printf(" ");
            }}
            else printf("  ");
            printf("%s", data[i][k]);
            if (k < 2 && k != 3){
            int str_head2[5] = {13, 17, 13, 0, 0};
            for (strlen(data[i][k]) , str_head2[4];strlen(data[i][k]) < str_head2[k];str_head2[k]--){
                printf(" ");
            }}
            else printf("     ");
        }
        num++;
        printf("|");
        printf("\n");
        printf("|----+--------------+--------------------------+----------------------+------------------------+-----------------|\n");

    }

    while(1){
        char number[5];
        printf("\nEnter the number from table (Enter '0' to End): ");
        scanf("%s", number);
        int nt = atoi(number);
        if (nt == 0) break;
        for (int i = 0; i < row; i++){
            if (nt == i){
                printf("Date: %s\n", data[i][0]);
                printf("Average Monthly Players : %s\n", data[i][1]);
                printf("Monthly Gain / Loss : %s\n", data[i][2]);
                printf("Monthly Gain / Loss %% : %s\n", data[i][3]);
                printf("All Time Peak : %s\n", data[i][4]);
            }
        }
    }
    printf("End of Program, Thank\n");
    return 0;
}
