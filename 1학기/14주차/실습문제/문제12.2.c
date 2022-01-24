#include <stdio.h>
void addArray(int* a, int* b, int* c, int n)//addArray 함수 정의
{
    int* p;//임의의 포인터 선언
 
    for (p = c; p < c + n; p++) {//c부터 c+n까지
 
        *p = *a + *(b+n-1);//포인터에 역방향으로 더함
        a++;
        b--;//값 조율
 
    }
}

int main() {//메인함수
    int N;//입력받을 정수 선언
    
    int A[20],B[20],R[20]={0};//3개의 배열 선언
    int* a, * b, * c, *p1;//3개의 포인터와 임의 포인터 p1

    scanf("%d", &N);//N을 입력받고
    for (a = A; a < A + N; a++) {//1차 배열에 값 저장
        scanf("%d", a);
    }
    for (b = B; b < B + N; b++) {//2차 배열에 값 저장
        scanf("%d", b);
    }
    c = R;//반복에 사용하기 위해 C에 R저장
    addArray(A, B, R, N);//함수 실행ㅇ
 
    for (p1=R;p1<R+N;p1++){//반복하여
        printf(" %d",*p1);//결과값 출력
    }
  
}
 

