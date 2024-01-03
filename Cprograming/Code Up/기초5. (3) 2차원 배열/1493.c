#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,m,sum = 0;
    int ipt[100][100] = {0};
    int rst[100][100];
    //fgets(arr, 101, stdin);
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&ipt[i][j]);
            sum += ipt[i][j];
        }
    }
    /*
    1 2 3 4 5 

    5 4 3 2 1 

    1 5 2 4 3 
    */
//    printf(">>sum = %d\n",sum);
   for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            rst[i][j] = sum; //printf("%d ",rst[i][j]);
            sum -= ipt[i][j];
        
        }//printf("\n");
   }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",rst[i][j]);
            
        }printf("\n");
    }



    


    /*
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++)printf("%d ",dnum[i][j]);
        printf("\n"); cnt++;
    }
    */
    

    
} 
/*
첫 번째 줄에 배열의 크기 n이 입력된다.
두 번째 줄에 n개의 값이 공백을 두고 입력된다.
[입력값의 정의역]
1<= n <= 100
-1000 <= k <= 1000
*/