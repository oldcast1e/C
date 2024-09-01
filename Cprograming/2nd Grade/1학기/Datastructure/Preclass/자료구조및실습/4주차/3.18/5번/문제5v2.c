#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,m,cnt=1; 
    scanf("%d %d",&n,&m);

    /*이중동적*/
    int dnum[100][100]={0};

    int cross = 1;
    for(int i=0;i<n;i++){
        // printf("cross = %d\n",cross);
        for(int j=0;j<cross;j++){
            // printf("[%d][%d] ",j,cross-j-1);
            dnum[j][cross-j-1] = cnt; cnt++;
            // printf("%d ",dnum[j][cross-j-1] );
        }
        cross++;
       // printf("\n");
    }cross--;
    int tmp = cross,big=0;
    /*n < m 일때만 성립*/
    if(n==m)cross --;
    // else if(n>m) {cross ++;}
    // for(int i=0;i<n;i++){//0,4 1,3 2,2 3,1
    //    for(int j = cross ;j>= 1; j-- ){
    //         printf("[%d][%d] ",tmp-j,j+i);
    //         dnum[tmp-j][j+i] = cnt; cnt++;
    //     }
    //     cross--;
    //     printf("cross = %d\n",cross);
    // }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)printf("%d ",dnum[i][j]);
        printf("\n"); cnt++;
    }
    
    

    
} 
/*
0,4 1,3 2,2 3,1

1  2  4  7 
3  5  8      12 
6  9      13 19 
10     14 20 25 
    15 21 26 30 

1   2  4  7 
3   5  8     12 
6   9     13 17 
10     14 18 21 
    15 19 22 24 


 1  2  4  7 
 3  5  8     12 
 6  9     13 17 
10     14 18 21 
    15 19 22 24 

[1][4] [2][3] [3][2] [4][1] 
[2][4] [3][3] [4][2] 
[3][4] [4][3] 
[4][4] 

1  2  4  7 
3  5  8     12 
6  9     13  0 
10     14 0  0 
    15  0 0  0 
*/