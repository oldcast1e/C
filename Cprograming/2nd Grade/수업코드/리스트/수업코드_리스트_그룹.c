#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef int element;

typedef struct DListNode {
    element data;
    char group;
    struct node* prev;
	struct node* next;
}DListNode;

void init(DListNode* head,DListNode* tail){
    head->next = head;
    tail->prev = tail;
}

void addNode(DListNode* p, int e, char g){
    DListNode* node = (DListNode*)malloc(sizeof(DListNode)); //헤드 노드 생성
    node->data = e;
    node->group = g;

    node->prev = p->prev;
    node->next = p;
    p->prev->next = node;
    p->prev
}

int main(){
    DListNode* head = (DListNode*)malloc(sizeof(DListNode)); //헤드 노드 생성
    DListNode* tail = (DListNode*)malloc(sizeof(DListNode)); //엔드 노드 생성
    init(head,tail);

    srand(time(NULL));
    char g[5] = {'A','B','C','D','E'};
    for(int i=1;i<=10;i++){
        element e = rand()%90 + 10;
        char c = g[rand()%5];
        add(Head,i,e,c);
    }

} 
