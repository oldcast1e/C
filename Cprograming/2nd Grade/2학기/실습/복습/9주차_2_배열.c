/*
[ 문제 2 ] (개방주소법 해시테이블 – 선형조사법) 크기 M인 해시테이블에 n개의 키 값을
입력받아 저장하고, 개방주소법 중 선형조사법을 이용하여 충돌을 처리하는
해시테이블 프로그램을 작성하시오.
◦ 구현 조건
    - 해시테이블은 크기가 M인 배열로 동적 할당한다.
    - n은 M보다 작은 자연수로 최대 삽입 개수다.
    - 입력 키는 중복이 없는 6자리 또는 8자리의 임의의 자연수(학번)다.
    - 키 x에 대한 해시함수 h(x) = x % M 을 사용한다.
    - 저장된 키 값이 없는 빈 버켓은 0으로 처리한다.
◦ 입력
    - 해시테이블의 크기 M과 입력 데이터의 크기 n을 입력받는다.
    - 삽입(i), 탐색(s) 명령어를 순서에 상관없이 반복하여 입력받는다.
        i <x> : 키 x를 해시테이블에 삽입
        s <x> : 키 x가 해시테이블에 존재하는지 탐색
        e : 프로그램 종료
◦ 출력
    - 키를 삽입하였을 때, 저장된 주소(배열 인덱스)를 인쇄한다.
    - 삽입할 때 충돌이 일어나면 선형조사법에 의해 다음 셀로 이동하여 충돌 검사를 계속한다.
    - 충돌 횟수만큼 C를 인쇄한 후, 삽입에 성공한 주소를 인쇄한다.
    - 탐색한 키가 테이블에 존재할 경우, 키가 저장된 주소와 값을 인쇄한다(없을 경우 –1을 인쇄한다)
*/

#include <stdio.h>
#include <stdlib.h>

int q = 1;  // 이중 해싱 시 사용할 전역 변수 q (사용자 입력 가능)

// 해시 함수
int hashFunction(int key, int M) {
    return key % M;
}

// 다음 버킷 위치를 계산하는 함수 (선형 조사법 / 2차 조사법 / 이중 해싱)
int getNextBucket(int index, int i, int M) {
    // 선형 조사법
    return (index + i) % M;

    // 2차 조사법
    // return (index + i * i) % M;

    // 이중 해싱 (q를 전역 변수로 사용)
    // return (index + i * (q - (index % q))) % M;
}

// 해시 테이블 초기화 함수
void initHashTable(int *table, int M) {
    for (int i = 0; i < M; i++) {
        table[i] = -1;  // -1로 초기화하여 빈 슬롯을 표시
    }
}

// 요소 삽입 함수
void insertItem(int* table, int M, int key, int value) {
    int index = hashFunction(key, M); // 해시 함수를 통해 초기 인덱스 계산

    for (int i = 0; i < M; i++) {
        int bucket = getNextBucket(index, i, M); // 조사법에 따라 다음 버킷 위치 계산
        if (table[bucket] == -1) { // 빈 슬롯을 찾으면 삽입
            printf("%d\n",bucket);// 삽입에 성공한 주소를 인쇄한다.
            table[bucket] = value;
            //insertItem 함수에서 table[bucket] = key;로 수정하여, 실제 삽입된 키 값을 해시 테이블에 저장하도록 합니다.
            return;
        }
        printf("C"); //충돌발생; 충돌 횟수만큼 C를 인쇄
    }
    // printf("Hash table is full. Cannot insert key %d.\n", key);
}

// 요소 찾기 함수
int findElement(int* table, int M, int key) {
    int index = hashFunction(key, M);

    for (int i = 0; i < M; i++) {
        int bucket = getNextBucket(index, i, M);
        if (table[bucket] == key) return bucket; // 요소를 찾으면 해당 인덱스 반환
        if (table[bucket] == -1) return -1; // 요소를 찾지 못함
    }
    return -1; // 요소를 찾지 못함
}

// 요소 삭제 함수
void removeElement(int* table, int M, int key) {
    int index = hashFunction(key, M);

    for (int i = 0; i < M; i++) {
        int bucket = getNextBucket(index, i, M);
        if (table[bucket] == -1) { // 빈 슬롯을 만나면 탐색 종료
            printf("Element with key %d not found.\n", key);
            return;
        }
        if (table[bucket] == key) { // 요소를 찾으면 삭제
            table[bucket] = -1; // 삭제된 슬롯을 빈 슬롯으로 표시
            printf("Element with key %d removed.\n", key);
            return;
        }
    }
    printf("Element with key %d not found.\n", key);
}

// 해시 테이블 출력 함수
void printHashTable(int* table, int M) {
    for (int i = 0; i < M; i++) {
        if (table[i] != -1) {
            printf("Index %d: %d\n", i, table[i]);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}


int main(){
    int M,n,data,key; 
    char command;
    
    scanf("%d %d",&M,&n); getchar();
    int *table = (int*)malloc(sizeof(int)*M);//해시테이블은 크기가 M인 배열로 동적 할당한다.
    
    initHashTable(table,M);
    /*
    i <x> : 키 x를 해시테이블에 삽입
    s <x> : 키 x가 해시테이블에 존재하는지 탐색
    e : 프로그램 종
    */

    while(1){
        scanf("%c",&command); getchar();
        if(command == 'i'){
            scanf("%d",&key);getchar();
            //입력 키는 중복이 없는 자연수다.
            insertItem(table,M,key,key);
        }
        else if(command == 's'){
            scanf("%d",&key);getchar();

            int rst = findElement(table,M,key);
            if(rst == -1) printf("-1\n");
            else printf("%d %d\n",rst,key);
        }
        else if(command == 'e'){
            // printf("e\n");
            break;
        }

    }
}

/*
7 3
i 17011112
i 17012345
i 17012687
s 17011111
e


13 10
i 16110243
i 17011111
i 17012331
i 17012354
i 17013672
i 16012342
s 17012354
i 15013986
i 102067
i 113478
i 14012322
s 16110243
e


*/