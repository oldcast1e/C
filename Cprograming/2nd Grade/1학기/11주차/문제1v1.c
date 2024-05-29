#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include  <time.h>

typedef int element;

#define N 10

typedef struct {
    element *data;
    int front,rear;
    int size;
} QueueType;

void print(QueueType *Q);

void init(QueueType *Q){
    Q->data = (int*)malloc(sizeof(int)*Q->size);
    // for (int i = 0; i < Q->size; i++) Q->data[i] = 0;

    Q->front = Q->rear = 0;
}

int isEmpty(QueueType *Q){
    return(Q->front == Q->rear);
}

int isFull(QueueType *Q){
    return ( Q->front == (Q->rear + 1) % Q->size );
}

void enqueue(QueueType *Q, element e){
    // if(isEmpty(Q))Q->rear =  (Q->rear + 1) % Q->size;
    /*
    verflow 발생 시 (즉, 포화 상태에서 삽입을 시도한 경우), 
    화면에 overflow와 배열 값들을 모두 출력하고 프로그램 종료.
    
    */

    // if(isFull(Q)) printf("FULL.\n");
    // if(isFull(Q)) {printf("overflow");print(Q);}
    if(isFull(Q)) {printf("overflow");print(Q);exit(1);}
    else{
        Q->rear = (Q->rear + 1)% Q->size;
        Q->data[Q->rear]  = e;
    }
}

element dequeue(QueueType *Q){
    // if(isEmpty(Q)) {printf("EMPTY.\n"); return 0;}
    if(isEmpty(Q)) {printf("underflow ");exit(1);} //underflow 이후 공백 차이!
    else{
        // element del = Q->data[(front + 1)%N];
        Q->front = (Q->front + 1) % Q->size;
        int del = Q->data[ Q->front ];
        Q->data[ Q->front ] = 0;
        return (del);

    }
}

void print(QueueType *Q){
    // printf("Front : %d - Rear : %d\n",Q->front,Q->rear);
    for(int j=0;j<Q->size;j++){
        printf(" %d",Q->data[j]);
    }printf("\n");
    // int i = Q->front;
    // while(i != Q->rear){
    //     i = (i+1)%N;
    //     printf("[%d] ",Q->data[i]);
    // } printf("\n");
}
/*
1) 첫 번째 라인 : 양의 정수 q (원형 큐의 크기)
※ q 값에는 제한이 없다. 또한, 동적 할당을 사용할 것. 
2) 두 번째 라인 : 양의 정수 n (연산의 개수)
3) 세 번째 이후 라인: n개의 연산이 차례로 입력됨.

*/
int main(){

    int q,n,e; scanf("%d",&q); scanf("%d",&n); getchar();
    char F;
    QueueType Q;
    Q.size = q;
    init(&Q);
    for (int i = 0; i < Q.size; i++) Q.data[i] = 0;

    for (int i = 0; i < n; i++) {
        /*
        - I 10 : 원형 큐에 원소 10을 삽입 (큐 원소는 양의 정수).
        - D : 원형 큐에서 원소를 삭제한 후 해당 배열 원소 값을 0으로 치환.
        - P : 배열 원소 전체를 차례로 화면에 출력 (입출력 예시 참조).
        */
        scanf("%c",&F);getchar();
        switch(F){
            case 'I':
                scanf("%d",&e); getchar();
                enqueue(&Q,e);
                break;
            
            case 'D':
                dequeue(&Q);
                // printf("[%d] is dequeded.\n",dequeue(&Q));
                break;
            
            case 'P':
                print(&Q);
                break;
        }
    }

    // srand(time(NULL));

    // for (int i = 0; i < 7; i++) {
    //     enqueue(&Q, rand()% 26 + 65);
    // }print(&Q);

    // for (int i = 0; i < 3; i++) {
    //     printf("[%c] is dequeded.\n",dequeue(&Q));
    // }print(&Q);



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
12
I 10
I 20
P
I 30
I 40
D
P
I 50
P
I 60
P
I 70
*/
