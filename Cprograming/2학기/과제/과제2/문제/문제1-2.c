#include  <stdio.h>
#include<string.h>

int changearr(int *arr,int *rstarr){

    
}
int main(){

    char A[20],B[20],*pa  = A,*pb = B;
    int N,cnt;
    scanf("%s",A);
    scanf("%s",B);
    
    for(int i=0;i<strlen(A);i++){
        if('A'<= *(pa+i) && *(pa+i)<='Z'){
            *(pa+i) += N;
            if(*(pa+i)>= '[') *(pa+i) = 'a'+N-1;
            // printf("%c",*(pa+i));
        }
        else if('a'<= *(pa+i) && *(pa+i)<='z'){
            *(pa+i) -= N;
            if(*(pa+i)<= 96) *(pa+i) = 'z'-N+1;
            // printf("%c",*(pa+i));
        }

        else if(('1'<= *(pa+i) && *(pa+i)<='9')){
            if('1'<= *(pa+i+1)&& *(pa+i+1)<='9'){//십의 자리
               cnt = (*(pa+i) - 48)*10 + *(pa+i+1)-48;

               *(pa+i+1) = -1;
            //    printf("\ncnt = %d\n",cnt);
               for(int j= 0;j<N;j++){
                   printf("%c",cnt+64);
               }
            }
            else{//일의 자리
                // printf("  --  ");
               for(int j= 0;j<N;j++){
                   printf("%c",*(pa+i)+16);
               }
            }
        }
        else if(*(pa+i)!= -1) printf(" ");
    }
    // printf("%s",A);



}
//문자열 A와 정수 N을 입력받아 다음의 규칙대로 문자열 A를 변경

//대문자 > 해당 대문자로부터 아스키 코드표 순서로 N번째 뒤 문자
//소문자 > 해당 소문자로부터 아스키 코드표 순서로 N번째 앞 문자
//숫자  > 해당 숫자 번째의 알파벳 대문자를 N번 반복
//그 외 > 공백으로 변경

// 문자열의 길이는 최대 20이다.
// - 정수 1≦N≦10 이다.
// - 문자열 A에 존재하는 숫자는 0보다 크고 27보다 작다.

//CLikp5tGLE?Qej15J
//두 개의 문자열(A, B)을 입력받아 위의 
//[문제 1-1] 규칙대로 A→B 또 는 B→A로 변경할 수 있는지 확인하시오.

//- 변경불가능하면 0
//A→B로 변경가능하면 1
//B→A로 변경가능하면 2를 출력하시오. 

//- (설명) 즉, 정수 N을 이용하여 A→B로 변경가능하면 1을 출력한다.