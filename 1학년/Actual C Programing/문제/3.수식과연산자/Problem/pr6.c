#include<stdio.h>
int main(){

    double N;
    double pi = 3.14;
    scanf("%lf",&N);
    double r = N/(2*pi);
    double S = pi*r*r;    
    printf("%.0f",S);

    
}