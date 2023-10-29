#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int h,k;
    char d;
    
    scanf("%d %d %c",&h,&k,&d);
    for(int i=0;i<h;i++){
        if(d=='L') for(int j=0;j<i;j++)printf(" ");
        else if(d =='R')for(int j=h-i-1;j>0;j--)printf(" ");

        for(int j=0;j<k;j++)printf("*"); printf("\n");
    }
 
} 
