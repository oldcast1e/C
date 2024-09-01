#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/**
[ 문제 7 ] 공백 없는 영어 문자열 하나를 입력받아, 
특정 문자가 몇 번 나타나는 지 검사하는 프로그램을 작성하시오.

◦ 문자열의 길이는 최대 100이고, 문자 검사 시 대소문자를 구별한다.

 첫 번째 문자가 's' 인지의 여부와 두 번째 문자 이후에서 나타나는 's'의 개수를 이용하여 계산
 */

void check(char *str,char let,int *prst){
    if(str[0] == '\0') return;
    else{
        if(str[0] == let) *prst +=1 ;
        str++;
        check(str,let,prst);
    }
}
int main(){
    char str[101],let; 
    int len,rst = 0,*prst = &rst;
    gets(str);scanf("%c",&let);
    check(str,let,prst);
    printf("%d",*prst);
}