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

// 선형 탐사 (Linear Probing) 사용
int getNextBucket(int v, int i, int size) {
    return (v + i) % size;
}

void insertItem(HashTable* table, int key) {
    int v = hash(key, table->size); // 키의 해시값(인덱스)을 계산합니다.
    int i = 0;

    while (i < table->size) { // 해시 테이블의 크기 안에서 반복합니다.
        int b = getNextBucket(v, i, table->size); // 다음 버킷 인덱스를 계산합니다.
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
        int b = getNextBucket(v, i, table->size);
        if (table->buckets[b].isEmpty) {
            return -1; // 키를 찾지 못함
        } else if (table->buckets[b].key == key) {
            return b; // 위치 반환 (1부터 시작)
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
        int b = getNextBucket(v, i, table->size);
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
            printf("%d ", table->buckets[i].key);
        }
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
    scanf("%d %d", &M,&n); 
    //해시테이블의 크기 M과 입력 데이터의 크기 n을 입력받는다.
    //n은 M보다 작은 자연수로 최대 삽입 개수다.

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
            case 'e': // 종료
                // freeHashTable(table);
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