#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b; scanf("%d %d",&a,&b);
    float c;
    // scanf("%d",&a);
    if(a%2==0) printf("짝수+");
    else printf("홀수+");

    if(b%2==0) printf("짝수=");
    else printf("홀수=");

    if(a%2==0&&b%2==0 || a%2!=0&&b%2!=0)printf("짝수");
    else printf("홀수");
    // else printf("enjoy");
    // // scanf("%f",&c);

}