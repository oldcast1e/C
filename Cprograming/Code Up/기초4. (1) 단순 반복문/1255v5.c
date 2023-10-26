#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    double n1,n2;
    scanf("%lf %lf",&n1,&n2);
    for(double i=n1;i<=n2;i+=0.01){
        printf("%.02f ",i);
    }
} 