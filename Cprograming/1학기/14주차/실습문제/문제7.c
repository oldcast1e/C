#include  <stdio.h>

void input(int *px,int *py,int *pz){//input함수 정의
    scanf("%d %d %d",px,py,pz);//3개의 포인터값을 받음
}

void output(int *px,int *py,int *pz){//output함수 정의
    printf("%d %d %d",*px,*py,*pz);//3개의 포인턱밧을 출력
}

int main(){
    
    int x, y, z;//3개의 정수형 변수 선언
    int *px = &x,*py = &y,*pz = &z;//3개의 포인터 선언
    input(px,py,pz);//input함수 실행
    output(px,py,pz);//output함수 실행
}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

