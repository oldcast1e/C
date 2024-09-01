/*
[ 문제 7 ] 공백 없는 영어 문자열 하나를 입력받아, 
특정 문자가 몇 번 나타나는 지 검사하는 프 로그램을 작성하시오.
◦ 문자열의 길이는 최대 100이고, 문자 검사 시 대소문자를 구별한다.*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int rst = 0;
void check(char *arr, int n, char *ipt){
    if(n > 0){
        if(arr[n] == *ipt) {rst ++;}
        n--; check(arr,n,ipt);
    }
}

int main(){    
    char arr[100],ipt,c; scanf("%s",arr); scanf("%c",&c);
    scanf("%c",&ipt);
    int len = (int)strlen(arr);
    check(&arr[0],len-1,&ipt);//문자열 길이 len을 인덱스로하고 하나씩 줄이자
    printf("%d",rst);
    
} 
/*
SheIsAStudent
s
*/