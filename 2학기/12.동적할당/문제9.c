#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){//메인함수

    int N;//열 행
    int nxlen,nwlen;
    char rst = 'a';//출력 초기 값

    scanf("%d",&N);//입력받음
    // printf("%d %d\n",N,M);
    getchar();
    

    char **arr = NULL;//이중 배열 동적할당
    arr = (char**) malloc ( sizeof(char*) * N );//동적할당
    for(int i=0; i<N; i++){//2차원 배열 동적할당
        arr[i] = (char*) malloc ( sizeof(char) * 100 );
    }

    for(int i=0;i<N;i++){//N번 반복
        gets(arr[i]);
    }
    // printf("%s",arr[2]);

    for(int i=0;i<N;i++){//N번 반복
        for(int j=0;j<N;j++){//N번 반복
            if(i!=j){//비교대상 겹치지 않게
                nwlen = strlen(arr[i]);
                nxlen = strlen(arr[j]);//각각의 비교대상의 배열 길이 구하기
                
                if(nwlen > nxlen ){//
                    // printf("<%d|%d>\n",nwlen,nxlen);
                    char tmp[100];
                    strcpy(tmp,arr[i]);
                    strcpy(arr[i],arr[j]);
                    strcpy(arr[j],tmp);//가장 길이가 긴 문자열 부터 출력 위한 스왑
                }
            }
        }
        
    }
    for(int i=0;i<N;i++){
        puts(arr[i]);//출력
    }
    //가장 길이가 긴 문자열부터 가장 길이가 작은 문자 열까지 정렬
    
    free(arr);//해제


}

