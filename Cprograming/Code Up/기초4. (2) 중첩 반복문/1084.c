#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    int i,j,k;
    
    scanf("%d %d %d",&a,&b,&c);
    // scanf("%d %d %d %d",&a,&b,&c,&d);

    for(i=0;i<a;i++)
        for(j=0;j<b;j++)
            for(k=0;k<c;k++) printf("%d %d %d\n",i,j,k);
        printf("%d",i*j*k);
 
} 
