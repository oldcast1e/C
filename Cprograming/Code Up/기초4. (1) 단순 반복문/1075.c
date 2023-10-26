#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    while(n!=0)
    {
    n=n-1; //n--; 와 같다.
    printf("%d\n", n);
    }
    
} 