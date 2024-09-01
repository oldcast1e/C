#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int element;

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

void add_front(DequeType* D, element e) {
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
        printf("underflow\n");
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
        printf("underflow\n");
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
        printf("[%c] ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int n, e; // 연산의 개수, 원소
    // scanf("%d", &n); getchar(); // 개행 문자 처리

    char F[5]; // 연산을 나타내는 문자열
    DequeType DQ; // 데크 선언
    init(&DQ); // 데크 초기화

    srand(time(NULL));

   printf("----------<add_front>----------\n");
    for (int i = 0; i < 7; i++) add_front(&DQ, rand() % 26 + 65); print(&DQ);
    printf("---------<delete_front>-------\n");
    for (int i = 0; i < 3; i++) printf("[%c] is deleted from front.\n", delete_front(&DQ)); print(&DQ);
    printf("-----------<add_rear>----------\n");
    for (int i = 0; i < 3; i++) add_rear(&DQ, rand() % 26 + 65); print(&DQ);
    printf("----------<delete_rear>-------\n");
    for (int i = 0; i < 1; i++) printf("[%c] is deleted from rear.\n", delete_rear(&DQ)); print(&DQ);
    printf("----------<add_front>----------\n");
    for (int i = 0; i < 3; i++) add_front(&DQ, rand() % 26 + 65); print(&DQ);

}

    // // 연산 수행
    // for (int i = 0; i < n; i++) {
    //     scanf("%s", F); // 연산 입력
    //     if (strcmp(F, "AF") == 0) {
    //         scanf("%d", &e); getchar();
    //         add_front(&DQ, e);
    //     } else if (strcmp(F, "AR") == 0) {
    //         scanf("%d", &e); getchar();
    //         add_rear(&DQ, e);
    //     } else if (strcmp(F, "DF") == 0) {
    //         delete_front(&DQ);
    //     } else if (strcmp(F, "DR") == 0) {
    //         delete_rear(&DQ);
    //     } else if (strcmp(F, "P") == 0) {
    //         print(&DQ);
    //     }
    // }

