#include  <stdio.h>

int spn = 0;//줄 띄움 변수 선언

void print_line(int x,int y,int z){//print_line 함수 정의
    if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
            printf("\n");
        spn++;//줄 띄움 변수 증가
    for(int i=0;i<x;i++)//x번 만큼 반복하여
        printf(" ");//공백 출력
    for(int j=0;j<y;j++)//y번 만큼 반복하여
        printf("*");//별 출력
    for(int k=0;k<x;k++)//z번 만큼 반복하여
        printf(" ");//공백 출력
}

int main(){

    int N;//입력받을 정수값 변수
    int x,y,z;//함수에 대입할 변수 선언
    scanf("%d",&N);//정수를 입력받아
    for(int i=1;i<=N;i++){//N번 반복
        x = N-i;//공백 출력 인자
        y = 2*i-1;//별 출력 인자
        z = N-i;//공백 출력 인자
        print_line(x,y,z);//함수 실행
    }    

}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
