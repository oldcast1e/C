#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n, i;
    int a[10000]={};
    scanf("%d", &n); //개수 입력 받기
    for(i=1; i<=n; i++) //개수 만큼 입력 받기
    scanf("%d", &a[i]); //읽어서 순서대로 배열에 넣는다.

    for(i=n; i>=1; i--)
    printf("%d ", a[i]); //i 번 배열에 저장되어 있는 값 출력하기
    } 
/*

*/