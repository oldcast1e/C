#include<stdio.h>
int main(){

    int n,h,m,s;
    scanf("%d",&n);
    h = n/3600;
    m = n/60%60;
    s = n%60;
    printf("%d:%d:%d",h,m,s);  

    
}