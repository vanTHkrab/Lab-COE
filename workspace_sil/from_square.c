#include <stdio.h>
#include <string.h>

int main() {
    char car[14][3][50] = {
    
        {"Personal Car", "110", "Personal Use"},
        {"", "120", "Commercial Use"},
        {"Passenger Car", "210", "Personal Use"},
        {"", "220", "Commercial Use"},
        {"", "230", "Public Employment"},
        {"Truck", "320", "Commercial Use"},
        {"", "320", "Special Commercial Use"},
        {"Tow Truck", "420", "Commercial Use"},
        {"Trailer", "520", "Commercial Use"},
        {"", "540", "Special Commercial Use"},
        {"Mortocycle", "610", "Personal Use"},
        {"", "620", "Commercial Use"},
        {"", "630", "Public Employment"},
        {"Taxi", "730", "Public Employment"}
    } ;
    
    printf("_____Car's Information_____\n\n");
    printf(" [Car's Type]  [Car's ID]    [Use for]\n");
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%s ", car[i][j]);
            int str_head[3] = {17, 7, 10};
            for (strlen(car[i][j]) , str_head[2];strlen(car[i][j]) < str_head[j];str_head[j]--){
                printf(" ");
            }
        }
        printf("\n");
    }
}