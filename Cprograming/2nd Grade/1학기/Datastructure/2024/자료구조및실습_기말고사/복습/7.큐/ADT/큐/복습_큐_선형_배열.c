#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 15

typedef char element;

typedef struct{
    int max; //큐의 용량
    int size; //현재 데이터 개수

    int front; //프런트
    int rear; //리어

    element *que; // 배열 포인터 
} QueueType;

void init(QueueType *Q){
    Q->que = (element*)malloc(sizeof(element)*MAX);
    Q->max = MAX;
    Q->size = 0;
    Q->front = Q->rear = -1;
}

int isEmpty(QueueType *Q){return (Q->size==0);}
int isFull(QueueType *Q){return (Q->rear == (MAX-1));}

void enqueue(QueueType *Q, element e){
    Q->que[++Q->rear] = e;
    Q->size ++;
}

element dequeue(QueueType *Q){
    element rtn = Q->que[Q->front+1];
    Q->que[Q->front++] = '\0';
    Q->size --;

    return rtn;
}

element frontPeek(QueueType *Q){return(Q->que[Q->front]);}
element rearPeek(QueueType *Q){return(Q->que[Q->rear]);}

int size(QueueType *Q){return Q->size;}

void print(QueueType *Q){
    for(int i= Q->front+1 ; i<= Q->rear ; i++){
        printf("[%c]",Q->que[i]);
    } printf("\n");
}

void printAll(QueueType *Q){
    for(int i= 0 ; i< MAX ; i++){
        printf("[%c]",Q->que[i]);
    } printf("\n");
}

element* elements(QueueType *Q){return Q->que;}

int main(){
    QueueType Q; init(&Q);
    srand(time(NULL));

    for(int i=0;i<rand()%9+1;i++) enqueue(&Q,'A'+rand()%26);
    // print(&Q);
    printAll(&Q);
    for(int i=0;i<rand()%9+1;i++) dequeue(&Q);
    // print(&Q);
    printAll(&Q);
}