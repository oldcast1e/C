#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/**
사용자로부터 공백을 포함하지 않는 문자열을 하나 입력 받아 
예제와 같이 왼쪽으로 한 칸씩 shift하여 출력하는 프로그램을 작성 하시오.

◦입력 받는 문자열 길이는 최대 100 이다.
◦ 출력 시 반복문을 사용하지 않고 문자열 출력(%s)을 사용하시오. 문자 출력(%c) 사용금지
 */
int main(){
    char str[100];gets(str);
    int len  = strlen(str);
    char *tmp = (char *)malloc(sizeof(char)*len + 1);
    for(int i=0;i<len;i++){
        for(int j=i;j<len;j++) tmp[j-i] = str[j];//앞
        for(int k=i;k>=0;k--){ tmp[len-k-1] = str[i-k];}
        //뒤
        // for(int k= 0;k<i;k++) tmp[i] = str[k];
        /**
        i = 0인경우: 0 1 2 3 4 -> 0 1 2 3 4
        i = 1인경우: 1 2 3 4   -> 0 1 2 3
        i = 2인경우: 2 3 4     -> 1 2 3
        i = 3인경우: 3 4       -> 
        i = 4인경우: 4

abcde

abcde
bcde e
cde  ee
de   eee
e    eeee
         */
        // for(int k=0;k<i;k++)tmp[len - k] = str[k];
        // strcpy(str,tmp);
        puts(tmp);
    }



}