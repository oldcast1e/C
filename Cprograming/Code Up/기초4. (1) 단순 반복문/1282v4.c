#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(){
    long int n,k=1,t,rep=1;
    scanf("%ld",&n);
    for(long int i=n;i>=1;i--){
        if(i*i<n){
            printf("%ld %ld",n-i*i,i);
            // printf(">>%ld*%ld=%ld",i,i,i*i);
            break;
        }
    }
} 