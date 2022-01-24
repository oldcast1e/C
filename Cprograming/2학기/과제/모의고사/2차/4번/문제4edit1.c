#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct student{
    /* data */
    int id;
    int score_1;
    int score_2;

    double sum;
};

struct passing{
    /* data */
    int id;
    int score_1;
    int score_2;
};


int main(){
    int N,cnt,passing_cnt;
    double avg = 0;
    scanf("%d",&N);
    //학번, 1차 인증 점수, 2차 인증 점수를 입력할 수 있는 구조체 N개를 동적으로 할당받아
    struct student *sys = NULL;
    sys = (struct student *)malloc(sizeof(struct student)*N);

    struct passing *person = NULL;
    person = (struct passing *)malloc(sizeof(struct passing)*N);

    for(int i=0;i<N;i++) {
        scanf("%d %d %d",&sys[i].id,&sys[i].score_1,&sys[i].score_2);
        sys[i].sum = (double)sys[i].score_1*0.4 + (double)sys[i].score_2*0.6;
        avg += sys[i].sum;
    }avg /= N;
    
    //조건 1 전체 학생의 60%를 인증통과자 로 선발 한다. 
    int n=0;passing_cnt = 0;cnt=0;
    while(N*0.6 > cnt){
        if(sys[n].sum > avg){
            // printf("cnt %d ",cnt);
            person[cnt].id = sys[n].id;
            person[cnt].score_1 = sys[n].score_1;
            person[cnt].score_2 = sys[n].score_2;

            printf("%d\n",sys[n].id);
            cnt++;
        }
        n++;
    }
    passing_cnt = cnt; n=0;
    while(N*0.8 > cnt){
        if(sys[n].sum < avg){
            
        }
        n++;
        //2차 인증 점수 우수자를 선발하되 
        //전체 인증 통과자가 총 학 생 수의 80%가 되도록 선발
    }

}
/*
인증 통과 규칙은 다음과 같다.
- 조건 1: 1차 인증 점수 40%, 
        2차 인증 점수 60%의 합산으로 전체 학생의 60%를 인증통과자 로 선발 한다. 
        
        예를 들어, N이 7인 경우 7명의 60% 인 4명을 선발 한다.

- 조건 2: 이후 탈락된 학생 중, 
        2차 인증 점수 우수자를 선발하되 전체 인증 통과자가 총 학 생 수의 80%가 되도록 선발 한다. 
        
        예를 들어, N이 7인 경우 총 선발 인원이 7명의 80%인 5 명이 되게 한다. 
        즉, 조건 1에 의한 선발 이후, 1명을 추가 선발 한다.
10
12345 15 86
12346 52 68
12347 55 90
12348 32 88
12349 22 12
12350 65 9
12351 1 100
12352 2 10
12353 50 90
12354 90 100

->
12345
12346
12347
12348
12351
12353

6
12345 80 100 
12121 80 100 
12358 80 100 
12364 80 100 
13548 80 100 
13154 80 100
*/