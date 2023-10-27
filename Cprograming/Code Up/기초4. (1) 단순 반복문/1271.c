#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0,max;
    float n1,n2;
    
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        scanf("%d",&b);
        if(i==0) max = b;
        else max = b>max?b:max;
    } printf("%d",max);
    
 
} 