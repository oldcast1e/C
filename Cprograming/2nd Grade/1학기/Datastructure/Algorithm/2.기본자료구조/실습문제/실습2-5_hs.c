#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/*배열 요소의 최댓값 구하기 프로그램*/
int max_heigh(int *arr){
    int max = arr[0];
    for(int i=0;i<(int)sizeof(arr[0]);i++){
        if(arr[i]> max) max = arr[i];
    }
    return max;
}
int main(){
    int N,*arr;
    printf("사람 수를 입력하세요: ");scanf("%d",&N);
    arr = (int*)malloc(N*sizeof(int));
    printf("키를 입력하세요\n");

    for(int i=0;i<N;i++){printf("heigh[%d]: ",i+1);scanf("%d",&arr[i]);}
    printf("입력된 사람의 키 중 가장 큰 값은 %d입니다.",max_heigh(arr));
    
}
