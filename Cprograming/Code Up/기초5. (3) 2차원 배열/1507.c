#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int x1,y1, x2,y2,cnt=0,min=0,sum=0;
    int dnum[101][101]={0};
    for(int i=0;i<4;i++){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if(x1 > x2){cnt = x1; x1=x2;x2=cnt;}
        if(y1 > y2){cnt = y1; y1=y2;y2=cnt;}

        for(int j=y1;j<=y2;j++){
            for(int k=x1;k<=x2;k++){
                // printf("[%d][%d]\n",j,k);
                dnum[j][k] += 1;
            }
        }
        sum += (x2-x1)*(y2-y1);

    }

    for(int i=10;i>=0;i--){
        cnt = 0;
        for(int j=0;j<10;j++)if(dnum[i][j]>1)cnt++;
        min += (cnt - 1);
    }
    for(int i=10;i>=0;i--){
        for(int j=0;j<10;j++)printf("%d ", dnum[i][j]);
        printf("\n");
    }

    printf("sum =%d | min = %d",sum,min);

    
} 
/*
1 2 3 4 
2 3 5 7 
3 1 6 5 
7 3 8 6 
*/