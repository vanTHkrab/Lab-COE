# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct test1{
    int a;
    char b[100];
}t1;

typedef struct test2{
    int c;
    char d[100];
    struct test1 t1;
}t2;

int main(){
    t2 t;
    t.t1.a = 1;
    strcpy(t.t1.b, "Hello");
    printf("%d %s", t.t1.a, t.t1.b);
}