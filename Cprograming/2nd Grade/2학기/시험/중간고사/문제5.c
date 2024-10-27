#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int countOnes(int **num, int n){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            if(num[i][j] == 0){
                cnt = cnt + (j+1);
                break;
            }
        }
        printf("cnt = %d\n",cnt);
    }
    return cnt;
}

int main(){
    int n; scanf("%d",&n);
    int **num = (int**)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)num[i]= (int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)scanf("%d",&num[i][j]);
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)printf("%d ",num[i][j]);
    //     printf("\n");
    // }
    // 
    printf("%d",countOnes(num,n));
}

/*

4
1 1 1 0
1 1 0 0
0 0 0 0
1 1 1 1

*/