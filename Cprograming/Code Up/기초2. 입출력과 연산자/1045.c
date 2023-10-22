#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    long int a,b;
    scanf("%ld %ld",&a,&b);
    printf("%ld\n",a+b);
    printf("%ld\n",a-b);
    printf("%ld\n",a*b);
    printf("%ld\n",a/b);
    printf("%ld\n",a%b);
    printf("%.02f\n",(float)a/(float)b);
    
}