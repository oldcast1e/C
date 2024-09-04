#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct ListNode {
    element data;
    struct ListNode* prev;
    struct ListNode* next;
} ListNode;

typedef struct ListType {
    ListNode* Head;  // 더미 노드, 데이터 없음
    ListNode* Tail;  // 더미 노드, 데이터 없음
    int size;
} ListType;

// 리스트 초기화
void init(ListType* list) {
    list->Head = (ListNode*)malloc(sizeof(ListNode));
    list->Tail = (ListNode*)malloc(sizeof(ListNode));
    
    // 더미 노드 초기화
    list->Head->next = list->Tail;
    list->Head->prev = NULL;
    list->Tail->next = NULL;
    list->Tail->prev = list->Head;
    
    list->size = 0;
}

// 리스트의 맨 앞에 노드 추가
void add_front(ListType* list, element e) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = e;
    
    newNode->prev = list->Head;
    newNode->next = list->Head->next;

    list->Head->next->prev = newNode;
    list->Head->next = newNode;

    list->size++;
}

// 리스트의 맨 뒤에 노드 추가
void add_back(ListType* list, element e) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = e;
    newNode->next = list->Tail;
    newNode->prev = list->Tail->prev;

    list->Tail->prev->next = newNode;
    list->Tail->prev = newNode;

    list->size++;
}

// 리스트의 중간에 노드 추가
void add_middle(ListType* list, int rank, element e) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = e;

    ListNode* temp = list->Head;
    for (int i = 0; i < rank - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;

    list->size++;
}

// 노드 추가 함수
void add(ListType* list, int rank, element e) {
    if (rank < 1 || rank > list->size + 1) {
        printf("invalid position\n");
        return;
    }

    if (rank == 1) {
        add_front(list, e);  // 맨 앞에 추가
    } else if (rank == list->size + 1) {
        add_back(list, e);  // 맨 뒤에 추가
    } else {
        add_middle(list, rank, e);  // 중간에 추가
    }
}

// 리스트 출력
void print(ListType* list) {
    ListNode* temp = list->Head->next;
    while (temp != list->Tail) {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// 메모리 해제 함수
void free_list(ListType* list) {
    ListNode* current = list->Head;
    ListNode* next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}
int main() {
    ListType list;
    init(&list);

    add(&list, 1, 'A'); printf("%c is added.\n[List] ",'A'); print(&list); // Expected output: ADC
    add(&list, 2, 'B'); printf("%c is added.\n[List] ",'B'); print(&list); // Expected output: ADC
    add(&list, 3, 'C'); printf("%c is added.\n[List] ",'C'); print(&list); // Expected output: ADC
    add(&list, 2, 'D'); printf("%c is added.\n[List] ",'D'); print(&list); // Expected output: ADC
    // print(&list); // Expected output: ADBC


    // print(&list); // Expected output: ADC

}
