#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
정답

cal과 row를 사용할 것!


*/

/*
[ 문제 2 ] 비트행렬에서 최대 1행 찾기
n × n 비트 행렬 A의 각 행은 1과 0으로만 구성되며, 
A의 어느 행에서나 1들은 해당 행의 0들보다 앞서 나온다고 가정하자. 
행렬 A를 입력받아, 가장 많은 1을 포함하는 행을 찾는 프로그램을 작성하시오. 

그러한 행이 여러 개 있을 경우 그 가운데 가장 작은 행 번호를 찾아야 한다.
*/

/*
◦ mostOnes(A, n) 함수
- 인자: 비트 행렬 A, 정수 n ≤ 100 (A의 크기) 
- 반환값: 정수 (최대 1 행 번호) : 1이 가장 많은 행의 번호
- 시간 성능: O(n)
*/
int mostOnes(int num[][100],int n){
    int row=0,cal=0,idx = 0;
    for (int j = 0; j < n; j++) {//첫번째 열이 모두 0이면 검사할 필요없음
        if (num[0][j] == 0) {
            cal = j;
            break;
        }   
    }
    for (int i = row; i < n; i++){//행 확인
        for (int j = cal; j < n; j++){//열 확인
            if(num[i][j] == 1){ //1이면
                cal ++; //열 증가
                idx  = i;
            }
            else if(num[i][j] == 0){//0이면
                row++;
            }
        }
    }
    return idx;
}

int main(){
    int n; scanf("%d",&n);
    int dnum[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)scanf("%d",&dnum[i][j]);
    }

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
1 1 1 1 0 0 0 0
1 1 1 1 1 0 0 0
1 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 0
1 1 1 1 1 0 0 0

4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0

4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

4
0 0 0 0
0 0 0 0
1 1 0 0
1 1 1 0
*/