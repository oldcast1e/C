#include <stdio.h>
int main(){

    int n;
    printf("정수 입력(0~25): ");
    scanf("%d",&n);
    char m =  n;
    printf("%d번째 영어 대문자는 %c",n,m + 65);
}