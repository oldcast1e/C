#include  <stdio.h>
int arrsum( int x[ ], int S, int E);//함수 재확인

int main(){//메인 함수
    
    int N,S,E;//입력받을 3개의 값 선언
    int result;//결과값
    int num[100];//크기 100의 정수형 배열 선언
    scanf("%d %d %d",&N,&S,&E);//3개의 정수 입력받음
    for(int i=0;i<N;i++){//N번 반복하여 정수를 입력받음
        scanf("%d",&num[i]);//배열에 저장
    }
    result = arrsum(num, S, E);//함수 실행하여 리턴값을 result에 저장
    printf("%d",result);//결과값 출력


}

int arrsum( int x[ ], int S, int E){//함수 선언

    int sum = 0;//정수의 합
    for(int i=S;i<=E;i++){//S부터 E까지 반복(인덱스)
        sum += x[i];//합 변수에 더함
    }

    return sum;//sum 반환
}

//if(spn!=0) printf("\n");
//spn ++;

