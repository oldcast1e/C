#include <stdio.h>
#include <stdlib.h>

// 노드 포인터 타입 정의
typedef int Node;

// 연결 리스트 ADT 함수 정의
Node* initialize(int n) {
    Node* head = NULL;
    return head;
}

Node* insert(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    *newNode = data;
    newNode[1] = (Node)head;
    head = newNode;
    return head;
}

Node* add(Node* head, int r, int data) {
    if (r < 0) {
        printf("인덱스는 0 이상이어야 합니다.\n");
        exit(1);
    }
    if (r == 0) {
        return insert(head, data);
    }
    Node* current = head;
    int idx = 0;
    while (current != NULL) {
        if (idx == r - 1) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            *newNode = data;
            newNode[1] = current[1];
            current[1] = (Node)newNode;
            return head;
        }
        current = (Node*)current[1];
        idx++;
    }
    printf("인덱스 범위를 벗어납니다.\n");
    exit(1);
}

void printList(Node* head) {
    printf("리스트: ");
    while (head != NULL) {
        printf("%d ", *head);
        head = (Node*)head[1];
    }
    printf("\n");
}

int get(Node* head, int r) {
    int idx = 0;
    while (head != NULL) {
        if (idx == r) {
            return *head;
        }
        head = (Node*)head[1];
        idx++;
    }
    printf("인덱스 범위를 벗어납니다.\n");
    exit(1);
}

Node* removeElement(Node* head, int r) {
    if (head == NULL) return NULL;

    if (r == 0) {
        Node* next = (Node*)head[1];
        free(head);
        return next;
    }

    Node* current = head;
    Node* prev = NULL;
    int idx = 0;

    while (current != NULL && idx != r) {
        prev = current;
        current = (Node*)current[1];
        idx++;
    }

    if (current == NULL) {
        printf("인덱스 범위를 벗어납니다.\n");
        exit(1);
    }

    prev[1] = current[1];
    free(current);

    return head;
}

int main() {
    Node* list = NULL;
    int n;
    printf("리스트의 크기를 입력하세요: ");
    scanf("%d", &n);

    printf("%d개의 노드를 추가하세요:\n", n);
    for (int i = 0; i < n; i++) {
        int data;
        printf("데이터 입력: ");
        scanf("%d", &data);
        list = insert(list, data);
    }

    printf("노드 추가 후: ");
    printList(list);

    int r;
    printf("삭제할 위치의 인덱스를 입력하세요: ");
    scanf("%d", &r);
    list = removeElement(list, r);

    printf("노드 삭제 후: ");
    printList(list);

}