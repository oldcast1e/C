#include  <stdio.h>

void print_triangle(int x){//print_triangle함수 정의

    int cnt = 1,spn=0;//반복 증가 변수 cnt와 줄바꿈 변수 spn 선언
    for(int i=0;i<x;i++){//입력받은 x만큼 반복하여(열)
        if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
            printf("\n");
        spn++;//줄 띄움 변수 증가

        for(int j=0;j<cnt;j++){//cnt만큼 반복하여
            printf("*");//*을 출력
        }
        cnt++;//cnt증가(별을 출력하는 횟수를 증가시키기 위함)
    }

}

int main(){//main함수
    
    int n,spn2=0;//입력받을 n과 줄띄움 변수 spn2선언
    while(1){//무한 루프
        scanf("%d",&n);//n을 입력받음
        if(n<=0)//n이 0이나 음수인 경우
            break;//종료(종료조건)
        if(spn2!=0)////첫번째 줄이 아니면 줄을 띄움
            printf("\n");
        spn2++;//줄 띄움 변수 증가
        print_triangle(n);//print_triangle함수 실행
        

        

    }
  
    
}


