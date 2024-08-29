#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int product(int a,int b){//a x b
    /*
    a x b = (a + a + ...)
    */ 
   if( b > 1 ) a += product(a, b-1);
   return a;
}
int main(){
    int a = 5 , b = 3;
    int rst = product(a,b) ;
    printf("result = %d",rst);
}