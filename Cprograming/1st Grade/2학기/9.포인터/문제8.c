#include  <stdio.h>
void swap(int *a,int *b){//두개의 포인터를 인자로 하는 함수 선언
    int tmp;//임의의 값을 저장할 변수 tmp선언
    tmp = *a;//인자로 받은 포인터의 값을 tmp에 저장
    *a = *b;//b의 포인터 참조를 a에 덮어씌움 
    *b = tmp; //b에 a를 저장한 값을 저장
}
int main(){//메인 함수
    int N,arr[50]={0},a,b;//3개의 정수형 변수와 크기 50의 배열 선언
    int *parr  = arr;//포인터를 배열에 연결
    scanf("%d",&N);//정수를 입력받아
    for(int i=0;i<N;i++){//입력받은 정수만큼 반복
        scanf("%d",(parr+i));//배열에 저장할 값을 입력받음
    }
    scanf("%d %d",&a,&b);//두개의 정수를 입력받고
    swap((parr+a),(parr+b));//스왑 함수를 실행 = 값 교환
    for(int i=0;i<N;i++){//n번 반복하여
        printf("%d ",*(parr+i));//결과 출력
    }
}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

//n개의 정수를 입력받아 배열에 저장한 후(50개 까지)
// 다시 배열에 값을 교환하고 싶은 서로 다른 첨자 a와b를 입력받는다