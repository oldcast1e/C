#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int element;

typedef struct QueueNode {
    element data;
    struct QueueNode* next;
    struct QueueNode* prev;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
    int size;
} QueueType;

void init(QueueType *Q){
    Q->size = 0;
    Q->front = Q->rear = NULL;
}

int isEmpty(QueueType *Q){return (Q->size == 0);}

//헤드 노드와 테일 노드가 없는 이중연결리스트

void add_front(QueueType* Q, element e){
    //front 위치에 원소를 삽입합니다. (→ +)

    QueueNode *new = (QueueNode*)malloc(sizeof(QueueNode));
    new->data = e;
    // printf("[add_front]");
    if(isEmpty(Q)) Q->front = Q-> rear = new;
    else{
        QueueNode *p = Q->front;
        // while(p->next != NULL) p = p->next;

        new->next = p;
        p->prev = new;

        Q->front = new;
        // printf("[%d]",Q->front->data);
    }

    Q->size ++; 
}

void add_rear(QueueType* Q, element e){
    // rear 위치에 원소를 삽입합니다. (+ ←)
    QueueNode *new = (QueueNode*)malloc(sizeof(QueueNode));
    new->data = e;

    if(isEmpty(Q)) Q->front = Q-> rear = new;
    else{
        QueueNode *p = Q->rear;
        while(p->next != NULL) p = p->next;
        p->next = new;
        new->prev = p;
    }

    Q->size ++; // printf("add_rear : %c\n",Q->rear->data);
}

element delete_front(QueueType *Q){
    //front 위치의 원소를 삭제하여 반환합니다. ( → -)
    char e = Q->front->data;
    // printf("[add_front]");
    if(isEmpty(Q)) Q->front = Q-> rear = NULL;
    else{
        // Q->front->next = Q->front->next->next;
        Q->front = Q->front->next;
        Q->front->prev = NULL;
        // printf("[%d]",Q->front->data);
    }
    Q->size -- ;

    return e;

}

element delete_rear(QueueType *Q){
    //rear 위치의 원소를 삭제하여 반환합니다.  (- ←)
    char e = Q->rear->data;
    if(isEmpty(Q)) Q->front = Q-> rear = NULL;
    else{
        QueueNode *p = Q->rear;
        QueueNode *pre;
        while(p->next != NULL) {
            pre = p;
            p = p->next;
        }
        pre->next = NULL;
    }
    Q->size -- ;
    return e;

}

void print(QueueType *Q){
    QueueNode *p = Q->front;
    while(p != NULL){
        printf(" %d",p->data);
        p= p->next;
    }printf("\n");
    
}

/*
- 주의 : 연산 수행 도중 원소가 모두 삭제되어 데크가 비는 경우에도, 아래 초기 상태가
되어야 함.
*/
int main(){
    QueueType Q; init(&Q);
    int N,data; 
    // N = 5;
    scanf("%d",&N);getchar();
    char tmp;

    // for(int i=0;i<N;i++) add_front(&Q,(i+1)*10);print(&Q);
    // for(int i=0;i<N;i++) add_rear(&Q,(i+1)*10);print(&Q);
    // delete_front(&Q);print(&Q);
    // delete_rear(&Q);print(&Q);

    for(int i=0;i<N;i++) {
        char fun[3];scanf("%s%c",fun,&tmp); //getchar();
        // AF (add_front), AR (add_rear), DF (delete_front), DR (delete_rear), P (print)
        if(strcmp(fun,"AF")==0){
            scanf("%d",&data);getchar();
            add_front(&Q,data);
        }
        else if(strcmp(fun,"AR")==0){
            scanf("%d",&data);getchar();
            add_rear(&Q,data); 
        }
        else if(strcmp(fun,"DF")==0){
            if(isEmpty(&Q)){printf("underflow");exit(1);}
            delete_front(&Q);
        }   
        else if(strcmp(fun,"DR")==0){
            if(isEmpty(&Q)){printf("underflow");exit(1);}
            delete_rear(&Q);
        }
        else if(strcmp(fun,"P")==0){
            print(&Q);
        }
    }
  
}
/*
7
AF 10
AF 20
AR 30
P
DF
DR
P

15
AF 10
AF 20
AF 30
AR 40
AR 50
P
DF
DF
DR
P
DF
DR
DR
*/