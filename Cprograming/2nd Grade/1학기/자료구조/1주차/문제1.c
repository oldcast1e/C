#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int rst = 0,n; scanf("%d",&n);
    for(int i = 1;i<=n;i++)for(int j= 1;j<=i;j++) rst += j;
    printf("%d",rst);
    
} 
/*

*/