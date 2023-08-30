#include  <stdio.h>

int func1(int x){//func1함수 정의

    int rst;//결과값을 저장할 rst 변수 선언
    rst = 2*x*x-5*x+1;//2x^2-5x+1 라는 함수에 대입한 값을 rst에 저장

    return rst;//rst 값을 반환
}
int main(){
    
    int n,R;//입력받을n값과 결과값 R선언
    scanf("%d",&n);//n을 입력받고
    R = func1(n);//func1함수 실행
    printf("%d",R);//결과값 출력

}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
