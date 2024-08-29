// 원형 연결리스트
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int element;

typedef struct CListNode {
   element data;
   struct CListNode* next;
}CListNode;

typedef struct CListType {
   CListNode* T;
   int size;
}CListType;

void init(CListType* CL) {
   CL->T = NULL;
   CL->size = 0;
}

int isEmpty(CListType* CL) {
   return CL->T == NULL;
}

void insertLast(CListType* CL, element e) {
   CListNode* node = (CListNode*)malloc(sizeof(CListNode));
   node->data = e;

   if (isEmpty(CL)) {
        printf("isEmpty...\n");
      CL->T = node;//노드를 그대로 테일 노드에 서장
      node->next = CL->T;
   }
   else {
      node->next = CL->T->next;//헤드 연결
      CL->T->next = node;//테일 연결
    //   CL->T = node;
   }
   CL->size++;
    printf("[%d]=> ",node->data);
}

void insertFirst(CListType* CL, element e) {
   CListNode* node = (CListNode*)malloc(sizeof(CListNode));
   node->data = e;

   if (isEmpty(CL)) {
      CL->T = node;
      node->next = CL->T;
   }
   else {
      node->next = CL->T->next;
      CL->T->next = node;
   }
   CL->size++;

}

void insert(CListType *CL, int pos, element e) {
   if (pos == 1) {
      insertFirst(CL, e);
   }
   else if (pos == CL->size + 1) {
      insertLast(CL, e);
   }
   else {
      CListNode* node = (CListNode*)malloc(sizeof(CListNode));
      CListNode* p = CL->T;

      for (int i = 1; i < pos; i++) {
         p = p->next;
      }
   
      node->data = e;
      node->next = p->next;
      p->next = node;

      CL->size++;
   }

}

element deleteLast(CListType* CL) {
   if (isEmpty(CL)) {
      return -1;
   }
   
   CListNode* p = CL->T; // 마지막 노드
   CListNode* q = p->next; // 첫번째 노드

   element e = p->data;

   //if (p->next == p)랑 if (p == q)는 똑같음 
   if (p == q) {
      CL->T = NULL;
   }
   else {
      while (q->next != p) {
         q = q->next;
      }
      q->next = p->next; // p->next는 첫번째 노드
      CL->T = q;
   }
   free(p);
   CL->size--;

   return e;
}

element deleteFirst(CListType* CL) {
   if (isEmpty(CL)) {
      return -1;
   }
   
    CListNode* p = CL->T; // 마지막 노드
    CListNode* q = p->next; // 첫번째 노드
    element e = q->data;
    if(p==q){
        CL->T = NULL;
    }
    else{
        p->next = q->next;    
    }free(q);
    CL->size--;
    return e;
}

void print(CListType* CL) {
   if (isEmpty(CL)) return;
   
   CListNode* p = CL->T;
   do {
      printf("[%c] => ", p->next->data);
      p = p->next;
   } while (p != CL->T);

   printf("\b\b\b    \n");
}

int main() {
   CListType CL;
   init(&CL);

   int N,K; scanf("%d %d",&N,&K);
   for(int i=1;i<=N;i++)insertLast(&CL,i);
   print(&CL);


   

}