typedef struct  stdrecord *stdtype;
struct  stdrecord {
	char  id[8];
	char  name[50];
	float  gpax;
	stdtype  next;
};
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int menu(){
	int answer;
	printf("                MENU\n");
	printf(" [1] Create student linked list\n");
	printf(" [2] Search student in linked list\n");
	printf(" [3] Insert student in linked list\n");
	printf(" [4] Delete student in linked list\n");
	printf(" [5] Print all student in linked list\n");
	printf(" [6] Stop running program\n\n");
	printf(" Your answer :");
	scanf("%d",&answer);
	return(answer);
}

stdtype  create(stdtype  std){
	stdtype newnode;
	char stdid[8];
	printf("Input student id is 0 for stop \n");
	scanf("%s",stdid);
	while (atoi(stdid)!= 0) {
		newnode = (stdtype)malloc(sizeof(stdtype));
		strcpy(newnode->id,stdid);
		printf("Input student name := ");
		scanf("%s",newnode->name);
		printf("Input GPAX := ");
		scanf("%f",&newnode->gpax);	
		newnode->next = std;
		std = newnode;
		printf("Input student id := ");
		scanf("%s",stdid);
	}
	return(std);
}

void search(stdtype std){
	stdtype  temp;
	char stdid[8],found = 'F';
	temp = std;
	printf("Input id for search := ");
	scanf("%s",stdid);
	while ((temp != NULL)&&(found == 'F')){
		if (strcmp(stdid,temp->id) == 0)
		   found = 'T';
		else
		   temp = temp->next;
	}
	if (found == 'T'){
	  printf("FOUND!!!\n");
	  printf("Name = %s\n",temp->name);
	  printf("GPAX = %0.2f\n",temp->gpax);
	}
	else
	  printf("NOT FOUND!!!\n");
}

stdtype insertnode(stdtype std){
	stdtype newnode;
	char stdid[8];
	newnode = (stdtype)malloc(sizeof(stdtype));
	printf("Input student id for insert := ");
	scanf("%s",newnode->id);
	printf("Input student name := ");
	scanf("%s",newnode->name);
	printf("Input GPAX := ");
	scanf("%f",&newnode->gpax);	
	newnode->next = std;
	std = newnode;
	return(std);
}

stdtype deletenode(stdtype std){
	std = std->next;
	return(std);
}

void display(stdtype  std){
	stdtype temp;
	int i;
	temp = std;
	i = 1;
	while (temp != NULL){
		printf("record #%d\n",i);
		printf("Id = %s\n",temp->id);
		printf("Name = %s\n",temp->name);
		printf("Gpax = %0.2f\n",temp->gpax);
		temp = temp->next;
		i = i+1;
	}
}

int main(void) {
	stdtype  std;
	int ch = 0;
	std = NULL;
	while (ch!=6) {
		ch = menu();
	    if (ch==1){
	    	std = NULL;
	    	std = create(std);
		}
		else if (ch==2)
			search(std);
	   	else if (ch ==3)
		   std = insertnode(std);
		else if(ch==4)      
		   std = deletenode(std);
		else if(ch==5)
		    display(std);
		else
		    printf("You must be input 1-6 only\n\n");
	}
}