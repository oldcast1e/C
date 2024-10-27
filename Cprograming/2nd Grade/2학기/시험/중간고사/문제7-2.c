

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// 선택 정렬

void swap(int *a,int *b){
    int tmp = *a;*a = *b;*b = tmp;
}

void selectSort(int *num, int size){
    //배열의 뒷 부분을 정렬 상태로 유지하고, 매 반복마다 최대 한 번의 교환 연산만 사용
    int max_val,max_index;
    for(int i=0;i< size;i++){
        max_val = num[0];
        max_index = 0;
        for(int j=0;j< size-i;j++){
            if(max_val < num[j]){
                max_val = num[j];
                max_index = j;
            }
        }
        swap(&num[size-1-i],&num[max_index]);
    }
}

int main(){
    int n; scanf("%d",&n);
    int *num = (int*)malloc(sizeof(int)*n);

    int rst[100]; //임의 개수 100개
    int rstSize= 100; 
    int cnt = 0,check=0;

    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    selectSort(num,n); //=> 배열 num은 정렬되어있음

    // rst[cnt] = num[0]; cnt ++;
    // for(int i=0;i<cnt;i++){
    //     check = 0;
    //     for(int j=0;j<n;j++){

    //         if(rst[i] != num[j]){
    //             rst[cnt+1] = num[j];
    //             cnt ++;
    //             // break;
    //             //다른게 있다면 
    //             // check = 1;
    //         }
    //     }
    //     // if(check == 0)
    // }

    for(int i=0;i<n;i++){
        if(num[i] != num[i+1]){
            rst[cnt] = num[i];
            cnt ++;
        }
    }

    // for(int i=0;i<n;i++)printf(" %d",num[i]); printf("\n");
    for(int i=0;i<cnt;i++)printf("%d ",rst[i]);


}
/*
8
8 31 48 73 3 65 20 29

8
73 65 48 31 29 20 8 3

5
100 170 130 150 100

=>
*/