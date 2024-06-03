#include <stdio.h>
#include <stdlib.h>

// typedef char element;
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
void makeNode(BinaryTree *tree, int value) {
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
void preOrder(BinaryTree *tree, int index) {
    if (index < MAX_SIZE && tree->elements[index] != -1) {
        visit(tree->elements[index]);
        preOrder(tree, 2 * index);
        preOrder(tree, 2 * index + 1);
    }
}

// 중위 순회 함수
void inOrder(BinaryTree *tree, int index) {
    if (index < MAX_SIZE && tree->elements[index] != -1) {
        inOrder(tree, 2 * index);
        visit(tree->elements[index]);
        inOrder(tree, 2 * index + 1);
    }
}

// 후위 순회 함수
void postOrder(BinaryTree *tree, int index) {
    if (index < MAX_SIZE && tree->elements[index] != -1) {
        postOrder(tree, 2 * index);
        postOrder(tree, 2 * index + 1);
        visit(tree->elements[index]);
    }
}

// 노드의 요소를 반환합니다.
int element(BinaryTree *tree, int v) {return tree->elements[v];}

// 루트 노드를 반환합니다.
int root(BinaryTree *tree) {return 1;}

// 노드 v가 루트인지 확인합니다.
int isRoot(int v) {return v == 1;}

// 노드 v의 부모를 반환합니다.
int parent(int v) {
    if (v == 1) return -1; // 루트 노드는 부모가 없음
    return v / 2;
}

// 노드 v의 왼쪽 자식을 반환합니다.
int leftChild(int v) {return 2 * v;}

// 노드 v의 오른쪽 자식을 반환합니다.
int rightChild(int v) {return 2 * v + 1;}

// 노드 v의 형제를 반환합니다.
int sibling(int v) {
    if (v == 1) return -1; // 루트 노드는 형제가 없음
    if (v % 2 == 0) return v + 1; // 왼쪽 자식인 경우
    return v - 1; // 오른쪽 자식인 경우
}

// 노드 v가 내부노드인지 확인합니다.
int isInternal(BinaryTree *tree, int v) {return tree->elements[v] != -1 && (tree->elements[2 * v] != -1 || tree->elements[2 * v + 1] != -1);}

// 노드 v가 외부노드인지 확인합니다.
int isExternal(BinaryTree *tree, int v) {return tree->elements[v] != -1 && tree->elements[2 * v] == -1 && tree->elements[2 * v + 1] == -1;}

// 노드 v의 요소를 e로 설정합니다.
void setElement(BinaryTree *tree, int v, int e) {
    tree->elements[v] = e;
}

// 노드 v와 w의 요소를 교환합니다.
void swapElements(BinaryTree *tree, int v, int w) {
    int temp = tree->elements[v];
    tree->elements[v] = tree->elements[w];
    tree->elements[w] = temp;
}

int main() {
    BinaryTree tree;
    initTree(&tree);

    makeNode(&tree, 1); // 루트 노드 추가
    addLeftChild(&tree, 1, 2); // 루트의 왼쪽 자식 추가
    addRightChild(&tree, 1, 3); // 루트의 오른쪽 자식 추가
    addLeftChild(&tree, 2, 4); // 2의 왼쪽 자식 추가
    addRightChild(&tree, 2, 5); // 2의 오른쪽 자식 추가
    addLeftChild(&tree, 3, 6); // 3의 왼쪽 자식 추가
    addRightChild(&tree, 3, 7); // 3의 오른쪽 자식 추가

    printf("Preorder Traversal: ");
    preOrder(&tree, 1);
    printf("\n");

    printf("Inorder Traversal: ");
    inOrder(&tree, 1);
    printf("\n");

    printf("Postorder Traversal: ");
    postOrder(&tree, 1);
    printf("\n");

    // 테스트 코드
    printf("Element at 1: %d\n", element(&tree, 1));
    printf("Root: %d\n", root(&tree));
    printf("Is 1 root? %d\n", isRoot(1));
    printf("Parent of 2: %d\n", parent(2));
    printf("Left child of 2: %d\n", leftChild(2));
    printf("Right child of 2: %d\n", rightChild(2));
    printf("Sibling of 2: %d\n", sibling(2));
    printf("Is 1 internal? %d\n", isInternal(&tree, 1));
    printf("Is 4 external? %d\n", isExternal(&tree, 4));
    setElement(&tree, 1, 10);
    printf("New element at 1: %d\n", element(&tree, 1));
    swapElements(&tree, 1, 2);
    printf("After swap, element at 1: %d, element at 2: %d\n", element(&tree, 1), element(&tree, 2));

    return 0;
}
