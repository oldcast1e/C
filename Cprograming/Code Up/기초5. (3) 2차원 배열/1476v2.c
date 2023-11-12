#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,val=1;
    int dnum[101][101];
    
    scanf("%d %d",&a,&b);

    int cnt_a,cnt_b=b-1,cnt=0;
    while(val<=a*b){

        if(cnt_a <= a-1){
            for(int i=0;i<=cnt_a;i++){
                dnum[cnt_a-i][i] = val;
                printf("dnum[%d][%d] = %d\n",cnt_a-i,i,val);
                val ++;
            }
            cnt_a ++;
        }
        else if(cnt_a > a-1){
            for(int i=0;i<cnt_b;i++){
                dnum[a-1-i][b-cnt_b+i] = val;
                printf("||dnum[%d][%d] = %d\n",a-1-i,b-cnt_b+i,val);
                val ++;
            }
            cnt_b --;
        
        }
        else val ++; 
        // else if(cnt_a == a-1)
/*
5 10
 1  3  6 10 15 20 29 37 44 50 
 2  5  9 14 19 28 36 43 49  0 
 4  8 13 18 27 35 42 48  0  0 
 7 12 17 26 34 41 47  0  0  0 
11 16 25 33 40 46  0  0  0  0 
------------
cnt_a: 5 | cnt_b: 4
*/
        

    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++)printf("%2d ",dnum[i][j]);
        printf("\n");
    }
    printf("------------\ncnt_a: %d | cnt_b: %d",cnt_a,cnt_b);

    
} 
/*
5 10
dnum[0][0] = 1
dnum[1][0] = 2
dnum[0][1] = 3
dnum[2][0] = 4
dnum[1][1] = 5
dnum[0][2] = 6
dnum[3][0] = 7
dnum[2][1] = 8
dnum[1][2] = 9
dnum[0][3] = 10
dnum[4][0] = 11
dnum[3][1] = 12
dnum[2][2] = 13
dnum[1][3] = 14
dnum[0][4] = 15
||dnum[4][1] = 16
||dnum[3][2] = 17
||dnum[2][3] = 18
||dnum[1][4] = 19
||dnum[0][5] = 20
||dnum[-1][6] = 21
||dnum[-2][7] = 22
||dnum[-3][8] = 23
||dnum[-4][9] = 24
||dnum[4][2] = 25
||dnum[3][3] = 26
||dnum[2][4] = 27
||dnum[1][5] = 28
||dnum[0][6] = 29
||dnum[-1][7] = 30
||dnum[-2][8] = 31
||dnum[-3][9] = 32
||dnum[4][3] = 33
||dnum[3][4] = 34
||dnum[2][5] = 35
||dnum[1][6] = 36
||dnum[0][7] = 37
||dnum[-1][8] = 38
||dnum[-2][9] = 39
||dnum[4][4] = 40
||dnum[3][5] = 41
||dnum[2][6] = 42
||dnum[1][7] = 43
||dnum[0][8] = 44
||dnum[-1][9] = 45
||dnum[4][5] = 46
||dnum[3][6] = 47
||dnum[2][7] = 48
||dnum[1][8] = 49
||dnum[0][9] = 50
 1  3  6 10 15 20 29 37 44 50 
 2  5  9 14 19 28 36 43 49  0 
 4  8 13 18 27 35 42 48  0  0 
 7 12 17 26 34 41 47  0  0  0 
11 16 25 33 40 46  0  0  0  0 
*/