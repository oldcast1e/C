#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n[10],key=0;
    for(int i=0;i<10;i++)scanf("%d",&n[i]);
    for(int i=0;i<10;i++)
        if(n[i]%5==0){printf("%d",n[i]);key = 1;break;}
    if(key == 0)printf("0");
} 
/*
10개의 수 중 5의 배수가 있으면 그 중 하나만 출력하고, 없다면 0을 출력한다.
*/