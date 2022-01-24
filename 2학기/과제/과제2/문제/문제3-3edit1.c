#include  <stdio.h>
#include  <string.h>
int main(){//메인함수
    char str1[101],str2[101],*pstr1 = str1,*pstr2 = str2;//문자열1,2와 포인터연결 정의
    gets(str1);
    gets(str2);//두 문자열을 입력받음
    int len1 = strlen(str1),len2 = strlen(str2);//문자열1,2의 길이 정의
    int key = 0,rst = 0;//조건값과 결과값을 초기화

    for(int i=0;i<len1;i++)if('A' <=  *(pstr1+i) && *(pstr1+i)<='Z') *(pstr1+i) += 32;//소문자통일
    for(int i=0;i<len2;i++)if('A' <=  *(pstr2+i) && *(pstr2+i)<='Z') *(pstr2+i) += 32;//소문자통일
    str1[len1] = '.';//str1의 끝에추가적으로 문자추가 = 문자열비교시 마지막 자리가 종료되었는지 판단하기 위함
    ///====>>>> 베리베리 중요
    
    // puts(str1);
    // puts(str2);

    for(int i=0;i<len1;i++){//배열1의 길이만큼 반복
        key = 0;//조건값 초기화


        if(*(pstr1+i) == *pstr2){//문자열1의 특정 요소와 문자열2의 첫번째 요소가 같은 경우
        //특정요소의 다음값이 공백인경우
            // printf("point1\n");
            if(i==0 && (*(pstr1+i+len2) == ' ' || *(pstr1+i+len2) == '.')){//i=0이고 배열2의 단어크기 뒤에 다른 문자가 없어야 실행
                // printf("point2\n");
                for(int j=0;j<len2;j++){//문자열2와 비교
                    if(*(pstr1+i+j) == *(pstr2+j)) key ++;//조건값 증가
                } 
            }
            else if(i!=0){//i가 0이 아니면
                // printf("point3\n");
                if((*(pstr1+i-1)==' '||*(pstr1+i-1)=='.')&& (*(pstr1+i+len2) == ' ' || *(pstr1+i+len2) == '.')){
                    //해당 요소 뒤에 문자가 없고, 배열2의 단어크기 뒤에 다른 문자가 없어야 실행
                    for(int j=0;j<len2;j++){//문자열2와 비교
                        if(*(pstr1+i+j) == *(pstr2+j)) key ++;//조건값 증가
                    } 
                }
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

// && (*(pstr1+i) == ' ' || *(pstr1+i) == '.')