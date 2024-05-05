#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef int element;

typedef struct Listnode {
	int data;
	struct Listnode* next;
}Listnode;

typedef struct ListType {
	struct Listnode* Head;
    int size;
}ListType;

void init(ListType* DList) {
   DList->Head = NULL;
   DList->size = 0;
}
void insertFirst(ListType* DList, element e) {
   Listnode* new = (Listnode*)malloc(sizeof(Listnode));
   //새로운 노드 동적할당
   Listnode* p = DList->Head;
   /*노드 추가 시 기본 알고리즘*/
   new->data = e; // 새로운 노드에 값 저장
   new->next = p;// 새로운 노드의 next를 H(헤드)를 저장한 p로 연결

   if (p == NULL) {DList->Head = new;}//p가 널이면 헤드-테일을 각각 new로 초기화
   else {DList->Head = new;}//연결리스트의 헤드를 new로 설정

   DList->size++;
}

void insertLast(ListType* DList, element e) {
    Listnode* new = (Listnode*)malloc(sizeof(Listnode));
    Listnode* p = DList->Head;
    while(p != NULL) {
        if (p->next == NULL) {
            break;
        }
        p = p->next;
    }
    new->data = e;
    new->next = NULL;
    if (p == NULL) {
        DList->Head = new;
    }
    else {
        p->next = new;
    }
    DList->size++;
}

void insert(ListType* DList, int rank, element e) {
   Listnode* new = (Listnode*)malloc(sizeof(Listnode));
   Listnode* p = DList->Head;//임의의 노드 생성

   if (rank == 1) {insertFirst(DList, e);}
   else if (rank == DList->size + 1) {insertLast(DList, e);}//(맨 마지막 + 1)위치 추가
   else {
      for (int i = 1; i < rank; i++) {p = p->next;}//원하는 위치까지 이동
      new->data = e;//새로운 노드에 값 저장
      new->next = p;//새로운 노드의 다음 노드를 원래 위치의 노드로 설정

      DList->size++;
   }
}

void deleteFirst(ListType* DList) {
    if (DList->Head == NULL) {
        return; // 연결리스트가 비어있으면 아무것도 안 함
    }
    Listnode* temp = DList->Head;
    DList->Head = temp->next;
    free(temp); // 삭제된 노드 메모리 해제
    DList->size--;
}

void deleteLast(ListType* DList) {
    if (DList->Head == NULL) {
        return; // 연결리스트가 비어있으면 아무것도 안 함
    }
    Listnode* p = DList->Head;
    Listnode* prev = NULL;
    while(p->next != NULL) {
        prev = p;
        p = p->next;
    }
    if (prev == NULL) {
        DList->Head = NULL; // 리스트에 노드가 하나만 있을 때
    }
    else {
        prev->next = NULL; // 마지막 노드를 삭제하기 위해 이전 노드의 다음 노드를 NULL로 설정
    }
    free(p); // 삭제된 노드 메모리 해제
    DList->size--;
}

void deleteNode(ListType* DList, int rank) {
    if (rank < 1 || rank > DList->size) {
        printf("Invalid rank\n");
        return;
    }
    if (rank == 1) {
        deleteFirst(DList);
    }
    else if (rank == DList->size) {
        deleteLast(DList);
    }
    else {
        Listnode* p = DList->Head;
        Listnode* prev = NULL;
        for (int i = 1; i < rank; i++) {
            prev = p;
            p = p->next;
        }
        prev->next = p->next;
        free(p); // 삭제된 노드 메모리 해제
        DList->size--;
    }
}

element getNode(ListType* DList, int rank) {
    if (rank < 1 || rank > DList->size) {
        printf("Invalid rank\n");
        return -1; // 유효하지 않은 순위일 경우 -1 반환
    }
    Listnode* p = DList->Head;
    for (int i = 1; i < rank; i++) {
        p = p->next;
    }
    return p->data;
}

void print(ListType* DList) {
   for (Listnode* p = DList->Head; p != NULL; p = p->next) {
      printf("[%d] -> ", p->data);
   }printf("\b\b\b\b   \n");
}

int main(){
    //순환문이용
    int n,m,tmp;
    ListType DList_A,DList_B;
    init(&DList_A);init(&DList_B);
    // scanf("%d",&n);
    n = 5;
    srand(time(NULL));
    for(int i=0;i<n;i++){
        // scanf("%d",&tmp);
        tmp = rand() % 99 + 1;
        insert(&DList_A,i+1,tmp);
    }

    printf("Original List: ");
    print(&DList_A);
    deleteLast(&DList_A);
    printf("deleting last node: ");
    print(&DList_A);
    deleteFirst(&DList_A);
    printf("deleting first node: ");
    print(&DList_A);
   
    return 0;
    



    
} 
