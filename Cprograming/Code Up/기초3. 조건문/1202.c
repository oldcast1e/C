#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,cnt=0;
    float d,e,f;
    
    scanf("%d",&a);
    // scanf("%d %d",&a,&b);
    // scanf("%d %d %d",&a,&b,&c);
    if(a>=90) printf("%c",'A');
    else if(a>=80) printf("%c",'B');
    else if(a>=70) printf("%c",'C');
    else if(a>=60) printf("%c",'D');
    else printf("%c",'F');

 
} 