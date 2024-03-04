#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int fac(int n){
    int rst;
    if(n>0) return n *fac(n-1);
    else return 1;
}

int main(){
    int n;
    printf("펙토리얼을 계산할 숫자를 입력하세요: ");scanf("%d",&n);
    printf("rst = %d",fac(n));   
}
/*

*/