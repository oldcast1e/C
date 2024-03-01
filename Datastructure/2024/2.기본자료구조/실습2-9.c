#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    unsigned count = 0,i,j;
    for(i=2;i<=1000;i++){
        for(j=2;j<i;j++){
            count ++;
            if(i%j == 0) break;
        }
        if(i==j)printf("%d\n",i);
    }
    printf("count = %d",count);
} 
/*
unsigned count = 0,i,j;
    for(i=2;i<=1000;i++){
        for(j=2;j<i;j++){
            count ++;
            if(i%j == 0) break;
        }
        if(i==j)printf("%d\n",i);
    }
    printf("count = %d",count);
*/