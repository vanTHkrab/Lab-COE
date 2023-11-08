# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct data_subject subjeat;
struct data_subject{
    char name[10000];
    float teacherpoint, subjeatpoint, subjectlevel;
};

typedef struct info_format_subject datasubject;
struct info_format_subject  {
    char nameofsubject[22];
    struct data_subject subjeat;
};

int main(){
    datasubject ps;
    int i = 0;
    float minsl = 5, minsp = 5, mintp = 5;
    float maxsl = 0, maxsp = 0, maxtp = 0;
    float sumsl = 0, sumsp = 0, sumtp = 0;
    printf("Subject: ");
    scanf("%s", &ps.nameofsubject);

    while(1){
        printf("Enter \" ! \"In Name To Stop\n");
        printf("Name: ");
        scanf("%s", &ps.subjeat.name);
        if (strcmp(ps.subjeat.name, "!") == 0){
            break;
        }
        do{
        printf("Difficulty course of %s (5 - 0) : ", ps.nameofsubject);
        scanf("%f", &ps.subjeat.subjectlevel);
        }while (ps.subjeat.subjectlevel > 5 || ps.subjeat.subjectlevel < 0);
        if (maxsl < ps.subjeat.subjectlevel){
            maxsl = ps.subjeat.subjectlevel;
        }
        if (minsl > ps.subjeat.subjectlevel){
            minsl = ps.subjeat.subjectlevel;
        }
        sumsl += ps.subjeat.subjectlevel;

        do{
        printf("Course liking score of %s (5 - 0)  : ", ps.nameofsubject);
        scanf("%f", &ps.subjeat.subjeatpoint);
        }while (ps.subjeat.subjeatpoint > 5 || ps.subjeat.subjeatpoint < 0);
        if (maxsp < ps.subjeat.subjeatpoint){
            maxsp = ps.subjeat.subjeatpoint;
        }
        if (minsp > ps.subjeat.subjeatpoint){
            minsp = ps.subjeat.subjeatpoint;
        }
        sumsp += ps.subjeat.subjeatpoint;

        do{
        printf("Teacher liking score of %s (5 - 0)) : ", ps.nameofsubject);
        scanf("%f", &ps.subjeat.teacherpoint);
        }while (ps.subjeat.teacherpoint > 5 || ps.subjeat.teacherpoint < 0);
        if (maxtp < ps.subjeat.teacherpoint){
            maxtp = ps.subjeat.teacherpoint;
        }
        if (mintp > ps.subjeat.teacherpoint){
            mintp = ps.subjeat.teacherpoint;
        }
        sumtp += ps.subjeat.teacherpoint;

        i++;
        printf("\n");
    }
    printf("\nMax:\nDifficulty: %.2f  Course: %.2f  Teacher: %.2f\n", maxsl, maxtp, maxsp);
    printf("\nMin:\nDifficulty: %.2f  Course: %.2f  Teacher: %.2f\n", minsl, mintp, minsp);
    printf("\nAverange:\nDifficulty: %.2f  Course: %.2f  Teacher: %.2f\n", sumsl / i, sumsp / i, sumtp / i); 
    // printf("Test 2");
}