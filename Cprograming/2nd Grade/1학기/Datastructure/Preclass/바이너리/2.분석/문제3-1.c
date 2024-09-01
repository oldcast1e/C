#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/**
원시 데이터값들로 구성된 배열 X의 i-번째 누적평균(prefix average)이란 
X의 i-번째에 이르기까지의 (i + 1)개 원소들의 평균이다. 
즉, A[i] = (X[0] + X[1] + ... + X[i])/(i + 1)

누적평균은 경제, 통계 분야에서 오르내림 변동을 순화시킴으로써 대략적 추세를 얻어내기 위해 사용된다. 
일례로 부동산, 주식, 펀드 등에도 자주 활용된다.

이 문제는 배열 X의 누적평균(prefix average) 배열 A를 구하는 프로그램을 구현하고 테스트하는데 관한 것이다.
 */
int *prefixAverages1(int *X,int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += X[i];
        X[i] = sum/(i+1);
    }
    return X;
}

int main(){
    int N;scanf("%d",&N);
    int *num = (int *)malloc(sizeof(int)*N);
    int *X = (int *)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++)scanf("%d",&num[i]);
    X =  prefixAverages1(num,N);


}