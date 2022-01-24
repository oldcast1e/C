#include  <stdio.h>
#include<string.h>
int main(){

    char A[20],*pa  = A;
    int N,cnt;
    scanf("%s",A);
    scanf("%d",&N);
    for(int i=0;i<strlen(A);i++){
        if('A'<= *(pa+i) && *(pa+i)<='Z'){
            *(pa+i) += N;
            if(*(pa+i)>= '[') *(pa+i) = 'a'+N-1;
        }
        else if('a'<= *(pa+i) && *(pa+i)<='z'){
            *(pa+i) -= N;
            if(*(pa+i)<= 96) *(pa+i) = 'z'-N+1;
    
        }

        else if(('1'<= *(pa+i) && *(pa+i)<='9')){
            for(int j=0;j<N;j++);
        }
        else printf(" ");
    }
    printf("%s",A);



}
//문자열 A와 정수 N을 입력받아 다음의 규칙대로 문자열 A를 변경

//대문자 > 해당 대문자로부터 아스키 코드표 순서로 N번째 뒤 문자
//소문자 > 해당 소문자로부터 아스키 코드표 순서로 N번째 앞 문자
//숫자  > 해당 숫자 번째의 알파벳 대문자를 N번 반복
//그 외 > 공백으로 변경