#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int element;

typedef struct CListNode{//원형 연결리스트
   element data;
   // struct CListNode* prev;
   struct CListNode* next;
}CListNode;

typedef struct {
   CListNode* Head;
   CListNode* Tail;
   int count;
}CListType;

void init(CListType* CList) {
   CList->Head = NULL;
   CList->Head->next = CList->Head;
   CList->Tail = NULL;
   CList->count = 0;
}

int isEmpty(CListType* CList) {
   return CList->Head == NULL;
   return CList->Tail == NULL; // 둘 중에 하나만 쓰면 됨
}

void insertFirst(CListType* CList, element data) {
   CListNode* new = (CListNode*)malloc(sizeof(CListNode));//새로운 노드 동적할당
   CListNode* p = CList->Head;
   /*노드 추가 시 기본 알고리즘*/
   new->data = data; // 새로운 노드에 값 저장// new->prev = NULL; // 새로운 노드의 이전 노드를 NULL : 첫 노드이므로
   new->next = p;// 새로운 노드의 next를 H(헤드)를 저장한 p로 연결

   if (p == NULL) {CList->Head = new;}//p가 널이면 헤드-테일을 각각 new로 초기화
   else {//아니라면
      // p->prev = new;//헤드를 저장한 p의 이전 노드를 new로 설정
      CList->Head = new;//연결리스트의 헤드를 new로 설정
   }

   CList->count++;
}

void insertLast(CListType* CList, element e) {
   CListNode* p = CList->Head;
   while(p->next!=NULL){
      p = p->next;
   }
   CListNode* new = (CListNode*)malloc(sizeof(CListNode));
   //새로운 노드 동적할당

   new->data = e; // 새로운 노드에 값 저장
   p->next = new;//새로운 노드의 다음은 NULL : 마지막에 추가했음

   CList->count++;
}

void insert(CListType* CList, int pos, element e) {
   CListNode* new = (CListNode*)malloc(sizeof(CListNode));
   CListNode* p = CList->Head;//임의의 노드 생성

   if (pos == 1) {//맨 처음에 추가
      insertFirst(CList, e);
   }
   else if (pos == CList->count + 1) {//(맨 마지막 + 1)위치 추가
      insertLast(CList, e);
   }
   else {//처음과 마지막 노드가 아닌경우
      for (int i = 1; i < pos; i++) {p = p->next;}
      //원하는 위치까지 이동
      new->data = e;//새로운 노드에 값 저장
      // // new->prev = p->prev;
      // 새로운 노드의 이전 노드를 원래 해당 위치에 있던 노드의 이전 노드로
      new->next = p;
      //새로운 노드의 다음 노드를 원래 위치의 노드로 설정
      
      // p->prev->next = new;
      //기존 위치의 이전 노드의  next를 새로운 노드로 : 이중연결리스트
      // p->prev = new;
      //기존 위치의 이전 노드를 새로운 노드로

      CList->count++;
   }
}
int deleteFirst(CListType* CList) {//삭제되는 값을 반환한다.
   if(CList->count == 0){
      printf("invaild connection");
      return -1;
   }
   else{
      CListNode* del =  CList->Head;
      //입력받은 연결리스트의 다음 노드, 즉 값을 가지는 노드를 del에 저장
      CList->Head = del->next;
      CList->count --;
      return del->data;
   }
    
}
element deleteLast(CListType* CList) {
   // CListNode* del = CList->Tail;
   // printf("삭제할 노드의 값: %d\n",del->data);
   // CList->Tail = NULL;
   // (del->prev->next) = CList->Tail;
   // CList->Tail = del->prev;
   
//    // p->next = 
//     return - 1;
}

element delete(CListType* CList, int pos){
   CListNode* p = CList->Head;//리스트의 헤드 노드를 p에 저장
   element rtn; //반환값
   if (pos == 1) {rtn = deleteFirst(CList);}
   else if (pos == CList->count) {rtn = deleteLast(CList);}
   else {
      for (int i = 1; i < pos; i++) {p = p->next;}
      //원하는 위치로 이동
      rtn = p->data;//원하는 위치의 노드 : 삭제할 노드 -> 반환값 저장
      if (p->next) {//다음 노드가 있으면
      //노드 연결
         // p->prev->next = p->next;
         // // p->next->prev = p->prev;
      }
      else {//다음 노드가 없으면 
         // p->prev->next = NULL;
      }
      CList->count--;
      free(p);
   }
   return rtn;
}
void print(CListType* List) {
   if (isEmpty(List))return;
   else{
      
   }
   
   
}

int main() {
   CListType CList; // 구조체 변수여서 .을 사용
   init(&CList);
   printf("-------------insertFirst-----------\n");
   insertFirst(&CList, 10); print(&CList);
   insertFirst(&CList, 20); print(&CList);
   insertFirst(&CList, 30); print(&CList); //getchar();
   insertFirst(&CList, 40); print(&CList); //getchar();
   insertFirst(&CList, 50); print(&CList); //getchar();

   int index;
   // printf("circle index : %d",&index)
   // printf("-------------insertLast-----------\n");
   // insertLast(&CList, 40); print(&CList);
   // insertLast(&CList, 50); print(&CList);
   // insertLast(&CList, 60); print(&CList); //getchar();
   

}