#include  <stdio.h>

int func2(int x,int a,int b,int c){//func1함수 정의

    int rst;//결과를 저장할 변수 rst 선언
    rst = a*x*x + b*x + c;// ax2 + bx + c 를 계산한 값 저장
    return rst;//rst값 반환
}
int main(){
    
    int x,a,b,c,R;//] 하나의 정수 x와 2차 함수 f(x)의 계수를 나타내는 3개의 정수를 입력 받음
    scanf("%d",&x);//x을 입력받음
    scanf("%d %d %d",&a,&b,&c);//3개의 계수를 입력받음
    R = func2(x,a,b,c);//함수를 실행하고 결과값을 R에 저장
    printf("%d",R);//결과값 출력
    


}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
