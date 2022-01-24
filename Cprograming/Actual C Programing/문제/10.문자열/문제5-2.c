#include  <stdio.h>
int main(){
    char str1[41]={0},str2[20];
    char *pstr1 = str1,*pstr2 = str2;//두개의 배열과 결과저장 배열을 포인터로 연결
    int pos,cnt=0;//정수변수 선언
    int len1=0,len2=0;//두배열의 길이 선언
    
    scanf("%s",str1);
    scanf("%s",str2);//두 배열을 입력받음
    for(int i=0;i<20;i++){//20번 반복
        if(*(pstr1+i)== '\0') break;//널 문자가 입력되면 = 문자열 입력이 종료되면
        len1 ++;//문자 개수 변수 증가
    }
    for(int i=0;i<20;i++){//20번 반복
        if(*(pstr2+i)== '\0') break;//널 문자가 입력되면 = 문자열 입력이 종료되면
        len2 ++;//문자 개수 변수 증가
    }
    scanf("%d",&pos);//정수를 입력받음
    for(int i=0;i<len2;i++){//배열2의 길이만큼 반복
        for(int j=len1+i-1;j>=pos+i;j--){//한칸씩 뒤로 이동
            *(pstr1+j+1) = *(pstr1+j);
            // printf("%c\n",*(pstr1+j));
        }
    }
    for(int i=pos;i<pos+len2;i++){//빈 공간에
        *(pstr1+i) = *(pstr2+i-pos);//배열2를 저장
    }
    printf("%s",str1);//결과값 출력
    

    
}
//공백x의 영문 문자열 str1,2와 삽입위치를 입력받은 후, str1의 해당 위치에 str2를 삽입하는 프로그램