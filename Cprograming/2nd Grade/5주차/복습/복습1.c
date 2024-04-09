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

    int sum_coe;
    while(fir != NULL && sec != NULL){
        if(fir->exp > sec->exp){
            rst->coe = fir->coe;rst->exp = fir->exp;
            printf("%d %d\n",rst->coe,rst->exp);
            rst = rst->next;

            fir = fir->next;
        }
        else if(fir->exp < sec->exp){
            rst->coe = sec->coe; rst->exp = sec->exp;
            printf("%d %d\n",rst->coe,rst->exp);
            rst = rst->next;
            
            sec = sec->next;
        }
        else{
            sum_coe  = fir->coe + sec->coe;
            rst->coe = sum_coe;
            rst->exp = sec->exp;
            printf("%d %d\n",rst->coe,rst->exp);
            
            rst = rst->next;

            fir = fir->next;sec = sec->next;
        }
    }
    
    while(fir != NULL){
        rst->coe = fir->coe;rst->exp = fir->exp;
        fir = fir->next;
        rst = rst->next;
    }
    while(sec != NULL){
        rst->coe = sec->coe;rst->exp = sec->exp;
        sec = sec->next;
        rst = rst->next;
    }

    return rst;
}
void print(listnode* p){
    while(p->next!=NULL){
        p = p->next;
        printf("%d %d",p->coe,p->exp);
    }printf("\n");
}

int main(){
    //순환문이용
    int n,m,c,e; scanf("%d",&n);

    listnode* fir = (listnode*)malloc(sizeof(listnode*));
    listnode* sec = (listnode*)malloc(sizeof(listnode*));

    for(int i=0;i<n;i++){
        scanf("%d %d",&c,&e);
        appendTerm(fir,c,e);
    }

    for(int i=0;i<m;i++){
        scanf("%d %d",&c,&e);
        appendTerm(sec,c,e);
    }

    listnode* rst = (listnode*)malloc(sizeof(listnode*));
    rst = addPoly(fir,sec);
    print(rst);

} 

/**

3
5 3 3 2 3 1
3
2 6 2 3 1 0

 */
