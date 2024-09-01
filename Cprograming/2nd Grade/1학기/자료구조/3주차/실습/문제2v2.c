#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*

[ 문제 2 ] 양의 정수를 입력 받아,
 각 자리의 수를 높은 자릿수부터 차례로 출력하는 
 프로그램을 작성하시오.
*/
int arr[100];
void printDigits(int n){
    if(n>0){
        int tmp=n,cnt = 0;
        while(tmp>0){tmp/=10;cnt++;}
        arr[cnt-1] = n%10; n/=10;
        // printDigitsf("cnt = %d | arr[%d] = %d\n",cnt,cnt-1,arr[cnt-1]);
        printDigits(n);
    }

}
int main(){
    int n,tmp,cnt = 0; 
    scanf("%d",&n); 
    tmp = n;
    while(tmp>0){tmp/=10;cnt++;}
    printDigits(n);
    for(int i=0;i<cnt;i++)printf("%d\n",arr[i]);

    

    
} 
/*
int 범위의 정수가 입력된다고 가정하고, %d를 이용하여 입력받아 저장할 것 
(%c 또는 %s 사용 금지)
◦ 다음 예에서 보여주는 재귀 관계를 이용하시오. (재귀 함수 사용).
- 예1: 3408의 자릿수 출력 ⇒ 340의 자리수를 출력하고, 일의 자릿수 8 출력
- 예2: 1234567의 자릿수 출력 ⇒ 123456의 자리수를 출력하고, 일의 자릿수 7 출력
도움말: 3408이 주어졌을 때, 340과 8을 구하기 위해 어떤 연산자를 사용해야 할지 생각해보자.

*/