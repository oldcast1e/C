#include  <stdio.h>
int main(){
    
    int f,r,m,x;//입력받을 변수와 마지막 값 저장 변수 x 선언
    //2  8  4
    int A[20]={0,};//20개의 숫자를 저장할 배열 선언
    scanf("%d %d %d",&f,&r,&m);//숫자를 입력받음

    for(int i=1;i<=20;i++){//20번 반복하여
        A[i-1] = i;//배열 A에 1~20까지 저장
    }

    x = A[r];//x에 마지막 값 저장
    for(int i=1;i<=r-m;i++){//4번반복
        if(i!=(r-m))//4가 아닌 경우
            A[r-i+1] = A[r-i];//전 값을 앞값에 대입
        else//4인 경우
            A[r-m+1]= x;//맨 앞값에 맨 뒷값을 대입
        
    }

    for(int i=0;i<20;i++){//결과값 출력
        printf("%d ",A[i]);
    }

    

}
