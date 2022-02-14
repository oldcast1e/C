#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int max; //큐의 용량
    int num; //현재 데이터 개수

    int front; //프런트
    int rear; //리어
    int *que; // 배열 포인터 == 큐의 맨 앞 요소에 대한 포인터
} IntQueue;

int Initialize(IntQueue *Que,int max){
    Que->num = Que->front = Que->rear = 0;
    //큐의 변수 초기화
    /**
    현재 데이터 개수, 프런트, 리어를 모두 0으로 저장
    대입은 <- 순으로 0 저장됨.
     */
    Que->que = (int*) malloc(sizeof(int)*max);
    //큐에 사용할 배열을 동적할당: 인자로 받은 큐의 용량만큼 동적할당
    if(Que->que == NULL){
        //동적할당 실패 시 용량 0 초기화 및 종료
        Que->max = 0;
        return - 1;
    }
    //동적할당 성공 시
    Que-> max = max;
    //큐의 '공식' 용량을 업데이트
    return 0;
}

int EnQue(IntQueue *Que,int data){
    if(Que->num >= Que->max) return -1;
    /**
    큐의 현재 데이터 개수가 큐의 최대 용량보다 큰 경우 -1 반환 후 종료
    >> 현재 데이터 개수가 최대 용량보다 크거나 작으면 더 이상 데이터 추가할 수 없음.
     */
    Que ->num ++;
    //큐의 현재 데이터 개수 증가
    Que->que[Que->rear ++] = data;
    /**
    큐가 가리키는 현재 인덱스에 데이터를 추가하고 
    rear(후미 인덱스) 값을 증가한다.
     */

    return 0;
}

int DeQue(IntQueue *Que,int *data){
    if(Que->num <=0) return -1;
    /**
    큐의 현재 데이터 개수가 0과 같거나 작으면 -1 반환 후 종료
    >> 현재 데이터 개수가 없으면 데이터를 디큐 할 수 없음
     */
    Que->num --;
    //현재 데이터 개수를 1 감소
    *data = Que->que[Que->front++];
    //인자로 받은 data에 현재 인덱스의 값을 저장하고 front를 증가 == 현재 인덱스 데이터를 빼냈기 때문
    
    if(Que->front == Que->max) Que->front = 0;
    /**
    만약 큐의 front가 큐의 최대 용량보다 같은 경우
    >>예를 들어 최대 용량이 10(0~9)인 큐에서 디큐를 9인덱스에서 하게되면 인덱스가 10으로 초과한다.
      따라서 front값을 맞춰주기 위해 이 조건문을 사용한다.
     */
    return 0;
}

int Peek(IntQueue *Que,int *data){
    if(Que->num <= 0 ) return -1;
    /**
    큐의 현재 데이터 개수가 0과 같거나 작으면 -1 반환 후 종료
    >> 현재 데이터 개수가 없으면 데이터를 피크 할 수 없음
     */
    *data = Que->que[Que->front];
    //맨 앞의 데이터 == 디큐에서 꺼낼 데이터를 저장
    return 0;
}

void Clear(IntQueue *Que){Que->num = Que->front = Que->rear = 0;}
//모든 큐의 인덱스를 초기화하여 접근을 제거

int Capacity(IntQueue *Que){return Que->max;}
//큐의 최대 용량 반환

int Size(IntQueue *Que){return Que->num;}
//큐의 현재 데이터 개수 반환

int IsEmpty(IntQueue *Que){return Que->num <=0;}
/**
큐가 비어있는지 확인
>> 큐의 현재 데이터의 개수가 0보다 작으면 1
 */

int IsFull(IntQueue *Que){return Que->num >= Que->max;}
/**
큐의 저장공간이 가득 찼는지 비교
>> 큐의 현재 데이터의 개수가 최대 용량보다 크면 1반환 아니면 0
 */

int Search(IntQueue *Que,int data){
    int idx;
    for(int i=0;i<Que->num;i++){//현재 데이터 개수 만큼 반복
        if(Que->que[idx = (i + Que->front)%Que->max] == data) return idx;
        /**
        큐가 가리키는 배열의 인덱스를 증가하면 인자로 받은 값과 확인.
        (i + Que->front)%Que와 같이 나머지 연산을 사용하는 이유는 front가 0~9일 수 있지만
        3~9~2일 수 도 있기 때문!

        이때 값을 찾은 인덱스를 반환
         */
    }
    return - 1;
}

void Print(IntQueue *Que){
    for(int i=0;i<Que->num;i++) printf("%d ",Que->que[(i + Que->front)%Que->max]);
    // Search와 같은 로직으로 모든 데이터 출력
}

void Terminate(IntQueue *Que){
    if(Que->que != NULL) free(Que->que);//큐의 배열이 할당되있으면(메모리 공간이 차있으면) 메모리 공간 해제
    Que->max = Que->num = Que->front = Que->rear = 0;
    //큐의 매개변수를 초기화
}

int main() {

}	
