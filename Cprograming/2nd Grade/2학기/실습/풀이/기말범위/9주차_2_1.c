/*
[ 문제 2 ] (개방주소법 해시테이블 – 선형조사법) 크기 M인 해시테이블에 n개의 키 값을
입력받아 저장하고, 개방주소법 중 선형조사법을 이용하여 충돌을 처리하는 해시테이블 프로그램을 작성하시오.
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
    충돌 횟수만큼 C를 인쇄한 후, 삽입에 성공한 주소를 인쇄한다.
    - 탐색한 키가 테이블에 존재할 경우, 키가 저장된 주소와 값을 인쇄한다(없을 경우 –1을인쇄한다).
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

typedef struct HashTable{
    Node** buckets;
    int size;
} HashTable;

// 해시 함수 정의
int hash(int x, int M) {return x % M;}

// 노드 생성 함수
Node* createNode(int key) {
    Node* new = (Node*)malloc(sizeof(Node));

    new->key = key;
    new->next = NULL;

    return new;
}

// 해시 테이블 초기화 함수
HashTable* initHashTable(int size) {
    //size(M) 크기의 헤시테이블 배열 생성 -> 헤시테이블 안에 버켓 -> 버켓: 구조체 배열

    HashTable* table = (HashTable*)malloc(sizeof(HashTable));//해쉬테이블(배열) 생성
    table->size = size;//사이즈 동적할당

    table->buckets = (Node**)malloc(size * sizeof(Node*));//버켓; 구조체 배열 -> 버켓은 셀로 구성
    for (int i = 0; i < size; i++) {table->buckets[i] = NULL;}//모든 셀 초기화
    
    return table;//해쉬테이블 반환
}

void insertItem(HashTable* table, int key) {

    int index = hash(key, table->size);//인덱스 계산; 삽입될 위치 (M: table->size)

    Node* new = createNode(key);

    // new->next = table->buckets[index];
    // table->buckets[index] = new;//table->buckets: 구조체 배열
}

int main(){
    int M,n;
    scanf("%d %d",&M,&n);//n은 M보다 작은 자연수로 최대 삽입 개수다.
    
    HashTable* table = initHashTable(M); // 저장된 키 값이 없는 빈 버켓은 0으로 처리한다.
    char command;
    int key;

    while (1) {
        scanf(" %c", &command); 
        switch (command) {
            case 'i': // 삽입
                scanf("%d", &key);//입력 키는 중복이 없는 6자리 또는 8자리의 임의의 자연수(학번)다.
                insertItem(table, key);
                break;
            case 's': // 탐색
                scanf("%d", &key);
                // int position = searchItem(table, key);
                // printf("%d\n", position);
                break;
            case 'e': // 종료

                return 0;
        }
    }
}