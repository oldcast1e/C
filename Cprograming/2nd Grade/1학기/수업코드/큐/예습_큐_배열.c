#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef char element;

typedef struct{
    int max; //큐의 용량
    int num; //현재 데이터 개수

    int front; //프런트
    int rear; //리어

    element *que; // 배열 포인터 
} QueueType;

void initQ(QueueType *Q){
    Q->max = MAX;
    Q->num = 0;

    Q->front = 0;
    Q->rear = 0;

    Q->que = (char*)malloc(sizeof(char)*MAX);
    // Q->que= NULL;
}

int isEmpty(QueueType *Q){
    if(Q->num == 0) return 1;
    return 0;
}

int isFull(QueueType *Q){
    if(Q->num == Q->max )return 1;
    return 0;
    /*
    isFull과 isEmpty를 구분할 수 없음.
    따라서 front의 앞이 비어있지 않다면 isFull로 설정
    */
}

void enQue(QueueType *Q, element c){
    if(isFull(Q)) {printf("Queue is Full!"); return ;}
    else{
        Q->que[Q->front++] = c;
        if(Q->front > Q->max) Q->
    }
}

int main() {
    QueueType Q;
    initQ(&Q);

    // enqueue(&Q, 'A');
    // prQueueType(&Q);
    // enqueue(&Q, 'C');
    // prQueueType(&Q);
    // enqueue(&Q, 'B');
    // prQueueType(&Q);

    // printf("[%c] is dequeued.\n", dequeue(&Q));
    // prQueueType(&Q);
    // printf("[%c] is dequeued.\n", dequeue(&Q));
    // prQueueType(&Q);

    return 0;
}
