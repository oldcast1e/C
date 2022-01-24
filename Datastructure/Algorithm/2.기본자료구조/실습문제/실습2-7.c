#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#define swap(tmp, x,y)do{tmp = x; x = y; y=tmp;}while(0)
//배열 요소를 역순으로 출력하는 프로그램(난수 생성)
void arr_reverse(int *arr){
    int tmp,rep = (int)sizeof(arr)/sizeof(arr[0])+1;
    
    for(int i=0;i<rep/2;i++){
        /**일일히 값 변환
        tmp = arr[i];
        arr[i] = arr[rep-i-1];
        arr[rep-i-1] = tmp;
        */
       swap(tmp,arr[i],arr[rep-i-1]);
       //함수 매크로 이용
    }
}

int main(){
    int num,*arr;
    printf("요소 개수를 입력하세요: ");scanf("%d",&num);
    arr = (int*)malloc(num*4);
    printf("%d 개의 정수를 입력하세요\n",num);

    for(int i=0;i<num;i++){
        printf("arr[%d]: ",i);scanf("%d",&arr[i]);
    }
    arr_reverse(arr);

    printf("배열의 요소를 역순으로 정렬했습니다.\n");
    for(int i=0;i<num;i++){
        printf("arr[%d]: %d\n",i,arr[i]);
    }
}
