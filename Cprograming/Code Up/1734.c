/*당신은 웹사이트 제작자이다.

ID를 입력하고 엔터를 누르면 환영 메시지를 띄우려고한다.

예를 들어 ID가  인 경우, welcome! anaki를 출력한다.

환영 메시지를 출력하는 프로그램을 작성하시오.*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char ipt[100];
    scanf("%s",ipt);
    printf("welcome! %s",ipt);
}