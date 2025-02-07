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

// 삽입 함수
void insertItem(HashTable* table, int key) {

    int index = hash(key, table->size);//인덱스 계산; 삽입될 위치 (M: table->size)

    Node* new = createNode(key);

    new->next = table->buckets[index];
    table->buckets[index] = new;//table->buckets: 구조체 배열
}
/*
    new->next = table->buckets[index];:

        새로 삽입할 노드 new의 next 포인터가 현재 table->buckets[index]가 가리키는 연결 리스트의 첫 번째 노드를 가리키도록 설정합니다.
        이렇게 하면 new가 리스트의 맨 앞에 위치하게 되고, 기존의 첫 번째 노드와 연결됩니다.
        예를 들어, 현재 버킷이 12 -> 15 -> 20 순서로 되어 있고, 새로 5를 삽입하려면 5가 맨 앞에 오도록 해야 합니다. 
        이 줄의 코드를 실행하면 5->next가 12를 가리키게 됩니다.

    table->buckets[index] = new;:

        table->buckets[index]를 new로 업데이트하여 index 버킷의 첫 번째 노드를 new로 변경합니다.
        즉, new가 리스트의 첫 번째 노드로 설정됩니다.
        결과적으로 버킷의 연결 리스트는 5 -> 12 -> 15 -> 20의 순서로 업데이트됩니다.
*/

// 탐색 함수
int searchItem(HashTable* table, int key) {
    int index = hash(key, table->size);//인덱스 계산; 삽입될 위치 (M: table->size)

    Node* current = table->buckets[index];

    int position = 1;
    while (current != NULL) {
        if (current->key == key) return position;
        
        current = current->next;
        position++;
    }
    return 0; // 키를 찾지 못한 경우
}

// 삭제 함수
int removeItem(HashTable* table, int key) {
    int index = hash(key, table->size);//인덱스 계산; 삽입될 위치 (M: table->size)

    Node* current = table->buckets[index]; //버켓으로 이동
    Node* prev = NULL;

    int position = 1;

    while (current != NULL) {

        if (current->key == key) {//삭제할 키를 찾은 경우

            if (prev == NULL)  table->buckets[index] = current->next;
            else  prev->next = current->next;
            
            free(current);
            return position;
        }
        prev = current;
        current = current->next;
        position++;
    }
    return 0; // 키를 찾지 못한 경우
}

// 해시 테이블 인쇄 함수
void printHashTable(HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        Node* current = table->buckets[i];
        while (current != NULL) {
            printf(" %d", current->key);
            current = current->next;
        }
    } printf("\n");
}

// 해시 테이블 메모리 해제 함수
void freeHashTable(HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        Node* current = table->buckets[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(table->buckets);
    free(table);
}

// 메인 함수
int main() {
    int M;
    scanf("%d", &M);
    
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
                int position = searchItem(table, key);
                printf("%d\n", position);
                break;
            case 'd': // 삭제
                scanf("%d", &key);
                int removedPosition = removeItem(table, key);
                printf("%d\n", removedPosition);
                break;
            case 'p': // 인쇄
                printHashTable(table);
                break;
            case 'e': // 종료
                freeHashTable(table);
                return 0;
        }
    }
}
/*
13
i 34
i 23
i 26
i 21
s 36
s 26
s 34
s 21
p
d 21
s 34
d 8
e
*/