#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){//메인함수

    int n,sum=0;//정수형 변수, 총합 결과값 초기화 및 정의
    int *score = NULL;//포인터 선언 및 초기화

    scanf("%d",&n);//입력받음
    score = (int*)malloc(n*sizeof(n));//동적할당
    if(score == NULL){//에러 발생시 종료 코드
        printf("error");
        return -1;//종료
    }

    for(int i=0;i<n;i++){//N번 반복
        scanf("%d",(score+i));//정수를 입력받고
        sum += *(score+i);//총합에 더함
    }
    printf("%d",sum);//결과 출력

    free(score);//해제


}