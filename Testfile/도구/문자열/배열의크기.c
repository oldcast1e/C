#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){
    int arr[100];//배열 선언
    
    int arr_num;//배열의 요소 개수 변수 선언
    arr_num = sizeof(arr)/sizeoff(arr[0]);//배열의 요소 개수 구한 후 저장
    //단 arr[]안의 인덱스는 배열의 크기보다 작거나 같아야 한다.
    
    printf("배열의 요소 개수는 %d입니다.",arr_num);
}