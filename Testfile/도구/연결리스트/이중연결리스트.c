#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef char element;

typedef struct ListNode {
    element data;
    struct ListNode* prev;
    struct ListNode* next;
} ListNode;

typedef struct ListType {
    struct ListNode* Head;
    struct ListNode* Tail;
    int size;
} ListType;

// 리스트 초기화 함수
void init(ListType* list) {
    list->Head = NULL;
    list->Tail = NULL;
    list->size = 0;
}

// 순위 r에 원소 e를 추가하는 함수
void add(ListType* list, int rank, element e) {
    if (rank < 1 || rank > list->size + 1) {
        printf("invalid position\n");
        return;
    }

    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = e;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (rank == 1) {
        // 리스트의 첫 번째 위치에 삽입하는 경우
        newNode->next = list->Head;
        if (list->Head != NULL) {
            list->Head->prev = newNode;
        }
        list->Head = newNode;
        if (list->Tail == NULL) {
            list->Tail = newNode;
        }
    } else if (rank == list->size + 1) {
        // 리스트의 마지막 위치에 삽입하는 경우
        newNode->prev = list->Tail;
        if (list->Tail != NULL) {
            list->Tail->next = newNode;
        }
        list->Tail = newNode;
        if (list->Head == NULL) {
            list->Head = newNode;
        }
    } else {
        // 리스트 중간에 삽입하는 경우
        ListNode* temp = list->Head;
        for (int i = 1; i < rank - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    list->size++;
}

// 순위 r에 위치한 원소를 삭제하는 함수
void delete(ListType* list, int rank) {
    if (rank < 1 || rank > list->size) {
        printf("invalid position\n");
        return;
    }

    ListNode* temp = list->Head;
    if (rank == 1) {
        // 첫 번째 원소를 삭제하는 경우
        list->Head = temp->next;
        if (list->Head != NULL) {
            list->Head->prev = NULL;
        }
        if (temp == list->Tail) {
            list->Tail = NULL;
        }
    } else if (rank == list->size) {
        // 마지막 원소를 삭제하는 경우
        temp = list->Tail;
        list->Tail = temp->prev;
        if (list->Tail != NULL) {
            list->Tail->next = NULL;
        }
        if (temp == list->Head) {
            list->Head = NULL;
        }
    } else {
        // 중간 원소를 삭제하는 경우
        for (int i = 1; i < rank; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }

    free(temp);
    list->size--;
}

// 순위 r에 위치한 원소를 반환하는 함수
element get(ListType* list, int rank) {
    if (rank < 1 || rank > list->size) {
        printf("invalid position\n");
        return '\0';
    }

    ListNode* temp = list->Head;
    for (int i = 1; i < rank; i++) {
        temp = temp->next;
    }
    return temp->data;
}

// 리스트의 모든 원소를 저장 순위대로 출력하는 함수
void print(ListType* list) {
    ListNode* temp = list->Head;
    while (temp != NULL) {
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    ListType list;
    init(&list);
    
    add(&list, 1, 'A'); printf
    add(&list, 2, 'B');
    add(&list, 3, 'C');
    add(&list, 2, 'D');
    // print(&list); // Expected output: ADBC

    delete(&list, 3);
    print(&list); // Expected output: ADC

}
