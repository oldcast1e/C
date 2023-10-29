#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    float n1,n2;
    
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        for(int k=a-1-i;k>0;k--)printf(" ");
        for(int j=0;j<a;j++)printf("*"); printf("\n");
    }
 
} 
