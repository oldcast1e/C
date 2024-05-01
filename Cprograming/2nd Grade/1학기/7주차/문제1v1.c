#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

typedef int element;

typedef struct DListNode {
	element data;
	struct DListNode* next;
    struct DListNode* prev;
}DListNode;

typedef struct SetType {
	DListNode* H;
    DListNode* T;
    element N;
}SetType;

DListNode* getNode();
void addNode(SetType* S,DListNode* p, element e);

void init(SetType* S) {

    S->H = getNode();
    S->T = getNode();

    S->H ->next = S->T;
    S->T->prev = S->H;
    S->N = 0;
}

void add(SetType* S, element e) { 
    DListNode* p = S->H;
    int status=0;

    if(p->next == S->T) addNode(S,p,e);
    else{
        while(e >= p->next->data && p->next->next != NULL){
            //입력된 원소의 값이 노드의 값보다 큰 경우
            // = 노드를 순회하며 값을 저장해야함.
            if(e == p->next->data) {status = 0;break;}
            p = p->next;
        }//값이 작거나, 마지막 노드보다 작거나, 값이 같거나
        if(status == 1)addNode(S,p,e);
    }
}

void addNode(SetType* S,DListNode* p, element e){
    DListNode *node = getNode();
    node ->data = e;

    node->prev = p;
    node->next = p->next;

    p->next->prev = node;
    p->next = node;

    S->N ++;
}

DListNode* getNode(){
    DListNode* node = (DListNode*)malloc(sizeof(DListNode));
    node -> data = 0;
    
    node ->next = NULL;
    node ->prev = NULL;

    return node;
}



void traverse(SetType* S){
    DListNode* p;
    for (p = S->H->next; p != NULL; p = p->next) {
      printf("[%d] <=> ", p->data);
   }printf("\b\b\b\b   \n");
}

int main(){
    SetType A,B;
    init(&A);init(&B);

    srand(time(NULL));
    for(int i=0;i<7;i++){
        int e1  = rand() % 10 +1;
        int e2  = rand() % 10 +1;

        add(&A,e1);
        add(&B,e1);
    }
    // print(&A);

    printf("A : "); traverse(&A);
    printf("B : "); traverse(&B);
    
}