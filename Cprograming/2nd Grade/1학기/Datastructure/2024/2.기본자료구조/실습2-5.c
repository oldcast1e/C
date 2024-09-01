#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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
    printf("%d사람의 키를 입력하세요.\n",num);

    for(int i=0;i<num;i++){
        printf("height[%d]: ",i);scanf("%d",&arr[i]);
    }

    printf("최대값은 %d입니다.\n",maxof(arr,num));
    free(arr);
    
} 
/*

*/