#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
void calculate(int *pn,int *pm){//함수 정의
    // printf("n = %d| m= %d\n",*pn,*pm);

    if(*pn > *pm){*pn -= *pm;calculate(pn,pm);}// 유클리드 호제법으로 최대공약수 계산
    else if(*pn < *pm){ *pm -= *pn; calculate(pn,pm);}
    else{}//두 포인터의 값이 똑같으면 재귀함수를 부르지 않음

}

int main(){

    int n,m,*pn = &n,*pm = &m;//두변수와
    //함수에서 값을 바꿔야하므로 포인터에 연결
    scanf("%d %d",&n,&m);//두 변수를 입력받고
    calculate(pn,pm);//함수 실행
    // print(">%d",rst);
    // printf("%d",calculate(n,m));
    printf("%d",n);//결과출력
}
//두 개의 양의 정수를 입력받고, 
//이 두 정수의 최대공약수를 출력하는 프로그램을 작성하시오. 반드시 재귀함수를 사용하시오.