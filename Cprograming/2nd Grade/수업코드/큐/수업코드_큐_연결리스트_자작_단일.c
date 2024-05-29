#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char element;

#define MAX 10

typedef struct QueueNode {
    element data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
    int size;
} QueueType;

void init(QueueType* Q) {
    Q->front = NULL;
    Q->rear = NULL;
    Q->size = 0;
}

int isEmpty(QueueType* Q) {return Q->size == 0;}

int isFull(QueueType* Q) {return Q->size >= MAX;}

void enqueue(QueueType* Q, element e) {
    QueueNode* new = (QueueNode*)malloc(sizeof(QueueNode));
    new->data = e;
    new->next = NULL;
    
    if (isEmpty(Q)) Q->front = new;
    else Q->rear->next = new;
    
    Q->rear = new;
    Q->size++;
}

element dequeue(QueueType* Q) {
    if (isEmpty(Q)) {
        printf("Empty.\n");
        exit(EXIT_FAILURE);
    }
    
    QueueNode* del = Q->front;
    element val = del->data;
    
    Q->front = del->next;
    free(del);
    Q->size--;
    
    if (isEmpty(Q)) Q->rear = NULL;
    return val;
}

void print(QueueType* Q) {
    if (isEmpty(Q)) {
        printf("Empty.\n");
        return;
    }
    
    QueueNode* p = Q->front;
    
    while (p != NULL) {
        printf("[%c] ", p->data);
        p = p->next;
    }printf("\n");

}


int main() {
    QueueType Q; // 큐 선언
    Q.size = MAX; // 큐의 크기 설정
    init(&Q); // 큐 초기화

    srand(time(NULL));

    for (int i = 0; i < 7; i++) enqueue(&Q, rand()% 26 + 65);print(&Q);
    for (int i = 0; i < 3; i++) printf("[%c] is dequeded.\n",dequeue(&Q));print(&Q);
    
    for (int i = 0; i < 3; i++) enqueue(&Q, rand()% 26 + 65);print(&Q);
    for (int i = 0; i < 1; i++) printf("[%c] is dequeded.\n",dequeue(&Q));print(&Q);

    enqueue(&Q, rand()% 26 + 65);print(&Q);
}
