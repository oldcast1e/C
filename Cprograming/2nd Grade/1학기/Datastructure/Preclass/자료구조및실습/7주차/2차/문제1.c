#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
[ 문제 1 ] 두 개의 집합 A와 B를 입력 받아, 
    A가 B의 부분집합인지를 검사하는 프로그램을 작성 하시오.
*/
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
/*
1) 집합은 오름차순 양의 정수로 저장 및 출력되어야 한다.
2) 공집합은 공집합을 포함한 모든 집합의 부분집합이다.
3) 입력: 프로그램은 두 개의 집합 A, B를 차례로 표준입력 받는다. 
    한 개의 집합을 나타내는 두 개의 입력 라인은 다음과 같이 구성된다.
첫 번째 라인: 정수 n (집합 크기, 즉 집합 원소의 개수)
두 번째 라인: 집합의 원소들 (오름차순 양의 정수 수열). 
    공집합은 첫 번째 라인은 0, 두 번째 라인은 존재하지 않는다.
4) 출력: A ⊂ B이면 0을 출력하고, 
    그렇지 않으면 집합 B에 속하지 않은 
    집합 A의 가장 작은 원 소를 표준 출력한다.
5) 모든 집합은 헤더 노드가 없는 
    단일연결리스트(singly-inked list) 형태로 구축되어야 한다.
6) 참고: 아래 그림은 일반적인 단일연결리스트를 나타낸다. 
    빈 리스트의 경우 null pointer로 나타 낸다. 
    (그림의 노드에 저장된 원소가 영문자인데, 
    이는 무시하고 리스트의 형태만 참고하시오.)
*/
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
   Listnode* new = (Listnode*)malloc(sizeof(Listnode));//새로운 노드 동적할당
   Listnode* p = DList->Head;   //테일 노드를 저장하는 노드
   printf("input data = %d\n",e);
   while(p != NULL){p=p->next;printf("-");}printf("\n");

   new->data = e; // 새로운 노드에 값 저장
   new->next = NULL;//새로운 노드의 다음은 NULL : 마지막에 추가했음

   if (p == NULL) {
        DList->Head = new;
        printf("Head: %d\n",DList->Head->data);
   }
   else {p->next = new;}//테일 노드의 다음을 new로 지정 : new가 추가됨
   DList->size++;
}

void insert(ListType* DList, int pos, element e) {
   Listnode* new = (Listnode*)malloc(sizeof(Listnode));
   Listnode* p = DList->Head;//임의의 노드 생성

   if (pos == 1) {insertFirst(DList, e);}
   else if (pos == DList->size + 1) {insertLast(DList, e);}//(맨 마지막 + 1)위치 추가
   else {
      for (int i = 1; i < pos; i++) {p = p->next;}//원하는 위치까지 이동
      new->data = e;//새로운 노드에 값 저장
      new->next = p;//새로운 노드의 다음 노드를 원래 위치의 노드로 설정

      DList->size++;
   }
}
void print(ListType* DList) {
   for (Listnode* p = DList->Head; p != NULL; p = p->next) {
      printf("[%d] <=> ", p->data);
   }printf("\b\b\b\b   \n");
}

/*
◦ 함수 subset : 집합 A가 집합 B의 부분집합인지 여부 검사
- 인자: 양의 정수 집합 A, B (A, B는 각각 단일연결리스트의 헤드 노드)
- 반환값: 정수 (A ⊂ B면 0, 그렇지 않으면 집합 B에 속하지 않은 집합 A의 가장 작은 원
소)
*/
// int subset(Listnode* small,Listnode* big){

    
// }
//출력: A ⊂ B이면 0을 출력하고, 그렇지 않으면 집합 B에 속하지 않은 집합 A의 가장 작은 원 소를 표준 출력한다.

int main(){
    //순환문이용
    int n,m,tmp;
    ListType DList_A,DList_B;
    init(&DList_A);init(&DList_B);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        insertLast(&DList_A,tmp);
    }
    



    
} 



/*
0
3
9 20 77

3
4 6 13
6
1 3 4 6 8 13

3
7 10 53
4
7 10 15 45


0
3
9 20 77

3
9 20 77
0


*/
