
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    int i,j,k;
    
    scanf("%d %d",&a,&b);
    // scanf("%d %d %d %d",&a,&b,&c,&d);

    for(i=a;i<=b;i++)
        for(j=1;j<=9;j++)
            printf("%d*%d=%d\n",i,j,i*j);
        // printf("%d",i*j*k);
 
} 
