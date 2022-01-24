#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
void ABC(int (*p)[20], int k1, int k2){//함수 정의
    //"배열의 이름”을 인자
    //k1은 인덱스의 개수, k2도 인덱스의 개수
    
    // (*(p+k1))[k2]=k1+k2;
    p[k1][k2] = k1+k2;//저장
    // printf("%d ",p[k1][k2]);
    // if((k1-k2)==1) printf("\n");

}
int main(){
    int N;
    scanf("%d",&N);//입력받을 값을 선언하고 입력받음
    int arr[20][20];//크기 20x20의 배열 선언
    int (*p)[20] = arr; //포인터 배열
  
    for(int i=0;i<N;i++){//N번반복
        for(int j=0;j<N;j++){//N번반복
            ABC(p,i,j);//함수 실행
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){//결과출력
            printf(" %d",p[i][j]);
        }
        printf("\n");
    }
}
