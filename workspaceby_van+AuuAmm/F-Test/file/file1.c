# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <conio.h>

typedef FILE *file;

struct struct_office
{
    char day[10], month[10], year[10];
}office;

struct data_infomath
{
    char id[10], name[30], lastname[30], height[10], weight[10];
    struct struct_office office;
}infomath;

file create(file fname){
    char filename[20];
    printf("File name: ");
    gets(filename);
    gets(filename);
    if ((fname = fopen(filename, "w")) == NULL){
        printf("Error create file");
        return 0;
    }
    while (1){
        printf("ID (Enter to stop): ");
        gets(infomath.id);
        if (infomath.id[0] == '\0') break;
        printf("Name: ");
        gets(infomath.name);
        printf("Lastname: ");
        gets(infomath.lastname);
        printf("Height: ");
        gets(infomath.height);
        printf("Weight: ");
        gets(infomath.weight);
        printf("Time \n");
        printf("Day:");
        gets(infomath.office.day);
        printf("Month: ");
        gets(infomath.office.month);
        printf("Year: ");
        gets(infomath.office.year);
        fwrite(&infomath, sizeof(infomath), 1, fname);
        if (ferror(fname)){
            printf("Error");
            return fname;
        }
    }
    fclose(fname);
    return fname;
}

void display(file fname){
    char filename[20];
    printf("File name: ");
    gets(filename);
    gets(filename);
    if ((fname = fopen(filename, "r")) == NULL){
        printf("Error to read");
        return;
    }
    while(fread(&infomath, sizeof(infomath), 1, fname) == 1){
        if (ferror(fname)){
            printf("Error to read");
            return;
        }
        else{
            printf("ID: %s \n", infomath.id);
            printf("Name: %s \n", infomath.name);
            printf("Lastname: %s \n", infomath.lastname);
            printf("Height: %s \n", infomath.height);
            printf("Weight: %s \n", infomath.weight);
            printf("Time: %s/%s/%s \n", infomath.office.day, infomath.office.month, infomath.office.year);
        }
    }
    fclose(fname);
}

int main(){
    file fp;
    while (1){
        int ch;
        printf("1. Create file \n");
        printf("2. Display file \n");
        printf("3. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch){
            case 1:
                fp = create(fp);
                break;
            case 2:
                display(fp);
                break;
            case 3:
                exit(0);
            default:
                printf("Enter again \n");
                break;
        }
        printf("\n\n");
    }
}