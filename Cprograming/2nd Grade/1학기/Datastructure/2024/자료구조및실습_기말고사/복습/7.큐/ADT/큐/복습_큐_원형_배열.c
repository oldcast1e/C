#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

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
int isFull(QueueType *Q){return (Q->size >= MAX);}

void enqueue(QueueType *Q, element e){
    // Q->que[++Q->rear] = e;
    if(isFull(Q)){printf("Queue is Full.");exit(1);}
    Q->que[ (++Q->rear) % Q->max ] = e;
    Q->size ++;
}

element dequeue(QueueType *Q){
    // element rtn = Q->que[Q->front+1];
    if(isEmpty(Q)){printf("Queue is Empty.");exit(1);}
    element rtn = Q->que[(Q->front) % Q->max + 1];

    Q->front = (++Q->front ) % Q->max;
    Q->que[Q->front] = ' ';
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

void enqueueNum(QueueType *Q, int n, char alpha){for(int i=0;i<n;i++) enqueue(Q,alpha++); printAll(Q); }
void dequeueNum(QueueType *Q, int n){for(int i=0;i<n;i++) dequeue(Q); printAll(Q); }


int main(){
    QueueType Q; init(&Q);
    srand(time(NULL));

    char alpha = 'A'; int cnt = 0;
    for(int i=0;i<MAX+1;i++)Q.que[i] = ' ';
    // dequeue(&Q);

    enqueueNum(&Q,10,alpha);
    dequeueNum(&Q,5);
    enqueueNum(&Q,3,alpha);
    dequeueNum(&Q,5);
    enqueueNum(&Q,5,alpha);enqueueNum(&Q,2,alpha);
    enqueue(&Q,alpha++); 
}