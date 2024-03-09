#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,m; scanf("%d %d",&n,&m);
    int cnt = 1,dir=0;//dir 순방향 0 : 오른쪽/아래쪽 1: 왼쪽 윗쪽
    int dnum[100][100];
    // int **dnum = (int**)malloc(sizeof(int*)*n+1);
    // for(int i=0;i<m;i++) dnum[i] = (int*)malloc(sizeof(int)*m+1);

    // 달팽이 배열
    int left=0,right=m-1,up=0,down=n-1;
    while(n*m >= cnt){
        if(dir%2 == 0){
            for(int i=left;i<=right;i++){dnum[up][i] = cnt; cnt ++;}
            up ++;
            for(int j=up;j<=down;j++){dnum[j][right] = cnt; cnt ++;}
            right --;
            dir ++;
        }
        else{
            for(int i=right;i>=left;i--){dnum[down][i] = cnt; cnt ++;  }
            down --;
            for(int j=down;j>=up;j--){dnum[j][left] = cnt; cnt ++; }
            left ++;;
            dir ++;
        }
    }
    // 출력문 삭제하지 말기
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)printf(" %d",dnum[i][j]);
        printf("\n"); cnt++;
    }
    
} 
/*
4

*/