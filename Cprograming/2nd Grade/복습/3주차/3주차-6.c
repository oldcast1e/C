#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int gcd(int a, int b){
    if( a !=0 && b !=0){
        if(a>b) return gcd(a%b,b);
        else return gcd(a,b%a);
    }
    else return(a==0?b:a);
}

int main(){
    //순환문이용
    int n,m; scanf("%d %d",&n,&m);
    printf("%d",gcd(n,m));
    


} 
/*
*/