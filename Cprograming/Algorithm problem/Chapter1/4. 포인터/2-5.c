#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int num = 10;
    int *pnum = &num;

    printf("%d",*pnum);
}