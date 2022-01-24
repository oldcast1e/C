#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){//메인함수

    int N,rst=0;
    char *score = NULL;//포인터 선언 및 초기화
    scanf("%d",&N);//입력받음
    getchar();

    score = (char*)malloc(N*sizeof(N));//동적할당
    if(score == NULL){//에러 발생시 종료 코드
        printf("error");
        return -1;//종료
    }

    for(int i=0;i<N;i++){//N번 반복
        scanf("%c",&score[i]);//실수를 입력받고
    }
    for(int i=0;i<N;i++){//N번 반복
        if(score[i]=='c')
            if(score[i+1]=='a')
                if(score[i+2]=='t') rst ++;//cat이 입력된 걸 확인하면 rst 1 증가
    }

    printf("%d",rst);//결과 출력
    free(score);//해제


}

