#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int max;
    int num;
    int front;
    int rear;
    int *que;
} IntQueue;

int Initialize(IntQueue *Que,int max){
    Que->num = Que->front = Que->rear = 0;

    Que->que = (int*) malloc(sizeof(int)*max);
    if(Que->que == NULL){
        Que->max = 0;
        return - 1;
    }
    // if(Que->que ==(int*) malloc(sizeof(int)*max)== NULL) {
    //     Que->max = 0;
    //     return - 1;
    // }
    Que-> max = max;
    return 0;
}

int EnQue(IntQueue *Que,int data){
    if(Que->num >= Que->max) return -1;
    Que ->num ++;
    Que->que[Que->rear ++] = data;

    return 0;
}

int DeQue(IntQueue *Que,int *data){
    if(Que->num <=0) return -1;
    Que->num --;
    *data = Que->que[Que->front++];
    if(Que->front == Que->max) Que->front = 0;
    return 0;
}

int Peek(IntQueue *Que,int *data){
    if(Que->num <= 0 ) return -1;
    *data = Que->que[Que->front];
    return 0;
}

void Clear(IntQueue *Que){
    Que->num = Que->front = Que->rear = 0;
}

int Capacity(IntQueue *Que){
    return Que->max;
}

int Size(IntQueue *Que){
    return Que->num;
}

int IsEmpty(IntQueue *Que){
    return Que->num <=0;
}

int IsFull(IntQueue *Que){
    return Que->num >= Que->max;
}

int Search(IntQueue *Que,int data){
    int idx;
    for(int i=0;i<Que->num;i++){
        if(Que->que[idx = (i + Que->front)%Que->max] == data) return idx;
    }
    return - 1;
}

void Print(IntQueue *Que){
    for(int i=0;i<Que->num;i++) printf("%d ",Que->que[(i + Que->front)%Que->max]);
}

void Terminate(IntQueue *Que);

int main() {

}	
