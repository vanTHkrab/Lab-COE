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
    printf("\n");
    printf("List of position of odd number: ");
    while (pt != NULL) {
        printf("%d ", pt->positionodd);
        pt = pt->oddnext;
    }
    printf("\n");
    printf("total of odd :%d\n", count);
}
// ------------------------------------------------------------
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
    printf("\n");
    printf("List of position of even number: ");
    while (et != NULL) {
        printf("%d ", et->positioneven);
        et = et->evennext;
    }
    printf("\n");
    printf("total of even :%d\n", count);
}

// ------------------------------------------------------------

int main() {
    datanum num;
    odd numodd;
    even numeven;
    num = NULL;
    numodd = NULL;
    numeven = NULL;
    num = getdatanum(num);
    // display(num);
    numodd = search_odd(numodd, num);
    display_odd(numodd);
    numeven = search_even(numeven, num);
    display_even(numeven);
    return 0;
}