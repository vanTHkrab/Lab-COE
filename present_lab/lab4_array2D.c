// https://onedrive.live.com/edit?id=CA02FAB35D91D925!157&resid=CA02FAB35D91D925!157&ithint=file%2cxlsx&ct=1699272857360&wdOrigin=OFFICECOM-WEB.MAIN.EDGEWORTH&wdPreviousSessionSrc=HarmonyWeb&wdPreviousSession=a34d863f-5cf5-4490-a1ef-3647e0841be8&wdo=2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

int main() {
    FILE *file;
    char data[1000][6][100]; 
    int row = 0, col = 0;

    file = fopen("data_genshinv2.txt", "r");

    while (fscanf(file, "%s", data[row][col]) != EOF) {
        col++;
        if (col == 5) {
            col = 0;
            row++;
        }
    }

    fclose(file);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }

    return 0;
}
