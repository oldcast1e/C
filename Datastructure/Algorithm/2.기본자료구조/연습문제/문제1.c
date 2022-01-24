#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <time.h>
/*실습문제2-6을 변형하여 키의 최솟값을 찾는 프로그램을 작성하라*/
int minof(int *arr){
    int min = arr[0];
    for(int i=0;i<(int)sizeof(arr[0]);i++){
        if(arr[i]< min)   min = arr[i];
    }
    return min;
}
int main(){
    int N,*arr,cnt=0;
    printf("사람 수를 입력하세요: ");scanf("%d",&N);
    arr = (int*)malloc(N*sizeof(int));
    
    srand(time(NULL));
    do{
        arr[cnt] = 100 + rand() % 90;
        if(150 <= arr[cnt] && arr[cnt] <= 210) cnt++;
    }while(N>cnt);
    printf("입력된 사람의 키 중 가장 작은 값은 %d입니다.",  minof(arr));
}