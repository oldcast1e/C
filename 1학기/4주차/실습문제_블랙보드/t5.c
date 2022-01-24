//5-2
#include<stdio.h>
int main(){

    int N,M;
    scanf("%d %d",&N,&M);//N,M을 선언하고 값을 입력받는다.
    if(N>M){//N이M보다 큰 경우
        if(M*M == N)//M의 제곱이 N일때
            printf("%d*%d=%d",M,M,N);//제곱관계출력
    
        else //아닌경우
            printf("none");//출력
    }
    else
        if(N*N == M)//N이 M보다 작거나 큰 경우
            printf("%d*%d=%d",N,N,M);//제곱관계출력
        else    
            printf("none");//아닌경우 none 출력
            //제곱관계가 정해지지 않았으므로 임의로 2개로 분리
}    