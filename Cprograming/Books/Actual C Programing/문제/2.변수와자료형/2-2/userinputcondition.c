#include<stdio.h>

int main(){

    char u;
    scanf("%c",&u);
    if('A'<=u && u<='Z'){
        printf("대문자");
    }
    else if('a'<=u && u<='z'){
        printf("소문자");
    }
    else if('0'<=u && u<='9'){
        printf("숫자");
    }
    else 
        printf("기타");
    
}