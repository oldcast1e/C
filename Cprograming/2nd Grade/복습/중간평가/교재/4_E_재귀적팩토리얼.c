#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int factorialInt(int a){
    if(a > 1) return a * factorialInt(a - 1);
    else return a;
}

int main(){
    int n = 5;
    int facResult = factorialInt(n);
    printf("result = %d",facResult);

}