#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c;
    float d,e,f;
    
    // scanf("%d",&a);
    scanf("%f %f",&d,&e);
    // scanf("%d %d %d",&a,&b,&c);
    float aa,bb,cc,dd,ee,cnt;
    aa = d+e; bb= d-e; cc = d*e; dd = d/e, ee=(int)d<<(int)e;
    if(aa>bb){cnt = aa;aa=bb;bb=cnt;}if(aa>cc){cnt = aa;aa=cc;cc=cnt;}if(aa>dd){cnt = aa;aa=dd;dd=cnt;}
    if(bb>cc){cnt = bb;bb=cc;cc=cnt;}if(bb>dd){cnt = bb;bb=dd;dd=cnt;}
    if(cc>dd){cnt = cc;cc=dd;dd=cnt;}
    printf("%0.6f",dd);
 
} 
/*
두 실수 a, b가 입력되면 
그 두수를 더하거나 빼거나 곱하거나 나누거나 
제곱을 해서 가장 큰 수를 출력하시오.*/