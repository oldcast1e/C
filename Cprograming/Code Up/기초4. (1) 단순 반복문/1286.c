#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    int min,max;
    
    
 

    for(int i=0;i<5;i++){
        scanf("%d",&a);
        if(i==0){min = a;max =a;}
        max = a > max ? a:max;
        min = a< min ? a: min;
    } printf("%d\n%d",max,min);
 
} 
