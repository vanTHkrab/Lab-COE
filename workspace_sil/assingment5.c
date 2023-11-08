#include<stdio.h>

struct info {
    char id[20] ;    
    char surename[20] ;     
    char lastname[20] ;
} client ; 
    
int main () {
    
    printf("Enter Your ID : ") ;
    scanf("%s",&client.id) ;
    printf("\nEnter Your Surename : ") ;
    scanf("%s",&client.surename) ;
    printf("\nEnter Your Lastname : ") ;
    scanf("%s",&client.lastname) ;
    
    int n ;
    printf("\nHow Many Account Do You Have : ") ;
    scanf("%d",&n) ;
    
    int DAN[n] ;
    int y[n] ;
    int x[n] ;
    int i, j=0 ;
    for(i=0;i<n;i++) {
        printf("\n(Account %d) Deposit Account Number : ",i+1) ;
        scanf("%d",&DAN[i]) ;
        printf("\nPress 1 Mean Savings Account\nPress 2 is Mean Daily Current Account\n") ;
        scanf("%d",&x[i]) ;
        
        if(x[i]==1) {
            printf("Account Deposit Balance : ") ;
            scanf("%d",&y[j]) ;
        } else if(x[i]==2) {
            printf("\nAccount Deposit Balance : ") ;
            scanf("%d",&y[j]) ;
            printf("\nCredits Limit : 40,000 Bath") ;
        } j++ ;
    }
    
    printf("\n\n_____Your Information_____\n") ;
    printf("\nClient ID : %s",client.id) ;
    printf("\nClient Name : %s\t%s",client.surename, client.lastname) ;
    printf("\nAmount of Account : %d",n) ;
    
    for(i=0;i<n;i++) {
        if(x[i]==1) {
        printf("\n(Account %d) Deposit Account Number : %d",i+1, DAN[i]) ;
        printf("\nRemaining a Deposit Balance : %d",y[i]) ;
        } else if(x[i]==2) {
        printf("\n(Account %d) Deposit Account Number : %d",i+1, DAN[i]) ;
        printf("\nRemaining a Deposit Balance : %d",y[i]) ;
        printf("\nHave Credit Limit : 40,000 Bath") ;
        }
    }
}