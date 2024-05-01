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
    int status = 1;

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
    // node -> data = 0;
    node -> data = 0;
    
    node ->next = NULL;
    node ->prev = NULL;

    return node;
}

void traverse(SetType* S){
    DListNode* p;
    for (p = S->H->next; p->next != NULL; p = p->next) {
      printf("[%d] <=> ", p->data);
   }printf("\b\b\b\b   \n");
}

void addLast(SetType* S, element e){
    DListNode* new = getNode();
    new->data = e; // 새로운 노드에 값 저장
    DListNode* p = S->T;
    new->prev = S->T ->prev;

    S->T->prev->next = new;
    S->T->prev = new;
    // printf("[%d]\n",new->data);


    S->N++;
}
SetType UnionSet(SetType* S1, SetType* S2) {
    SetType S3;
    init(&S3);

    DListNode* p = S1->H->next;
    DListNode* q = S2->H->next;

    while (p != S1->T && q != S2->T) {
        if (p->data < q->data) {
            addLast(&S3, p->data);
            p = p->next;
        } else if (p->data > q->data) {
            addLast(&S3, q->data);
            q = q->next;
        } else { // 두 집합에 모두 존재하는 원소인 경우
            addLast(&S3, p->data);
            p = p->next;
            q = q->next;
        }
    }

    // 남은 원소들 추가
    while (p != S1->T) {
        addLast(&S3, p->data);
        p = p->next;
    }
    while (q != S2->T) {
        addLast(&S3, q->data);
        q = q->next;
    }

    return S3;
}



/*교집합*/
SetType IntersectSet(SetType* S1,SetType* S2) {
	DListNode* p = S1->H->next;
	DListNode* q = S2->H->next;

	SetType S3; init(&S3);

	while ((p != S1->T) && (q != S1->T)) {
		if (p->data > q->data) {
			q = q->next;
		}
		else if (p->data < q->data) {
			p = p->next;
		}
		else {
			//두 개의 값이 동일한 경우: 교집합 추가
            // printf("[%d]\n",p->data);
			addLast(&S3,p->data);
			p = p->next;
			q = q->next;	
		}
	}

	while (p != S1->T) {
		p = p->next;
		addLast(&S3, p->data);
	}
	while (q != S1->T) {
		q = q->next;
		addLast(&S3, p->data);
	}

    // traverse(&S3);
	return S3;
}

int isMember(SetType* S, element e){

}

int main(){
    SetType A,B;
    init(&A);init(&B);

    srand(time(NULL));
    for(int i=0;i<7;i++){
        int e1  = rand() % 10 +1;
        int e2  = rand() % 10 +1;

        add(&A,e1);
        add(&B,e2);
    }
    // print(&A);

    printf("A : "); traverse(&A);
    printf("B : "); traverse(&B);

    SetType intersection = IntersectSet(&A,&B);
    printf("intersection : "); 
    traverse(&intersection);
    
}