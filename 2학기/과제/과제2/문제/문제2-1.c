#include  <stdio.h>
#include<string.h>
int main(){//메인함수

    char str[100],tmp;//크기 100의 배열과 값 체인지 시 필요한 임의의 변수 정의
    scanf("%s",str);//문자여을 입력받음
    for(int i=0;i<strlen(str);i++){//문자열 길이만큼 반복
        for(int j=0;j<strlen(str);j++){//문자욜 길이만큼 반복
            if(i!=j){//해당 조건 충족 시
                if(str[i]<str[j]){//알파벳 순 정렬
                    tmp =str[i];//저장
                    str[i] = str[j];
                    str[j] = tmp;//다시 대입
                }
            }
        }
    }
    printf("%s",str);//결과 출력

}