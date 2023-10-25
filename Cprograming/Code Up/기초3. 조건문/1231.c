#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt;
    float n1,n2;
    char p;
    scanf("%d%c%d",&a,&p,&c);
    printf(">>%d %c %d\n",a,p,c);
    switch (p){
    case '+': printf("%d",a+c); break;
    case '-': printf("%d",a-c); break;
    case '*': printf("%d",a*c); break;
    case '/': printf("%.02f",(float)a/(float)c); break;
    }
    // scanf("%d %d %d %d",&a,&b,&c,&d);
    // printf("%d",1<<3);
    // printf("%f",cnt);
 
} 