#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,cnt=0,val = 1,dir=0;
    int num[100];
    int dnum[100][100];
    //fgets(arr, 101, stdin);
    scanf("%d",&a);
    int cnt_i=0,cnt_j=0;
    while(1){
        if(val == a*a) break;

        if(a > cnt_i) dir = 1;
        else {
            printf("방향 전환\n");
            dir = 0;
            cnt_i --;
            cnt_j++;
        }

        if(dir == 1){
            dnum[cnt_i][cnt_j] = val; 
            printf("[순방향] dnum[%d][%d] = %d\n",cnt_i,cnt_j,val);
            val++;
            cnt_i ++;
        }
        else if(dir == 0){
            dnum[cnt_i][cnt_j] = val; 
            printf("<역방향> dnum[%d][%d] = %d\n",cnt_i,cnt_j,val);
            val++;
            cnt_i --;
        }
        // else if(n > cnt_i)cnt_i ++;
    }
    /*
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++)printf("%d ",dnum[i][j]);
        printf("\n"); cnt++;
    }
    */
    

    
} 
/*

*/