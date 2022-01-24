#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int add(int a, int b){return a+b;}
int main(){

    int A,n,m;//입력받을 정수형 변수 정의
    int (*fp)(int, int);//함수 포인터 선언
    scanf("%d",&A);//입력받기(1)
    void *pa = &A;//void포인터 연결
    //void 포인터를 사용하여 int형 변수에 담긴 값을 화면에 출력한다.
    
    printf("%d\n",*(int*)pa);//결과 출력
    //void 포인터를 int형 포인터로 형변환 한 후, 역참조연산자 * 를 사용

    fp = add;//함수포인터 연결
    scanf("%d %d",&n,&m);//정수형 변수 입력받기(2)
    printf("%d",fp(n,m));//결과출력

}