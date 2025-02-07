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

int q = 1;  // 이중 해싱 시 사용할 전역 변수 q (사용자 입력으로 설정)

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
void initHashTable(int *table, int M) {
    for (int i = 0; i < M; i++) {
        table[i] = 0;  // 문제 요구사항에 따라 빈 슬롯을 0으로 초기화
    }
}

// 요소 삽입 함수
void insertItem(int* table, int M, int key) {
    int index = hashFunction(key, M); // 첫 번째 해시 함수를 통해 초기 인덱스 계산

    for (int i = 0; i < M; i++) {
        int bucket = getNextBucket(key, i, M); // 이중 해싱을 사용해 다음 버킷 위치 계산
        if (table[bucket] == 0) { // 빈 슬롯을 찾으면 삽입
            printf("%d\n", bucket);  // 삽입에 성공한 주소를 출력
            table[bucket] = key;     // 실제 키 값을 해시 테이블에 저장
            return;
        }
        printf("C"); // 충돌 발생 시 C를 출력
    }
    printf("Hash table is full. Cannot insert key %d.\n", key);
}

// 요소 찾기 함수
int findElement(int* table, int M, int key) {
    int index = hashFunction(key, M);

    for (int i = 0; i < M; i++) {
        int bucket = getNextBucket(key, i, M);
        if (table[bucket] == 0) return -1;  // 빈 슬롯을 만나면 탐색 실패로 간주
        if (table[bucket] == key) return bucket; // 요소를 찾으면 해당 인덱스 반환
    }
    return -1; // 요소를 찾지 못함
}

// 해시 테이블 출력 함수
void printHashTable(int* table, int M) {
    for (int i = 0; i < M; i++) {
        if (table[i] != 0) printf(" %d", table[i]);
        else printf(" 0");
    }
    printf("\n");
}

int main() {
    int M, n, key;
    char command;

    scanf("%d %d %d", &M, &n, &q); getchar();
    int *table = (int*)malloc(sizeof(int) * M);  // 해시 테이블을 크기 M인 배열로 동적 할당

    initHashTable(table, M);

    while (1) {
        scanf("%c", &command); getchar();
        if (command == 'i') {
            scanf("%d", &key); getchar();
            insertItem(table, M, key);  // 입력 키는 중복이 없는 자연수로 가정
        }
        else if (command == 's') {
            scanf("%d", &key); getchar();

            int rst = findElement(table, M, key);
            if (rst == -1) printf("-1\n");
            else printf("%d %d\n", rst, key);
        }
        else if (command == 'p') {
            printHashTable(table, M);
        }
        else if (command == 'e') {
             printHashTable(table, M);
            break;
        }
    }

    free(table);  // 동적으로 할당한 메모리 해제
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