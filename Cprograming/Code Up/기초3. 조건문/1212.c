#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,cnt;
    float d,e,f;
    scanf("%d %d %d",&a,&b,&c);
    if(a<b){cnt = a;a=b;b=cnt;}if(a<c){cnt = a;a=c;c=cnt;}
    if(b<c){cnt = b;b=c;c=cnt;}
    
    if(a < b+ c) printf("yes");
    else printf("no");
 
} 