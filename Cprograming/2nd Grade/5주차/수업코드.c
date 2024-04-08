#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int element;

typedef struct DListNode{
   element data;
   struct DListNode* prev;
   struct DListNode* next;
}DListNode;

typedef struct {
   DListNode* H;
   DListNode* T;
   int count;
}DListType;

void init(DListType* DL) {
   DL->H = NULL;
   DL->T = NULL;
   DL->count = 0;
}

int isEmpty(DListType* DL) {
   return DL->H == NULL;
   //return DL->T == NULL; // 둘 중에 하나만 쓰면 됨
}

void insertFirst(DListType* DL, element e) {
   DListNode* node = (DListNode*)malloc(sizeof(DListNode));
   DListNode* p = DL->H;

   node->data = e;
   node->prev = NULL;
   node->next = p;

   if (p == NULL) {
      DL->H = DL->T = node;
   }
   else {
      p->prev = node;
      DL->H = node;
   }

   DL->count++;
}

void insertLast(DListType* DL, element e) {
   DListNode* node = (DListNode*)malloc(sizeof(DListNode));
   DListNode* p = DL->T;

   node->data = e;
   node->prev = p;
   node->next = NULL;

   if (p == NULL) {
      DL->H = DL->T = node;
   }
   else {
      p->next = node;
      DL->T = node;
   }

   DL->count++;
}

void insert(DListType* DL, int pos, element e) {
   DListNode* node = (DListNode*)malloc(sizeof(DListNode));
   DListNode* p = DL->H;

   if (pos == 1) {
      insertFirst(DL, e);
   }
   else if (pos == DL->count + 1) {
      insertLast(DL, e);
   }
   else {
      for (int i = 1; i < pos; i++) {
         p = p->next;
      }
      node->data = e;
      node->prev = p->prev;
      node->next = p;

      p->prev->next = node;
      p->prev = node;

      DL->count++;
   }
}

void deleteFirst(DListType* DL) {
    DListNode* del =  DL->H->next;
    DL->H-> next = del->next;
    // DL->H ->next = del->next->next;
    // (del->pre)->next = del->next;
	// (del->next)->pre = del->pre;
}
void deleteLast(DListType* DL) {
    DListNode* p = DL->T->prev;//맨 마지막 노드의 전 노드
    p->next = DL->T;
}

void delete(DListType* DL, int pos) {
   DListNode* node = (DListNode*)malloc(sizeof(DListNode));
   DListNode* p = DL->H;

   if (pos == 1) {//연결리스트의 맨 첫번째 일때
      deleteFirst(DL);
   }
   else if (pos == DL->count + 1) {//연결리스트의 맨 마지막일때
      deleteLast(DL);
   }
   else {
        for (int i = 1; i < pos; i++) {
            p = p->next;
        }
        DListNode* tmp = p;
        (p->prev)->next = p->next;
        (p->next)->prev = tmp->prev;
   }

  
}

void print(DListType* DL) {
   for (DListNode* p = DL->H; p != NULL; p = p->next) {
      printf("[%d] <=> ", p->data);
   }printf("\b\b\b\b   \n");
}

int main() {
   DListType DL; // 구조체 변수여서 .을 사용
   init(&DL);

   insertFirst(&DL, 20); print(&DL);
   insertFirst(&DL, 10); print(&DL);
   insertFirst(&DL, 30); print(&DL); getchar();

   insertLast(&DL, 20); print(&DL);
   insertLast(&DL, 10); print(&DL);
   insertLast(&DL, 30); print(&DL); getchar();

   insert(&DL, 1, 70); print(&DL);
   insert(&DL, DL.count + 1, 100); print(&DL);
   insert(&DL, 4, 80); print(&DL); getchar();

   delete(&DL, 1); print(&DL);
//    delete(&DL, DL.count + 1); print(&DL);
//    delete(&DL, 4); print(&DL); getchar();

}