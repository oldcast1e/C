#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int size,n,m,cnt=0,num=1;
    int dnum[100][100]={};
    //fgets(arr, 101, stdin);
    scanf("%d",&size);
    scanf("%d %d",&n,&m);
    dnum[n-1][m-1] = num; num ++;

    
    for(int i=n-2;i>=0;i--){dnum[i][m-1] = num; num++;} num = 2;
    for(int i=n;i<size;i++){dnum[i][m-1] = num; num++;}  num = 2;

    for(int i=0;i<size;i++){
        int start = dnum[i][m-1] + 1,cnt=start;
        for(int j=m-2;j>=0;j--){dnum[i][j] = cnt; cnt++;} cnt=start;
        for(int j=m;j<size;j++){dnum[i][j] = cnt; cnt++;} cnt=start;
    }

    
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++)printf("%d ",dnum[i][j]);
        printf("\n"); cnt++;
    }
    

    
} 
/*
여러분들은 배열크기 N과 시작위치 X , Y를 입력받아 숫자등고선을 만드시오.
예를 들어 배열크기가 5이고 시작위치가 3 , 4 라면 3,4로 시작하는 다음과같은 숫자등고선을 만들수 있다.
     [4]
0 0 0 3 0
0 0 3 2 3
0 3 2 1 2  [3]
0 0 3 2 3
0 0 0 3 0

5 4 3 2 1
6 0 0 0 2
7 0 0 0 0  [3]
8 0 0 0 0
9 0 0 0 0
*/