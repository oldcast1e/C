#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef int element;
/*
분리집합 트리 ADT(배열기반)는 아래 조건을 따른다.
1. 각 집합에는 공통되는 요소가 없다.
2. 각 배열의 의미상 배열일 뿐, 하나의 배열을 사용한다.
3. 각 배열의 인덱스는 원소의 값이다.
4. 각 배열의 요소(값)는 부모 노드이다.

- 원소 1의 부모가 0이라면, Parent[1] = 0이다.
- 루트 노드는 자신의 부모가 자신이므로, 예를 들어 `Parent[0] = 0`이 된다.
*/
// int isContain(int * arr, int size, element e){
    
// }

/*
- 각 배열의 인덱스가 분리집합의 값
- 각 배열의 요소가 해당 노드의 부모 노드 인덱스

집합 A = {1, 4, 7}, B = {2, 3, 6, 9}, C = {0, 5, 8, 10, 11}
  배열의 인덱스  -> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
원하는 분리집합  -> {11, 1, 2, 2, 1, 5, 2, 1, 5, 6, 5, 8}
내 방식 분리집합 -> { 0, 1, 2, 2, 1, 0, 2, 1, 0, 3, 5, 5}
*/

void makeNode(int* setArr, int* arr, int SetSize){
    // int SetSize = sizeof(arr)/sizeof(arr[0]);
    // printf(">>"); for(int i = 0;i<SetSize;i++)printf("[%d] ",arr[i]);printf("\n");
    for(int i=0;i<SetSize;i++){
        //1,4,7
        //2,3,6,9
        if(i==0) setArr[arr[i]] = arr[i];//arr[1]=1
        else{
            // printf("index = %d , arr[%d] = %d\n",i,i,arr[i]);
            setArr[arr[i]] = arr[i-1];//arr[0]=1
            printf("setArr[arr[%d]:%d] <= arr[%d]:%d\n",i,arr[i],i-1,arr[i-1]);

            if(arr[i+1])setArr[arr[i+1]] = arr[i-1];//arr[2]=6
            if(arr[i+1])printf("setArr[arr[%d]:%d] <= arr[%d]:%d\n",i+1,arr[i+1], i-1,arr[i-1]);

            i += 2;
        }
    }
    //배열의 인덱스  -> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
    //                  { 0, 1, 2, 2, 1, 0, 2, 1, 0, 3, 5, 5}
    // for(int i = 0;i<12;i++)printf("[%d] ",setArr[i]); printf("\n");
}

int main(){

    // int Arr = (int*)malloc(sizeof(int)*size_A);
    // 집합 A = {1, 4, 7}, B = {2, 3, 6, 9}, C = {0, 5, 8, 10, 11}
    int A[3] = {1,4,7}; int SetASize = sizeof(A)/sizeof(A[0]);
    int B[4] = {2,3,6,9}; int SetBSize = sizeof(B)/sizeof(B[0]);
    int C[5] = {0,5,8,10,11}; int SetCSize = sizeof(C)/sizeof(C[0]);

    int setSize = SetASize+ SetBSize+ SetCSize;
    // printf("size A = %d",setSize);
    int *setArr = (int*)malloc(sizeof(int)*setSize);
    for(int i = 0;i<setSize;i++)setArr[i] = i;

    // makeNode(setArr,A,SetASize);
    // for(int i = 0;i<setSize;i++)printf("[%d] ",setArr[i]); printf("\n");
    // makeNode(setArr,B,SetBSize);
    // for(int i = 0;i<setSize;i++)printf("[%d] ",setArr[i]); printf("\n");
    makeNode(setArr,C,SetCSize);
    for(int i = 0;i<setSize;i++)printf("[%d] ",setArr[i]); printf("\n");


}
/*
집합 A = {1, 4, 7}, B = {2, 3, 6, 9}, C = {0, 5, 8, 10, 11}

 배열의 인덱스  ->   { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
 내 방식 분리집합 -> { 0, 1,  2,  2,  1,  0,  2,  1,  0,  3,  5,   5}
                     [0] [1] [2] [3] [4] [0] [6] [7] [0] [9] [10] [10]
*/