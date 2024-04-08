#include  <stdio.h>

int main(){
    char str1[40],str2[40],rst[50]={0},tmp[20];//두개의 배열과 결과를 저장할 배열 선언
    char *pstr1 = str1,*pstr2 = str2,*prst = rst;//두개의 배열과 결과저장 배열을 포인터로 연결
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
    if(pos == 0){
        for(int i=0;i<len2;i++){//삽입위치 만큼
            *(prst+i) = *(pstr2+i);//배열1을 결과값에 저장
        }
        for(int i=len2;i<len1+len2;i++){//삽입위치 만큼
            *(prst+i) = *(pstr1+i-len2);//배열1을 결과값에 저장
        }
        printf("%s",rst);//결과값 출력
    }
    else{

        for(int i=0;i<pos;i++){//삽입위치 만큼
            *(prst+i) = *(pstr1+i);//배열1을 결과값에 저장
        }
        for(int i=pos;i<pos+len2;i++){//삽입위치부터 배열2 저장
            *(prst+i) = *(pstr2-pos+i);
        }
        for(int i=pos+len2;i<len2+len1;i++){//삽입위치+배열2 부터 나머지값 저장
            *(prst+i) = *(pstr1+i-pos-1);
        }
        printf("%s",rst);//결과값 출력
    }
}
//공백x의 영문 문자열 str1,2와 삽입위치를 입력받은 후, str1의 해당 위치에 str2를 삽입하는 프로그램