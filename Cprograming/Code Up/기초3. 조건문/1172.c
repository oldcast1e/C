#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,cnt=0;
    float d,e,f;
    
    // scanf("%d",&a);
    // scanf("%d %d",&a,&b);
    scanf("%d %d %d",&a,&b,&c);
    if(a<b){cnt = a;a=b;b = cnt;} if(a<c){cnt = a;a=c;c = cnt;}
    if(b<c){cnt = b;b=c;c = cnt;}
    printf("%d %d %d",c,b,a);
 
} 