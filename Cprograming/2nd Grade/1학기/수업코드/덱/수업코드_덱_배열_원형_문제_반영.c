#include <stdio.h>
#include <stdlib.h>

typedef int element;

#define N 10

typedef struct {
    element *data; // 데이터 저장 배열
    int front, rear; // 포인터와 리어 변수
    int size; // 배열의 사이즈
} DequeType;

void print(DequeType *Q);

// 큐 초기화 함수
void init(DequeType *Q){
    Q->data = (int*)malloc(sizeof(int)*Q->size);
    Q->front = Q->rear = 0; // 큐의 front와 rear를 초기화
}

// 큐가 비어있는지 확인하는 함수
int isEmpty(DequeType *Q){
    return (Q->front == Q->rear);
}

// 큐가 꽉 차 있는지 확인하는 함수
int isFull(DequeType *Q){
    return (Q->front == (Q->rear + 1) % Q->size);
}

// 데크의 앞에 원소를 추가하는 함수
void add_front(DequeType *Q, element e){
    if (isFull(Q)) {
        printf("overflow "); // overflow 메시지 출력
        print(Q); // 현재 큐의 상태 출력
        exit(1); // 프로그램 종료
    } else {
        Q->data[Q->front] = e;
        Q->front = (Q->front - 1 + Q->size) % Q->size; // front 이동
    }
}

// 데크의 뒤에 원소를 추가하는 함수
void add_rear(DequeType *Q, element e){
    if (isFull(Q)) {
        printf("overflow "); // overflow 메시지 출력
        print(Q); // 현재 큐의 상태 출력
        exit(1); // 프로그램 종료
    } else {
        Q->rear = (Q->rear + 1) % Q->size; // rear 이동
        Q->data[Q->rear] = e; // 데이터 삽입
    }
}

// 데크의 앞에서 원소를 삭제하는 함수
element delete_front(DequeType *Q){
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

// 데크의 뒤에서 원소를 삭제하는 함수
element delete_rear(DequeType *Q){
    if (isEmpty(Q)) {
        printf("underflow "); // underflow 메시지 출력
        exit(1); // 프로그램 종료
    } else {
        int del = Q->data[Q->rear]; // 삭제된 원소 저장
        Q->data[Q->rear] = 0; // 삭제된 위치를 0으로 초기화
        Q->rear = (Q->rear - 1 + Q->size) % Q->size; // rear 이동
        return del; // 삭제된 원소 반환
    }
}

// 큐의 상태를 출력하는 함수
void print(DequeType *Q){
    for(int j = 0; j < Q->size; j++){
        printf(" %d", Q->data[j]); // 배열의 모든 원소 출력
    }
    printf("\n");
}

// 메인 함수
int main(){
    int q, n, e; // 큐의 크기, 연산의 개수, 원소
    scanf("%d", &q); // 큐의 크기 입력
    scanf("%d", &n); // 연산의 개수 입력
    getchar(); // 개행 문자 처리

    char F; // 연산을 나타내는 문자
    DequeType DQ; // 큐 선언
    DQ.size = q; // 큐의 크기 설정
    init(&DQ); // 큐 초기화

    // 큐에 원소 삽입 전 모든 원소를 0으로 초기화
    for (int i = 0; i < DQ.size; i++) {
        DQ.data[i] = 0;
    }

    // 연산 수행
    for (int i = 0; i < n; i++) {
        scanf("%c", &F); // 연산 입력
        getchar(); // 개행 문자 처리

        switch (F) {
            case 'I':
                scanf("%d", &e); // 삽입할 원소 입력
                getchar(); // 개행 문자 처리
                add_rear(&DQ, e); // 데크의 뒤에 원소 삽입
                break;

            case 'D':
                delete_front(&DQ); // 데크의 앞에서 원소 삭제
                break;

            case 'F':
                scanf("%d", &e); // 삽입할 원소 입력
                getchar(); // 개행 문자 처리
                add_front(&DQ, e); // 데크의 앞에 원소 삽입
                break;

            case 'R':
                delete_rear(&DQ); // 데크의 뒤에서 원소 삭제
                break;

            case 'P':
                print(&DQ); // 큐의 상태 출력
                break;
        }
    }

    free(DQ.data); // 동적 할당된 메모리 해제
    return 0;
}
