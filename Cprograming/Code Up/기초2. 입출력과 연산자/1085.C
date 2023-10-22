#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    float w, h, b ;
    scanf("%f %f %f",&w,&h,&b);
    printf("%0.2f MB",(w*h*b)/8/1024/1024);
}