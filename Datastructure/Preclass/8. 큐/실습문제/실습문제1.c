#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/**
배열로 구성된 원형 큐를 위한 삽입, 삭제 프로그램을 작성하시오.
- front, rear, 배열의 초기 값은 0
- 삽입 시 rear 값을 하나 증가시킨 후 데이터를 큐에 삽입 (출력 예시 1 참고)
- 삭제 시 front 값을 하나 증가시킨 후 front가 가리키는 데이터를 삭제
- front = rear면 공백 상태로 정의하고, front가 rear보다 하나 앞에 있으면 포화 상태로 정의함

1) 첫 번째 라인 : 양의 정수 q (원형 큐의 크기)
※ q 값에는 제한이 없다. 또한, 동적 할당을 사용할 것. 
2) 두 번째 라인 : 양의 정수 n (연산의 개수)
3) 세 번째 이후 라인: n개의 연산이 차례로 입력됨. 
*/
typedef struct{
    int max; //큐의 용량
    int num; //현재 데이터 개수

    int front; //프런트
    int rear; //리어
    int *que; // 배열 포인터 == 큐의 맨 앞 요소에 대한 포인터
} IntQueue;

int Initialize(IntQueue *Que,int max);
int EnQue(IntQueue *Que,int data);
int DeQue(IntQueue *Que);
int Peek(IntQueue *Que,int *data);
void Clear(IntQueue *Que);
int Capacity(IntQueue *Que);
int Size(IntQueue *Que);
int IsEmpty(IntQueue *Que);
int IsFull(IntQueue *Que);
int Search(IntQueue *Que,int data);
void Print(IntQueue *Que);
void Terminate(IntQueue *Que);

int main() {
    int size,rep,data;scanf("%d",&size);
    char cal,tmp;
    IntQueue queue;
     if(Initialize(&queue,size) == -1) {puts("큐 생성 실패");return 1;}
    // (queue->que) = (int*)malloc(sizeof(int)*size);
    scanf("%d",&rep);getchar();
    /**
    ※ 연산의 종류는 I (삽입), D (삭제), P (출력)
    - I 10 : 원형 큐에 원소 10을 삽입 (큐 원소는 양의 정수).
    -  D : 원형 큐에서 원소를 삭제한 후 해당 배열 원소 값을 0으로 치환.
    -  P : 배열 원소 전체를 차례로 화면에 출력 (입출력 예시 참조).
     */
    for(int i=0;i<rep;i++){
        scanf("%c%c",&cal,&tmp);
        if(cal == 'I'){
            scanf("%d",&data);getchar();
            EnQue(&queue,data);
            // printf("I:data= %d\n",data);
        }
        else if(cal == 'P'){
            // printf(">>P");
            Print(&queue);
        }
        else if(cal == 'D'){
            // printf(">>D");
            DeQue(&queue);
        }
    }
}

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

    for(int i=0;i<max;i++)Que->que[i] = 0;
    //동적할당 성공 시
    Que-> max = max;
    //큐의 '공식' 용량을 업데이트
    return 0;
}

int EnQue(IntQueue *Que,int data){
    if(Que->num >= Que->max) return -1;
    else{
        if(IsFull(Que)==1){
            printf("overflow");
            Print(Que);
            exit(1);
        }
        // 삽입 시 rear 값을 하나 증가시킨 후 데이터를 큐에 삽입 (출력 예시 1 참고)
        Que ->num ++;
        //큐의 현재 데이터 개수 증가
        Que->que[Que->rear ++] = data;
        if(Que->rear == Que ->max) Que->rear = 0;
        /**
        큐가 가리키는 현재 인덱스에 데이터를 추가하고 
        rear(후미 인덱스) 값을 증가한다.
        */
    }
    return 0;
}

int DeQue(IntQueue *Que){
    // if(Que->num <=0) return -1;
    if(IsEmpty(Que)==1){
        printf("underflow");
        exit(1);
    }
    // 삭제 시 front 값을 하나 증가시킨 후 front가 가리키는 데이터를 삭제
    Que->num --;
    //현재 데이터 개수를 1 감소
    Que->que[++Que->front] = 0;

    
    if(Que->front == Que->max) Que->front = 0;
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
    for(int i=0;i<Que->max;i++) printf(" %d",Que->que[(i + Que->front)%Que->max]);
    printf("\n");
    // Search와 같은 로직으로 모든 데이터 출력
}

void Terminate(IntQueue *Que){
    if(Que->que != NULL) free(Que->que);//큐의 배열이 할당되있으면(메모리 공간이 차있으면) 메모리 공간 해제
    Que->max = Que->num = Que->front = Que->rear = 0;
    //큐의 매개변수를 초기화
}