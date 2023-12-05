#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int main(){
    char a[5] = "1234";
    char b[5];
    strcpy(a, b);
    
    printf("%s", b);
}