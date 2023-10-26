#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n,m,cnt; scanf("%d %d",&n,&m);if(n>m){cnt = n,n=m,m=cnt;}
    for(int i=n;i<=m;i++) printf("%d ",i);
 
} 