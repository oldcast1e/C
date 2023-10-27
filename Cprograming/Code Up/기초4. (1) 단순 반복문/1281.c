#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    float n1,n2;
    
    // scanf("%d",&a);
    scanf("%d %d",&a,&b);
    for(int i=a;i<=b;i++){
        if(i%2==0){ cnt -= i;printf("-%d",i);}
        else {cnt += i;if(i!=a)printf("+"); printf("%d",i);}
    } printf("=%d",cnt);
 
} 