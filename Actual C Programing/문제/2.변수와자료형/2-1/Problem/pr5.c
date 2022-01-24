#include<stdio.h>
int main(){

    printf("큰 따옴표는 \"입니다.\n");
    printf("작은 따옴표는 \'입니다.\n");
    printf("문자 A는 'A'입니다.\n");
    char a = 92, b = 34;
    printf("큰 따옴표의 이스케이프 시퀸스는 %c%c입니다.",a,b);


}