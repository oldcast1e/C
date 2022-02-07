#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//선형검색
int search(int *arr,int n,int key){//key를 선형검색하는 함수
    /**
    arr: 값이 저장된 배열
    n: 반복횟수
    key: 찾고자하는 값
     */
    for(int i=0;i<n;i++){
        if(i==n) return -1;
        if(arr[i] == key) return i;
    }
    return 0;
}

int main(){
    int num,key;
    printf("[선형 검색]\n");
    printf("검색 개수: ");scanf("%d",&num);
    
    int *arr = (int*)malloc(sizeof(int)*num);

    for(int i=0;i<num;i++){printf("X[%d]: ",i);scanf("%d",&arr[i]);}
    printf("검색값: ");scanf("%d",&key);

    int idx = search(arr,num,key);
    switch(idx){
        case -1:
            puts("검색에 실패했습니다.");
        break;
        default:
            printf("%d(은)는 x[%d]에 있습니다.",key,idx);
            free(arr);
        break;
    }
    return 0;
}