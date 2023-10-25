#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,cnt=0;
    float d,e,f;
    
    scanf("%d",&a);
    // scanf("%d %d",&a,&b);
    // scanf("%d %d %d",&a,&b,&c);
    cnt  = a%10;
    if(a/10==1) printf("%dth",a);
    else{
        if(a%10 == 1) printf("%dst",a);
        else if(a%10 == 2) printf("%dnd",a);
        else if(a%10 == 3) printf("%drd",a);
        else  printf("%dth",a);
    }
    // printf("%d",a);
 
} 