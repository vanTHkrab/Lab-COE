#include <stdio.h>
#include <stdlib.h>
typedef struct nodestruct *nodetype;
struct nodestruct{
    int data;
    nodetype next;
};
nodetype Sc(nodetype first){
    nodetype newnode;
    int a;
    printf("Input Number(0 for stop): ");
    scanf("%d",&a);
    while(a!=0){
    newnode = (nodetype)malloc(sizeof(struct nodestruct));
    newnode->data = a;
    newnode->next = first;
    first = newnode;
    scanf("%d",&a);
    }
    return first;}
nodetype Divide(nodetype first,nodetype second){
    while(first!=NULL){
    if(first->data%7==0){
    nodetype newnode;
    newnode = (nodetype)malloc(sizeof(struct nodestruct));
    newnode->data = first->data;
    newnode->next = second;
    second = newnode;}
    first = first->next;
    }
    return second;}
void pr(nodetype second){
    while(second!=NULL){
    printf("%d\n",second->data);
    second=second->next;
    }}
int main(){
    nodetype first = NULL,second = NULL;
    first = Sc(first);
    second = Divide(first,second);
    pr(second);
    return 0;
    }