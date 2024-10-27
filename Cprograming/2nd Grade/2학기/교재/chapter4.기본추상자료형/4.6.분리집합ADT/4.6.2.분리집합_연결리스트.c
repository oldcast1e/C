#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
/*
주요메쏘드
•setfind(e):원소c가속한집합을반환
•union(x,y):집합x,y를통합
보조메쏘드
•integersize(S):집합S의원소수를반환
*/

typedef int element;
typedef struct dSetType{
    struct dSetNode* head;
    int size;
}dSetType;

typedef struct dSetNode{
    struct dSetNode* next;
    element data;
}dSetNode;

void init(dSetType* D){
    D->head = (dSetNode*)malloc(sizeof(dSetNode));
    D->size = 0;
}

int isConstain(dSetType* D, element e){
    dSetNode* tmp= D->head;
    for(int i=0;i<D->size;i++){
        if(tmp->data == e) return 1;
        tmp = tmp->next;
    }
    return 0;
}

void upsort(dSetType* D){
    dSetNode* tmp_i= D->head;
    for(int i=0;i<D->size;i++){
        for(int j=i+1;j<D->size;j++){
            dSetNode* tmp_j= D->head;
            for(int k=0;k<j;k++)tmp_j = tmp_j->next;
            
            if(tmp_i->data > tmp_j->data){
                int tmp = tmp_i->data;
                tmp_i->data = tmp_j->data;
                tmp_j->data = tmp;
            }
        }
        tmp_i=tmp_i->next; 
    }
}

void add(dSetType* D,element e){
    dSetNode* new= (dSetNode*)malloc(sizeof(dSetNode));
    new->data = e;
    if(D->size <=0){D->head = new;}
    else{
        new->next = D->head;
        D->head = new;
    }
    D->size++;
}

void printSet(dSetType* D){
    dSetNode* tmp= D->head;
    for(int i=0;i<D->size;i++){
        printf("[%d] ",tmp->data);
        tmp = tmp->next;
    }printf("\n");
}

void unionSet(dSetType* UD, dSetType* D1, dSetType* D2){
    // dSetType UD; init(&UD);
    dSetNode* tmp1 = D1->head;
    for(int i=0;i<D1->size;i++){
        add(UD,tmp1->data);
        tmp1 = tmp1->next;
    }
    dSetNode* tmp2 = D2->head;
    for(int i=0;i<D2->size;i++){
        add(UD,tmp2->data);
        tmp2 = tmp2->next;
    }

    upsort(UD);
}

// •setfind(e):원소c가속한집합을반환
dSetType* setfind(dSetType* D1, dSetType* D2, element c){
    if(isConstain(D1,c)) return D1;
    else if(isConstain(D2,c)) return D2;
    else {printf("Error\n"); return NULL;}
}

int main(){
    srand(time(NULL));
    dSetType D1; init(&D1);
    dSetType D2; init(&D2);
    for(int i=0;i<15;i++){
        int val  = rand()%100;
        if(isConstain(&D1,val) == 1) {i = i -1;continue;}
        else add(&D1,val);
    }
    for(int i=0;i<10;i++){ // 집합 D1,D2를 분리집합으로 구성
        int val  = rand()%100;
        if(isConstain(&D2,val) == 1 || isConstain(&D1,val)) {i = i -1;continue;}
        else add(&D2,val);
    }



    // printSet(&D1);
    upsort(&D1);printSet(&D1);
    upsort(&D2);printSet(&D2);

    dSetType UD; init(&UD);
    unionSet(&UD,&D1,&D2);
    printSet(&UD);

    element c = rand()%100+1;
    if(isConstain(&D1,c)){printf("[%d] in D1.\n",c);printSet(setfind(&D1,&D2,c));}
    else if(isConstain(&D2,c)){printf("[%d] in D2.\n",c);printSet(setfind(&D1,&D2,c));}
    else printf(">>[%d] doesn't in D1 & D2.\n",c);
    
}


