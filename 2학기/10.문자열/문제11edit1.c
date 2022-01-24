#include  <stdio.h>
#include<string.h>
int main(){//메인함수
    char str1[81],str2[11];//두개의 배열 선언
    char *pstr1 = str1,*pstr2 = str2;//두 배열을 포인터에 연결
    int rst=0,cnt;// 조건 분석ㄱ밧 key,결과값 rst, 문자열 포함 여부 분석 cnt
    
    scanf("%s",str1);
    scanf("%s",str2);//두 배열을 입력받아
    int str1len = strlen(str1),str2len = strlen(str2);//두 배열의 길이를 선언 및 저장

    for(int i=0;i<str1len;i++){//배열 1의 길이 만큼 반복
        
        cnt = 0;//cnt 초기화
        if(*(pstr1+i) == *str2){//조건이 참인 경우
            for(int j=0;j<str2len;j++)if(*(pstr1+i+j) == *(pstr2+j)) cnt++;
            //배열2의 길이만큼 반복하여
            //해당 요소가 배열2의 순서와 같은 경우 = 포함된 경우 cnt증가
            if(cnt==str2len){
                rst ++;//cnt가 배열2의 길이와 같은 경우 = 모두 같은 경우  = 배열2가 포함됨 -> 결과값을 1로 저장
            }   
        }
    }
    printf("%d %d",(int)strlen(str1),rst);//결과출력
}