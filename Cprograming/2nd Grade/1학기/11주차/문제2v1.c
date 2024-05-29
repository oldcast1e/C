#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include  <string.h>

typedef int element;

#define MAX 10

typedef struct QueueNode {
    element data;
    struct QueueNode* prev;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
    int size;
} DequeType;

void init(DequeType* D) {
    D->front = NULL;
    D->rear = NULL;
    D->size = 0;
}

int isEmpty(DequeType* D) {
    return D->size == 0;
}

int isFull(DequeType* D) {
    return D->size >= MAX;
}

void add_front(DequeType* D, element e) {
    if (isFull(D)) {
        printf("Deque is full.\n");
        return;
    }

    QueueNode* new = (QueueNode*)malloc(sizeof(QueueNode));
    new->data = e;
    new->prev = NULL;
    new->next = D->front;

    if (isEmpty(D)) {
        D->rear = new;
    } else {
        D->front->prev = new;
    }

    D->front = new;
    D->size++;
}

void add_rear(DequeType* D, element e) {
    if (isFull(D)) {
        printf("Deque is full.\n");
        return;
    }

    QueueNode* new = (QueueNode*)malloc(sizeof(QueueNode));
    new->data = e;
    new->prev = D->rear;
    new->next = NULL;

    if (isEmpty(D)) {
        D->front = new;
    } else {
        D->rear->next = new;
    }

    D->rear = new;
    D->size++;
}

element delete_front(DequeType* D) {
    if (isEmpty(D)) {
        printf("Deque is empty.\n");
        exit(EXIT_FAILURE);
    }

    QueueNode* del = D->front;
    element val = del->data;

    D->front = del->next;
    if (D->front != NULL) {
        D->front->prev = NULL;
    } else {
        D->rear = NULL;
    }

    free(del);
    D->size--;
    
    return val;
}

element delete_rear(DequeType* D) {
    if (isEmpty(D)) {
        printf("Deque is empty.\n");
        exit(EXIT_FAILURE);
    }

    QueueNode* del = D->rear;
    element val = del->data;

    D->rear = del->prev;
    if (D->rear != NULL) {
        D->rear->next = NULL;
    } else {
        D->front = NULL;
    }

    free(del);
    D->size--;
    
    return val;
}

void print(DequeType* D) {
    if (isEmpty(D)) {
        printf("Deque is empty.\n");
        return;
    }

    QueueNode* p = D->front;
    while (p != NULL) {
        printf(" %d", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int q, n, e; // 큐의 크기, 연산의 개수, 원소
    scanf("%d", &n);  getchar(); // 개행 문자 처리

    char F[5]; // 연산을 나타내는 문자
    DequeType DQ; // 큐 선언
    DQ.size = q; // 큐의 크기 설정
    init(&DQ); // 큐 초기화


    // 연산 수행
    for (int i = 0; i < n; i++) {
        scanf("%s", F); // 연산 입력
        getchar(); // 개행 문자 처리
        
        if(strcmp(F,"AF") == 0) {
            scanf("%d",&e); getchar();
            add_front(&DQ,e);
        }
        else if(strcmp(F,"AR") == 0) {
            scanf("%d",&e); getchar();
            add_rear(&DQ,e);
        }

        else if(strcmp(F,"DF") == 0) {
            delete_front(&DQ);
        }
        else if(strcmp(F,"AR") == 0) {
            delete_rear(&DQ);
        }
        else if(strcmp(F,"P") == 0) {
            print(&DQ);
        }
    }
    return 0;
}
