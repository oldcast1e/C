/*
[ 문제 3 ] (개방주소법 해시테이블 – 이중해싱) 문제 2에서 충돌처리 방법을 이중해싱으로
변경하시오.
◦ 구현 조건
- 해시테이블은 크기가 M인 배열로 동적 할당한다(종료 시 해제).
- n은 M보다 작은 자연수로 최대 삽입 개수다.
- n은 M보다 작은 자연수로 최대 삽입 개수다.
- 입력 키는 중복이 없는 2자리 이상의 자연수다.
- 입력 키는 중복이 없는 2자리 이상의 자연수다.
- 키 x에 대한 첫 번째 해시함수 h(x) = x % M, 두 번째 해시함수 h‘(x) = q – (x % q) 를
사용한다. q는 M보다 조금 작은 소수로 입력으로 주어진다.
- 저장된 키가 없는 빈 버켓은 0으로 처리한다.
- 저장된 키가 없는 빈 버켓은 0으로 처리한다.
◦ 입력
◦ 입력
- M, n, q를 입력받는다.
- 삽입(i), 탐색(s), 출력(p) 명령어를 순서에 상관없이 반복하여 입력받는다.
i <x> : 키 x를 입력받아 해시테이블에 삽입
s <x> : 키 x가 해시테이블에 존재하는지 탐색
p : 현재의 해시테이블 인쇄
e : 해시테이블 인쇄 후 프로그램 종료
◦ 출력
- 키를 삽입하였을 때, 저장된 주소(배열 인덱스)를 인쇄한다.
- 삽입할 때 충돌이 일어나면 두 번째 해시함수로부터 얻은 셀로 이동하여 충돌 검사를
계속한다. 충돌 횟수만큼 C를 인쇄한 후, 삽입에 성공한 주소를 인쇄한다.
- 탐색한 키가 테이블에 존재할 경우, 키가 저장된 주소와 값을 인쇄한다(없을 경우 –1을
인쇄한다).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Bucket{
    int key;
    int isEmpty; // 1이면 비어있고, 0이면 비어있지 않음
} Bucket;

typedef struct HashTable{
    Bucket* buckets;
    int size;
} HashTable;

int q;

int hash(int key, int size) {
    return key % size;
}

// 초기화 함수
HashTable* initHashTable(int size) {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->size = size;

    table->buckets = (Bucket*)malloc(size * sizeof(Bucket));
    for (int i = 0; i < size; i++) {table->buckets[i].isEmpty = 1; }

    return table;
}


int hash_p(int key, int size) {
    return q - (key % q); 
}

// // 선형 탐사 (Linear Probing) 사용
// int getNextBucket(int v, int i, int size) {
//     return (v + i) % size;
// }

// 이중 해싱을 위한 getNextBucket 함수
int getNextBucket(int v, int i, int key, int size) {
    return (v + i * hash_p(key, size)) % size; // 이중 해싱 적용
}


void insertItem(HashTable* table, int key) {
    int v = hash(key, table->size); // 키의 해시값(인덱스)을 계산합니다.
    int i = 0;

    while (i < table->size) { // 해시 테이블의 크기 안에서 반복합니다.
        int b = getNextBucket(v, i, key, table->size); // 다음 버킷 인덱스를 계산합니다.
        // printf("bucket index: %d\n",b);

        if (table->buckets[b].isEmpty) { // 빈 버킷을 찾으면
            printf("%d\n",b);

            table->buckets[b].key = key; // 해당 위치에 키를 저장하고
            table->buckets[b].isEmpty = 0; // 비어있지 않음으로 설정합니다.
            return; // 삽입을 완료하고 함수 종료
        }
        else printf("C");
        
        i++; // 충돌 발생 시 다음 위치로 이동하기 위해 i를 증가시킴
    }
    // printf("Error: Hash table overflow\n"); // 해시 테이블이 가득 찬 경우
}


// 탐색 함수
int findElement(HashTable* table, int key) {
    int v = hash(key, table->size);
    int i = 0;

    while (i < table->size) {
        int b = getNextBucket(v, i,key, table->size);
        if (table->buckets[b].isEmpty) {
            return -1; // 키를 찾지 못함
        } else if (table->buckets[b].key == key) {
            return b; // 위치 반환 (0부터 시작)
        }
        i++;
    }

    return -1; // 키를 찾지 못함
}

// 삭제 함수
void removeItem(HashTable* table, int key) {
    int v = hash(key, table->size);
    int i = 0;

    while (i < table->size) {
        int b = getNextBucket(v, i, key, table->size);
        if (table->buckets[b].isEmpty) {
            printf("0\n"); // 키를 찾지 못함
            return;
        } else if (table->buckets[b].key == key) {
            table->buckets[b].isEmpty = 1; // 삭제 시 빈 상태로 설정
            printf("%d\n", b + 1); // 위치 출력
            return;
        }
        i++;
    }

    printf("0\n"); // 키를 찾지 못함
}

// 해시 테이블 출력 함수
void printHashTable(HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        if (!table->buckets[i].isEmpty) {
            printf(" %d", table->buckets[i].key);
        }
        else printf(" %d", 0);
    }
    printf("\n");
}

// 메모리 해제 함수
// void freeHashTable(HashTable* table) {
//     free(table->buckets);
//     free(table);
// }

// 메인 함수
int main() {
    int M,n;
    scanf("%d %d %d", &M,&n,& q); 
    //해시테이블의 크기 M과 입력 데이터의 크기 n을 입력받는다.
    //n은 M보다 작은 자연수로 최대 삽입 개수다.
    //키 x에 대한 첫 번째 해시함수 h(x) = x % M, 두 번째 해시함수 h‘(x) = q – (x % q) 를 사용한다. 
    //q는 M보다 조금 작은 소수로 입력으로 주어진다.

    HashTable* table = initHashTable(M);
    char command;
    int key;

    while (1) {
        scanf(" %c", &command);
        switch (command) {
            case 'i': // 삽입
                scanf("%d", &key);
                insertItem(table, key);
                break;
            case 's': // 탐색
                scanf("%d", &key);
                int position = findElement(table, key);
                if(position!=-1) printf("%d %d\n", position,key);
                else printf("%d",position);
                
                break;
            case 'p':
                printHashTable(table);
                break;
            case 'e': // 종료
                // freeHashTable(table);
                printHashTable(table);
                return 0;
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

7 3
i 17011112
bucket index: 6
6
i 17012345
bucket index: 0
0
i 17012687
bucket index: 6
cbucket index: 0
cbucket index: 1
6
s 17011111
-1
e
*/