/*
[ 문제 1 ] (선택 정렬) n개의 양의 정수(중복 가능)를 입력받아, 아래에서 설명하는 선택 정렬을
이용하여 정렬하는 프로그램을 작성하시오.
◦ 구현해야 할 선택 정렬 알고리즘 (가장 큰 값을 찾는 버전):
- 크기가 n인 배열을 동적 할당하여, 입력된 양의 정수 저장(입력 정수는 중복 가능)
- 제자리(in place) 정렬 사용.즉, 입력 값 저장을 위한 배열 이외에 O(1)의 추가 공간만 사용
- 배열의 뒷 부분을 정렬 상태로 유지하고, 매 반복마다 최대 한 번의 교환 연산만 사용
(매 반복마다 가장 큰 값을 찾아, 오른쪽부터 채우는 방식으로 정렬)

- 가능하면 교재의 의사코드를 보지 말고 구현해볼 것을 권장
- 참고: 아래 그림에 예시된 버전은 매 반복마다 가장 작은 값을 찾아 왼쪽부터 채워 나가는,
따라서 교재의 알고리즘과는 정반대 방향으로 작동하는 버전이다.
*/

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

    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    selectSort(num,n);
    for(int i=0;i<n;i++)printf(" %d",num[i]);
}
/*
8
8 31 48 73 3 65 20 29

8
73 65 48 31 29 20 8 3

--------

7
3 73 48 31 8 11 20

8
73 65 48 31 29 20 8 3
*/