#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char element;

typedef struct CListNode{//원형 연결리스트
   element data;
   struct CListNode* next;
}CListNode;

typedef struct {
   CListNode* Tail;
   int size;
}CListType;

void init(CListType* CList) {
   CList->Tail = NULL;
   CList->size = 0;
}

int isEmpty(CListType* CList) {
   return CList->Tail == NULL; // 둘 중에 하나만 쓰면 됨
}

void insertLast(CListType* CList, element data) {
   CListNode* new = (CListNode*)malloc(sizeof(CListNode));
   new->data = data;

   if (isEmpty(CList)) {
       CList->Tail = new; // 연결리스트의 꼬리를 새로운 노드로 설정
       new->next = CList->Tail;
       //새로운 노드의 다음을 연결리스트의 꼬리로 설정
   } 
   else {
       new->next  = CList->Tail->next;
       CList->Tail->next = new;
       CList->Tail = new;
   }


   CList->size++;
} 


void insertFirst(CListType* CL, element e) {
   CListNode* node = (CListNode*)malloc(sizeof(CListNode));
   node->data = e;

   if (isEmpty(CL)) {
      CL->Tail = node;
      node->next = CL->Tail;
   }
   else {
      node->next = CL->Tail->next;
      CL->Tail->next = node;
   }
   CL->size++;

}

// void insert(CListType* CList, int pos, element e) {
//     if (pos == 1) {
//         insertFirst(CList, e);
//     } else if (pos == CList->size + 1) {
//         insertLast(CList, e);
//     } else {
//         CListNode* new = (CListNode*)malloc(sizeof(CListNode));
//         if (new == NULL) {
//             fprintf(stderr, "Memory allocation failed.\n");
//             exit(EXIT_FAILURE);
//         }
//         new->data = e;

//         for (int i = 1; i < pos - 1; i++) {
//             p = p->next;
//             }
//         }

//         node->data = e;
//       node->next = p->next;
//       p->next = node;

//       CL->size++;
//     }
// }

int deleteFirst(CListType* CList) {//삭제되는 값을 반환한다.
   if(CList->size == 0){
      printf("invaild connection");
      return -1;
   }
   else{
      //입력받은 연결리스트의 다음 노드, 즉 값을 가지는 노드를 del에 저장
      CList->size --;
      return del->data;
   }
}
element deleteLast(CListType* CList) {
    if (isEmpty(CList)) {// 노드가 없으면 삭제할 수 없음
        printf("Invalid connection. The list is empty.\n");
        return -1;
    }

    CListNode* del = del_pre->next;
    element e;

    if (del == del_pre) { // 노드가 하나인 경우
        e = del_pre->data;
        free(del_pre);
    } else { // 두 개 이상인 경우
            del_pre = del;
            del = del->next;
        }
        e = del->data;
        free(del);
    }

    CList->size--;
    return e;
}

element delete(CListType* CList, int pos){
   element rtn; //반환값
   if (pos == 1) {rtn = deleteFirst(CList);}
   else if (pos == CList->size) {rtn = deleteLast(CList);}
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
      CList->size--;
      free(p);
   }
   return rtn;
}
void print(CListType* List) {
   if (isEmpty(List))return;

   CListNode* p = List->Tail;

   do {
      printf("[%c] => ", p->next->data);
      p = p->next;
   } while (p != List->Tail);

   printf("\b\b\b    \n");
   
   
}

int main() {
    CListType CList; // 구조체 변수여서 .을 사용
    init(&CList);
    printf("-------------insertFirst-----------\n");
//    insertFirst(&CList, 'D'); print(&CList);

//    insertLast(&CList, 'A'); print(&CList);
//    insertLast(&CList, 'B'); print(&CList);
//    insertLast(&CList, 'C'); print(&CList); getchar();

//    insertFirst(&CList, 'E'); print(&CList);
//    insertFirst(&CList, 'F'); print(&CList); getchar();

//    insert(&CList, 1, 'G'); print(&CList); getchar();

    int index;
    // printf("circle index : %d",&index)
    printf("-------------insertLast-----------\n");
    // insertLast(&CList, 40); print(&CList);
    // insertLast(&CList, 50); print(&CList);
    // insertLast(&CList, 60); print(&CList); //getchar();

    // printf("-------------deleteLast-----------\n");
    // deleteLast(&CList); print(&CList);
    // deleteLast(&CList); print(&CList);

   

}