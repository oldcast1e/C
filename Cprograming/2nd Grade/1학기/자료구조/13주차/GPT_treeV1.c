#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // 배열의 최대 크기 정의

// 이진 트리 구조체 정의
typedef struct {
    int size; // 현재 트리의 크기
    int elements[MAX_SIZE]; // 트리를 저장하는 배열
} BinaryTree;

// 이진 트리 초기화 함수
void initTree(BinaryTree *tree) {
    tree->size = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        tree->elements[i] = -1; // -1을 사용하여 빈 노드를 표시
    }
}

// 루트 노드 추가 함수
void addRoot(BinaryTree *tree, int value) {
    if (tree->size == 0) {
        tree->elements[1] = value;
        tree->size++;
    } else {
        printf("트리가 이미 초기화되었습니다.\n");
    }
}

// 왼쪽 자식 노드 추가 함수
void addLeftChild(BinaryTree *tree, int parentIndex, int value) {
    int leftChildIndex = 2 * parentIndex;
    if (leftChildIndex < MAX_SIZE && tree->elements[parentIndex] != -1) {
        tree->elements[leftChildIndex] = value;
        tree->size++;
    } else {
        printf("왼쪽 자식 노드를 추가할 수 없습니다.\n");
    }
}

// 오른쪽 자식 노드 추가 함수
void addRightChild(BinaryTree *tree, int parentIndex, int value) {
    int rightChildIndex = 2 * parentIndex + 1;
    if (rightChildIndex < MAX_SIZE && tree->elements[parentIndex] != -1) {
        tree->elements[rightChildIndex] = value;
        tree->size++;
    } else {
        printf("오른쪽 자식 노드를 추가할 수 없습니다.\n");
    }
}

// 노드 방문 함수
void visit(int value) {
    if (value != -1) {
        printf("%d ", value);
    }
}

// 전위 순회 함수
void preorderTraversal(BinaryTree *tree, int index) {
    if (index < MAX_SIZE && tree->elements[index] != -1) {
        visit(tree->elements[index]);
        preorderTraversal(tree, 2 * index);
        preorderTraversal(tree, 2 * index + 1);
    }
}

// 중위 순회 함수
void inorderTraversal(BinaryTree *tree, int index) {
    if (index < MAX_SIZE && tree->elements[index] != -1) {
        inorderTraversal(tree, 2 * index);
        visit(tree->elements[index]);
        inorderTraversal(tree, 2 * index + 1);
    }
}

// 후위 순회 함수
void postorderTraversal(BinaryTree *tree, int index) {
    if (index < MAX_SIZE && tree->elements[index] != -1) {
        postorderTraversal(tree, 2 * index);
        postorderTraversal(tree, 2 * index + 1);
        visit(tree->elements[index]);
    }
}

int main() {
    BinaryTree tree;
    initTree(&tree);

    addRoot(&tree, 1); // 루트 노드 추가
    addLeftChild(&tree, 1, 2); // 루트의 왼쪽 자식 추가
    addRightChild(&tree, 1, 3); // 루트의 오른쪽 자식 추가
    addLeftChild(&tree, 2, 4); // 2의 왼쪽 자식 추가
    addRightChild(&tree, 2, 5); // 2의 오른쪽 자식 추가
    addLeftChild(&tree, 3, 6); // 3의 왼쪽 자식 추가
    addRightChild(&tree, 3, 7); // 3의 오른쪽 자식 추가

    printf("Preorder Traversal: ");
    preorderTraversal(&tree, 1);
    printf("\n");

    printf("Inorder Traversal: ");
    inorderTraversal(&tree, 1);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(&tree, 1);
    printf("\n");

    return 0;
}
