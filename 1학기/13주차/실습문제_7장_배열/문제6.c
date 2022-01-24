#include  <stdio.h>
int prt( int x[ ][5], int N);//함수 원형 선언
int main(){//메인 함수
    
    int N;//입력받을 정수 N선언
    scanf("%d",&N);//입력받음
    int num[20][5];//배열 초기화

    for(int i=0;i<N;i++){//N번 반복하여(열)
        for(int j=0;j<5;j++){//5번 반복(행)
            scanf("%d",&num[i][j]);//배열에 저장
        }
    }
    prt(num,N);//함수 실행

}

int prt( int x[ ][5], int N){//함수 정의
    //printf("00000 %d ",N);
    int spn = 0;//줄뜨ㅣ움 변수
    for(int i=N-1;i>=0;i--){//마지막 부터
        if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
        spn ++;//줄 띄움 변수 증가

        for(int j=0;j<5;j++){//5번 반복하여
            printf("%d ",x[i][j]);//해당 열의 요소 출력
        }
        
    }
    return 0;//0반환
}


