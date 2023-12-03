# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct number *datanum;
struct number {
    int num;
    int position;
    datanum next;
};

typedef struct odd *odd;
struct odd {
    int numodd, positionodd;
    odd oddnext;
};

typedef struct even *even;
struct even {
    int numeven, positioneven;
    even evennext;
};

// ------------------------------------------------------------

datanum getdatanum(datanum num) {
    datanum newnode;
    int n;
    int position = 1;
    printf("Enter a number (Stop enter -1): ");
    do {
        newnode = (datanum)malloc(sizeof(struct number));
        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        newnode->num = n;
        newnode->position = position++;
        newnode->next = num;
        num = newnode;
    } while (1);
    return num;
}

odd search_odd(odd numodd, datanum num) {
    datanum oddtemp = num;
    odd newnode;
    while (oddtemp != NULL) {
        if (oddtemp->num % 2 != 0) {
            newnode = (odd)malloc(sizeof(struct odd));
            newnode->numodd = oddtemp->num;
            newnode->positionodd = oddtemp->position;
            newnode->oddnext = numodd;
            numodd = newnode;
        }
        oddtemp = oddtemp->next;
    }
    return numodd;
}

even search_even(even numeven, datanum num) {
    datanum eventemp = num;
    even neweven;
    while (eventemp != NULL) {
        if (eventemp->num % 2 == 0) {
            neweven = (even)malloc(sizeof(struct even));
            neweven->numeven = eventemp->num;
            neweven->positioneven = eventemp->position;
            neweven->evennext = numeven;
            numeven = neweven;
        }
        eventemp = eventemp->next;
    }
    return numeven;
}

void display(datanum num) {
    datanum temp;
    temp = num;
    printf("List of number: ");
    while (temp != NULL) {
        printf("%d ", temp->num);
        temp = temp->next;
    }
    printf("\n");
}

// ------------------------------------------------------------


void display_odd(odd numodd) {
    odd pr, pt;
    pr = numodd;
    pt = numodd;
    int count = 0;
    printf("\nList of odd number:             ");
    while (pr != NULL) {
        printf("%d ", pr->numodd);
        pr = pr->oddnext;
        count++;
    }
    printf("\nList of position of odd number: ");
    while (pt != NULL) {
        printf("%d ", pt->positionodd);
        pt = pt->oddnext;
    }
    printf("\ntotal of odd :%d\n", count);
    printf("\n");
}

void search_odd_position(odd numodd, datanum num) {
    datanum oddtemp = num;
    odd newnode;
    int n, count = 0, a[100];
    printf("Enter number: ");
    scanf("%d", &n);
    if (n % 2 == 0) {
        printf("Not odd number\n");
        return;
    }
    while(oddtemp != NULL){
        if(oddtemp->num == n){
            a[count] = oddtemp->position;
            count++;
        }
        oddtemp = oddtemp->next;
    }
    printf("Position of %d: ", n);
    if (count == 0) printf("Not found\n");
        else{
        for(int i = 0; i < count; i++){
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}
// ------------------------------------------------------------

void display_even(even numeven) {
    even er, et;
    er = numeven;
    et = numeven;
    int count = 0;
    printf("\nList of even number:             ");
    while (er != NULL) {
        printf("%d ", er->numeven);
        er = er->evennext;
        count++;
    }
    printf("\nList of position of even number: ");
    while (et != NULL) {
        printf("%d ", et->positioneven);
        et = et->evennext;
    }
    printf("\ntotal of even :%d\n", count);
}

void search_even_position(even numeven, datanum num) {
    datanum eventemp = num;
    even neweven;
    int n, count = 0, a[100];
    printf("Enter number: ");
    scanf("%d", &n);
    if (n % 2 != 0) {
        printf("Not even number\n");
        return;
    }
    while(eventemp != NULL){
        if(eventemp->num == n){
            a[count] = eventemp->position;
            count++;
        }
        eventemp = eventemp->next;
    }
    printf("Position of %d: ", n);
    if (count == 0) printf("Not found\n");
    else{
        for(int i = 0; i < count; i++){
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// ------------------------------------------------------------

int main() {
    datanum num;
    odd numodd;
    even numeven;
    num = NULL;
    numodd = NULL;
    numeven = NULL;
    // display(num);
    while(1){
        int n;
        printf("1. Add number\n2. Display\n3. Search odd position\n4. Search even position\n5. Display odd\n6. Display even\n7. Clear number\n8. Exit\n-> ");
        scanf("%d", &n);
        if (num == NULL && n != 1 && n != 8) {
            printf("Please add number\n___________________________\n");
            continue;
        }
        switch (n) {
            case 1:
                num = getdatanum(num);
                numodd = search_odd(numodd, num);
                numeven = search_even(numeven, num);
                break;
            case 2:
                display(num);
                break;
            case 3:
                search_odd_position(numodd, num);
                break;
            case 4:
                search_even_position(numeven, num);
                break;
            case 5:
                display_odd(numodd);
                break;
            case 6:
                display_even(numeven);
                break;
            case 7:
                num = NULL;
                numodd = NULL;
                numeven = NULL;
                break;
            case 8:
                printf("Exit program, Thanks\n");
                exit(0);
                break;
            default:
                printf("Enter Just 1-8\n");
                break;
        }
        printf("_________________________________________________\n");
    }
    return 0;
}