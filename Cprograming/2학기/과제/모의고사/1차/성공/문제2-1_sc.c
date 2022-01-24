#include  <stdio.h>
#include  <string.h>//문자열 라이브러리
int main(){//메인 함수 선언
    char str[100],*pstr = str;//크기 100의 배여 선언
    char word[100][100]={{0}};//단어 저장 배열 정의

    int N,len;//문자열의 길이와 입력받을 정수 변수 선언
    int a=0,b=0;//단어 배열의 열과 행
    gets(str);
    scanf("%d",&N);//문자열과 정수를 입력받고
    len = strlen(str);//문자열 길이 저장

    for(int i=0;i<len;i++){//문자열 만큼 반복
        if(*(pstr+i)==' '){// 공백 발생시
            b = 0;//행 초기화
            a ++;//열 증가
        }
        else{
            word[a][b] = *(pstr+i);//단어 배열에 저장
            b++;//행 증가
        }
    }
    printf("%s",word[N-1]);//출력
}
