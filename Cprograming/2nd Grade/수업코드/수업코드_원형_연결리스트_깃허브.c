#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char element;

typedef struct CListNode{
   element data;
   struct CListNode* next;
}CListNode;

typedef struct {
   CListNode* Tail;
   int count;
}CListType;

void init(CListType* CList) {
   CList->Tail = NULL;
   CList->count = 0;
}

int isEmpty(CListType* CList) {
   return CList->Tail == NULL; // 둘 중에 하나만 쓰면 됨
}

void insertFirst(CListType* CList, element e) {
   CListNode* new = (CListNode*)malloc(sizeof(CListNode));
   //새로운 노드 동적할당
   new->data = e; // 새로운 노드에 값 저장
   
    if (isEmpty(CList)){
        /*
        CList가 비어있는 상태에서 추가하면,

        1. 테일은 추가된 노드이다.
        2. 추가된 노드의 다음을 자신을 가리킨다
        */
        CList->Tail = new;
        new->next = CList->Tail;

    }
    else {
        /*
        새로 값을 추가한다면,
        1. new의 넥스트가 테일을 가리키고
        2. 기존 테일의 다음값이 new를 가리키고
        3. 테일값에 new를 저장함
        (new 자체가 테일로 작동)
        */
        new->next = CList->Tail->next;
        CList->Tail->next = new;
        // CList->Tail = node;
    }    

    CList->count++;
}

void insertLast(CListType* CList, element e) {
   CListNode* new = (CListNode*)malloc(sizeof(CListNode));
   //새로운 노드 동적할당
   new->data = e; // 새로운 노드에 값 저장
   
    if (isEmpty(CList)){
        /*
        CList가 비어있는 상태에서 추가하면,

        1. 테일은 추가된 노드이다.
        2. 추가된 노드의 다음을 자신을 가리킨다
        */
        CList->Tail = new;
        new->next = CList->Tail;

    }
    else {
        /*
        새로 값을 추가한다면,
        1. new의 넥스트가 테일을 가리키고
        2. 기존 테일의 다음값이 new를 가리키고
        3. 테일값에 new를 저장함
        (new 자체가 테일로 작동)
        */
        new->next = CList->Tail->next;
        CList->Tail->next = new;
        CList->Tail = new;
    }    

    CList->count++;
}

void insert(CListType* CList, int pos, element e) {
   CListNode* new = (CListNode*)malloc(sizeof(CListNode));

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
      // 새로운 노드의 이전 노드를 원래 해당 위치에 있던 노드의 이전 노드로
      new->next = p;
      //새로운 노드의 다음 노드를 원래 위치의 노드로 설정
      
      //기존 위치의 이전 노드의  next를 새로운 노드로 : 이중연결리스트
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
      //입력받은 연결리스트의 다음 노드, 즉 값을 가지는 노드를 del에 저장
      CList->count --;
      return del->data;
   }
    
}
element deleteLast(CListType* CList) {
   CListNode* del = CList->Tail;
   // printf("삭제할 노드의 값: %d\n",del->data);
   CList->Tail = NULL;
   
   // p->next = 
    return - 1;
}

element delete(CListType* CList, int pos){
   element rtn; //반환값
   if (pos == 1) {rtn = deleteFirst(CList);}
   else if (pos == CList->count) {rtn = deleteLast(CList);}
   else {
      for (int i = 1; i < pos; i++) {p = p->next;}
      //원하는 위치로 이동
      rtn = p->data;//원하는 위치의 노드 : 삭제할 노드 -> 반환값 저장
      if (p->next) {//다음 노드가 있으면
      //노드 연결
      }
      else {//다음 노드가 없으면 
      }
      CList->count--;
      free(p);
   }
   return rtn;
}

void print(CListType* CList) {
      printf("[%c] <=> ", p->data);
   printf("\b\b\b\b   \n");
}

int main() {
   CListType CList; // 구조체 변수여서 .을 사용
   init(&CList);
   printf("-------------insertFirst-----------\n");
   insertFirst(&CList, 'B'); print(&CList);
   insertFirst(&CList, 'A'); print(&CList);
   insertFirst(&CList, 'C'); print(&CList); //getchar();

   printf("-------------insertLast-----------\n");
   insertLast(&CList, 'D'); print(&CList);
   insertLast(&CList, 'E'); print(&CList);
   insertLast(&CList, 'F'); print(&CList); //getchar();

//    printf("-------------insert-----------\n");

//    insert(&CList, 1, 'G'); print(&CList);
//    insert(&CList, CList.count + 1, 100); print(&CList);
//    // insert(&CList, 4, 80); print(&CList); getchar();
   
//    printf("--------------deleteFirst-------------\n");
//    deleteFirst(&CList);print(&CList);
//    deleteFirst(&CList);print(&CList);
//    // deleteFirst(&CList);print(&CList);

//    printf("--------------deleteLast-------------\n");
//    deleteLast(&CList);print(&CList);
//    deleteLast(&CList);print(&CList);
//    // deleteLast(&CList);print(&CList);
//    // delete(&CList, 4); print(&CList);
//    printf("--------------delete-------------\n");
//    delete(&CList, 1); print(&CList);
//    delete(&CList, CList.count ); print(&CList);
//    // delete
//    printf("-------------insertLast-----------\n");
//    insertLast(&CList, 50); print(&CList);
//    insertLast(&CList, 60); print(&CList);

//    printf("-------------delete: check return value-----------\n");
//    printf("delte list number: ");
//    int input; scanf("%d",&input);
//    printf("[%d] is deleted.\n",delete(&CList,input));
//    print(&CList);
   

}