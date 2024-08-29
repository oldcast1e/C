#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 이진 탐색 트리 노드 정의
typedef struct Node {
    int key;
    struct Node *left;//왼쪽 노드
    struct Node *right;//오른쪽 노드
} Node;

// 새로운 노드를 생성하는 함수
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // 새로운 노드 생성
    newNode->key = key;//새로운 노드에 키 저장
    
    newNode->left = NULL;//왼쪽 노드의 초기화
    newNode->right = NULL;//오른쪽 노드의 초기화
    return newNode;
}

// 이진 탐색 트리에서 주어진 키를 가지고 있는 노드가 내부 노드인지 확인하는 함수
int isInternalKey(Node* root, int key) {
    // 트리가 비어있을 경우
    if (root == NULL) return -1;

    // 주어진 키를 가지고 있는 노드 탐색
    Node* current = root;
    while (current != NULL) {
        if (current->key == key) { // 주어진 키를 가지고 있는 노드를 찾은 경우
            if (current->left != NULL || current->right != NULL) // 내부 노드인지 확인
                return 1; // 내부 노드이면 1 반환
            else
                return 0; // 리프 노드이면 0 반환
        } else if (key < current->key) {
            current = current->left; // 왼쪽 서브트리로 이동
        } else {
            current = current->right; // 오른쪽 서브트리로 이동
        }
    }

    return -1; // 주어진 키를 가진 노드가 트리에 없는 경우 -1 반환
}

// Node* isInternal(Node* root){
//     if (root == NULL)//부모노드의 값이 없다면
//         return createNode(key);//노드를 생성
// }

// 이진 탐색 트리에 노드 추가 함수
Node* insert(Node* root, int key) {
    
    if (root == NULL)//부모노드의 값이 없다면
        return createNode(key);//노드를 생성

    if (key <= root->key) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

// 이진 탐색 트리에서 최대 키를 갖는 원소를 찾는 함수
Node* findMaxElementNode(Node* root) {
    // 트리가 비어있을 경우
    if (root == NULL) return NULL;
    
    // 오른쪽 자식이 없을 때까지 계속 오른쪽으로 이동
    while (root->right != NULL) {root = root->right;}
    return root;// 최대 키를 갖는 노드 반환
}

// 주어진 이진 탐색 트리에서 최대 키 값을 반환하는 함수
int findMaxElement(Node* root) {
    // 트리가 비어있을 경우
    if (root == NULL) return -1; // 혹은 다른 적절한 값을 반환
    
    // 오른쪽 자식이 없을 때까지 계속 오른쪽으로 이동
    while (root->right != NULL) {
        root = root->right;
    }
    return root->key; // 최대 키를 갖는 노드의 키 값 반환
}
/*
Function: findMaxKeyValue(root: Node) -> int
Input: 이진 탐색 트리의 루트 노드를 가리키는 포인터 root
Output: 이진 탐색 트리에서 최대 키 값을 나타내는 정수 값

1. If root is NULL, return -1. [Return -1 if the tree is empty] 
2. While the right child of root is not NULL, do:
    - Update root to its right child. [Repeat until the right child of root is NULL]
3. Return the key value of the node root is pointing to. [Return the key value of the node that root is pointing to]


*/


// 중위 순회로 트리 출력 함수
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main() {
    srand(time(NULL)); // 난수 생성기 시드 초기화
    Node* root = NULL;
    int i, key;

    // 노드 추가
    for (i = 0; i < 15; i++) {
        key = rand() % 99 + 1;// 새로운 키 생성 (1 ~ 99 사이의 랜덤 값)
        root = insert(root, key);// 노드 삽입
        // key(v) <= key(w) 조건 충족 확인 및 보정
        if (root->right != NULL && root->key > root->right->key) {
            int temp = root->key;
            root->key = root->right->key;
            root->right->key = temp;
        }
    }

    printf("중위 순회로 정렬된 트리의 노드: ");
    inorderTraversal(root);
    printf("\n");
    /*
    이진 탐색 트리 생성
    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(15);
    root->right->right = createNode(25);
    */
    Node* maxElementNode = findMaxElementNode(root);// 최대 키를 갖는 원소 찾기
    int MaxKey = findMaxElement(root);

    // 최대 키를 출력
    if (maxElementNode != NULL) {
        // printf("Max Element: %d\n", maxElementNode->key);
         printf("Max Element: %d\n", MaxKey);
    }
    else printf("Tree is empty!\n");

    return 0;
}
/*
findMaxElementNode(Node* root):
    // 트리가 비어있을 경우
    if root == NULL:
        return NULL
    
    // 오른쪽 자식이 없을 때까지 계속 오른쪽으로 이동
    while root->right != NULL:
        root = root->right
    
    // 최대 키를 갖는 노드 반환
    return root

*/