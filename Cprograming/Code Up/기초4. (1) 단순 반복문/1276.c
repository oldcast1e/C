#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=1;
    float n1,n2;
    
    scanf("%d",&a);
    // scanf("%d %d",&a,&b);
    // scanf("%d %d %d",&a,&b,&c);
    // scanf("%d %d %d %d",&a,&b,&c,&d);

    for(int i=1;i<=a;i++) cnt *= i;
    printf("%d",cnt);
 
} 