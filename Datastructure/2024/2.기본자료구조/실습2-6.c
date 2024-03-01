#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include  <time.h>
int maxof(const int arr[], int n){
    int max = arr[0];
    for(int i=0;i<n;i++){
        if(max < arr[i]) max = arr[i];
    }
    return max;
}

int main(){
    int num, *arr;
    printf("사람 수: ");scanf("%d",&num);
    arr = (int *)malloc(sizeof(int)*num);
    // printf("%d사람의 키를 입력하세요.\n",num);
    srand(time(NULL));
    for(int i=0;i<num;i++){
        arr[i] = 100 + rand()%99;
        printf("height[%d]: %d\n",i,arr[i]);
        //scanf("%d",&arr[i]);
    }

    printf("최대값은 %d입니다.\n",maxof(arr,num));
    free(arr);
    
} 
/*

*/