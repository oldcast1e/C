#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    float n1,n2;
    
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%d",&b);if(b%2!=0)cnt += 1;
    }printf("%d",cnt);
    
 
} 
