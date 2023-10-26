#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a[3]={0,0,0},b[3]={0,0,0};
    char cnt;
    // scanf("%d.%d%d%c%d.%d%d",&a[0],&a[1],&a[2],&cnt,&b[0],&b[1],&b[2]);
    scanf("%d %d%d",&a[0],&a[1],&a[2]);
    printf(">%d\n",a[0]);
    printf(">%d\n",a[1]);
    printf(">%d\n",a[2]);
    // printf(">>%d.%d%d %d.%d%d",a[0],a[1],a[2],b[0],b[1],b[2]);
} 