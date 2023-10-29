 #include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt,spc;
    float n1,n2;
    
    scanf("%d",&a); cnt = 1; spc = a/2;
    while(1){
        for(int i=0;i<spc;i++)printf(" ");
        for(int i=0;i<cnt;i++) printf("*"); printf("\n");
        cnt += 2; spc -=1;
        if(cnt > a) break;
    }
 
} 
