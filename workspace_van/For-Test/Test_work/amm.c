# include <stdio.h>

typedef struct amm_auu amm;
struct amm_auu
{
    int number, sum;

};

void howtomarry(amm *k){
    printf("Enter name : ");
    scanf("%s", k->name);    
}

int main(){
    amm amm;
    howtomarry(&amm);
    printf("%s", amm.name);
}

