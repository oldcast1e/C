#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int i, j,n,m;
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            printf("%d %d\n", i, j);
 
} 
