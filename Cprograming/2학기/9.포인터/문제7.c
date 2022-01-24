#include  <stdio.h>
void input(int *px,int *py,int *pz){//세개의 포인터를 인자로 하는 함수  선언
    scanf("%d %d %d",px,py,pz);//3개의 포인터를 입력받음
    
}
void output(int *px,int *py,int *pz){//세개의 포인터를 인자로 하는 함수  선언
    printf("%d %d %d",*px,*py,*pz);//3개의 포인터 값 출력
}
int main(){//메인 함수

    int x,y,z;//3개의 정수 선언
    int *px = &x,*py = &y,*pz = &z;//3개의 포인터를 정수형 변수와 연결
    input(px,py,pz);//input함수 실행
    output(px,py,pz);//output함수 실행


}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가
