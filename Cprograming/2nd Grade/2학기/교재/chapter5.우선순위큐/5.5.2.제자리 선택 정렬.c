#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//제자리 선택 정렬
void inPlaceSelectionSort(int *num){
    int size = 20;

    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){ // 1~10
            if(num[i] > num[j]){
                int tmp = num[i];
                num[i]  = num[j];
                num[j]  = tmp;
            }
        }
        // printf(">>small: %d\n",num[small_index]);
    }
    for(int i=0;i<size;i++)printf("%d ",num[i]); printf("\n");
}

int main(){
    // int num[10] = {3,6,9,1,2,4,0,8,7,5};
    int num[20] = {29, 10, 14, 37, 14, 13, 11, 25, 6, 27, 40, 39, 2, 25, 5, 33, 12, 9, 22, 41};
    for(int i=0;i<20;i++)printf("%d ",num[i]);printf("\n");
    inPlaceSelectionSort(num);

}