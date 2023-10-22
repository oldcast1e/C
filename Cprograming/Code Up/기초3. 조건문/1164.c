#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c;
    float d,e,f;
    
    // scanf("%d",&a);
    scanf("%d %d %d",&a,&b,&c);
    printf("%s",(a<=170)||(b<=170)||(c<=170) ? "CRASH":"PASS");
 
} 