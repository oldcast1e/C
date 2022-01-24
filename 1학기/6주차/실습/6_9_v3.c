#include<stdio.h>
int main(){

    int N,i=0,j;//정수형 변수 3개 선언
    int cnt = 0;//줄 띄움 변수 선언
    scanf("%d",&N);//정수를 입력 받음

    while(i<N){//i값에 따른 반복문 

        for(j=i+1;j<=N;j++){//j=i+1부터 j<=N일때 까지 j를 증가
            printf("%d ",j%10);//j%10인 이유는 10이 0이되야하기 때문
        }
        for(j=N+1;j<N+i+1;j++){//숫자가 왼쪽으로 이동하는 출력이므로
            printf("%d ",j%10);//다음 숫자는 N+1이되야함
        }
        cnt +=1;//줄 띄움 카운트
        if(cnt!=N)//마지막 줄의 공백을 없게함
            printf("\n");
        i++;//반복 순서 결정 코드
    }

    
}
