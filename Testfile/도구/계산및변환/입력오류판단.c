#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    char str[100];
    scanf("%s",str);

    int length = (int)sizeof(strlen(str));
    int key = -1;
    /**
    key가 -1인 경우: 입력에러
    key가 0인 경우: 입력받은 값이 영어로 시작함
    key가 1인 경우: 입력받은 값이 숫자로 시작함
     */
    if('a'<= str[0] && str[0]<='z' || 'A'<= str[0] && str[0]<='Z') key = 0; // 첫 번째 문자가 영어인 경우
    if('0'<= str[0] && str[0]<='9') key = 1;    //첫번째 문자가 숫자인 경우
    
    for(int i=1;i<length;i++){
        if(key == 0 && i>0) key = ('0'<= str[i] && str[i]<='9') ? -1:0;
        //영어로 시작했는데 숫자가 나온 경우
        if(key == 1 && i>0) key = ('a'<= str[i] && str[i]<='z' || 'A'<= str[i] && str[i]<='Z') ? -1:1;
        //숫자로 시작했는데 영어가 나온 경우

        if(key == -1) break;
    }
    if(key == 0) printf("영어를 입력하였습니다.");
    else if(key == 1) printf("숫자를 입력하였습니다.");
    else printf("입력 오류입니다.");
    
}	