#include<stdio.h>

int main(){
    //소문자를 대문자로 변환하는 프로그램
    char arr[100];
    printf("소문자 11개를 입력하세요: ");
    for(int i=0;i<11;i++)scanf("%c",&arr[i]);

    printf("소문자를 대문자로 변환합니다.\n");
    for(int i=0;i<11;i++)printf("%c",arr[i] - ('a'-'A'));

}