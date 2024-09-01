#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int mostOnes(int **dn, int n){
    int i=0,j=0,rst;
    while(n-1 >= i){
        //요솟값이 1이면 해당 행 인덱스를 저장 -> 1이 제일 많이 나오는 행 찾기
        if(dn[i][j] == 1) {
            if((n - 1) == j ) return i;
            rst =i;j++;
        }//다음 열을 확인해야함
        else{
            i ++;// 0이 나왔으므로 다음 행을 검사해야함.
        }
    }
    return rst;
    // int row = 0, jmax = 0;
    // while ((j < n) && (dn[i, j] = 1))
}
/*
Alg mostOnes(A, n) {slow version} input bit matrix A[n × n]
output the row of A with most 1’s
>1. row, jmax ← 0
>2. for i ← 0 to n – 1
>j←0
while ((j < n) & (A[i, j] = 1))
j←j+1 if (j > jmax)
row ← i
jmax ← j
3. return row
*/
int main(){
    int n; scanf("%d",&n);
    int **dn = (int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++) dn[i] = (int*)malloc(sizeof(int)*n);
    
    for(int i=0;i<n;i++)for(int j=0;j<n;j++) {scanf("%d",&dn[i][j]);} 

    int rst = mostOnes(dn,n);
    printf("%d",rst);
    
} 
/*
8
1 1 1 1 0 0 0 0
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 0 0 0
*/
/*
[ 문제 2 ] 비트행렬에서 최대 1행 찾기
n × n 비트 행렬 A의 각 행은 1과 0으로만 구성되며, A의 어느 행에서나 1들은 해당 행의 0들보다 앞서 나온다고 가정하자. 
행렬 A를 입력받아, 가장 많은 1을 포함하는 행을 찾는 프로그램을 작성하시오. 

그러한 행이 여러 개 있을 경우 
그 가운데 가장 작은 행 번호를 찾아야

8
1 1 1 1 0 0 0 0
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 0 0 0

1->1->1->1->0  0  0  0
1  1  1  1  1->0  0  0
1  0  0  0  0  0  0  0
1  1  1  1  1  1  0  0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 0 0 0
*/