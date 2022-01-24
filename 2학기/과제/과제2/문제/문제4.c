#include  <stdio.h>
#include  <string.h>
int s_cneck(char *p,char *q){//p = str || q = strlen(str)
    char *i;
    int rst = 0;;a
    for(i = p+1;i<=q+1;i++){
        if('a'<= *i && *i <= 'z') rst ++;
    }
    return rst;
}
int main(){
    int M,K1,K2,result;
    char str[100];
    scanf("%d",&M);

    scanf("%d",&K1);
    scanf("%d",&K2);
    getchar();
    for(int i=0;i<M;i++){
        gets(str);
        str[strlen(str)] = 'A';
        str[strlen(str)+1] = '\0';
        result = (int)s_cneck(str+K1-1,str+K2-1);
        if(result!=0) printf("%d\n",result);
    }


}
//공백을 포함하는 M개의 문자열을 입력받고, ILil
//각 문자열의 K1번째 문자부터 K2문자까지의 문자중에 알파벳 소문자의 개수를 세 출력하라.
// - 입력받는 문자열 M의 크기는 최대 200이다.
// - 소문자 개수가 0이면 출력에서 제외한다.
//=> 0번째도 있다고 가정한다.

//정수 M과 K1, K2를 입력받고, 공백이 포함된 M개의 문자열을 입력받는다. (M ≦ 10)

//알파벳 소문자의 개수를 출력하는 함수는 s_check 함수를 사용한다.

//  표준 문자열 처리함수는 strlen을 사용한다.
