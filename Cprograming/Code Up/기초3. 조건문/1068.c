#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a; scanf("%d",&a);
    printf("%c",a>=90?'A':(a>=70?'B':a>=40?'C':'D'));
}