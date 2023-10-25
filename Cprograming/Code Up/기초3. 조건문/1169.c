#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,cnt=0,rst;
    float d,e,f;
    scanf("%d",&a);
    int year  = 2012 + 1 - a;
    printf("%d %d",year%100,year/100==20?3:1);
    // scanf("%d %d",&a,&b);
   
    // printf("%d",2012-a+1);
 
} 