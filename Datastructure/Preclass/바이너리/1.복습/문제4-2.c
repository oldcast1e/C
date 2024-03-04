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
    int len  = strlen(str),cnt=0;
    char *tmp = (char *)malloc(sizeof(char)*len + 1);
    for(int i=0;i<len;i++){
        for(int k=i;k<len;k++) tmp[k-i] = str[k];
        //입력된 문자열의 뒷부분을 tmp의 앞부분으로 이동
        for(int j=len-i;j<len;j++) tmp[j]  = str[j - len + i];
        //입력된 문자열의 앞부분을 tmp의 뒷부분으로 이동
        puts(tmp);
    }
    
}