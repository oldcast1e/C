#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    unsigned count = 0,i,j;
    int prime[500];
    unsigned long cnt = 0;
    prime[count ++ ] = 2;
    prime[count ++ ] = 3;
    
    for(i=5;i<=1000;i+=2){
        for(j=1;j<count;j++){
            if(prime[j]* prime[j] < i){
                cnt ++;
                if( i % prime[j] == 0) break;
            }
        }
        if(j == (count)) prime[count++] = i;
    }
    for(i=0;i<count;i++)printf("%d\n",prime[i]);
    printf("count = %lu",cnt);
}