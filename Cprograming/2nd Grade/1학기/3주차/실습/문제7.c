#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
[ 문제 7 ] 공백 없는 영어 문자열 하나를 입력받아, 
특정 문자가 몇 번 나타나는 지 검사하는 프 로그램을 작성하시오.

◦ 문자열의 길이는 최대 100이고, 문자 검사 시 대소문자를 구별한다.
*/

int count(char *arr,char ipt, int len, int *psum){
    if(len >= 0){
        if(arr[len] == ipt) {
            *psum += 1;
            // printf("%d -> %c\n",len,arr[len]);
        }
        len --;
        return count(arr,ipt,len,psum);
    }
    return *psum;
}
int main(){
    char ipt;
    int sum  = 0,*psum = &sum;
    char *arr = (char *)malloc(sizeof(char)*101);
    scanf("%s",arr);getchar();
    
    scanf("%c",&ipt);
    int len  = (int)strlen(arr) - 1;
    printf("%d",count(arr,ipt,len,psum));
} 
/*
sheIsAStudent
s
*/