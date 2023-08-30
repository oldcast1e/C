#include  <stdio.h>
#include  <string.h>
void s_check(char *p,char *q){//p = str //s_chec함수 정의
    char *i;//포인터 정의
    int rst = 0,len = strlen(p)-strlen(q);//결과값을 저장할 변수와 반복횟수 초기화
    // printf("len = %d\n",len);
    for(i = p;i<=p+len;i++){//배열의 길이만큼 반복하여
        if(*i == '\0') break;//해당 요소가 0이면 종료
        if('a'<= *i && *i <= 'z') rst ++;//소문자이면 결과값 증가
    }
    if(rst!=0) printf("%d\n",rst);//0이 아닌 경우 결과값 출력
}
int main(){//메인함수
    int M,K1,K2,result;//세개의 조건 내 변수와 결과변수 정의
    int len;//
    char str[100] = {0,},tmp[10]={0},*pstr= str;//배열 정의 및 포인터 연결

    scanf("%d",&M);scanf("%d",&K1);scanf("%d",&K2);//순서대로 3개의 값을 입력받고
    getchar();//엔터값 지우기
    for(int i=0;i<M;i++){//M번반복
        gets(str);//문자열 입력받고
        s_check(str+K1,str+K2);//함수 실행
    }
}
// 3
// 2 9
// ClanguageIsInteres ting 
//CCC CCCC
// LanguageC