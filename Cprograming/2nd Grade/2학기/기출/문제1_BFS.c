/*
1. 루트를 기준으로 이진트리를 반전시키는 문제이다. 
(아래의 그림 참고) 조건에 맞게 알고리즘을 의사 코
드로 작성한 후, 알고리즘의 진행 과정을 설명하라.


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

// 트리 반전 함수 (BFS 기반)
void invertBinaryTreeBFS(Node* root) {
    if (root == NULL) return;

    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];

        // 왼쪽과 오른쪽 자식 노드 교환
        Node* temp = current->left;
        current->left = current->right;
        current->right = temp;

        // 자식 노드를 큐에 추가
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
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

        // // 들여쓰기 출력
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

    invertBinaryTreeBFS(root);

    printf("After inversion:\n");
    printTree(root);

    return 0;
}


/*

# BFS를 활용한 반전 코드

Alg invertBinaryTreeBFS(root)
    Input: root of binary tree
    Output: inverted binary tree
    1. if root == null:
           return null
    2. Initialize queue Q
    3. Q.enqueue(root)
    4. while Q is not empty:
           5. current = Q.dequeue()
           6. Swap current.left and current.right
           7. if current.left is not null:
                  Q.enqueue(current.left)
           8. if current.right is not null:
                  Q.enqueue(current.right)
    9. return root


BFS(너비 우선 탐색) 기반:

트리의 레벨 순서대로 각 노드를 방문하며 반전을 수행합니다.
루트를 시작으로 큐(queue)를 초기화합니다.
큐에서 노드를 하나씩 꺼내 해당 노드의 왼쪽과 오른쪽 자식을 교환(swap)합니다.
교환 후, 왼쪽 자식과 오른쪽 자식이 null이 아닌 경우 이를 큐에 추가하여 다음 레벨에서 처리합니다.
큐가 빌 때까지 반복하며, 모든 노드에 대해 반전을 수행합니다.
진행 과정 예시:

초기 트리 (루트: 5, 왼쪽: 3, 오른쪽: 8).
큐에 5 추가 → 자식 노드 3과 8을 교환 → 큐에 8과 3 추가.
8의 자식 노드 6과 9를 교환 → 3의 자식 노드 2와 4를 교환.
결과적으로 출력 트리: 루트(5), 왼쪽(8, 자식 9, 6), 오른쪽(3, 자식 4, 2).

*/