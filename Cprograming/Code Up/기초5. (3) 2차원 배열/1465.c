#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=1;
    int dnum[100][100];
    scanf("%d %d",&a,&b);
    // scanf("%s",arr);
    // for(int i=0;i<(int)strlen(arr);i++)
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){dnum[i][j]=cnt;cnt++;}
    }
    for(int i=a-1;i>=0;i--){
        for(int j=0;j<b;j++)printf("%d ",dnum[i][j]);
        printf("\n");
    }
} 
/*
1 2 3
4 5 6
*/