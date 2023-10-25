#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,cnt=0;
    float d,e,f;
    
    // scanf("%d",&a);
    scanf("%d %d %d",&a,&b,&c);
    if(b>a){cnt = a;a=b;b=cnt;} if(c>a){cnt = a;a=c;c=cnt;}
    if(c>b){cnt = b;b=c;c=cnt;}
    printf("%d",b);
 
} 