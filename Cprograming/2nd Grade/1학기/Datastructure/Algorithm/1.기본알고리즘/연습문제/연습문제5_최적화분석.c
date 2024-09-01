#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//세 정수의 중앙값을 찾는 최적화된 알고리즘
int centerval(int a,int b,int c){
    int rst;
    //1번째 조건문 : 최대 4번
    if(a>=b){//a와 b를 비교하여 a가 더 큰 경우
        if(b>=c) return b;
        //a > b > c -> 중앙값은 b이다.
        else if(a <=c) return a;
        //c > a > b
        else return c;
    }
    //2번째 조건문: 최대 2번
    else if(a>c) return a;//1번째 조건문을 불만족 == a보다 b가 더크다
    /**
    2번째 조건문 ->a보다 b가 더 클 때, a가 c보다 큰 경우
    따라서 중앙값은 a이다.
    >>b > a > c 
     */

    //3번째 조건문: 최대 3번
    else if(b > c) return c;//1번째 조건문과 2번째 조건문을 불만족 => a보다 b가 더크고 c가 a보다 더 크다
    /**
    3번째 조건문에 따라 a보다 b가 더크고 c가 a보다 더 크면서 b가 c보다 크다
    >> b > c > a 따라서 중앙값은 c
     */
    else return b; //모든 경우의 수를 제외하면 남는 것은 b이다.
    //최대 4번

}
int main(){//최대 4번안에 결과값 도출
    
    int a,b,c;
    printf("세 정수의 중앙값을 구합니다.\n");
    printf("a의 값: ");scanf("%d",&a);
    printf("b의 값: ");scanf("%d",&b);
    printf("c의 값: ");scanf("%d",&c);

    int rst = centerval(a,b,c);
    printf("결과값: %d",rst);

}
