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

int EnQue_rear(IntQueue *Que,int data){//Basic
    if(Que->num >= Que->max) return -1;
    else{
        /**
        큐의 현재 데이터 개수가 큐의 최대 용량보다 큰 경우 -1 반환 후 종료
        >> 현재 데이터 개수가 최대 용량보다 크거나 작으면 더 이상 데이터 추가할 수 없음.
        */
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

int EnQue_front(IntQueue *Que,int data){
    if(Que->num >= Que->max) return -1;
    else{
        /**
        큐의 현재 데이터 개수가 큐의 최대 용량보다 큰 경우 -1 반환 후 종료
        >> 현재 데이터 개수가 최대 용량보다 크거나 작으면 더 이상 데이터 추가할 수 없음.
        */
        Que ->num ++;
        //큐의 현재 데이터 개수 증가
        Que->front = (Que->front -1 + Que->max) % Que->max;
        printf("\n<<<<<<<< Que->front = %d>>>>>>>>\n",Que->front);
        Que->que[Que->front] = data;
    }
    return 0;
}

int DeQue_front(IntQueue *Que,int *data){//Basic
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

int DeQue_rear(IntQueue *Que,int *data){
    if(Que->num <=0) return -1;
    Que->num --;
    //현재 데이터 개수를 1 감소
    //Que->front = (Que->front -1 + Que->max) % Que->max;
    
    if((Que->rear-1) < 0) Que->rear = (Que->rear -1 + Que->max) % Que->max;
    *data = Que->que[Que->rear --];
    //인자로 받은 data에 현재 인덱스의 값을 저장하고 front를 증가 == 현재 인덱스 데이터를 빼냈기 때문
    

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

int Search2(IntQueue *Que,int data){
    int idx;
    for(int i=0;i<Que->num;i++){//현재 데이터 개수 만큼 반복
        if(Que->que[idx = (i + Que->front)%Que->max] == data) return i;
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
    
    IntQueue que;
    if(Initialize(&que,64) == -1) {puts("큐 생성 실패");return 1;}

    while(1){
        int menu,x;
        printf("[현재 데이터 수: %d / %d]\n\n",Size(&que),Capacity(&que));
        printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (5)초기화\n");
        printf("(6)용량확인 (7)큐의 현재 데이터 상태 (8)큐 저장상태 (9)큐 과저장 유무 (10)검색\n");
        printf("(11)프런트 인큐 (12) 리어 디큐 (0)종료");

        printf("\n>>번호를 입력하세요: ");scanf("%d",&menu);

        if(menu == 0) break;
        switch(menu){
            case 1:
                printf("데이터: ");scanf("%d",&x);
                if(EnQue_rear(&que,x)==-1)puts("인큐에 실패하였습니다.");
                break;

            case 2:
                if(DeQue_front(&que,&x) == -1) puts("디큐에 실패하였습니다.");
                else printf("디큐 데이터는 %d입니다.\n",x);
                break;

            case 3:
                if(Peek(&que,&x)==-1)puts("피크에 실패하였습니다.");
                else printf("피크 데이터는 %d입니다.\n",x);
                break;

            case 4:
                printf("\n[");
                Print(&que);printf("]\n\n");
                break;
            case 5:
                Clear(&que);
                break;

            case 6:
                printf("큐의 용량은 %d입니다.\n",Capacity(&que));
                break;

            case 7:
                printf("큐의 현재 데이터 개수는 %d입니다.\n",Size(&que));
                break;

            case 8:
                if(IsEmpty(&que) == 1) printf("큐는 비어있습니다.\n");
                else  printf("큐의 현재 데이터가 존재합니다.\n");
                //큐의 데이터 개수가 0보다 작거나 같으면 1
                //큐의 데이터 개수가 0보다 크면 1
                break;

            case 9:
                if(IsFull(&que) == 1) printf("큐을 현재 사용할 수 없습니다(과저장).\n");
                else  printf("큐을 사용할 수 있습니다.\n");
                //큐의 데이터 개수가 큐의 최대 용량보다 많으면 1 반환
                //큐의 데이터 개수가 큐의 최대 용량보다 적으면 0 반환
                break;

            case 10:
                printf("검색할 데이터를 입력하세요: ");scanf("%d",&x);
                if(Search2(&que,x) == -1) printf("검색 실패\n");
                else{
                    printf("검색한 데이터 %d의 인덱스는 %d입니다.\n",x,Search2(&que,x));
                }
                /**
                인자로 받은 검색값과 일치하는 
                stt가 가리키는 배열의 데이터가 있을 시 해당 인덱스 반환
                */
                break;
            
            case 11:
                printf("데이터: ");scanf("%d",&x);
                if(EnQue_front(&que,x)==-1)puts("프런트 인큐에 실패하였습니다.");
                break;
            
            case 12:
                if(DeQue_rear(&que,&x) == -1) puts("리어 디큐에 실패하였습니다.");
                else printf("디큐 데이터는 %d입니다.\n",x);
                break;

            // case 1:
            //     printf("데이터: ");scanf("%d",&x);
            //     if(EnQue_front(&que,x)==-1)puts("인큐에 실패하였습니다.");
            //     break;

            // case 2:
            //     if(DeQue_front(&que,&x) == -1) puts("디큐에 실패하였습니다.");
            //     else printf("디큐 데이터는 %d입니다.\n",x);
            //     break;
        }

    }
    Terminate(&que);
    return 0;
}	
