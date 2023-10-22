#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//1163

int main(){
    int a,b,d; scanf("%d %d %d",&a,&b,&d);
    float c;

    int cnt = (a + b + d)/100%10;
    printf("%s",cnt%2==0?"대박":"그럭저럭");
}