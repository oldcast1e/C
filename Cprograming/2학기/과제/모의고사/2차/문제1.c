#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
void input(int *p, int N){//input함수 선언
    for(int *i = p;i< p+N;i++){//주소 이용 반복
        scanf(" %d",i);
        //반복문으로 배열을 훑어볼 시, 주소를 이용하여 반복문을 구현
    }

}
void output(int *p, int K){//output함수 선언
    for(int *i = p;i< p+K;i++){//주소 이용 반복
        printf(" %d",*i);
        //반복문으로 배열을 훑어볼 시, 주소를 이용하여 반복문을 구현
    }
}
// void reset(int *num){
//     for(int i=0;i<100;i++) *(num+i) = NULL;
// }
int main(){
    int M,N,K;//입력받을 정수값
    int X[100],Y[100],*px = X,*py = Y;//베열 선언 및 포인터 연결
    scanf("%d %d",&M,&N);//입력
    input(px,M);input(py,N);//함수 실행
    scanf("%d",&K);
    //정수 K를 입력받아, X와 Y에 저장된 정수를 K개씩 번갈아가며 출력

    for(int i=0;i<100;i+=K){
        if(M>i)output((px+i),K);////함수 실행
        if(N>i)output((py+i),K);//함수 실행
    }

}
/**
정수 M과 N을 입력 받은 후, 
M개의 정수를 입력받아 배열 X에, N개의 정수를 입력받 아 배열 Y에 저장 한다. 

다음, 정수 K를 입력받아, X와 Y에 저장된 정수를 K개씩 번갈아가며 출력 하는 프로그램

단, M과 N은 100보다 작은 K의 배수이며, X에 저장된 정수부터 K개씩 출력한다.
- input과 output 함수에서 반복문으로 배열을 훑어볼 시, 주소를 이용하여 반복문을 구현한다. 

즉, 포인터가 배열의 각 원소를 순차적으로 가리키도록 하며, 
포인터가 가리키는 위치의 원 소에 대해 필요한 작업을 수행한다. 
단, main 함수에서의 주소 표현 방식은 제한 사항 없음.

4 8 
1 2 3 4
5 6 7 8 9 10 11 12
2

6 3
1 2 3 4 5 6
7 8 9
3
 */