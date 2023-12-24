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
    char id[100], name[100], lastname[100], high[100], weight[100];
    struct struct_office office;
}infomath;

file create(file fname){
    char filename[100];
    printf("File name : ");
    gets(filename);
    gets(filename);
    if ((fname = fopen(filename, "w")) == NULL){
        printf("Error creating file");
        return 0;
    }
    while (1){
        printf("ID (Enter to stop): ");
        gets(infomath.id);
        if (strlen(infomath.id) == 0)break;
        printf("Name : ");
        gets(infomath.name);
        printf("Lastname : ");
        gets(infomath.lastname);
        printf("High : ");
        gets(infomath.high);
        printf("Weight : ");
        gets(infomath.weight);
        printf("Time \n");
        printf("Day : ");
        gets(infomath.office.day);
        printf("Month : ");
        gets(infomath.office.month);
        printf("Year : ");
        gets(infomath.office.year);
        fwrite(&infomath, sizeof(infomath), 1, fname);
        if (ferror(fname)){
            printf("Error writing file");
            return 0;
        }
    }
    fclose(fname);
    return fname;
}

void display(file fname){
    char filename[100];
    printf("File name : ");
    gets(filename);
    gets(filename);
    if ((fname = fopen(filename, "r")) == NULL){
        printf("Error to read");
        return;
    }
    while(fread(&infomath, sizeof(infomath), 1, fname)){
        if (ferror(fname)){
            printf("Error to read");
            return;
        }
        else{
        printf("ID : %s\n", infomath.id);
        printf("Name : %s\n", infomath.name);
        printf("Lastname : %s\n", infomath.lastname);
        printf("High : %s\n", infomath.high);
        printf("Weight : %s\n", infomath.weight);
        printf("Time : %s/%s/%s\n", infomath.office.day, infomath.office.month, infomath.office.year);
        }
    }
    fclose(fname);
}

int main(){
    file fp;
    int ch;
    while (1){
        printf("1. Create file\n");
        printf("2. Display file\n");
        printf("3. Exit\n");
        printf("Enter your choice : ");
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
                printf("Invalid choice\n");
                break;
        }
        printf("\n\n");
    }
}