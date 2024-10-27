#include<stdio.h>
#include<stdlib.h>

typedef int element;

// 분리집합 트리 생성 함수
void makeNode(int* setArr, int* arr, int SetSize){
    setArr[arr[0]] = arr[0]; // 첫 번째 요소는 자기 자신을 부모로 가짐 (루트 노드)
    for(int i = 1; i < SetSize; i++){
        setArr[arr[i]] = arr[i-1]; // 이전 원소가 부모가 됨
        printf("setArr[arr[%d]:%d] <= arr[%d]:%d\n", i, arr[i], i-1, arr[i-1]);
    }
}

int main(){
    // 집합 A = {1, 4, 7}, B = {2, 3, 6, 9}, C = {0, 5, 8, 10, 11}
    int A[3] = {1, 4, 7}; 
    int B[4] = {2, 3, 6, 9}; 
    int C[5] = {0, 5, 8, 10, 11}; 

    // 배열 크기 계산
    int SetASize = sizeof(A)/sizeof(A[0]);
    int SetBSize = sizeof(B)/sizeof(B[0]);
    int SetCSize = sizeof(C)/sizeof(C[0]);
    int setSize = SetASize + SetBSize + SetCSize;

    // 분리집합을 저장할 배열 선언
    int *setArr = (int*)malloc(sizeof(int) * setSize);

    // 초기화: 배열의 각 원소가 자기 자신을 부모로 가짐
    for(int i = 0; i < setSize; i++) setArr[i] = i;

    // 각 집합에 대해 트리 생성
    makeNode(setArr, A, SetASize);
    makeNode(setArr, B, SetBSize);
    makeNode(setArr, C, SetCSize);

    // 결과 출력
    printf("\n최종 분리집합 트리 배열:\n");
    for(int i = 0; i < setSize; i++) printf("[%d] ", setArr[i]); 
    printf("\n");

    // 메모리 해제
    free(setArr);

    return 0;
}
