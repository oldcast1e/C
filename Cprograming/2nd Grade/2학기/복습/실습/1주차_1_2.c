/*
◦ 다음 네 가지 연산을 지원해야 함 (순위는 1부터 시작한다고 가정)
- add(list, r, e) : list의 순위 r에 원소 e를 추가한다.
- delete(list, r) : list의 순위 r에 위치한 원소를 삭제한다. (주교재의 remove와 동일)
- get(list, r) : list의 순위 r에 위치한 원소를 반환한다.
- print(list) : list의 모든 원소를 저장 순위대로 공백없이 출력한다.
*/

/*기초만 작성 후 자세한 ADT 생략*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef char element;

typedef struct listType{
    struct listNode* head;
    struct listNode* Tail;
    int size;
}listType;

typedef struct listNode{
    struct listNode* next;
    struct listNode* prev;
    element data;
}listNode;

void init(listType* L){
    L->head = (listNode*)malloc(sizeof(listNode));
    L->Tail = (listNode*)malloc(sizeof(listNode));

    L->head->next = L->Tail;
    L->Tail->next = NULL;
    L->head->prev = NULL;
    L->Tail->prev = L->head;

    L->size = 0;
}



void addFront(listType* L,element e){
    listNode* new = (listNode*)malloc(sizeof(listNode));
    new->data = e;

    L->head->next->prev = new;
    new->prev = L->head;
    new->next = L->head->next;
    L->head->next = new;

    // L->size ++;
    // printf(">>addFront\n");
}

void addLast(listType* L,element e){

    listNode* new = (listNode*)malloc(sizeof(listNode));
    new->data = e;
    
    new->prev = L->Tail->prev;
    new->next = L->Tail;
    L->Tail->prev->next = new;
    L->Tail->prev = new;
    // printf(">>addLast\n");
}

void addMiddle(listType* L,int rank, element e){
    listNode* new = (listNode*)malloc(sizeof(listNode));
    new->data = e;

    listNode* tmp  = L->head;
    for(int i=0;i<rank-1;i++){tmp = tmp->next;}

    tmp->next->prev = new;
    new->prev = tmp;
    new->next = tmp->next;
    tmp->next = new;
    // printf(">>addMiddle\n");
}

void add(listType* L,int rank, element e){
    // if(rank > L->size + 1 || rank < 1) printf("invalid position\n");

    if(rank == 1)addFront(L,e);
    else if(rank > L->size) addLast(L,e);
    else addMiddle(L,rank,e);
    L->size ++;
}

void delete(listType* L, int rank){
    // if( rank < 1 || rank > L->size){ printf("invalid position\n"); return -1;}
    
    listNode* del  = L->head;
    for(int i=0;i<rank;i++) del = del->next;
    // element val = del->data;

    del->next->prev = del->prev;
    del->prev->next = del->next;
    L->size --;
    // return val;
}

void get(listType* L, int rank){
    listNode* tmp  = L->head;
    // if( rank < 1 || rank > L->size){ printf("invalid position\n"); return;}

    for(int i=0;i<rank;i++) tmp = tmp ->next;
    printf("%c\n",tmp->data);
}

void print(listType* L){
    listNode* tmp = L->head->next;
    //  listNode* tmp = L->Tail->prev;
    for(int i=0;i<L->size;i++){
        printf("%c",tmp->data);
        // tmp = tmp->prev;
        tmp = tmp->next;
    }printf("\n");
}

int main(){
    listType list; init(&list);
    int n,rank; scanf("%d",&n);getchar();
    char func,tmp,data;
    for(int rep = 0 ; rep < n; rep ++){
        scanf("%c%c",&func,&tmp);
        if(func == 'A'){
            // printf("operating A...\n");
            scanf("%d%c%c",&rank,&tmp,&data); getchar();
            if(rank > (list.size + 1) || rank < 1){ printf("invalid position\n");}
            else add(&list,rank,data);
        } 
        else if(func == 'D'){
            // printf("operating D...\n");
            scanf("%d",&rank);getchar();
            if(rank > (list.size) || rank < 1){ printf("invalid position\n");}
            else delete(&list,rank);
        }    
        else if(func == 'G'){
            // printf("operating G...\n");
            scanf("%d",&rank);getchar();
            if(rank > (list.size) || rank < 1){ printf("invalid position\n");}
            else get(&list,rank);
        }
        else if(func == 'P'){
            print(&list);
        }
    }
    
}
/*
5 
A 1 S
A 2 t
A 3 r
A 3 a
P


9
A 1 D
A 2 a
A 3 y
D 1
P
G 3
A 1 S
P
G 3
*/