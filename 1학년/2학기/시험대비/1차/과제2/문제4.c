#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

int s_check(char *p, char *q){
    int rst =0;
    char *i;

    for(i =p;i<q;i++){
        if('a'<= *i && *i<= 'z') rst++;
    }
    return rst;

}

int main(){
    int M,K1,K2,rst;
    char str[201];

    scanf("%d",&M);
    scanf("%d %d",&K1,&K2);

    for(int i=0;i<M;i++){
        strcpy(str,"\0");
        getchar();
        gets(str);
        rst = s_check((str+K1),(str+K2));
        if(rst!=0) printf("%d\n",rst);

    }


}
/*
- 정수 M과 K1, K2를 입력받고, 공백이 포함된 M개의 문자열을 입력받는다. 
M ≦ 10 - 알파벳 소문자의 개수를 출력하는 함수는 s_check 함수를 사용한다.
- 표준 문자열 처리함수는 strlen을 사용한다.
- 입력받는 문자열 M의 크기는 최대 200이다.
- 소문자 개수가 0이면 출력에서 제외한다.

3
2 9
Clanguagesnteres ting 
CCC CCCC
LanguageC

*/