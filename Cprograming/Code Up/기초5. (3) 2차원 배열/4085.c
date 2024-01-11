#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,m,x,y,cnt=0;
    int dnum[100][100];
    scanf("%d %d %d %d",&m,&n,&x,&y);
    // scanf("%s",arr);
    // for(int i=0;i<(int)strlen(arr);i++)
    //for(int i=0;i<cnt;i++)
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)scanf("%d",&dnum[i][j]);
    
    for(int i=n-1;i>=0;i--) {//세로: 위방향
        for(int j=m-1;j>=0;j--){//가로: 역방향 <-
        cnt = 0;
            for(int row=0;row<y;row++){
                if(i-row < 0) continue;
                cnt += dnum[i-row][j];
            }dnum[i][j] = cnt;
        }
    }

     for(int i=n-1;i>=0;i--) {//세로: 위방향
        for(int j=m-1;j>=0;j--){//가로: 역방향 <-
        cnt = 0;
            for(int cro=0;cro<x;cro++){
                if(i-cro < 0) continue;
                cnt += dnum[i][j-cro];
            }dnum[i][j] = cnt;
        }
    }
    int max = -1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            // printf("%d ",dnum[i][j]);
            if(dnum[i][j] > max) max = dnum[i][j];
        // }printf("\n");
    }
    }
    printf("%d",max);
} 
/*
10 3 2 2
10 15 11 24 55 21 10 19 14 10
10 12 19 19 44 39 24 15 14 11
10 77 66 50 50 50 40 35 25 15

10 15 11 24 55 21 10 19 14 10 
20 27 30 43 99 60 34 34 28 21 
20 89 85 69 94 89 64 50 39 26 

10 15 11 24 55 21 10 19 14 10 
20 47 57 73 142 159 94 68 62 49 
20 109 174 154 163 183 153 114 89 65 


------------------

10 4 3 3
10 15 11 24 55 21 10 19 14 10
10 12 19 19 44 39 24 15 14 11
10 77 66 50 50 50 40 35 25 15
10 11 12 13 14 15 16 17 18 19

---------------------------

10 15 11 24 55 21 10 19 14 10 
20 27 30 43 99 60 34 34 28 21 
30 104 96 93 149 110 74 69 53 36 
30 100 97 82 108 104 80 67 57 45 

---------------
10 15 11 24 55 21 10 19 14 10 
20 47 57 73 142 159 94 68 62 49 
30 134 230 293 338 352 333 253 196 158 
30 130 227 279 287 294 292 251 204 169 
*/