#include <stdio.h>

#define MAX 23  // 1) 해시테이블의 사이즈 M = 23 으로 정의할 것.

int q = 7;  // 두 번째 해시 함수에서 사용할 소수. M보다 작은 소수여야 합니다.

//2) 이중해싱에 기반해야 하며 h 및 h’은 각자 적절히 정의하여 사용할 것.
// 첫 번째 해시 함수
int hashFunction(int key, int M) {
    return key % M;
}

// 두 번째 해시 함수
int hashFunction2(int key) {
    return q - (key % q);
}

// 다음 버킷 위치를 계산하는 함수 (이중 해싱 사용)
int getNextBucket(int key, int i, int M) {
    return (hashFunction(key, M) + i * hashFunction2(key)) % M;
}

// 해시 테이블 초기화 함수
void initHashTable(int table[]) {
    for (int i = 0; i < MAX; i++) {
        table[i] = 0;  // 빈 슬롯을 0으로 초기화
    }
}

// 요소 삽입 함수
void insertItem(int table[], int key) {
    // 3) 저장 원소는 0에서 99 사이의 정수로 제한할 것.

    if (key < 0 || key > 99) {
        printf("Invalid input.\n");
        return;
    }

    int index = hashFunction(key, MAX);  // 첫 번째 해시 함수를 통해 초기 인덱스 계산

    for (int i = 0; i < MAX; i++) {
        int bucket = getNextBucket(key, i, MAX);  // 이중 해싱으로 다음 버킷 위치 계산

        // 4) 삽입(i) 명령시, 중복 키 또는 해시테이블이 만원일 경우 적절한 안내 메시지와 함께 명령수행을 거절할 것.
        if (table[bucket] == key) {printf("Duplicate keys.\n");return;}

        // 빈 슬롯 또는 비활성화 슬롯을 찾으면 삽입
        if (table[bucket] == 0 || table[bucket] == -1) {
            table[bucket] = key;
            // printf("%d\n", bucket);  // 삽입된 주소를 출력
            return;
        }

        // printf("C");  // 충돌 발생 시 C를 출력
    }

    // 4) 삽입(i) 명령시, 중복 키 또는 해시테이블이 만원일 경우 적절한 안내 메시지와 함께 명령수행을 거절할 것.
    printf("Hash table is full.\n");
}

// 요소 찾기 함수
int findElement(int table[], int key) {
    int index = hashFunction(key, MAX);

    for (int i = 0; i < MAX; i++) {
        int bucket = getNextBucket(key, i, MAX);
        if (table[bucket] == 0) {
            return -1;  // 빈 슬롯을 만나면 탐색 실패
        }
        if (table[bucket] == key) {
            return bucket;  // 요소를 찾으면 해당 인덱스 반환
        }
    }
    return -1;  // 요소를 찾지 못함
}

// 요소 삭제 함수 (비활성화 방식)
int removeElement(int table[], int key) {
    int index = hashFunction(key, MAX);

    for (int i = 0; i < MAX; i++) {
        int bucket = getNextBucket(key, i, MAX);
        if (table[bucket] == 0) {
            return -1;  // 빈 슬롯을 만나면 탐색 실패
        }
        if (table[bucket] == key) {
            table[bucket] = -1;  // 삭제된 슬롯을 비활성화(-1)로 표시
            return bucket;  // 삭제된 인덱스를 반환
        }
    }
    return -1;  // 요소를 찾지 못함
}

// 해시 테이블 출력 함수
void printHashTable(int table[]) {
    /*
    1) (주교재 문제의 요구와 다른 점) 인쇄(p) 명령시에만, 아래 예시처럼 현재 해시테이블의 내용을 두 개의 라인으로 보여줄 것. 
    윗 라인은 해시테이블의 배열첨자, 아래 라인은 저장된 원소들임. 비어있는 셀은 점으로 표시할 것.

    */
    // 첫 줄: 인덱스 출력
    for (int i = 0; i < MAX; i++) {printf("%2d ", i);}printf("\n");

    // 두 번째 줄: 실제 데이터 출력, 빈 슬롯은 '.'으로 표시
    for (int i = 0; i < MAX; i++) {
        if (table[i] > 0) printf("%2d ", table[i]);  // 저장된 키 출력
        else if (table[i] == -1) printf(" . ");  // 비활성화된 슬롯은 .으로 표시
        else printf(" . ");  // 빈 슬롯은 .으로 표시
    }
    printf("\n");
}

int main() {
    int table[MAX];
    initHashTable(table);

    char command;
    int key;

    while (1) {
        scanf(" %c", &command);  // 명령어 입력

        switch (command) {
            case 'i':
                scanf("%d", &key);
                insertItem(table, key);
                break;

            case 'f':
                scanf("%d", &key);
                int result = findElement(table, key);
                if (result == -1) printf("NoSuchKey\n");
                //5) 탐색(f) 또는 삭제(r) 명령시, 함께 주어진 키가 존재하지 않을 경우 NoSuchKey를 반환 및 인쇄할 것.
                else printf("%d\n", key);
                // else printf("%d %d\n", result, key);
                break;

            case 'r':
                scanf("%d", &key);
                int delResult = removeElement(table, key);
                if (delResult == -1) printf("NoSuchKey\n");
                //5) 탐색(f) 또는 삭제(r) 명령시, 함께 주어진 키가 존재하지 않을 경우 NoSuchKey를 반환 및 인쇄할 것.
                else printf("%d\n", delResult);
                break;

            case 'p':
                printHashTable(table);
                break;

            case 'q':
                // printHashTable(table);  // 종료 전 해시 테이블 상태 출력
                return 0;
        }
    }

    return 0;
}


/*
i 42
i 30
i 21
i 16
i 55
p
f 30
f 99
r 30
p
q


i 25
i 13
i 16
i 15
i 70
p
i 28
i 31
i 20
i 14
f 20
f 27
i 38
p
q

-------

i 10
i 5
i 23
f 50
r 23
f 23
i 10
i 101
i 99
q

i 12
i 25
i 99
i 120
f 40
i 12
r 25
f 25
p
q

i 42
i 30
i 55
p
i 42
f 99
r 55
f 55
i 101
q


*/