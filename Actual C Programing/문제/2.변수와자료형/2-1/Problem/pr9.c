#include <stdio.h>
int main(){

    char u;
    printf("소문자 입력: ");
    scanf("%c",&u);
    char k  = u-32;
    printf("대문자 출력: %c ",k);
}