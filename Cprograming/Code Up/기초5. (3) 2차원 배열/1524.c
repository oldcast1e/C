#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    int dnum[10][10];
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++)scanf("%d",&dnum[i][j]);
        // printf("\n"); cnt++;
    }
    scanf("%d %d",&a,&b);

    // printf("--------------------------------\n"); 
    // for(int i=1;i<=9;i++){
    //         for(int j=1;j<=9;j++)printf("%d ",dnum[i][j]);
    //         printf("\n"); 
    //     }
    
    if(dnum[a][b] == 1){printf("-1");}
    else{
        
        for(int i=a-1;i<=a+1;i++){
            if(i<=0 || i>=10)continue;
            else{
                for(int j=b-1;j<=b+1;j++){
                    if(j<=0 || j>=10)continue;
                    else{
                        cnt = dnum[i][j]>0?(cnt+1):cnt;
                        printf("dnum[%d][%d] = %d | cnt = %d\n",i,j,dnum[i][j],cnt);
                    }
                }
            }
        }
        printf("%d",cnt);
    }
    
    
} 
/*
1 0 1 0 0 0 0 0 0 
1 0 0 0 1 0 0 0 0 
1 0 0 0 1 0 0 1 0 
1 0 1 1 1 0 0 0 0 
1 0 1 0 1 0 0 0 0 
1 0 1 1 1 0 0 1 0 
1 0 0 0 1 0 0 0 0 
1 0 0 0 1 0 0 1 0 
1 0 0 0 1 0 0 0 0 
5 4

그 칸 주변의 8방향의 칸에 지뢰가 있는 개수를 화면에 표시해준다.
만약 지뢰가 있는 칸을 선택한 경우 -1을 출력하고, 지뢰가 없으면 0을 출력한다.

예를 들어 (2, 3)의 좌표를 클릭하는 경우 주변의 지뢰가 3개 있으므로 3을 출력한다.( (1,2), (1,3), (2,2) )


0 1 1 0 0 0 0 0 0
1 1 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0
0 0 0 1 1 0 1 0 1
0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0
1 0 1 0 0 0 1 1 0
2 3
*/