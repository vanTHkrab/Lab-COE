# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct datalink1 link1;
typedef struct datalink2 link2;

struct datalink1
{
    char name[10];
    char id[10];
    char age[5];
    struct datalink2 *info;
    link1 next1;
};

struct datalink2 {
    char address[10];
    char phone[10];
    link2 next2;
};

link1 creat(link1 d1){

}

link1 info(link1 d1){

}

int main(){

}

