#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef int element;

typedef struct{
    int max; //큐의 용량
    int size; //현재 데이터 개수

    int front; //프런트
    int rear; //리어

    element *que; // 배열 포인터 
} QueueType;

void init(QueueType *Q, int max){
    Q->que = (element*)malloc(sizeof(element)*max);
    Q->max = max;
    Q->size = 0;
    Q->front = Q->rear = 0;
}

int isEmpty(QueueType *Q){return (Q->size==0);}
int isFull(QueueType *Q){return (Q->size >= Q->max-1);}

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
    Q->que[Q->front] = 0;
    Q->size --;

    return rtn;
}

element frontPeek(QueueType *Q){return(Q->que[Q->front]);}
element rearPeek(QueueType *Q){return(Q->que[Q->rear]);}

int size(QueueType *Q){return Q->size;}

void print(QueueType *Q){
    for(int i= Q->front+1 ; i<= Q->rear ; i++){
        printf("[%d]",Q->que[i]);
    } printf("\n");
}

void printAll(QueueType *Q){
    for(int i= 0 ; i< Q->max ; i++){
        printf(" %d",Q->que[i]);
    } printf("\n");
}

element* elements(QueueType *Q){return Q->que;}

void enqueueNum(QueueType *Q, int n, char alpha){for(int i=0;i<n;i++) enqueue(Q,alpha++); printAll(Q); }
void dequeueNum(QueueType *Q, int n){for(int i=0;i<n;i++) dequeue(Q); printAll(Q); }


int main(){
    //위 전략은 front가 맨 앞 원소 위치보다 한 셀 앞 위치를 가리키는 방식으로 정의되었다. 
    int q,n,data; char fuc,tmp;
    scanf("%d",&q);//큐의 크기
    scanf("%d",&n); getchar();//반복 횟수
    QueueType Q; init(&Q,q);
    //init(QueueType *Q, int max)
    // for(int i=0;i<n;i++) enqueue(&Q,0);
    // printAll(&Q);

    for(int i=0;i<n;i++){
        scanf("%c%c",&fuc,&tmp);
        if(fuc == 'I'){
            if(isFull(&Q)){printf("overflow");printAll(&Q);exit(1);}
            scanf("%d",&data); getchar(); //printf("data = %d",data);
            enqueue(&Q,data);
        }
        else if(fuc == 'D'){
            if(isEmpty(&Q)){printf("underflow ");;exit(1);}
            dequeue(&Q);
        }
        else if(fuc == 'P') printAll(&Q);
    }
}   

/*
6
10
I 10
I 20
P
I 30
I 40
D
P
I 50
I 60
I 70

6
1
I 40
*/