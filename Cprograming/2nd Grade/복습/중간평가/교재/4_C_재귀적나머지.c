#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int quotient(int a, int b){
    /*
    a / b = a - b -b ...
    */ 
   if( a > b ) return quotient(a-b,b);
   return a;
}

int main(){
    int a =17 , b = 3;
    int rst = quotient(a,b) ;
    printf("result = %d",rst);
}