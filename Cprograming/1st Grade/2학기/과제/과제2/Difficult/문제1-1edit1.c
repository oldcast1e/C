#include  <stdio.h>
#include<string.h>
int main(){//메인함수

    char str[31],*pstr = str,tmp[30]={},*ptmp = tmp;
    char changeval,apt[10],*papt = apt;
    int N,num;

    // for(int i=0;i<20;i++) *(apt+i) = ' ';

    scanf("%s",str);scanf("%d",&N);
    for(int i=0;i<strlen(str);i++){
        if('A' <= *(pstr+i) &&  *(pstr+i)<= 'Z')*(pstr+i) += N;
        else if('a' <= *(pstr+i) &&  *(pstr+i)<= 'z')*(pstr+i) -= N;
        else if('0' <= *(pstr+i) &&  *(pstr+i)<= '9'){
            if('0' <= *(pstr+i+1) &&  *(pstr+i+1)<= '9'){
                //관찰하려는 숫자 뒤에 숫자가 있는경우 = 두자리 숫자인경우
                
                strcpy(tmp,apt);//tmp초기화
                for(int j=i+2;j<strlen(str);j++){
                    *(tmp+j-i-2) =  *(pstr+j);//tmp에 해당 요소 뒤의 뒤 요소 모두 저장
                    printf("[%d]\n",j);
                }
                printf("숫자: %c <%s>\n",*(pstr+i),tmp);

                num = 1;
                num *= (*(pstr+i)-48)*10;
                printf("(%d)\n",num);
                num += (*(pstr+i+1)-48);
                printf("(%d)\n",num);
                for(int k=0;k<N;k++) *(pstr+i+k) =  num + 64;
                //해당 숫자번째 대문자를 N번 반복저장 -> 두자리
                for(int j=i+N;j<strlen(str);j++){
                    *(pstr+j) =  *(tmp+j-i-N);
                } 
                i += N-1;
                
            }
            else{//한 자리 숫자인경우
                changeval = *(pstr+i);
                strcpy(tmp,apt);//tmp초기화
                for(int j=i+1;j<strlen(str);j++){
                    *(tmp+j-i-1) =  *(pstr+j);//tmp에 해당 요소 뒤 요소 모두 저장
                    // printf("[%d]\n",j-i);
                } 
                // printf("<%s>\n",tmp);
                for(int k=0;k<N;k++) *(pstr+i+k) =  changeval + 16;//해당 숫자번째 대문자를 N번 반복저장

                for(int j=i+N;j<strlen(str);j++){
                    *(pstr+j) =  *(tmp+j-i-N);
                    
                } 
                i += N-1;
            }


            
        }
       
        else *(pstr+i) = ' ';
    }
    printf("%s",str);
}
//문자열 A와 정수 N을 입력받아 다음의 규칙대로 문자열 A를 변경

//대문자 > 해당 대문자로부터 아스키 코드표 순서로 N번째 뒤 문자
//소문자 > 해당 소문자로부터 아스키 코드표 순서로 N번째 앞 문자
//숫자  > 해당 숫자 번째의 알파벳 대문자를 N번 반복
//그 외 > 공백으로 변경

//CLikp5tGLE?Qej15J
//ENginEErING SchOOL
