#include  <stdio.h>
#include<string.h>
int main(){//메인 함스
    int N,min=102,len;//줄의 개수를 저장할 변수 N과 최대 문자 길이를 저장할 변수 min, 문자열의 길이를 저장할 변수 len
    char str[100],tmp[100],rst[100];//3개의 배열 선언
    char delim[] = " ,\n";//문자열을 분리할 조건
    scanf("%d",&N);//문자열 입력 횟수
    getchar();//
    for(int i=0;i<N;i++){//N번 반복하여
        strcpy(str,"");//입력받을 문자열(배열)초기화
        strcpy(tmp,"");//입력받을 문자열(배열)초기화
        scanf("%[^\n]%*c",str);//엔터입력까지 문자열을 입력받음
        len = strlen(str);//문자열 길이를 구하고
        if(len<min){//최소 문자열 길이이면
            min = len;//최소 문자열 길이에 저장하고
            strcpy(rst,"");//결과 문자열을 초기화
            strcat(rst,str);//결과 문자열에 저장
        }
    }
    printf("%s",rst);//결과 출력
}