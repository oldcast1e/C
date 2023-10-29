#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a;    
    scanf("%d",&a);
    for(int i=0;i<a-1;i++){
        for(int j=0;j<=i;j++)printf("*");printf("\n");}

    for(int j=0;j<a;j++)printf("*");printf("\n");

    for(int i=a-1;i>0;i--){
        for(int j=i;j>0;j--)printf("*");printf("\n");} 
} 
