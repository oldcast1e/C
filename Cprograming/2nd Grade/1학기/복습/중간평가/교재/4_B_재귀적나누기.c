#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int quotient(int a, int b){// a > b
    /*
    a / b 
    b * n + k = a

    n
    */ 
    // if(a < b)return 0;
    // else 
    //     return 1 + quotient(a -b, b );
    if( a >= b) 
        return 1 + quotient(a - b, b);
    else return 0;
//    int rst = 0;
//    if( a - b > b) rst = 1+  quotient(a - b, b);
//    else return 1;

//    return rst;
}

int main(){
    int a =5 , b = 2;
    int rst = quotient(a,b) ;
    printf("result = %d",rst);
}