#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){//메인함수

    int N;
    float num,max;//실수형 변수, 총합 결과값 초기화 및 정의
    float *score = NULL;//포인터 선언 및 초기화

    scanf("%d",&N);//입력받음

    score = (float*)malloc(N*sizeof(N));//동적할당
    if(score == NULL){//에러 발생시 종료 코드
        printf("error");
        return -1;//종료
    }

    for(int i=0;i<N;i++){//N번 반복
        scanf("%f",(score+i));//실수를 입력받고
        if(i==0)max = *(score+i);//첫번째 반복시 최대값 초기화
        else{//두번째 반복부터 최대값 비교
            if(*(score+i)> max) max = *(score+i);//조건 만족시 최댓값 업데이트
        } 
    }
    printf("%.2f",max);//결과 출력

    free(score);//해제


}