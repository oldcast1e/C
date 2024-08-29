#include <stdio.h>
#include <stdlib.h>

typedef struct DListNode {
    char color;
    struct DListNode* prev, * next;
} DListNode;

void initialize(DListNode* H, DListNode* T) {
    H->next = T;
    T->prev = H;
}
void insertFirst(DListNode* H, char newColor) {
    DListNode* new = (DListNode*)malloc(sizeof(DListNode));
    new->color = newColor;

    new -> prev = H;
    new -> next = H->next;

    H->next->prev = new;
    H->next = new;
}

void printNode(DListNode* H) {
    DListNode* p = H->next;
    while(p->next != NULL){
        printf("[%c] ",p->color);
        p = p->next;
    }
}

int main() {
    DListNode* H = (DListNode*)malloc(sizeof(DListNode));
    DListNode* T = (DListNode*)malloc(sizeof(DListNode));
    initialize(H, T);

    char arr[10] = { 'R','B','B','R','G','R','B','G','G','B' };
    for (int i = 9; i >= 0; i--) insertFirst(H, arr[i]);
    // printNode(H);
    // printf("Original List: ");
    // printNode(H);
    // printf("\n");

    // quickSort(H, T);

    // printf("Sorted List: ");
    // printNode(H);

}
