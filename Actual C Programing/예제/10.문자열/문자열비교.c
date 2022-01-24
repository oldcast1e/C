#include  <stdio.h>
#include <string.h>
int main(){
    char arr[40] = "Sejong Univ";
    char carr[40] = "Ime 21011898";
    
    int rst = strcmp(arr,carr);
    printf("result: %d\n",rst);
    printf(rst>0?"문자열 A가 사전순으로 먼저입니다":"문자열 A가 사전순으로 먼저입니다");
}