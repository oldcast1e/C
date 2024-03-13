#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
필요 함수:
◦ mostOnes(A, n) 함수
- 인자: 비트 행렬 A, 정수 n ≤ 100 (A의 크기) - 반환값: 정수 (최대 1 행 번호)
- 시간 성능: O(n)
*/
int mostOnes(int **A, int n){
    int i=0,j=0,rst=0;
    while(n-1 >= i){//행이 끝나기 전까지 반복
        if((n - 1) == j ) return i;//열이 끝나면 더이상 확인 불필요

        if(A[i][j]==1){//1을 만나면 다음 요솟값이 1인지 확인 : 열 증가
            rst = i; // 행을 저장
            j++;//열을 증가
        }
        else if(A[i][j]==0){//행을 검사할때 0이면 열을 넘어간다.
            i++;
        }
    }
    return rst;
}
int main(){
    int n; scanf("%d",&n);
    
    int **dnum = (int **)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++) dnum[i] = (int *)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)scanf("%d",&dnum[i][j]);
    
    int rst = mostOnes(dnum,n);
    printf("%d",rst);
    
} 
/*
8
1 1 1 1 0 0 0 0
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 0 0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 0 0 0


8
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0

8
1 1 1 0 1 1 1 0
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
*/