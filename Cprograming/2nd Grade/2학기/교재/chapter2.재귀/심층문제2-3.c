#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int cnt = 0, rst[2];

int* divide(int a, int b){
    if(a > b){cnt ++; a-=b; return divide(a,b);}
    else {
        rst[0] = cnt; rst[1] = a;
        return rst;
    }
}

int main(){
    int* rst = divide(15,2);
    printf("몫: %d, 나머지: %d",rst[0],rst[1]);
}