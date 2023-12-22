# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <conio.h>

typedef FILE *file;

struct publishstruct {
    char code[7];
    char title[20];
    int price;
} publishing;

file creatfile(file fname){
    char filename[10];
    printf("File name : ");
    gets(filename);
    gets(filename);
    if((fname = fopen(filename, "w"))== NULL){
        printf("Error in opening file\n");
        return fname;
    }
    while(1){
        printf("Code (Enter = Quit) : ");
        gets(publishing.code);
        if(publishing.code[0] == '\0') {
            printf("\n\n");
            break;
        }
        printf("Title : ");
        gets(publishing.title);
        printf("Price : ");
        scanf("%d", &publishing.price);
        fwrite(&publishing, sizeof(publishing), 1, fname);
        if (ferror(fname)){
            printf("Error in writing\n");
            return fname;
        }
    }
    fclose(fname);
    return fname;
}
void read(file fname){
    char filename[10];
    printf("File name : ");
    gets(filename);
    gets(filename);
    if((fname = fopen(filename, "r")) == NULL){
        printf("Error in opening file\n");
        return;
    }
    while(1) {
        if (ferror(fname)) {
            printf("Error in reading\n");
            return;
        }
        fread(&publishing, sizeof(publishing), 1, fname);
        if (feof(fname)) {
            printf("End of file\n");
            return;
        }
        printf("Code = %s\n", publishing.code);
        printf("Title = %s\n", publishing.title);
        printf("Price = %d\n", publishing.price);
    }
    fclose(fname);
}

int main(){
    file fname;
    int answer;
    while(1){
        printf("1. Create file\n");
        printf("2. Read file\n");
        printf("3. Exit\n");
        printf("Your choice : ");
        scanf("%d", &answer);
        switch(answer){
            case 1:
                fname = creatfile(fname);
                break;
            case 2:
                read(fname);
                break;
            case 3:
                return 0;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;

}