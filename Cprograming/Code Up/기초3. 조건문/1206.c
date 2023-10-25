#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c;
    float d,e,f,cnt;
    
    // scanf("%d",&a);
    scanf("%d %d",&a,&b);
    if(b%a==0) printf("%d*%d=%d",a,(int)b/a,b);
    else if(a%b==0) printf("%d*%d=%d",b,(int)a/b,a);
    else printf("none");
    // printf("%f",cnt);
 
} 
/*
b가 a의 배수이면 "a*x=b"를 출력하고,

a가 b의 배수이면 "b*x=a"를 출력하고,

배수관계가 아니면 "none"을 출력하시오.*/