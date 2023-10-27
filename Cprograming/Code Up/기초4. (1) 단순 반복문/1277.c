#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0,fir,mid,fin;
    float n1,n2;
    
    scanf("%d",&a);
    // scanf("%d %d",&a,&b);
    // scanf("%d %d %d",&a,&b,&c);
    // scanf("%d %d %d %d",&a,&b,&c,&d);
    // printf("%d",cnt);
    for(int i=0;i<a;i++){
        scanf("%d",&b);
        if(i == 0) fir = b;
        if(i == a/2) mid = b;
        if(i== (a-1)) fin = b;
    }printf("%d %d %d",fir,mid,fin);
 
} 