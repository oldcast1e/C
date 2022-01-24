#include <stdio.h>
int main(){

    char u;
    printf("소문자 입력: ");
    scanf("%c",&u);
    printf("%c는 %d번째 영어 소문자",u,u-97);
}