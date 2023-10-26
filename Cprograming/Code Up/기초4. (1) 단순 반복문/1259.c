#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c=0,d,cnt=0;
    float n1,n2;
    scanf("%d",&a);
    for(int i=1;i<=a;i++)if(i%2==0)cnt += i;
    printf("%d",cnt);
 
} 