#include  <stdio.h>
#include <string.h>
int main(){//메인함수
    char str1[100],str2[100],*pstr1 = str1,*pstr2 = str2;//두개의 배열을 선언 및 각각 포인터를 연결
    int cnt = 0,rstcnt = 0,key,str2len = 0;//배열의 길이를 구할 cnt변수와 포함된 개수를 저장할rstcnt,조건값 key와 배열2의 길이 변수 선언
    while(1){//무한반복
        scanf("%c",(pstr1+cnt));//배열1을 입력받고
        if(*(pstr1+cnt) == '\n') break;//엔터가 입력되면 입력종료
        cnt ++;
    }
    scanf("%s",str2);//배열2를 입력받고
    str2len = strlen(str2);//배열2의 길이를 구함

    for(int i=0;i<cnt;i++){//배열1의 길이만큼 반복
        key = 0;//조건값 초기화
        if(*(pstr1+i) == *str2){//배열1의 해당요소가 배열2의 시작요소와 같을 경우
            for(int j=0;j<str2len;j++){//배열2의 길이만큼 반복
                if(*(pstr1+i+j) == *(str2+j)) key ++;//중복시 조건값 증가
            }
            if (key == str2len){//조건값이 배열2의 길이와 같은 경우 = 포함된 경우
                rstcnt ++;//포함된 수를 증가
                for(int j=0;j<str2len;j++){//해당 포함된 문자열을 공백을 초기화 = 다음 계산에서 제외
                    *(pstr1+i+j) = ' ';
                }
            }
        }
    }
    // for(int i=0;i<cnt;i++)printf("%c",*(pstr1+i));
    printf("%d",rstcnt);//결과출력
}
//공백을 포함하는 문자열 str1과 공백을 포함하지않는 문자열 str2를 입력받음
//str1에 str2가 몇번 반복되는지 그 횟수를 출력하라.

//이미 계산된 문자는 다음 계산에 사용하지않는다.

//함ㅁ수는 strlen()만 사용가능

//Prrogram prrogram
//rr