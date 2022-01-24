#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){//메인함수

    int N,M;//열 행
    int cnt = 0,key = 0;//조건 겂
    char rst = 'a';//출력 초기 값

    scanf("%d %d",&N,&M);//입력받음
    // printf("%d %d\n",N,M);
    getchar();
    

    char **arr = NULL;
    arr = (char**) malloc ( sizeof(char*) * M );//동적할당
    for(int i=0; i<M; i++){//2차원 배열 동적할당
        arr[i] = (char*) malloc ( sizeof(char) * N );
    }

    for(int i=0;i<M;i++){//N번 반복
        for(int j=0;j<N;j++){//N번 반복
            if(rst > 'z'){//출력값이 z를 넘어가면 대문자 A로 변환
                key  = 1; cnt = 0;
                rst = 'A';
            }
            if(rst > 'Z' && key == 1){//출력값이 Z를 넘어가면 소문자 a로 변환
            //단 1번 if문의 변화한 조건값과 일치해야함
                rst = 'a';
                key = 0;
            }
            // printf("rst = %c\n",rst);
            arr[i][j] = rst;
            rst++;//출력값 업데이트
            
        }
    }

    for(int i=0;i<M;i++){//N번 반복
        for(int j=0;j<N;j++){//N번 반복
            printf("%c ",arr[i][j]);
        }
        printf("\n");//결과출력
    }
    
    free(arr);//해제


}

