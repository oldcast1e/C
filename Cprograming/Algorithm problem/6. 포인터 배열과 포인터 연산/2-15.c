#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    
    char arr[6] = {'a','b','c','d','e','f'};
    char *parr = arr;
    
    printf("parr을 1씩 증가해보자.\n");
    for(int i=0;i<6;i++){ printf("parr = 0x%p, *parr : %c\n",parr,*parr); parr++;}
}