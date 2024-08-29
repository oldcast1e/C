#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int fibonachi(int n){
    /*
    */
   if(n == 0 || n == 1)return n;
   else return fibonachi(n-1) + fibonachi(n-2);
}
int main(){
    int n = 10;
    printf("result = %d",fibonachi(n));
}