#include <stdio.h>

int main(){
    int x;
    scanf("%c", &x);

    if('A'<= x && x <='Z')
        printf("대문자입니다.");
    else if('a' <= x && x <= 'z')
        printf("소문자입니다.");
    else if(0 <= x && x <= 9)
        printf("숫자입니다.");
    else
    printf("사용하지 않는 키 입력");
}

/**
10
AF 10
AF 20
AF 30
AR 40
 */