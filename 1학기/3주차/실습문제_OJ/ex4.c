#include<stdio.h>
int main(){

    int N,M,R;//5자리 양의 정수

    scanf("%d",&N);//입력받음
    M = N;//N값을 M에 저장한다. 그 이유는 N의 값은 바뀔예정이기 때문이다.

    M -= (M%1000); //M의 값 중 100의 자리 밑을 없앤다.

    N /=100;//N을 세자리로 만든다
    N %=10; // N의 백자리를 만든다.
    M = (N>=5?M+1000:M);// N의 백자리와 비교후 5를 기준으로 반올림한다,
    
    printf("%d",M);

    


}    