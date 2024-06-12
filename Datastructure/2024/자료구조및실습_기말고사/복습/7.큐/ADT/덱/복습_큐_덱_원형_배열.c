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
int isFull(QueueType *Q){return (Q->rear == (MAX-1));}
int isEnd(QueueType *Q){return (Q->rear <= -1 || Q->front <= -1 || Q->front >= MAX - 1 || Q->rear >= MAX - 1  );}

// front 위치에 원소를 삽입합니다.
void push(QueueType *Q, element e){//<<<<<
    //front가 0보다 작으면 rear값으로 변경
    if(isFull(Q)){printf("Qeueu is Full.\n");exit(1);}

    if(Q->front < 0){
        Q->front = Q->max - 2;
        Q->que[Q->front + 1] = e;
    }
    else Q->que[ (Q->front-- % Q->max)  ] = e;
    Q->size ++;
}

//rear 위치에 원소를 삽입합니다.
void inject(QueueType *Q, element e){
    // if(isEnd(Q)){printf("Qeueu is End.\n");exit(1);}
    if(isFull(Q)){printf("Qeueu is Full.\n");exit(1);}
    // Q->que[++Q->rear] = e;
    Q->que[ (++Q->rear) % Q->max ] = e;
    Q->size ++;
}

// front 위치의 원소를 삭제하여 반환합니다.
element pop(QueueType *Q){ //( → -)
    // if(isEnd(Q) || (Q->front == Q->rear) ){printf("Qeueu is End.\n");exit(1);}
    if(isEmpty(Q)){printf("Qeueu is Empty.\n");exit(1);}
    // element rtn = Q->que[Q->front+1];
    element rtn = Q->que[(Q->front + 1) % Q->max];
    // printf("popped : [%c]\n",rtn);

    Q->front = (++Q->front) % Q->max;
    Q->que[Q->front] = ' ';
    Q->size --;

    return rtn;
}
//rear 위치의 원소를 삭제하여 반환합니다.
element eject(QueueType *Q){
    if(isEmpty(Q)){printf("Qeueu is Empty.\n");exit(1);}
    // element rtn = Q->que[(Q->front) % Q->max + 1];
    // Q->front = (++Q->front ) % Q->max;

    element rtn = Q->que[(Q->rear)%Q->max];
    Q->que[(Q->rear--)%Q->max] = ' ';
    // Q->que[ (++Q->rear) % Q->max ] = e;
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
    char aplpha = 'A';
    for(int i=0;i<MAX;i++) Q.que[i] = ' ';


    /*--------------------------------------------------------------------------------------*/
    // for(int i=0;i<4;i++) push(&Q,aplpha ++);printAll(&Q); //front 위치에 원소를 삽입합니다. (→ +)
    // printf("Q->front : %d | Q->rear : %d\n",Q.front,Q.rear);
    
    for(int i=0;i<5;i++) inject(&Q,aplpha ++);printAll(&Q); 
    //rear 위치에 원소를 삽입합니다. (+ ←) : enqueue
    printf("Q->front : %d | Q->rear : %d\n",Q.front,Q.rear);

    for(int i=0;i<3;i++) pop(&Q); printAll(&Q); 
    // front 위치의 원소를 삭제하여 반환합니다. ( → -) : dequeue / 에러 확인 완료
    printf("Q->front : %d | Q->rear : %d\n",Q.front,Q.rear);

    // for(int i=0;i<5;i++) eject(&Q); printAll(&Q); 
    //오른쪽 삭제 (- ←) / 에러 확인 완료
    // printf("Q->front : %d | Q->rear : %d\n",Q.front,Q.rear);
    /*--------------------------------------------------------------------------------------*/
    
    
    // for(int i=0;i<3;i++) inject(&Q,aplpha ++);printAll(&Q); //rear 증가: 오른쪽
    // for(int i=0;i<3;i++) pop(&Q); printAll(&Q); //front 증가 : 왼쪽 삭제


}