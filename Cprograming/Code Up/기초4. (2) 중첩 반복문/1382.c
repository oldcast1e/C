#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	

    for(int i=1;i<=9;i++){
        for(int j=2;j<=5;j++) printf("%d x %d = %d\t",i,j,i*j); printf("\n");
    }//printf("%d",rst);
 
} 
/*
구구단의 2~5단을 문제 설명에서 보여준 출력 양식대로 출력한다.

표현 오류가 날 가능성이 높으므로 다음 조건들을 잘 확인하여 작성한다.

1. 연산자와 피연산자 사이에는 공백이 한칸 존재한다. 곱셈 기호는 소문자 x이다.
2. 곱셈의 결과는 두 칸으로 봤을 때 우측 정렬하여 출력한다. (%2d)
3. 단과 단 사이에는 탭(\t)으로 분리한다. 한칸 아님.
4. 각 행의 마지막인 5단의 곱셈 결과를 출력한 후 공백없이 바로 줄을 바꾼다(\n).
*/