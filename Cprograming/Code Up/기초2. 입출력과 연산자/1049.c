#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",!a&&!b?1:0);
    // printf("%d",b!=a?1:0);
}