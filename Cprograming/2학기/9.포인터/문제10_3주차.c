#include  <stdio.h>

void gcdlcm(int n,int m,int *pn,int *pm){//gcdlcm함수 선언
    //최소공배수는 큰 수부터 시작
    //최대공약수는 작은 수 부터 시작
    int large = (n>m?n:m),small = (n>m?m:n);//두 수중 큰수와 작은 수를 선정
    while(1){//반복문 1 - 최소공배수
        if(large%n == 0 && large%m==0) break;
        large ++;//해당 조건을 만족하지 않으면 비교할 수를 증가
    }
    while(1){//반복문 2 - 최대공약수
        if(n%small == 0 && m%small==0) break;
        small --;//해당 조건을 만족하지 않으면 비교할 수를 감소
    }
    *pm = large;//포인터에 저장
    *pn = small;//포인터에 저장

}
int main(){//메인함수

    int n,m;//입력받을 정수형 변수 선언
    int *pn = &n,*pm = &m;//포인터에 각각 연결해줌
    scanf("%d %d",&n,&m);//정수를 입력받고,
    gcdlcm(n,m,pn,pm);//함수 실행
    printf("%d %d",*pn,*pm);//결과값 출력

}