# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <conio.h>

typedef FILE *file;

struct databook{
    char BookID[10];
    char name[30];
    char author[30];
    char publisher[30];
    char Booknum[10];
    int year;
    int num;
}b;

void getdata(){
    printf("Enter BookID: ");
    scanf("%s", b.BookID);
    printf("Enter name: ");
    scanf("%s", b.name);
    printf("Enter author: ");
    scanf("%s", b.author);
    printf("Enter publisher: ");
    scanf("%s", b.publisher);
    printf("Enter Booknum: ");
    scanf("%s", b.Booknum);
    printf("Enter year: ");
    scanf("%d", &b.year);
    printf("Enter num: ");
    scanf("%d", &b.num);
}

file create(file fname){
    char name[30];
    printf("Enter file name: ");
    scanf("%s", name);
    if((fname = fopen(name, "w")) == NULL){
        printf("Cannot create file.\n");
        return NULL;
    }
    fclose(fname);
    return fname;
}

file inputdatabook(file fname){
    char name[30];
    printf("Enter file name: ");
    scanf("%s", name);
    if((fname = fopen(name, "a")) == NULL){
        printf("Cannot open file.\n");
        return NULL;
    }
    fwrite(&b, sizeof(b), 1, fname);
    fclose(fname);
    return fname;
}

void displaydatabook(file fname){
    char name[30];
    printf("Enter file name: ");
    scanf("%s", name);
    if((fname = fopen(name, "r")) == NULL){
        printf("Cannot open file.\n");
        return;
    }
    while(fread(&b, sizeof(b), 1, fname) == 1){
        printf("BookID: %s\n", b.BookID);
        printf("Name: %s\n", b.name);
        printf("Author: %s\n", b.author);
        printf("Publisher: %s\n", b.publisher);
        printf("Booknum: %s\n", b.Booknum);
        printf("Year: %d\n", b.year);
        printf("Num: %d\n", b.num);
    }
    fclose(fname);
}

void search(file fname){
    char name[30];
    printf("Enter file name: ");
    scanf("%s", name);
    if((fname = fopen(name, "r")) == NULL){
        printf("Cannot open file.\n");
        return;
    }
    char BookID[10];
    printf("Enter BookID: ");
    scanf("%s", BookID);
    while(fread(&b, sizeof(b), 1, fname) == 1){
        if(strcmp(b.BookID, BookID) == 0){
            printf("BookID: %s\n", b.BookID);
            printf("Name: %s\n", b.name);
            printf("Author: %s\n", b.author);
            printf("Publisher: %s\n", b.publisher);
            printf("Booknum: %s\n", b.Booknum);
            printf("Year: %d\n", b.year);
            printf("Num: %d\n", b.num);
        }
    }
    fclose(fname);
}

int main(){
    int n;
    file fname;
    while(1){
        printf("Func (gets()) Have many bugs -_- .\n");
        printf("1. Create file\n");
        printf("2. Input data Book\n");
        printf("3. Input data Book to file\n");
        printf("4. Display data Book\n");
        printf("5. Search\n");
        printf("6. Exit\n");
        printf("Enter: ");
        scanf("%d", &n);
        switch(n){
            case 1:
                fname = create(fname);
                break;
            case 2:
                getdata();
                break;
            case 3:
                fname = inputdatabook(fname);
                break;
            case 4:
                displaydatabook(fname);
                break;
            case 5:
                search(fname);
                break;
            case 6:
                exit(0);
            default:
                printf("Enter again.\n");
        }
        printf("<---------------------->\n")
    }
    return 0;
}