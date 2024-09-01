#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <time.h>
//키의 합계를 구하는 프로그램을 작성하라.

int sumof(const int arr[],int n){
    int rst = 0;
    for(int i=0;i<n;i++) rst += arr[i];
    return rst;
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
    printf("키의 합계는 %d 입니다.",sumof(arr,N));


}