#include<stdio.h>
int main(){

    int N,M,R,K;//n은 원래 숫자,m은 배수
    int result = 0;
    scanf("%d",&N);//3,5,15
    M =((N%3==0) && (N%5!=0) && (N%15!=0) ?3:-1);
    R =(N%3!=0 && N%5==0 && N%15!=0?5:-1);
    K =(N%3!=0 && N%5!=0 && N%15==0?15:-1);

    result = (M>R && M>K?M:-1);
    result = (R>M && R>K?R:M);
    result = (K>M && K>R?K:R);

    printf("%d is a multiple of %d",N,result);


}