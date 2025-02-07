/*
[ 문제 2 ] (삽입 정렬) n개의 양의 정수를 입력(중복 가능)받아, 아래에서 설명하는 삽입 정렬을
이용하여 정렬하는 프로그램을 작성하시오.
◦ 구현해야 할 삽입 정렬 알고리즘:
- 크기가 n인 배열을 동적 할당하여, 입력된 양의 정수 저장(입력 정수는 중복 가능)
- 제자리(in-place) 정렬 사용.
즉, 입력 값 저장을 위한 배열 이외에 O(1)의 추가 공간만 사용
- 배열의 앞부분을 정렬 상태로 유지
- 가능하면 교재의 의사코드를 보지 말고 구현해볼 것을 권장
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int tmp = *a;*a = *b;*b = tmp;
}

void insertSort(int *num, int size){
    //배열의 앞부분을 정렬 상태로 유지
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(num[i] > num[j]) swap(&num[i],&num[j]);
        }
    }
}

int main(){
    int n; scanf("%d",&n);
    int *num = (int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    insertSort(num,n);
    for(int i=0;i<n;i++)printf(" %d",num[i]);
}