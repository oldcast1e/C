#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,cnt=0;
    float d,e,f;
    
    scanf("%d",&a);
    // scanf("%d %d",&a,&b);
    // scanf("%d %d %d",&a,&b,&c);
    int rst  = a%10 * 10 + a/10; rst *= 2;
    if (rst > 100) rst -= 100;
    printf("%d\n%s",rst,rst<=50?"GOOD":"OH MY GOD");
 
} 