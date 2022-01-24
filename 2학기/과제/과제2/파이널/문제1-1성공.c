#include  <stdio.h>
#include<string.h>
int main(){//메인함수

    char A[1000],*pa  = A;//크기 20의 배열 정의 및 포인터 연결
    char rst[1000];
    int N,cnt,len=0,numcnt = 0;;//입력받을 정수와 배열의 길이 임의의 정수 저장 변수 정의
    
    for(int i=0;i<21;i++){//20번 반복
        scanf("%c",(pa+i));//해당 요소를 입력받고
        if(*(pa+i)=='\n') break;//엔터가 입력되면 종료
        len ++;//길이 증가
    }
    scanf("%d",&N);//정수를 입력받음
    for(int i=0;i<strlen(A);i++){//배열의 길이만큼 반복
        if('A'<= *(pa+i) && *(pa+i)<='Z'){//대문자이면
            *(pa+i) += N;//해당 요소에 N을 더함
            rst[numcnt] = *(pa+i); numcnt++;//결과배열에 저장
        }
        else if('a'<= *(pa+i) && *(pa+i)<='z'){//소문자이먄
            *(pa+i) -= N;//해당 요소에 N을 뺌
            rst[numcnt] = *(pa+i); numcnt++;//결과배열에 저장
        }

        else if(('0'<= *(pa+i) && *(pa+i)<='9')){//숫자면

            if('0'<= *(pa+i+1)&& *(pa+i+1)<='9'){//십의 자리
               cnt = (*(pa+i) - 48)*10 + *(pa+i+1)-48;//정수화
               *(pa+i+1) = -1;//다음 숫자를 -1로
            //    printf("\ncnt = %d\n",cnt);
               for(int j= 0;j<N;j++){//N번 반복하여ㅕ
                //    printf("%c",cnt+64);//출력
                   rst[numcnt] = cnt+64; numcnt++;//결과배열에 저장
               }
            }
            else{//일의 '자리
                // printf("  --  ");
               for(int j= 0;j<N;j++){//N번 반복
                //    printf("%c",*(pa+i)+16);//출력
                   rst[numcnt] = *(pa+i)+16; numcnt++;//결과배열에 저장
               }
            }
        }
        else if(*(pa+i)!= -1){
            rst[numcnt] = ' '; numcnt++;//결과배열에 공백 저장
            // printf(" ");
        } 
    }
    // printf("numcnt = %d\n",numcnt);
    rst[numcnt-1] = '\0';//결과값 마지막 요소 앞에 널 문자 저장 = 출력 위함
    strcpy(A,rst);//배열 A에 대입
    printf("%s",A);//배열 A 출력
    // for(int i=0;;i++){
    //     if(rst[i]=='\0') break;
    //     printf("%c",rst[i]);
    // }
}
//문자열 A와 정수 N을 입력받아 다음의 규칙대로 문자열 A를 변경

//대문자 > 해당 대문자로부터 아스키 코드표 순서로 N번째 뒤 문자
//소문자 > 해당 소문자로부터 아스키 코드표 순서로 N번째 앞 문자
//숫자  > 해당 숫자 번째의 알파벳 대문자를 N번 반복
//그 외 > 공백으로 변경

//CLikp5tGLE?Qej15J
//ENginEErING SchOOL 
