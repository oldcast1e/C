#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    while(n!=0)
    {
    printf("%d\n", n);
    n=n-1; //n--;와 같다.
    }
    
} 