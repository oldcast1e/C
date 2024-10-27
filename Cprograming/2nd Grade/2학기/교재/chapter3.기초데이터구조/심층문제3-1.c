#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n; scanf("%d",&n);
    int cnt = 1;

    int **num = (int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++) num[i] = (int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++)for(int j=0;j<n;j++)  num[i][j] =0;
       
    

    for(int i=0;i<n;i++){
        if(i%2==0) for(int j=0;j<n;j++)num[i][j] = cnt++;
        if(i%2 == 1) for(int j=n-1;j>=0;j--) num[i][j] = cnt++;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) printf("%2d ",num[i][j]);
        printf("\n");
    }
}