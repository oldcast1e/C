#include  <stdio.h>
#include<string.h>
int main(){//메인함수
    char str1[80],str2[10];//두개의 배열 선언
    char *pstr1 = str1,*pstr2 = str2;//두 배열을 포인터에 연결
    int str1len = strlen(str1),str2len = strlen(str2);//두 배열의 길이를 선언 및 저장
    int key=0,rst=0,cnt;// 조건 분석ㄱ밧 key,결과값 rst, 문자열 포함 여부 분석 cnt

    scanf("%s",str1),scanf("%s",str2);//두 배열을 입력받아
    for(int i=0;i<str1len;i++){//배열 1의 길이 만큼 반복
        if(rst == 1) break;

        if(*(pstr1+i)==*pstr2)key = 1;//해당 요소에 배열 2의 시작 요소와 같은 값이 존재하면 조건값을 1로 만들어 밑의 코드를 실행함

        if(key==1){//조건이 참인 경우
            cnt = 0;//cnt 초기화
            for(int j=0;j<str2len;j++){//배열2의 길이만큼 반복하여
                if(*(pstr1+i+j) == *(pstr2+j)) cnt++;//해당 요소가 배열2의 순서와 같은 경우 = 포함된 경우 cnt증가
            }
            if(cnt==str2len)rst = 1;//cnt가 배열2의 길이와 같은 경우 = 모두 같은 경우  = 배열2가 포함됨 -> 결과값을 1로 저장
            else key = 0;//조건값 초기화
        }
    }
    printf("%d %d",(int)strlen(str1),rst);//결과출력
}