/*
// 1. 루트를 기준으로 이진트리를 반전시키는 문제이다. 
(아래의 그림 참고) 조건에 맞게 알고리즘을 의사 코
// 드로 작성한 후, 알고리즘의 진행 과정을 설명하라.
*/

#include <stdio.h>
#include <stdlib.h>

// 이진 트리 노드 정의
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// 노드 생성 함수
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 트리 반전 함수 (DFS 기반)
void invertBinaryTreeDFS(Node* root) {
    if (root == NULL) return;

    // 왼쪽과 오른쪽 자식 노드 교환
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // 좌우 서브트리에 대해 재귀 호출
    invertBinaryTreeDFS(root->left);
    invertBinaryTreeDFS(root->right);
}

// 트리 출력 함수 (피라미드 형태)
void printTree(Node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int currentLevel = 0;
    while (front < rear) {
        int nodeCount = rear - front;

        // 들여쓰기 출력
        for (int i = 0; i < 4 - currentLevel ; i++) {
            printf(" ");
        }

        while (nodeCount > 0) {
            Node* current = queue[front++];
            printf("%d ", current->data);

            if (current->left) queue[rear++] = current->left;
            if (current->right) queue[rear++] = current->right;

            nodeCount--;
        }

        printf("\n");
        currentLevel++;
    }
}

int main() {
    Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(8);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    root->right->right = createNode(9);

    printf("Before inversion:\n");
    printTree(root);

    invertBinaryTreeDFS(root);

    printf("After inversion:\n");
    printTree(root);

    return 0;
}


/*

# DFS를 활용한 반전 코드

Alg invertBinaryTreeDFS(root)
    Input: root of binary tree
    Output: inverted binary tree
    1. if root == null:
           return null
    2. Swap root.left and root.right
    3. if root.left is not null:
           invertBinaryTreeDFS(root.left)
    4. if root.right is not null:
           invertBinaryTreeDFS(root.right)
    5. return root


DFS(깊이 우선 탐색) 기반:

재귀 호출을 이용하여 깊이 우선으로 노드를 방문하며 반전을 수행합니다.
현재 노드의 왼쪽과 오른쪽 자식을 교환(swap)합니다.
왼쪽 자식과 오른쪽 자식이 null이 아닐 경우, 각각에 대해 재귀적으로 함수를 호출합니다.
트리 전체를 재귀적으로 탐색하며, 각 노드의 자식을 교환하여 반전을 수행합니다.
진행 과정 예시:

루트(5)에서 시작 → 자식(3, 8) 교환 → 왼쪽 서브트리(8)에서 6과 9 교환 → 오른쪽 서브트리(3)에서 2와 4 교환.
모든 노드 방문 완료 후 결과 트리는 BFS 기반 반전 결과와 동일합니다.


*/