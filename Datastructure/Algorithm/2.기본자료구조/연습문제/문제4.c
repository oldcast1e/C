#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <time.h>
//사람의 수와 키를 난수로 생성한 후 키의 최댓값을 출력하라
int maxof(int *arr){
    int max = arr[0];
    for(int i=0;i<(int)sizeof(arr[0]);i++){
        if(arr[i] > max)   max = arr[i];
    }
    return max;
}
int main(){
    int N,*arr,cnt =0;
    arr = (int*)malloc(N*sizeof(int));
    srand(time(NULL));
    do{N = rand() % 90;}while(5 > N || N > 20);
    do{
        arr[cnt] = 100 + rand() % 90;
        if(140 <= arr[cnt] && arr[cnt] <= 210) cnt++;
    }while(N>cnt);
    printf("%d명의 키 중 가장 큰 키는 %d 입니다.",N,maxof(arr));
}
