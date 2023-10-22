#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b; //scanf("%d %d",&a,&b);
    float c;
    // scanf("%d",&a);
    scanf("%f",&c);
    printf("%s",((50<=c&&c<=70)||(int)c%6==0)?"win":"lose");
} 