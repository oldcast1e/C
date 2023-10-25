#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,cnt;
    float d,e,f;

    scanf("%d %d %d",&a,&b,&c);
    if(a<b){cnt = a;a=b;b=cnt;}if(a<c){cnt = a;a=c;c=cnt;}
    if(b<c){cnt = b;b=c;c=cnt;}//printf(">>%d %d %d\n",a,b,c);

    if(a >= (b+c)) printf("삼각형아님");
    else if(a==b && b==c) printf("정삼각형");
    else if (a==b || b == c || a==c) printf("이등변삼각형");
    else if( a*a + b*b  == c*c || a*a + c*c  == b*b || c*c + b*b  == a*a ) printf("직각삼각형");
    else printf("삼각형");
 
} 