# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# include <string.h>


int main() {
    const char *folderPath = "FolderForTest";

    const char *fileName = "AuuJee&Amm.txt";

    char filePath[100];
    snprintf(filePath, sizeof(filePath), "%s/%s", folderPath, fileName);

    FILE *file = fopen(filePath, "w");
    if (file != NULL) {

        fprintf(file, "Hello, World!\n");

        fclose(file);

        printf("Can make file\n");
    } else {
        printf("cann't make file\n");
    }

    return 0;
}