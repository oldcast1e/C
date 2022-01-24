#include<stdio.h>
int main(){

    int n;
    scanf("%d",&n);
    int a,b,c,d,e;
    a = n/10000;
    b = (n%10000)/1000;
    c = (n%1000)/100;
    d = (n%100)/10;
    e = n%10;
    printf("%d만%d천%d백%d십%d",a,b,c,d,e);


}