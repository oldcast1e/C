#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int rst[10000]={0,}; 
    int cnt=0,num;
    scanf("%d",&num);if(num==0)cnt = 1;
    while(num>0){
        rst[cnt] = num%2; cnt++;
        num/=2;
    }
    for(int i=cnt-1;i>=0;i--)printf("%d",rst[i]);
} 
/*

*/