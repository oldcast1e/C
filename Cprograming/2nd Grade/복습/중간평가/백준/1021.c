#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct CListNode
{
    int data;
    struct CListNode* next;
    struct CListNode* prev;
}CListNode;

void initialize(CListNode* Head,CListNode* Tail){
    Head->next = Tail;
    Tail->next = Head;

    Head->prev = Tail;
    Tail->prev = Head;
}

int main(){
    int N,M;
    CListNode* Head = (CListNode*)malloc(sizeof(CListNode));
    CListNode* Tail = (CListNode*)malloc(sizeof(CListNode));

    scanf("%d %d",&N,&M);

}