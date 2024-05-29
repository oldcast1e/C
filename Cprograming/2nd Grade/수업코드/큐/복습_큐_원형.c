#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char element;

#define MAX 10

typedef struct {
    element *data; // 데이터 저장 배열
    int front, rear; // 포인터와 리어 변수
    int size;// 배열의 사이즈
} QueueType;

void print(QueueType *Q);
void printQue_R_TO_E(QueueType *Q);

// 큐 초기화 함수
void init(QueueType *Q){
    Q->data = (char*)malloc(sizeof(char)*Q->size);
    // Q->data = (int*)malloc(sizeof(int)*Q->size);
    Q->front = Q->rear = 0; // 큐의 front와 rear를 초기화
}

// 큐가 비어있는지 확인하는 함수
int isEmpty(QueueType *Q){return (Q->front == Q->rear);}

// 큐가 꽉 차 있는지 확인하는 함수
int isFull(QueueType *Q){return (Q->front == (Q->rear + 1) % Q->size);}

// 큐에 원소를 삽입하는 함수
void enqueue(QueueType *Q, element e){
    // 포화 상태에서 삽입을 시도한 경우 처리
    if (isFull(Q)) {
        printf("overflow "); // overflow 메시지 출력
        printQue_R_TO_E(Q); // 현재 큐의 상태 출력
        exit(1); // 프로그램 종료
    } 
    else {
        Q->rear = (Q->rear + 1) % Q->size; // rear 이동
        Q->data[Q->rear] = e; // 데이터 삽입
    }
}

// 큐에서 원소를 삭제하는 함수
element dequeue(QueueType *Q){
    // 공백 상태에서 삭제를 시도한 경우 처리
    if (isEmpty(Q)) {
        printf("underflow "); // underflow 메시지 출력
        exit(1); // 프로그램 종료
    } else {
        Q->front = (Q->front + 1) % Q->size; // front 이동
        int del = Q->data[Q->front]; // 삭제된 원소 저장
        Q->data[Q->front] = 0; // 삭제된 위치를 0으로 초기화
        return del; // 삭제된 원소 반환
    }
}

// 큐의 상태를 출력하는 함수
void print(QueueType *Q){
    for(int j=0; j<Q->size; j++){
        printf(" %d", Q->data[j]); // 배열의 모든 원소 출력
    }printf("\n");
}

void printQue(QueueType *Q){
    int i = Q->front;
    while (i != Q->rear) {
        i = (i + 1) % Q->size;
        printf("%c ", Q->data[i]);
    }
    printf("\n");
}

void printQue_R_TO_E(QueueType *Q){
     for(int j=0; j<Q->size; j++){
        printf("[%c] ", Q->data[j]); // 배열의 모든 원소 출력
    }
    printf("\n");
}

// 메인 함수
int main(){
    QueueType Q; // 큐 선언
    Q.size = MAX; // 큐의 크기 설정
    init(&Q); // 큐 초기화
    for (int i = 0; i < Q.size; i++) {Q.data[i] = ' ';}

    srand(time(NULL));

    for (int i = 0; i < 7; i++) enqueue(&Q, rand()% 26 + 65);printQue_R_TO_E(&Q);
    for (int i = 0; i < 3; i++) printf("[%c] is dequeded.\n",dequeue(&Q));printQue_R_TO_E(&Q);
    
    for (int i = 0; i < 3; i++) enqueue(&Q, rand()% 26 + 65);printQue_R_TO_E(&Q);
    for (int i = 0; i < 1; i++) printf("[%c] is dequeded.\n",dequeue(&Q));printQue_R_TO_E(&Q);

    for (int i = 0; i < 3; i++) enqueue(&Q, rand()% 26 + 65);printQue_R_TO_E(&Q);

    enqueue(&Q, rand()% 26 + 65);printQue_R_TO_E(&Q);
}
