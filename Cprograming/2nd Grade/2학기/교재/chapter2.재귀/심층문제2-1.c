#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int r;

int gcd1(int a, int b){
    //최대 공약수
    while(b > 0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int gcd2(int a, int b){
    //최대 공약수
    while(a !=b){
        if(a>b) a -=b;
        else b -= a;
    }
    return a;
}

int gcd3(int a, int b){
    //최대 공약수
    if(a == 0 || b == 0) return a;
    
    if(a>b)return gcd3(a-=b,b);
    else return gcd3(a,b-=a);
    
}

int main(){
    printf("result gcd1 = %d",gcd1(48,16)); printf("\n");
    printf("result gcd1 = %d",gcd1(78,104)); printf("\n");
    printf("result gcd1 = %d",gcd1(368,138)); printf("\n");
    printf("\n");
    printf("result gcd2 = %d",gcd2(48,16)); printf("\n");
    printf("result gcd2 = %d",gcd2(78,104)); printf("\n");
    printf("result gcd2 = %d",gcd2(368,138)); printf("\n");
    printf("\n");
    printf("result gcd3 = %d",gcd3(48,16)); printf("\n");
    printf("result gcd3 = %d",gcd3(78,104)); printf("\n");
    printf("result gcd3 = %d",gcd3(368,138)); printf("\n");
}

