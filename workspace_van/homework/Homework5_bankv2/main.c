#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data_member *member;
struct data_member {
    char Customer_ID[10];
    char name[30];
    char lastname[30];
    char creditID[15];
    char type[15];
    float balance;
    float credit_limit;
    member next;
};

member newmember(member *member){
    
}