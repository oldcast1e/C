#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,cnt=0;
    float d,e,f;
    
    // scanf("%d",&a);
    scanf("%d %d",&a,&b);
    int h = a,m = b;
    if((m - 30)<0 ){
        h -= 1;
        m = 60 - (30-m);
    }
    else m -= 30;

    if(h<0) h = 24 + h;
    // scanf("%d %d %d",&a,&b,&c);
    printf("%d %d",h,m);
 
} 