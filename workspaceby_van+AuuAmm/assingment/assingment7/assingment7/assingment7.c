// add insert and search

# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# include <string.h>

struct publishstruct {
    char code[7];
    char title[20];
    int price;
} publishing;

typedef FILE *filetype;

int menu(){
    int answer;
    printf(" MENU\n");
    printf(" [1] Create file\n");
    printf(" [2] Display Data in file\n");
    printf(" [3] Insert Data in file\n");
    printf(" [4] Search Data in file\n");
    printf(" [5] Stop running program\n\n");
    printf(" Your answer :");
    scanf("%d",&answer);
    return(answer);
}

filetype CreateFile(filetype fname){
    char filename[10], price[6];
    printf(" File name : ");
    gets(filename);
    gets(filename);
    printf("%s\n",filename) ;
    if (( fname = fopen(filename,"w")) == NULL ) {
        printf(" Error in opening file \n " );
        return(fname);
        }
    while (1) {
        printf(" Code ( Enter = Quit ) : ");
        gets(publishing.code);
        if (publishing.code[0] == '\0' ) break;
        printf(" Title : " );
        gets(publishing.title);
        printf(" Price : ");
        gets(price);
        publishing.price = atoi(price);
        fwrite(&publishing,sizeof(publishing),1,fname);
        if (ferror(fname)) {
            printf(" Error in writing \n ");
            return(fname);
        }
    }
    fclose(fname);
    return(fname);
}

void Display(filetype fname) {
    char filename[10];
    printf(" File name : ");
    gets(filename);
    gets(filename);
    if ((fname = fopen(filename,"r")) == NULL) {
        printf(" Error in opening file \n ");
        return;
    }
    while (fread(&publishing ,sizeof(publishing),1,fname) == 1){
    if (ferror(fname)) {
        printf(" Error in reading file \n ");
        return;
    }
    else {
        printf("code = %s \n",publishing.code);
        printf("Title = %s \n",publishing.title);
        printf("price = %d \n",publishing.price);
        }
    }
}

filetype Insert(filetype fname){
    char filename[10], price[6];
    printf(" File name : ");
    gets(filename);
    gets(filename);
    printf("%s\n",filename) ;
    if (( fname = fopen(filename,"r")) == NULL ) {
        printf(" Error in opening file \n " );
        return(fname);
        }
    fclose(fname);
    if (( fname = fopen(filename,"a")) == NULL ) {
        printf(" Error in opening file \n " );
        return(fname);
        }
    while (1) {
        printf(" Code ( Enter = Quit ) : ");
        gets(publishing.code);
        if (publishing.code[0] == '\0' ) break;
        printf(" Title : " );
        gets(publishing.title);
        printf(" Price : ");
        gets(price);
        publishing.price = atoi(price);
        fwrite(&publishing,sizeof(publishing),1,fname);
        if (ferror(fname)) {
            printf(" Error in writing \n ");
            return(fname);
        }
    }
    fclose(fname);
    return(fname);
}

void search(filetype fname){
    char filename[10], code[7];
    printf("File name : ");
    gets(filename);
    gets(filename);
    printf("%s\n",filename) ;
    if (( fname = fopen(filename,"r")) == NULL ) {
        printf(" Error in opening file \n " );
        return;
        }
    printf(" Code ( Enter = Quit ) : ");
    gets(code);
    while (fread(&publishing ,sizeof(publishing),1,fname) == 1){
        if (ferror(fname) ) {
            printf(" Error in reading file \n ");
            return;
        }
        if (strcmp(publishing.code,code)==0){
            printf(" code = %s \n",publishing.code);
            printf(" Title = %s \n",publishing.title);
            printf(" price = %d \n",publishing.price);
            return;
        }
    }
    printf(" Not found\n");
}/


int main(void) {
    filetype fp;
    int ch = 0;
    while(1){
        ch = menu();
        switch (ch) {
            case 1: 
                CreateFile(fp); 
                break;
            case 2: 
                Display(fp);
                break;
            case 3: 
                Insert(fp); 
                break;
            case 4:
                search(fp);
                break;
            case 5: 
                exit(0);
            default: 
                printf("Please enter 1-5 only\n");
        }
    }
}