/*
◦ 다음 네 가지 연산을 지원해야 함 (순위는 1부터 시작한다고 가정)
- add(list, r, e) : list의 순위 r에 원소 e를 추가한다.
- delete(list, r) : list의 순위 r에 위치한 원소를 삭제한다 (주교재의 remove와 동일)
- get(list, r) : list의 순위 r에 위치한 원소를 반환한다.
- print(list) : list의 모든 원소를 저장 순위대로 공백없이 출력한다.
※ 순위 정보가 유효하지 않으면 화면에 에러 메시지 "invalid position" 출력하고, 해당 연산
을 무시한다.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char element;

typedef struct CListNode {
   element data;
   struct CListNode* next;
   struct CListNode* prev;
}CListNode;

typedef struct CListType {
   CListNode* Head;
   CListNode* Tail;
   int size;
}CListType;

void initialize(CListType* DNode){
    DNode->Head = NULL;
    DNode->Tail = NULL;

    DNode->size = 0;
}

void insertFirst(CListType* DNode, element data){
    CListNode* new = (CListNode*)malloc(sizeof(CListNode));
    new->data = data;
    if(DNode->Head == NULL){
        printf("First Node Input\n");
        DNode->Head = DNode->Tail = new;
    }
    else{
        CListNode* tmp =DNode->Head;
        new->next = tmp;
        new->prev = NULL;

        tmp->prev = new;
        DNode->Head= new;
    }
    DNode->size ++;
}

void insertLast(CListType* DNode, element data){
    CListNode* new = (CListNode*)malloc(sizeof(CListNode));
    new->data = data;
    if(DNode->Tail == NULL){
        printf("Last Node Input\n");
        DNode->Head = DNode->Tail = new;
    }
    else{
        CListNode* tmp =DNode->Tail;
        new->prev = tmp;
        new->next = NULL;

        tmp->next = new;
        DNode->Tail= new;
    }
    DNode->size ++;
}

void insert(CListType* DNode, element data, element rank){
    if(rank < 0 || rank > DNode->size+1){
        printf("Invailed Connection."); return;
    }
    else{
        if(rank == 0) insertFirst(DNode,data);
        else if(rank == DNode->size+1)insertLast(DNode,data);
        else{
            printf("[%c]->rank = %d\n",data,rank);
            CListNode* curr = DNode->Head;
            for(int i=0;i<rank-1;i++){curr = curr->next;}

            CListNode* new = (CListNode*)malloc(sizeof(CListNode));
            new ->data = data;

            new->next = curr->next;
            new->prev = curr;

            curr->next = new;
            DNode->size ++;
        }
    }
}

int deleteFirst(CListType* DNode){
    printf("rank = 0\n");
    if(DNode->Head == NULL){
        printf("Invailed Connection.");
        return -1;
    }
    int ouput = DNode->Head->data;
    DNode->Head = DNode->Head->next;
    // CListNode* p = DNode->Head->next;
    // DNode->Head ->next = p;
    // p->prev = DNode->Head;
    DNode->Head->prev = NULL;
    // DNode->Head = p;

    DNode->size --;

    return ouput;
}

int deleteLast(CListType* DNode){
    if(DNode->Tail == NULL){
        printf("Invailed Connection.");
        return -1;
    }
    int ouput = DNode->Tail->data;
    printf("ouput = %c\n",ouput);
    DNode->Tail = DNode->Tail->prev;
    DNode->Tail ->next = NULL;
    DNode->size --;
    return ouput;
}

int delete(CListType* DNode,int rank){
    if(rank < 0 || rank > DNode->size){
        printf("Invailed Connection."); return -1;
    }
    else{
        if(rank == 0) {deleteFirst(DNode);}
        else if(rank == DNode->size-1)deleteLast(DNode);
        else{
            CListNode* curr = DNode->Head;
            for(int i=0;i<rank;i++){curr = curr->next;}
            printf("delete[%c]  rank[%d]\n",curr->data,rank);
            printf("curr->prev->data : %c\n",curr->prev->data);
            // curr->prev->next = curr->next;
            // curr->next->prev = curr->prev;
            /* ----------아래 중요------------*/
            curr->next->prev = curr->prev;
            curr = curr->next;
            curr->prev ->next = curr;
            /* ----------위에 중요------------*/
            // DNode->Tail = DNode->Tail->prev;
            // DNode->Tail ->next = NULL;
            // DNode->size --;


            DNode->size --;
            return curr->data;
        }
    }
    return 0;
}

void printNode(CListType* DNode){
    CListNode* curr = DNode->Head;
    while(curr != NULL){
        printf("[%c] ",curr->data);
        curr = curr->next;
    }printf("\n");
}

int getNode(CListType* DNode, int rank){
    CListNode* curr = DNode->Head;
    for(int i=0;i<rank;i++){curr = curr->next;}
    return curr->data;
}

int main(){
    CListType DNode;
    initialize(&DNode);
    printf("-----------------------insertFirst-----------------------\n");
    insertFirst(&DNode,'A');printNode(&DNode);//printf("\n");
    insertFirst(&DNode,'C');printNode(&DNode);//printf("\n");
    insertFirst(&DNode,'B');printNode(&DNode);//printf("\n");
    printf("-----------------------insertLast-----------------------\n");
    insertLast(&DNode,'D');printNode(&DNode);//printf("\n");
    printf("-----------------------insert-----------------------\n");
    insert(&DNode,'E',1);printNode(&DNode);
    insert(&DNode,'F',2);printNode(&DNode);
    // insert(&DNode,'K',4);printNode(&DNode);
    printf("-----------------------deleteFirst-----------------------\n");
    deleteFirst(&DNode);printNode(&DNode);
    deleteFirst(&DNode);printNode(&DNode);
    printf("-----------------------insertLast-----------------------\n");
    insertLast(&DNode,'F');printNode(&DNode);//printf("\n");
    insertLast(&DNode,'G');printNode(&DNode);//printf("\n");
    printf("-----------------------deleteLast-----------------------\n");
    // deleteFirst(&DNode);printNode(&DNode);
    deleteLast(&DNode);printNode(&DNode);
    // deleteLast(&DNode);printNode(&DNode);
    // delete(&DNode,1);printNode(&DNode);
    // delete(&DNode,0);printNode(&DNode);
    printf("-----------------------delete-----------------------\n");
    delete(&DNode,3);printNode(&DNode);
    printf("-----------------------insertFirst-----------------------\n");
    insertFirst(&DNode,'X');printNode(&DNode);//printf("\n");
    insertFirst(&DNode,'Y');printNode(&DNode);//printf("\n");
    insertFirst(&DNode,'Z');printNode(&DNode);//printf("\n");
    printf("-----------------------insertLast-----------------------\n");
    insertLast(&DNode,'Y');printNode(&DNode);//printf("\n");
    insertLast(&DNode,'Z');printNode(&DNode);//printf("\n");
    printf("-----------------------delete-----------------------\n");
    delete(&DNode,3);printNode(&DNode);
    delete(&DNode,3);printNode(&DNode);
    printf("-----------------------getNode-----------------------\n");
    printf("getNode[%d] = [%c]\n",3,getNode(&DNode,3));

}