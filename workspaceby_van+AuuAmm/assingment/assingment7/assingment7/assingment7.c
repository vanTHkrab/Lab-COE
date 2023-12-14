#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct publishstruct {
    char code[7];
    char title[20];
    int price;
} publishing;

typedef FILE *filetype;

const char *folderPath = "Folder_File_assingment7";

char *getFilePath(const char *fileName) {
    char *filePath = malloc(strlen(folderPath) + strlen(fileName) + 2);
    if (filePath == NULL) {
        printf("Error to creatfile\n");
        return NULL;
    }
    sprintf(filePath, "%s/%s", folderPath, fileName);
    return filePath;
}

int menu(){
    int answer;
    printf(" MENU\n");
    printf(" [1] Create file\n");
    printf(" [2] Display Data in file\n");
    printf(" [3] Insert Data in file\n");
    printf(" [4] Search Data in file\n");
    printf(" [5] Stop running program\n\n");
    printf(" Your answer: ");
    scanf("%d",&answer);
    return(answer);
}

filetype CreateFile(filetype fname) {
    char filename[10], price[6];
    printf(" File name : ");
    gets(filename);
    gets(filename);
    printf(" ->\"%s\"\n", filename);
    char *filePath = getFilePath(filename);
    if ((fname = fopen(filePath, "w")) == NULL) {
        printf(" Error in opening file \n ");
        free(filePath);
        return fname;
    }
    free(filePath);
    while (1) {
        printf(" Code ( Enter = Quit ) : ");
        gets(publishing.code);
        if (publishing.code[0] == '\0') break;
        printf(" Title : ");
        gets(publishing.title);
        printf(" Price : ");
        gets(price);
        publishing.price = atoi(price);
        fwrite(&publishing, sizeof(publishing), 1, fname);
        if (ferror(fname)) {
            printf(" Error in writing \n ");
            return fname;
        }
    }
    fclose(fname);
    return fname;
}

void Display(filetype fname) {
    char filename[10];
    printf(" File name : ");
    gets(filename);
    gets(filename);
    char *filePath = getFilePath(filename);
    if ((fname = fopen(filePath, "r")) == NULL) {
        printf(" Error in opening file \n ");
        free(filePath);
        return;
    }
    free(filePath);
    while (fread(&publishing, sizeof(publishing), 1, fname) == 1) {
        if (ferror(fname)) {
            printf(" Error in reading file \n ");
            return;
        } else {
            printf(" code = %s \n", publishing.code);
            printf(" Title = %s \n", publishing.title);
            printf(" price = %d \n", publishing.price);
        }
    }
    fclose(fname);
}

filetype Insert(filetype fname) {
    char filename[10], price[6];
    printf(" File name : ");
    gets(filename);
    gets(filename);
    printf(" ->\"%s\"\n", filename);
    char *filePath = getFilePath(filename);
    if ((fname = fopen(filePath, "r")) == NULL) {
        printf(" Error in opening file \n ");
        free(filePath);
        return fname;
    }
    fclose(fname);
    if ((fname = fopen(filePath, "a")) == NULL) {
        printf(" Error in opening file \n ");
        free(filePath);
        return fname;
    }
    free(filePath);
    while (1) {
        printf(" Code ( Enter = Quit ) : ");
        gets(publishing.code);
        if (publishing.code[0] == '\0') break;
        printf(" Title : ");
        gets(publishing.title);
        printf(" Price : ");
        gets(price);
        publishing.price = atoi(price);
        fwrite(&publishing, sizeof(publishing), 1, fname);
        if (ferror(fname)) {
            printf(" Error in writing \n ");
            return fname;
        }
    }
    fclose(fname);
    return fname;
}

void search(filetype fname) {
    char filename[10], code[7];
    printf("File name : ");
    gets(filename);
    gets(filename);
    printf(" \"->%s\"\n", filename);
    char *filePath = getFilePath(filename);
    if ((fname = fopen(filePath, "r")) == NULL) {
        printf(" Error in opening file \n ");
        free(filePath);
        return;
    }
    free(filePath);
    printf(" Code: ");
    gets(code);
    int n = 0;
    while (fread(&publishing, sizeof(publishing), 1, fname) == 1) {
        if (ferror(fname)) {
            printf(" Error in reading file \n ");
            return;
        }
        if (strcmp(publishing.code, code) == 0) {
            printf(" Title = %s \n", publishing.title);
            printf(" price = %d \n\n", publishing.price);
            n++;
        }
    }
    fclose(fname);
    if (n != 0) return;
    printf(" Not found\n");
    return;
}

int main(void) {
    filetype fp;
    int ch = 0;
    while (1) {
        ch = menu();
        switch (ch) {
            case 1:
                printf(" \"Create file\"\n");
                CreateFile(fp);
                break;
            case 2:
                printf(" \"Display Data in file\"\n");
                Display(fp);
                break;
            case 3:
                printf(" \"Insert Data in file\"\n");
                Insert(fp);
                break;
            case 4:
                printf(" \"Search Data in file\"\n");
                search(fp);
                break;
            case 5:
                printf(" \"Stop running program\"\n");
                exit(0);
            default:
                printf(" \"Please enter 1-5 only\"\n");
        }
        printf("<------------------------------------------>\n");
    }
}
