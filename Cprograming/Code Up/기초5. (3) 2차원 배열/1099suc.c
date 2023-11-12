#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int dir=0,y_cnt=2;//dir 0이면 가로 1이면 세로
    int dnum[11][11];
    for(int i=1;i<=10;i++)
        for(int j=1;j<=10;j++) scanf("%d",&dnum[i][j]);
    
    for(int i=2;i<=9;i++){
        if(dir==0){
            for(int j=y_cnt;j<=10;j++){
                if(dnum[i][j]==2){dnum[i][j] = 9;i=10; break;}//먹이를 찾음
                if(dnum[i][j]==0)dnum[i][j] = 9;
                else if(dnum[i][j]==1){
                    dir = 1; y_cnt = j-1;
                    break;
                }
            }
        }
        if(dir==1)dir = 0;
    }
    for(int i=1;i<=10;i++){
        for(int j=1;j<=10;j++) printf("%d ",dnum[i][j]);
        printf("\n");}
    
} 