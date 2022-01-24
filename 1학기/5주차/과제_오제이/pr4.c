#include<stdio.h>
int main(){

    char u;//char 형태 변수 선언
    scanf("%c",&u);//입력받음
    if('A'<= u && u<='Z'){//입력받은 값이 대문자 영어 범위인 경우, 
        u +=32;//32을 더함=소문자 범위로 바꿈
        printf("%c",u);//소문자 출력
    }

    else if('a'<= u && u<= 'z'){//입력받은 값이 소문자 영어 범위인 경우, 
        u -=32;//32을 뺌=대문자 범위로 바꿈
        printf("%c",u);//대문자 출력
    }
    else    
        printf("none");//아무것도 충족하지못하는 경우 none출력

}