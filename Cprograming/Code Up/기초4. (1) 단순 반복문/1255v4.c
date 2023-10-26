#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    double n1,n2;
    scanf("%f %f",&n1,&n2);
    int a = n1*100, b = n2*100;
    // printf("%d %d",a,b);
    for(int i=a;i<=b;i++){
        printf("%.02f ",i/100+(i%100)*0.01);
    }
 
} 