#include<stdio.h>

struct info {
    char id[20] ;    
    char surename[20] ;     
    char lastname[20] ;
} client ; 
    
int main () {

int p, i ;
    printf("How Many People Do You Want, sir? : ") ;
    scanf("%d",&p) ;

for(i=0;i<p;i++) {
    printf("Client (%d)\n",i+1) ;
    printf("Enter Your ID : ") ;
    scanf("%s",&client.id) ;
    printf("\nEnter Your Surename : ") ;
    scanf("%s",&client.surename) ;
    printf("\nEnter Your Lastname : ") ;
    scanf("%s",&client.lastname) ;
    
int n ;
    printf("\nAccount Limit at 10") ;
    printf("\nHow Many Account Do You Have : ") ;
    scanf("%d",&n) ;
int DAN[n] ;
    int y[n] ;
    int x[n] ;
    int z[n] ;
    int j=0 ;
do {
    if (n<=10) {
    
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
            printf("\nCredits Limit : ") ;
            scanf("%d",&z[j]) ;
        } j++ ;
    } 
    } else
            printf("\nYour Account More than 10") ;
            break ; 
} while(1) ;   
    printf("\n\n_____Your Information_____\n") ;
    printf("\nClient ID : %s",client.id) ;
    printf("\nClient Name : %s\t%s",client.surename, client.lastname) ;
    printf("\nAmount of Account : %d",n) ;
for(i=0;i<p;i++) {
    for(i=0;i<n;i++) {
        if(x[i]==1) {
            printf("\n(Account %d) Deposit Account Number : %d",i+1, DAN[i]) ;
            printf("\nRemaining a Deposit Balance : %d",y[i]) ;
        } else if(x[i]==2) {
            printf("\n(Account %d) Deposit Account Number : %d",i+1, DAN[i]) ;
            printf("\nRemaining a Deposit Balance : %d",y[i]) ;
            printf("\nRemaining a Credit Limit : %d",z[i]) ;
        }
        } 
    }
}
}



