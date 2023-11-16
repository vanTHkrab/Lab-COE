# include <stdio.h>

int main(){
    int a;
    while (1)
    {
        printf("Enter number: "); scanf("%d", &a);
        if(a == 15){ 
            printf("You are something forget \nBye");
            break;
        }
        if(a < 15) printf("You are less than \n");
        if(a > 15) printf("You are greater than \n");
    }
    
}