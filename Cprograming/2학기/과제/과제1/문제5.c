#include  <stdio.h>
int main(){
    char str[1000],*pstr = str;//크기 1000의 배열과 포인터 연결
    int len = 0,cnt=0;//배열의 길이와 공백 구분 변수 cnt
    while(1){//무한 반복하여
        scanf("%c",(pstr+len));//요소를 입력받고
        if(*(pstr+len)=='.' || *(pstr+len)=='!' || *(pstr+len)=='?')break;//종료 조건일때 종료
        len ++;//길이 증가
    }
    // printf("%d\n",len);
    // printf("%c\n",*(str+len-1));
    for(int i = len-1 ;i>=0;i--){//배열의 끝부터
        // printf("%d ",i);
        if(*(pstr+ i) != ' '){//해당 요소가 공백이 아니면
            cnt ++;//공백 수 증가
            // printf("%d",cnt);
        }
        if(*(pstr+ i) == ' ' || i==0){//공백이면
            if(i==0) printf("%c",*pstr);   //배열의 인덱스가 0이면 맨 처음 값 출력
            for(int j=1;j<=cnt;j++){//1부터 cnt까지 더하면서
                if(i==0 && j==cnt)printf("%c",*(pstr+len));//i==0 또는 j==cnt이면 꼬리값 출력
                else printf("%c",*(pstr+(i+j)));//그 전의 요소값 출력
            }
            cnt  = 0;//cnt초기화
            if(i!=0)printf(" ");//0이아니면 공백 = 단어 구분   
        }
    }
}//you can cage a swallow can't you?
//최대 1000개의 영어 문자로 이루어진 문장을 입력받아 맨 뒤의 단어부터 거꾸로 출력

//맨 뒤의 단어부터 거꾸로 출력

//입력의 종료 조건 : . ? !
//함수에서도 배열 표기 사용x
