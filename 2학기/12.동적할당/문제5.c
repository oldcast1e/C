#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){//메인함수

    int N,sum=0;
    int *score = NULL;//포인터 선언 및 초기화
    scanf("%d",&N);//입력받음

    score = (int*)malloc(N*sizeof(N));//동적할당
    if(score == NULL){//에러 발생시 종료 코드
        printf("error");
        return -1;//종료
    }

    for(int i=0;i<N;i++){//N번 반복
        scanf("%d",&score[i]);//실수를 입력받고
       
        if(i!=0){//두 번째 요소부터 반복
            if(score[i-1] > score[i]){
                int tmp;
                tmp = score[i];
                score[i] = score[i-1];
                score[i-1] = tmp;
                // 첫 번째 원소가 두 번째 원소보다 크면 서 로 교환하여 저장 
            }
            // pval = score[i];
        }
    }
    for(int i=0;i<N;i++) printf("%d\n",score[i]);//결과 출력
    free(score);//해제


}

/*
사용자로부터 정수 N을 입력받고, N개의 정수를 동적할당을 이용해 입력 받으시오.

- 그 후, 첫 번째 원소와 두 번째 원소를 비교하여 
    첫 번째 원소가 두 번째 원소보다 크면 서 로 교환하여 저장 하시오.
- 이 교환 연산(i번째 원소와 i+1번째 원소의 비교 후, 앞의 원소가 크면 교환)을 
    첫 번째 원소 부터 마지막 바로 전 원소까지 반복 하시오.
- (동적할당된) 배열에 저장된 순서대로 정수를 출력 하시오. 
- 참고: 제일 큰 수가 맨 뒤로 이동한다.

*/