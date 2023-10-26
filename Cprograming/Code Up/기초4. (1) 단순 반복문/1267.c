#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    float n1,n2;
    
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%d",&b);if(b%5==0)cnt += b;
    }printf("%d",cnt);
    
 
} 
