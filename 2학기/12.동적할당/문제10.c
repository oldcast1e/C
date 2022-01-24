#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){

    int N;//임의의 정수 정의
    scanf("%d",&N);//입력

    int *num = NULL;//동적할당
    num = (int*)malloc(N*sizeof(N));
    for(int i=0;i<N;i++){//N반 반복
        if(i != N/2){//중간값 제외
            num[i]  = i;//저장 및 출력
            printf(" %d",num[i]);
        }
    }
    // for(int i=0;i<N;i++) printf("%d ",num[i]);

}
/*
사용자로부터 정수 한 개를 입력받는다. 이것을 N 이라고 하자. 
N은 홀 수라고 가정한다. 

정수 N개를 저장할 수 있는 메모리를 동적 할당한 후에, 
이 메모리에 0부터 N-1 까지 정수를 저장한다 (0 1 2 ... N-1). 

이 배열의 중간에 위치한 값을 제외한 나머지 값들을 순서대로,
 M (N-1)개 새로 동적할당된 메모리에 대입한 후 출력한다.
*/