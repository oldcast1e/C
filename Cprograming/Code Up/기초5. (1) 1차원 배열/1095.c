#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n, i,min=23;
    int a[10000]={};
    scanf("%d", &n); //개수 입력 받기
    for(i=1; i<=n; i++) {
        scanf("%d", &a[i]); //읽어서 순서대로 배열에 넣는다.
        min = a[i]<min?a[i]:min;
    }printf("%d",min);
    } 
/*

*/