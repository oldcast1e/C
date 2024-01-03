#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,sum = 0;
    int num[2][100]={0};
    //fgets(arr, 101, stdin);
    scanf("%d",&n);
    // scanf("%s",arr);
    // for(int i=0;i<(int)strlen(arr);i++)
    for(int i=0;i<n;i++){scanf("%d",&num[0][i]);sum += num[0][i];}
    for(int i=n-1;i>=0;i--){
        // printf("sum = %d | num[0][%d] = %d\n",sum,i,num[0][i+1]);
        sum -= num[0][i+1];
        num[1][i] = sum;
    }
    for(int i=0;i<n;i++) printf("%d ",num[1][i]);


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