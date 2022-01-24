#include<stdio.h>
int main(){

    char n;

    char a = 37;//%
    char b = 99;//c
    char c = 100;//d
    printf("문자형 입력: ");
    scanf("%c",&n);
    printf("\n");
    printf("문자로 출력(%c%c): %c\n",a,b,n); 
    printf("정수로 출력(%c%c): %d",a,c,n-48);



}