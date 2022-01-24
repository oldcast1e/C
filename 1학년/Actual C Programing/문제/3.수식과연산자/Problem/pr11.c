#include<stdio.h>
int main(){
    int N,M,K,R;
    scanf("%d %d",&N,&M);
    K = (N>M?N/M:M/N);
    R = (N>M?N%M:M%N);
    printf("%d\n",K);
    printf("%d",R);
}