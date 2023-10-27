#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    float n1,n2;
    
    scanf("%d",&a);
    for(int i=1;i<=a;i++) if(a%i==0)cnt++;
    if(cnt == 2)printf("prime");
    else printf("not prime");
 
} 