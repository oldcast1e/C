#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
[ 문제 7 ] 공백 없는 영어 문자열 하나를 입력받아, 
특정 문자가 몇 번 나타나는 지 검사하는 프 로그램을 작성하시오.

◦ 문자열의 길이는 최대 100이고, 문자 검사 시 대소문자를 구별한다.
*/
char arr[101];
int sum  = 0;
int count(char ipt, int len){
    if(len >= 0){
        if(arr[len] == ipt) {
            sum += 1;
            // printf("%d -> %c\n",len,arr[len]);
        }
        len --;
        return count(ipt,len);
    }
    return sum;
}
int main(){
    char ipt;
    scanf("%s",arr);getchar();scanf("%c",&ipt);
    int len  = (int)strlen(arr) - 1;
    printf("%d",count(ipt,len));
} 
/*
sheIsAStudent
s
*/