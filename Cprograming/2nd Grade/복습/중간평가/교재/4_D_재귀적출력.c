#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void rPrintDigits(int n){
    if(n <10)printf("%d\n",n);
    else{
        rPrintDigits(n / 10);
        printf("%d\n",n%10);
    }
}

void PrintDigits(){
    int n;
    printf("Input Number: ");scanf("%d",&n);
    rPrintDigits(n);
}

int main(){
    PrintDigits();
}