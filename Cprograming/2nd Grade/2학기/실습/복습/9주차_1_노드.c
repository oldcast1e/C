/*
[ 문제 1 ] (분리연쇄법 해시테이블) 크기 M인 해시테이블에 여러 개의 키 값을 입력받아
저장하고, 분리연쇄법을 이용하여 충돌을 처리하는 해시테이블 프로그램을 작성하시오.
◦ 구현 조건
    - 해시테이블은 크기가 M인 배열로 동적 할당한다.
    - 입력 키는 중복이 없는 자연수다.
    - 키 x에 대한 해시함수 h(x) = x % M 을 사용한다.
    - 삽입 시 충돌이 발생하는 경우, 해당 버켓 리스트의 맨 앞에 삽입한다.
◦ 입력
    - 해시테이블의 크기 M을 입력받는다.
    - 삽입(i), 탐색(s), 삭제(d), 인쇄(p) 명령어를 순서에 상관없이 반복하여 입력받는다.
        i <x> : 키 x를 해시테이블에 삽입
        s <x> : 키 x가 해시테이블에 존재하는지 탐색
        d <x> : 키 x가 해시테이블에 존재하면 삭제
        p : 해시테이블에 저장된 키들을 순서대로 인쇄(입출력 예시 참조)
        e : 프로그램 종료
◦ 출력
    - 키를 삽입하였을 때 아무 출력을 하지 않는다.
    - 탐색 또는 삭제할 때, 키가 존재하면 리스트에서 해당 키가 저장된 순위(1부터 시작)를
        인쇄하고 없다면 0을 인쇄한다(해시테이블의 주소가 아닌 리스트에서의 순위를 인쇄함에 유의).
    - 해시테이블을 인쇄할 때, 0번 주소부터 마지막 주소까지 순회하면서 저장된 키들을 방문하는 순으로 인쇄한다.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int hashFunction(int M,int key) {
    return key % M;
}

void insertItem(int* arr, int M , int key, int value) {
    /*
    key: 해시 테이블에 삽입할 요소의 키; 해시 함수에 의해 인덱스로 변환되어 해시 테이블에서 데이터가 저장될 위치를 결정
    value: 해시 테이블에 저장할 실제 데이터 값 (v)
    */
    int index = hashFunction(M,key); // 해시 함수를 사용하여 키 k의 인덱스를 계산

    for (int i = 0; i < M; i++) {// 선형 탐사
        int try = (index + i) % M; 
        if (arr[try] == -1) { 
            arr[try] = value;// -1인 경우 빈 슬롯으로 간주 -> 값 저장 후 종료
            return;
        }
    }
    // printf("Hash table is full. Cannot insert key %d.\n", key);
}

// 해시 테이블에서 요소를 찾는 함수
int findElement(int* arr, int M, int key) {
    int index = hashFunction(key);

    for (int i = 0; i < M; i++) {
        int try = (index + i) % M;
        if (arr[try] == -1) { break;}// 빈 슬롯을 만난 경우 : 탐색 종료
        if (arr[try] == key) {return try; }
    }
    return -1; // 요소를 찾지 못한 경우
}

// 해시 테이블에서 요소를 제거하는 함수
void removeElement(int* arr, int M, int key) {
    int index = hashFunction(key);

    for (int i = 0; i < M; i++) {
        int try = (index + i) % M;
        if (arr[try] == -1) break;
        
        if (arr[try] == key) {
            arr[try] = -1; // 요소를 삭제하고 빈 슬롯으로 설정
            // printf("Element with key %d removed.\n", key);
            return;
        }
    }
    // printf("Element with key %d not found.\n", key);
}

// 해시 테이블 출력 함수
void printHashTable(int* arr, int M) {
    for (int i = 0; i < M; i++) {
        if (arr[i] != -1) {
            printf("%d ",arr[i]);
            // printf("Index %d: Value = %d\n", i, arr[i]);
        } else {
            // printf("Index %d: Empty\n", i);
        }
    }printf("\n");
}

int main(){
    int M,data; scanf("%d",&M);getchar();
    int *arr = (int*)malloc(sizeof(int)*M);
    //해시테이블은 크기가 M인 배열로 동적 할당한다.
    char f;

    for(int i=0;i<M;i++){
        scanf("%c",&f); getchar();
        if(f == 'i'){
            scanf("%d",&data);
            //입력 키는 중복이 없는 자연수다.
            insertItem(arr,M,i,data);
            printf("i\n");
        }
        else if(f == 's'){
            printf("s\n");
        }
        else if(f == 'd'){
            printf("d\n");
        }
        else if(f == 'p'){
            printf("p\n");
        }
        else if(f == 'e'){
            printf("e\n");
            break;
        }
    }
}