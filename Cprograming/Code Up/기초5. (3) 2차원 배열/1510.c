#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int num,val = 1;
    int dnum[51][51]={0};
    scanf("%d",&num);
    dnum[1][num/2+1]=val; val ++;
    // printf("%d")
    //for(int i=0;i<cnt;i++)
    int idx_i=1,idx_j=num/2+1;
    while(1){
        if(val > num*num) break;
        //행을 감소, 열을 증가하면서 순차적으로 수를 넣어간다.
        if((val-1)%num!=0){
            idx_i = (idx_i-1)<1?num:(idx_i-1);
            idx_j = idx_j+1>num?1:(idx_j+1);//넣은 수가 n의 배수이면 행만 증가한다. 열은 변화없음.
        }

        if((val-1)%num==0)idx_i = idx_i+1>num?1:idx_i+1;
        dnum[idx_i][idx_j] = val; //printf(">>dnum[%d][%d] = %d\n",idx_i,idx_j,val);
        val ++;

    }

    for(int i=1;i<=num;i++){
        for(int j=1;j<=num;j++)printf("%d ",dnum[i][j]);
        printf("\n"); 
    }
    
    

    
} 
/*
 행을 감소, 열을 증가하면서 순차적으로 수를 넣어간다.
 넣은 수가 n의 배수이면 행만 증가한다. 열은 변화없음.
- 열 + j
8 1 6   - 
3 5 7  행 i
4 9 2   +

- 열 +
8 1 6 -
3 5 7 행
4 9 2 +


크기가 5인 마방진
행을 감소, 열을 증가하면서 순차적으로 수를 넣어간다.

-  열  +
15 17 1 8 0   -
16 5 7 0 14
4 6 0 13 20  행
10 12 0 19 3
11 0 18 2 9  +
*/