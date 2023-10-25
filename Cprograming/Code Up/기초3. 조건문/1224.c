#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    float a,b,c,d,cnt;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("%c",(a/b > c/d)?'>':(a/b == c/d ? '=':'<'));

 
} 