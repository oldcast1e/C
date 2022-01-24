#include<stdio.h>
int main(){//메인함수
    char arr[20]={0},*parr= arr;//크기 20인 배열과 포인터 연결
    int cnt  = 0;//문자의 개수를 저장할 변수
    scanf("%s",arr);//문자열을 입력받음
    for(int i=0;i<20;i++){//20번 반복
        if(*(parr+i)== '\0') break;//널 문자가 입력되면 = 문자열 입력이 종료되면
        cnt ++;//문자 개수 변수 증가
    }
    for(int i=0;i<cnt;i++){//문자의 개수만큼
        if(97<=*(parr+i) && *(parr+i) <= 122) printf("%c",*(parr+i));//소문자면 출력
    }
}