# include <stdio.h>

int main() {
    char name[100][100], lastname[100][100], age[100][100];
    float gpa[100];
    int count = 0;
    int k;
    printf("Enter 0 to stop");
    do{
        printf("\n");
        printf("Enter 0 to stop, 1 to continue: ");
        scanf("%d", &k);
        if (k == 0) {
            break;
        }
        printf("Enter name:");
        scanf("%s", &name[count]);
        printf("%s\n", name[count]);
        printf("Enter lastname:");
        scanf("%s", &lastname[count]);
        printf("Enter age:");
        scanf("%s", &age[count]);
        printf("Enter grade:");
        scanf("%d", &gpa[count]);
        count++;
    } while (1);
    printf("\n");
    for (int i = 0; i < count; i++){
        printf("Record #%d\n", i + 1);
        printf("Name: %s\n", name[i]);
        printf("Lastname: %s\n", lastname[i]);
        printf("Age: %s\n", age[i]);
        printf("Grade: %d\n", gpa[i]);
        printf("-----------------------\n");
    }
}