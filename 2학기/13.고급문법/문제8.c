#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int add(int n, int m){return (n+m);}//더하기
int sub(int n, int m){return (n-m);}//빼기
int multiply(int n, int m){return (n*m);}//곱하기
int main(){

    int x,y;
    scanf("%d %d",&x,&y);//정수형 변수 입력받기
    int (*handle[3]) (int, int) = { add, sub, multiply };
    // handle[0] = add;
    //함수 포인터 배열의 각 원소와 1)에서 정의한 각 함수와 연결
    for(int i=0;i<3;i++)printf("%d ",handle[i](x,y));//결과출력
}
    