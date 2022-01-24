#include  <stdio.h>
#include  <string.h>
//#include  <stdlib.h>

struct struct_bank{
    int id; // 아이디, T1, T2, T3 대신, 1, 2, 3, ... 으로 한다. 
    int arrival_time; // 도착시간
    int service_time; // 서비스시간
    int waiting_time; // 대기시간
}guest[100];

typedef struct struct_bank sb;//재정의

int main(){//메인함수
    int N;//정수형 변수 정의
    double rst=0;//결과값 저으이
    scanf("%d",&N);//정수형 변수 입력받음

    for(int i=0;i<N;i++){//N번 반복
        guest[i].waiting_time = 0;//대기시간 초기화
        scanf("%d %d %d",&guest[i].id, &guest[i].arrival_time, &guest[i].service_time);
        //아이디, 도착시간, 서비스 시간 입력받음
    }
    for(int i=0;i<N;i++){//N번 반복
        if(i!=0){//두번째 손님부터
            for(int j=0;j<i;j++){//이전 서비스 시간 더하기
                guest[i].waiting_time += guest[j].service_time;
            }
                guest[i].waiting_time -= guest[i].arrival_time;//도착 시간 빼기
            }
        
        // printf("wating: %d\n",guest[i].waiting_time);
    }

    for(int i=0;i<N;i++){//N번반복
        rst+= (double)guest[i].waiting_time;//합 구하기
    }
    printf("%.2lf",rst/N);//평균출력



}

/*
4 
1 0 7
2 2 4
3 4 1
4 5 4

*/