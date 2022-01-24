#include  <stdio.h>
#include  <string.h>
int main(){//메인함수
    char str1[100],str2[100],*pstr1 = str1,*pstr2 = str2;//문자열1,2와 포인터연결 정의
    gets(str1);
    gets(str2);//두 문자열을 입력받음

    int len1 = strlen(str1),len2 = strlen(str2);//문자열1,2의 길이 정의
    int key = 0,rst = 0;//조건값과 결과값을 초기화
    for(int i=0;i<len1;i++){//배열1의 길이만큼 반복
        key = 0;//조건값 초기화
        if(*(pstr1+i) == *pstr2){//문자열1의 특정 요소와 문자열2의 첫번째 요소가 같은 경우
            for(int j=0;j<len2;j++){//문자열2와 비교
                if(*(pstr1+i+j) == *(pstr2+j)) key ++;
            }       
        }
        if(key == len2) rst ++;//==문자열 포함 = 결과값 증가
    }
    printf("%d",rst);//결과출력


}
//영문 대소문자, 공백, 그리고 점들로만 이루어진 문자열을 입력받는다.
//그리고 영문 대소문자로만 이루어진 문자열을 입력받는다.

//이들을 입력받은 순서대로 첫 번째 문자열을 문자열 1 | 문자열 2 라 한다.

//문자열 1에 문자열2가 몇번 등장하는지 출력하라.

//단, 대소문자를 구분하며, 각 문자열의 길이는 100을 넘지 않는다.