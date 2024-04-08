#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	int coe;
    int exp;
	struct node* next;
}listnode;

void appendTerm(listnode* p, int c, int e){
    listnode* new = (listnode*)malloc(sizeof(listnode*));
    new->coe = c;
    new->exp = e;
    while(p->next != NULL){ p = p->next; }
    p->next = new;
}

listnode* addPoly(listnode* x, listnode* y){
    listnode* fir = (listnode*)malloc(sizeof(listnode*));
    listnode* sec = (listnode*)malloc(sizeof(listnode*));

    listnode* rst = (listnode*)malloc(sizeof(listnode*));
    rst->next = NULL;
    fir = x; sec = y;

    while(fir != NULL && sec != NULL){
        if(fir->exp > sec->exp){

        }
    }

}

int main(){
    //순환문이용
    int n; scanf("%d",&n);
    int *num = (int *)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    for(int i=0;i<n;i++)printf("%d",num[i]);



} 
