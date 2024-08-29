#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
[ 문제 3 ] 누적 평균
원시 데이터값들로 구성된 배열 X의 i-번째 
    누적평균(prefix average)이란 X의 i-번째에
    이르기까지의 (i + 1)개 원소들의 평균이다. 
즉, A[i] = (X[0] + X[1] + ... + X[i])/(i + 1)
    누적평균은 경제, 통계 분야에서 오르내림 변동을 순화시킴으로써 
    대략적 추세를 얻어내기 위해 사용된다. 
일례로 부동산, 주식, 펀드 등에도 자주 활용된다.. 

이 문제는 배열 X의 누적평균(prefix average) 
배열 A를 구하는 프로그램을 구현하고 테스트하는데 관한 것이다.

*/
/*
!!!!!!!!!!!!

3) 평균 계산 시 소수점 이하를 반올림하여 정수로 구한다. 
정확한 반올림을 위해, %.f를 쓰지 말고 int 성질을 이용해서 반올림하라.
*/
int* prefixAverages1(int num[],int n){
    int *rst = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        rst[i] = 0;
        for(int j=0;j<=i;j++){
            rst[i] += num[j];
        }
    ///소수점 이하 반올림
    rst[i] = (int)(rst[i] / (i+1) + 0.5);
    }
    /*
    A[i] = (X[0] + X[1] + ... + X[i])/(i + 1)
    */
   return rst;
}

int* prefixAverages2(int num[],int n){
    int *rst = (int *)malloc(sizeof(int)*n);
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += num[i];
        rst[i] = (int)(sum/(i+1)+0.5);
    }
   return rst;
}
int main(){

    int n; scanf("%d",&n);
    int *num = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)scanf("%d",&num[i]);

    int *rst1 = prefixAverages1(num,n);
    int *rst2 = prefixAverages2(num,n);
    for(int i=0;i<n;i++)printf("%d ",rst1[i]);printf("\n");
    for(int i=0;i<n;i++)printf("%d ",rst2[i]);
} 
/*
3
5 1 9

>>5 3 5

6
1 3 2 10 6 8
*/