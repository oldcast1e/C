#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int *prefixAverages1(int x[],int n){
    int *rst = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++) rst[i] += x[j];
        rst[i] /= (i+1);
    }
    return rst;
    //A[i] = (X[0] + X[1] + ... + X[i])/(i + 1)
}
int *prefixAverages2(int x[],int n){
    /*
    이를 수정하여 이전의 i – 1번째까지의 합을 보관하여 
    다음 반복으로 전달하는 방식으로 반복한다면 
    현재 합을 구하는데 필요한 시간을 단축할 수 있다
    */
    int *rst = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        rst[i] += x[j];
        prefixAverages2(x,rst[i]);
    }
    return rst;
    //A[i] = (X[0] + X[1] + ... + X[i])/(i + 1)
}
int main(){
    int n,*x; scanf("%d",&n);
    x = (int*)malloc(sizeof(int)*n);

    int *rst1 = (int*)malloc(sizeof(int)*n);
    int *rst2 = (int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++)scanf("%d",&x[i]);

    rst1 = prefixAverages1(x,n);
    rst2 = prefixAverages1(x,n);
    for(int i=0;i<n;i++)printf("%d ",rst1[i]);

    
    
} 
/*
원시 데이터값들로 구성된 배열 X의 i-번째 누적평균(prefix average)이란 
X의 i-번째에 이르기까지의 (i + 1)개 원소들의 평균이다. 
즉, A[i] = (X[0] + X[1] + ... + X[i])/(i + 1)

3
5 1 9

6 
1 3 2 10 6 8
*/