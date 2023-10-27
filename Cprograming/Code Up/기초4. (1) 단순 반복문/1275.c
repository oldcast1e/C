#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=1;
    float n1,n2;
    
    // scanf("%d",&a);
    scanf("%d %d",&a,&b);
    for(int i=0;i<b;i++) cnt*=a;
    printf("%d",cnt);
 
} 