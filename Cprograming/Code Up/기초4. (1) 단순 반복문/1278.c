#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,cnt=1,opt=0;    
    scanf("%d",&a);
    while(a>0){
        opt++;
        a/=10;
    }printf("%d",opt);
 
} 