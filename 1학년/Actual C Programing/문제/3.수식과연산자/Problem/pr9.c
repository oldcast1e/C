#include <stdio.h>
int main(){

    int N,M;
    scanf("%d",&N);
    M = N%2;
    
    printf(M==0?"짝수":"홀수");
}