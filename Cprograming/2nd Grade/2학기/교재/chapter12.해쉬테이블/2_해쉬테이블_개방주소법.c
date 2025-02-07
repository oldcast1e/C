#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int q; // 이중 해싱에 사용할 전역 변수 q, 사용자가 입력한다고 가정

typedef struct {
    int key;
    int value;
    bool empty;      // 버킷이 비어있는지 여부
    bool deleted;    // 삭제된 항목 여부를 나타내는 플래그
} Bucket;

typedef struct {
    Bucket* buckets; // 버킷 배열
    int size;        // 해시 테이블 크기
} HashTable;

// 해시 함수
int hashFunction(int key, int size) {
    return key % size;
}

// getNextBucket 함수 (선형 조사법 / 2차 조사법 / 이중 해싱 중 하나 선택)
int getNextBucket(int v, int i, int size) {
    // 선형 조사법
    return (v + i) % size;

    // 2차 조사법
    // return (v + i * i) % size;

    // 이중 해싱
    // return (v + i * (q - (v % q))) % size;
}

// 해시 테이블 초기화 함수
HashTable* initHashTable(int size) {
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->size = size;
    table->buckets = (Bucket*)malloc(size * sizeof(Bucket));
    
    for (int i = 0; i < size; i++) {
        table->buckets[i].empty = true;
        table->buckets[i].deleted = false;
    }
    return table;
}

// 요소 찾기 함수
int findElement(HashTable* table, int key) {
    int v = hashFunction(key, table->size);
    int i = 0;

    while (i < table->size) {
        int b = getNextBucket(v, i, table->size);
        if (table->buckets[b].empty && !table->buckets[b].deleted) {
            return -1;  // NoSuchKey (요소를 찾지 못함)
        } else if (!table->buckets[b].empty && table->buckets[b].key == key) {
            return table->buckets[b].value;  // 요소를 찾으면 값 반환
        } else {
            i++;
        }
    }
    return -1;  // NoSuchKey (요소를 찾지 못함)
}

// 요소 삽입 함수
void insertItem(HashTable* table, int key, int value) {
    int v = hashFunction(key, table->size);
    int i = 0;

    while (i < table->size) {
        int b = getNextBucket(v, i, table->size);
        if (table->buckets[b].empty || table->buckets[b].deleted) {
            table->buckets[b].key = key;
            table->buckets[b].value = value;
            table->buckets[b].empty = false;
            table->buckets[b].deleted = false;
            return;
        } else {
            i++;
        }
    }
    printf("overflowException: 테이블이 가득 찼습니다.\n");
}

// 요소 제거 함수
void removeElement(HashTable* table, int key) {
    int v = hashFunction(key, table->size);
    int i = 0;

    while (i < table->size) {
        int b = getNextBucket(v, i, table->size);
        if (table->buckets[b].empty && !table->buckets[b].deleted) {
            printf("키 %d에 해당하는 요소를 찾을 수 없습니다.\n", key);
            return;
        } else if (!table->buckets[b].empty && table->buckets[b].key == key) {
            table->buckets[b].deleted = true;  // 요소를 비활성화 (삭제 표시)
            table->buckets[b].empty = true;
            printf("키 %d의 요소를 제거했습니다.\n", key);
            return;
        } else {
            i++;
        }
    }
    printf("키 %d에 해당하는 요소를 찾을 수 없습니다.\n", key);
}

// 메모리 해제 함수
void freeHashTable(HashTable* table) {
    free(table->buckets);
    free(table);
}

// 메인 함수
int main() {
    int size;
    printf("해시 테이블의 크기를 입력하세요: ");
    scanf("%d", &size);

    printf("이중 해싱에 사용할 값 q를 입력하세요: ");
    scanf("%d", &q);

    // 해시 테이블 초기화
    HashTable* table = initHashTable(size);

    // 예제 데이터 삽입
    insertItem(table, 10, 100);
    insertItem(table, 20, 200);
    insertItem(table, 30, 300);

    // 예제 데이터 검색
    int key = 20;
    int value = findElement(table, key);
    if (value != -1) {
        printf("키 %d의 값은 %d입니다.\n", key, value);
    } else {
        printf("키 %d에 해당하는 요소를 찾을 수 없습니다.\n", key);
    }

    // 예제 데이터 삭제
    removeElement(table, 20);

    // 삭제 후 재검색
    value = findElement(table, key);
    if (value != -1) {
        printf("키 %d의 값은 %d입니다.\n", key, value);
    } else {
        printf("키 %d에 해당하는 요소를 찾을 수 없습니다.\n", key);
    }

    // 해시 테이블 메모리 해제
    freeHashTable(table);

    return 0;
}
