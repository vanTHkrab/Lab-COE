#include <stdio.h>
int main () {
    int num[1000], i, ce=0, co=0 ;
    
    for (i=0;i<1000;i++) {
        printf("Press 0 to Stop\n") ;
        printf("Enter Your Number = ") ;
        scanf("%d",&num[i]) ;
        
        if (num[i]%2==0 && num[i]!=0) {
            ce = ce+1 ;
        }
        else if (num[i]%2!=0 && num[i]!=0) {
            co = co+1 ;
        }
    if (num[i]==0) {
        printf("Stop Input\n") ;
        printf("Even Number are include : \n%d\n",num[i]) ;
        printf("Amount of Even Number = %d\n",ce) ;
        printf("Odd Number are include : \n%d\n",num[i]) ;
        printf("Amount of Odd Number = %d\n",co) ;
        break ;
        
    }
    else if (num[i]!=0) {
        continue ;
    }
    }
}