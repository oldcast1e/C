#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//선형검색: 보초법의 사용
int search(int *arr,int n,int key){//key를 선형검색하는 함수
    /**
    arr: 값이 저장된 배열
    n: 반복횟수
    key: 찾고자하는 값
     */
    arr[n] = key;
    for(int i=0;i<n;i++)
        if(arr[i] == key) return i;
    /*보초법을 이용함에 따라 조건문이 두 개에서 하나로 줄어들음.*/
    return 0;
}

int main(){
    int num,key;
    printf("[선형 검색]\n");
    printf("검색 개수: ");scanf("%d",&num);
    
    int *arr = (int*)malloc(sizeof(int)*(num+1));//보초를 위한 공간 추가 할당

    for(int i=0;i<num;i++){printf("X[%d]: ",i);scanf("%d",&arr[i]);}
    printf("검색값: ");scanf("%d",&key);

    int idx = search(arr,num,key);
    if(idx == num) puts("검색에 실패했습니다.");
    else {
        printf("%d(은)는 x[%d]에 있습니다.",key,idx);
        free(arr);
    }
}