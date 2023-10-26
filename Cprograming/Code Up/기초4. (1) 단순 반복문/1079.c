#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n;
    char p;
    while(1){
        scanf("%c",&p);
        if(p!=' ') printf("%c\n",p);
        // printf("%c\n",(p!=' ')?p:"");
        if(p=='q') break;
    }
} 