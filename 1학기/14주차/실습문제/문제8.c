#include  <stdio.h>
void swap(int *p1,int *p2){//swap함수 선언

    int tmp = *p1;//임의의 값 tmp에 *p1을 저장
    *p1 = *p2;//*p1에 *p2저장
    *p2 = tmp; //*p2에 다시 tmp저장

}

int main(){//메인함수
    
    int N,a,b;//3개의 정수형 변수 선언
    int num[50];//크기 50의 배열 선언
    scanf("%d",&N);//N의 입력받음
    for(int i=0;i<N;i++){//N번 반복하여
        scanf("%d",&num[i]);//배열에 입력값 저장
    }
    scanf("%d %d",&a,&b);//a,b입력받음
    int *p1 = &num[a];//p1에 num[a] 주소를 저장할 포인터 선언
    int *p2 = &num[b];//p2에 num[b] 주소를 저장할 포인터 선언

    swap(p1, p2);//swap함수 실행
    for(int i=0;i<N;i++){//N번 반복하여
        printf(" %d",num[i]);//해당 요솟값 출력
    }

}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

