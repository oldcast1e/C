#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;             // 키 값
    int value;           // 저장할 데이터
    struct Node* next;   // 다음 노드를 가리키는 포인터
} Node;

typedef struct HashTable {
    Node** buckets;      // 버킷 배열 (연결 리스트 포인터 배열)
    int size;            // 해시 테이블 크기
} HashTable;

int hashFunction(int key, int M) { return key % M;}

HashTable* initHashTable(int M) {
    HashTable* table = (HashTable*)malloc(Mof(HashTable)); // (1) 해쉬테이블 동적할당
    table->size = M; //해쉬 테이블(;배열) 크기 선언

    table->buckets = (Node**)malloc(M * Mof(Node*));
    // 해쉬테이블의 버킷 동적할당 ; 최대 크기는 해쉬테이블의 크기임
    
    for (int i = 0; i < M; i++) {table->buckets[i] = NULL;}
    // 각 버킷을 빈 리스트로 초기화

    return table;
}

void insertItem(HashTable* table, int key, int value) {
    int index = hashFunction(key, table->size);//해쉬 함수 실행; 인덱스 계산
    
    Node* new = (Node*)malloc(sizeof(Node));//새로운 노드 동적할당
    new->key = key;//키 저장 ~ 인덱스
    new->value = value;//값 저장 ~ 데이터
    /*
    key ~ 인덱스
    - 해시 테이블에서 각 항목을 고유하게 식별하는 요소
    - 해시 함수에 입력되어 버킷 인덱스를 결정
    (ex) 특정 학생의 학번, 상품 ID, 또는 단어
    value ~ 데이터
    - 키에 매핑된 실제 데이터
    - 값은 키와 연결된 실제 정보를 의미
    (ex) 학생의 학번이 키라면, 값은 학생의 이름 또는 기타 정보일 수 있습니다.

    */

    new->next = table->buckets[index];
    table->buckets[index] = new;
}

Node* findElement(HashTable* table, int key) {
    int index = hashFunction(key, table->size);
    Node* current = table->buckets[index];
    //table->buckets[index]는 첫번째로 연결되있는 버켓

    while (current != NULL) {
        if (current->key == key) return current; // 요소를 찾으면 반환
        current = current->next; // 버켓 리스트 탐색
    }
    return NULL; // 요소를 찾지 못한 경우
}

int removeElement(HashTable* table, int key) {
    int index = hashFunction(key, table->size);
    Node* current = table->buckets[index];
    //table->buckets[index]는 첫번째로 연결되있는 버켓
    Node* prev = NULL;//삭제를 위해 임의의 노드를 생성

    while (current != NULL) {//버켓에 저장된 키(주소)가 0이 아닐때까지
        if (current->key == key) {
            if (prev == NULL)  table->buckets[index] = current->next;
            else  prev->next = current->next;
            
            int value = current->value;
            return value; // 제거한 요소의 값 반환
        }
        prev = current;
        current = current->next;
    }
    return -1; // 요소가 없을 경우
}

int main(){

}