#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    float n1,n2;
    
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        if(i==0 || i == (a-1)){
            for(int j=0;j<a;j++)printf("*");printf("\n");}
        else{ 
            printf("*");
            for(int j=1;j<a-1;j++)printf(" ");
            printf("*\n");
        }
    }
} 

