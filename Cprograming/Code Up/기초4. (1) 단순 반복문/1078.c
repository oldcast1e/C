#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int sum=0;
    int i, n;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
    if(i%2==0) sum=sum+i;
    } printf("%d",sum);

 
} 