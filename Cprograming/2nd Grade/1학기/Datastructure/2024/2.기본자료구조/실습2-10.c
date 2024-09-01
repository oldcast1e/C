#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    unsigned count = 0,i,j;
    int prime[500],cnt = 0;
    prime[count ++ ] = 2;
    for(i=3;i<=1000;i+=2){
        for(j=3;j<i;j++){
            cnt ++;
            if(i%j == 0) break;
        }
        if(i==j)prime[count++] = i;
    }
    for(i=0;i<count;i++)printf("%d\n",prime[i]);
    printf("count = %d",cnt);
}