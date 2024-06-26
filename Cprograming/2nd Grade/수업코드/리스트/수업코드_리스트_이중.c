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
   DListNode* Head;
   DListNode* Tail;
   int size;
}DListType;

void init(DListType* DList) {
   DList->Head = NULL;
   DList->Tail = NULL;
   DList->size = 0;
}

void insertFirst(DListType* DList, element e) {
   DListNode* new = (DListNode*)malloc(sizeof(DListNode));
   //새로운 노드 동적할당
   DListNode* p = DList->Head;
   new->data = e; // 새로운 노드에 값 저장
   new->prev = NULL; // 새로운 노드의 이전 노드를 NULL : 첫 노드이므로
   
   new->next = p;// 새로운 노드의 next를 H(헤드)를 저장한 p로 연결

   if (p == NULL) {DList->Head = DList->Tail = new;}//p가 널이면 헤드-테일을 각각 new로 초기화
   else {//아니라면
      p->prev = new;//헤드를 저장한 p의 이전 노드를 new로 설정
      DList->Head = new;//연결리스트의 헤드를 new로 설정
   }

   DList->size++;
}

void insertLast(DListType* DList, element e) {
   DListNode* new = (DListNode*)malloc(sizeof(DListNode));
   //새로운 노드 동적할당
   
   DListNode* p = DList->Tail;
   //테일 노드를 저장하는 노드

   new->data = e; // 새로운 노드에 값 저장
   new->prev = p; //새로운 노드를 테일의 이전 노드와 연결
   new->next = NULL;//새로운 노드의 다음은 NULL : 마지막에 추가했음

   if (p == NULL) {DList->Head = DList->Tail = new;}
   else {
      p->next = new;//테일 노드의 다음을 new로 지정 : new가 추가됨
      DList->Tail = new;//테일 초기화
   }
   DList->size++;
}

void insert(DListType* DList, int pos, element e) {
   if (pos < 1 || pos > DList->size) {
        printf("Invalid pos\n");
        return ;
    }
   DListNode* new = (DListNode*)malloc(sizeof(DListNode));
   DListNode* p = DList->Head;//임의의 노드 생성

   if (pos == 1) {//맨 처음에 추가
      insertFirst(DList, e);
   }
   else if (pos == DList->size + 1) {//(맨 마지막 + 1)위치 추가
      insertLast(DList, e);
   }
   else {//처음과 마지막 노드가 아닌경우
      for (int i = 1; i < pos; i++) {p = p->next;}
      //원하는 위치까지 이동
      new->data = e;//새로운 노드에 값 저장
      new->prev = p->prev;
      // 새로운 노드의 이전 노드를 원래 해당 위치에 있던 노드의 이전 노드로
      new->next = p;
      //새로운 노드의 다음 노드를 원래 위치의 노드로 설정
      
      p->prev->next = new;
      //기존 위치의 이전 노드의  next를 새로운 노드로 : 이중연결리스트
      p->prev = new;
      //기존 위치의 이전 노드를 새로운 노드로

      DList->size++;
   }
}
element deleteFirst(DListType* DList) {//삭제되는 값을 반환한다.
   if(DList->size == 0){
      printf("invaild connection");
      return -1;
   }
   else{
      DListNode* del =  DList->Head;
      element ouput = del->data;
      //입력받은 연결리스트의 다음 노드, 즉 값을 가지는 노드를 del에 저장
      DList->Head = del->next;
      DList->size --;
      return ouput;
   }  
}
element deleteLast(DListType* DList) {
   if (DList->Tail == NULL) return -1; 
    
   DListNode* del = DList->Tail;
   element ouput = del->data;
   // printf("삭제할 노드의 값: %d\n",del->data);
   DList->Tail = NULL;
   (del->prev->next) = DList->Tail;
   DList->Tail = del->prev;
   return ouput;
}

element delete(DListType* DList, int pos){
   if (pos < 1 || pos > DList->size) {
        printf("Invalid pos\n");
        return -1;
    }
   DListNode* p = DList->Head;//리스트의 헤드 노드를 p에 저장
   element output; //반환값
   if (pos == 1) {output = deleteFirst(DList);}
   else if (pos == DList->size) {output = deleteLast(DList);}
   else {
      for (int i = 1; i < pos; i++) {p = p->next;}
      //원하는 위치로 이동
      output = p->data;//원하는 위치의 노드 : 삭제할 노드 -> 반환값 저장
      if (p->next) {//다음 노드가 있으면
         p->prev->next = p->next;
         p->next->prev = p->prev;
      }
      else  p->prev->next = NULL;//다음 노드가 없으면 
      
      DList->size--;
      free(p);
   }
   return output;
}

int isEmpty(DListType* DList) {
   return DList->Head == NULL;
   //return DList->Tail == NULL; // 둘 중에 하나만 쓰면 됨
}

void print(DListType* DList) {
   for (DListNode* p = DList->Head; p != NULL; p = p->next) {
      printf("[%d] <=> ", p->data);
   }printf("\b\b\b\b   \n");
}

element get(DListType* DList, int rank) {
    if (rank < 1 || rank > DList->size) {
        printf("Invalid rank\n");
        return -1; // 유효하지 않은 순위일 경우 -1 반환
    }
    DListNode* p = DList->Head;
    for (int i = 1; i < rank; i++) {
        p = p->next;
    }
    return p->data;
}

int main() {
   DListType DList; // 구조체 변수여서 .을 사용
   init(&DList);
   printf("--------------------insertFirst--------------------\n");
   insertFirst(&DList, 20); print(&DList);
   insertFirst(&DList, 10); print(&DList);
   printf("--------------------insertLast--------------------\n");
   insertLast(&DList, 40); print(&DList);
   insertLast(&DList, 50); print(&DList);
   printf("----------------------insert---------------------\n");
   insert(&DList, 1, 70); print(&DList);
   insert(&DList, DList.size , 100); print(&DList);
   insert(&DList, 4, 80); print(&DList); 
   printf("--------------------deleteFirst------------------\n");
   deleteFirst(&DList);print(&DList);
   printf("--------------------deleteLast-------------------\n");
   deleteLast(&DList);print(&DList);
   printf("----------------------delete---------------------\n");
   delete(&DList, 1); print(&DList);


   // printf("-------------delete: check return value-----------\n");
   // printf("delte list number: ");
   // int input; scanf("%d",&input);
   // printf("[%d] is deleted.\n",delete(&DList,input));
   // print(&DList);
   printf("%d",DList.Head->data);

}