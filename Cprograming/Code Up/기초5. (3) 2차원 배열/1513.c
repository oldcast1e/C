#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,cnt,min=0,val = 1;
    int dnum[100][100]={};
    scanf("%d",&a); cnt = a-1;
    for(int cro=0;cro<a;cro++){
        if(cro%2==0){
            int idx_i=cnt,idx_j=cro;
            for(int i=cnt;i>=min;i--){
                dnum[idx_i][idx_j] = val ;
                val ++;
                idx_i --;
                idx_j ++;
            }//cnt = a-1;
        }
        if(cro%2!=0){
            int idx_i=cro,idx_j=a-1;
            for(int i=cro;i<a;i++){
                dnum[idx_i][idx_j] = val ;
                val ++;
                idx_i ++;
                idx_j --;
            }
            // cnt = cro;
            min += 2;
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++)printf("%d ",dnum[i][j]);
        printf("\n"); //cnt++;
    }
    
    

    
} 
/*
0 0 0 0 5 
0 0 0 4 6 
0 0 3 7 12 
0 2 8 11 15 
1 9 10 16 17
*/