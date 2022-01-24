#include  <stdio.h>

int func1(int x,int a,int b,int c){//func1함수 정의

    int rst1;//결과를 저장할 변수 rst1 선언
    rst1 = a*x*x + b*x + c;// ax^2 + bx + c 를 계산한 값 저장
    
    return rst1;//rst1값 반환
}

int func2(int k,int A,int B,int C){//func1함수 정의

    int rst2;//결과를 저장할 변수 rst2 선언
    rst2 = A*k*k+B*k+C;// Ak^2 + Bk + C 를 계산한 값 저장
    
    return rst2;//rst2값 반환
}


int main(){
    
    int x,a,b,c,A,B,C,k,R;//] 하나의 정수 x와 2차 함수 f(x)의 계수를 나타내는 3개의 정수를 입력 받음
    scanf("%d",&x);//x을 입력받음
    scanf("%d %d %d",&a,&b,&c);//3개의 계수를 입력받음
    scanf("%d %d %d",&A,&B,&C);//3개의 계수를 입력받음
    k = func1(x,a,b,c);//함수1를 실행하고 결과값을 k에 저장
    R = func2(k,A,B,C);//함수2를 실행하고 결과값을 R에 저장
    printf("%d",R);//결과값 출력
    


}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
