#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define swap(type, x,y) do{type t = x; x = y; y = t;} while(0)

void arr_swap(int arr[], int num){
    for(int i=0; i< num/2;i++){
        swap(int,arr[i],arr[num-i-1]);
    }
}

int main(){
    int num, *arr;    
    printf("요소 개수: "); scanf("%d",&num);
    arr = (int *)malloc(sizeof(int)*num);
    printf("%d 개의 정수를 입력하세요.\n",num);
    for(int i=0;i<num;i++){
        printf("x[%d]: ",i);scanf("%d",&arr[i]);
    }
    arr_swap(arr,num);
    printf("배열 요소를 역순으로 정렬했습니다.\n");
    for(int i=0;i<num;i++){
        printf("x[%d]: %d\n",i,arr[i]);
    }

    
} 
/*

*/