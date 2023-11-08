// https://onedrive.live.com/edit?id=CA02FAB35D91D925!157&resid=CA02FAB35D91D925!157&ithint=file%2cxlsx&ct=1699272857360&wdOrigin=OFFICECOM-WEB.MAIN.EDGEWORTH&wdPreviousSessionSrc=HarmonyWeb&wdPreviousSession=a34d863f-5cf5-4490-a1ef-3647e0841be8&wdo=2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fdatagenshin;
    char data[1000][6][100]; 
    int row = 0, col = 0;

    printf(" ________________________________________________________________________________________________________________\n");
    printf("|  # |    Month     |  Average_Monthly_Players |  Monthly_Gain_/_Loss |  Monthly_Gain_/_Loss_%% |  All_Time_Peak  |\n");
    printf("|----+--------------+--------------------------+----------------------+------------------------+-----------------|\n");

    fdatagenshin = fopen("data_genshinv2.txt", "r");
    while (fscanf(fdatagenshin, "%s", data[row][col]) != EOF) {
        if (col == 4) {
            row++;
            col = 0;
        }
        else col++;
    }
    fclose(fdatagenshin);
    
    int num = 1;
    for (int i = 0; i < row; i++) {
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
        int nt;
        printf("\nEnter the number from table (Enter '0' to End): ");
        scanf("%d", &nt);
        if (nt == 0) break;
        if (nt < 0 || nt > row - 1){
            printf("Number not in list\n");
            continue;
        }
        for (int i = 0; i < row; i++){
            if (nt == i){
                printf("Date : %s\n", data[i][0]);
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
