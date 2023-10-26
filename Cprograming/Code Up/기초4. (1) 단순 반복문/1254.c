#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char n,m,cnt; scanf("%c %c",&n,&m);if(n>m){cnt = n,n=m,m=cnt;}
    for(char i=n;i<=m;i++) printf("%c ",i);
 
} 