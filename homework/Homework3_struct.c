# include <stdio.h>
// wednesday afternoon
typedef struct data_subject subjeat;
struct data_subjeat{
    char namesubject[22], commentsubject[200];
    float teacherpoint, subjeatpoint, subjectlevel;
};

typedef struct info_format_personal personalstudent;
struct info_format_personal {
    char dataname[10000];
    struct data_subjeat subjeat;
};

int main(){
    personalstudent ps;
    int i, name[100], count = 0;
    printf("Enter \" n \" To stop\n");
    while(1){
        printf("Name: ");
        scanf("%s", &name[count++]);
        if (name[count - 1] == 'n'){
            break;
        }
        printf("Subject: ");
        scanf("%s", ps.subjeat.namesubject);
        printf("Difficulty of %s (1-5): ", ps.subjeat.namesubject);
        scanf("%f", ps.subjeat.subjectlevel);
        printf("Level(1-5) %s: ", ps.subjeat.namesubject);
        scanf("%f", ps.subjeat.subjectlevel);
        printf("Test\n");
    }
    printf("Test 2");
}