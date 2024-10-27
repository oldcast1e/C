#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

//제자리 선택 정렬
void selectSort(int *num,int size){

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
    int num[10] = {3,6,9,1,2,4,0,8,7,5};
    for(int i=0;i<10;i++)printf("%d ",num[i]);printf("\n");
    selectSort(num,10);

}