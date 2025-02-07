#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//제자리 삽입 정렬
void inPlaceInsertionSort(int *num){
    int size = 20;
    //0~10 -> 1~10 -> 2~10 ... 9->10
    int small_val,small_index,tmp;
    for(int i=0;i<size;i++){
        small_index = i; //0
        small_val = num[i] ;
        for(int j=i+1;j<size;j++){ // 1~10
            if(small_val > num[j]){
                small_val = num[j];
                small_index = j;
            }
        }
        // printf(">>small: %d\n",num[small_index]);
        tmp = num[i];
        num[i] = num[small_index];
        num[small_index] = tmp;
        
    }
    for(int i=0;i<size;i++)printf("%d ",num[i]); printf("\n");
}
/*
제자리 삽입 정렬 -> 왼쪽부터 범위가 줄어드는 정렬
1. i번째 인덱스를 가장 작은 인덱스로 설정
2. 반복을 수행하며 가장 작은 요소의 인덱스를 저장
3. j 반복이 끝날때마다 가장 작은 요소를 i번째에 스왑하여 저장

*/

int main(){
    int num[20] = {29, 10, 14, 37, 14, 13, 11, 25, 6, 27, 40, 39, 2, 25, 5, 33, 12, 9, 22, 41};
    for(int i=0;i<20;i++)printf("%d ",num[i]);printf("\n");
    inPlaceInsertionSort(num);

}