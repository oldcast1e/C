#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char element;

// 노드 구조체 정의
typedef struct TreeNode {
    element key;               // 노드의 데이터
    struct TreeNode* parent;   // 부모 노드를 가리키는 포인터
    struct TreeNode* left;     // 왼쪽 자식 노드를 가리키는 포인터
    struct TreeNode* right;    // 오른쪽 자식 노드를 가리키는 포인터
} TreeNode;

typedef TreeNode* QueueElement;

typedef struct {
    QueueElement *data; // 데이터 저장 배열
    int front, rear; // 포인터와 리어 변수
    int size; // 배열의 사이즈
} QueueType;

// 큐 초기화 함수
void initQueue(QueueType *Q, int size) {
    Q->data = (QueueElement *)malloc(sizeof(QueueElement) * size);
    Q->front = Q->rear = 0;
    Q->size = size;
}

int isEmpty(QueueType *Q) {
    return Q->front == Q->rear;
}

int isFull(QueueType *Q) {
    return (Q->rear + 1) % Q->size == Q->front;
}

void enqueue(QueueType *Q, QueueElement item) {
    if (isFull(Q)) {
        printf("Queue is full\n");
        exit(1);
    }
    Q->rear = (Q->rear + 1) % Q->size;
    Q->data[Q->rear] = item;
}

QueueElement dequeue(QueueType *Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty\n");
        exit(1);
    }
    Q->front = (Q->front + 1) % Q->size;
    return Q->data[Q->front];
}

// 노드 생성 함수
TreeNode* makeNode(element key, TreeNode *parent, TreeNode *left, TreeNode *right) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(1);
    }
    node->key = key;
    node->parent = parent;
    node->left = left;
    node->right = right;

    return node;
}

// 전위 순회 함수
void preOrder(TreeNode* node) {
    if (node != NULL) {
        printf("%c ", node->key); // 현재 노드 방문 
        preOrder(node->left); // 왼쪽 서브트리 방문
        preOrder(node->right); // 오른쪽 서브트리 방문
    }
}

// 중위 순회 함수
void inOrder(TreeNode* node) {
    if (node != NULL) {
        inOrder(node->left); // 왼쪽 서브트리 방문
        printf("%c ", node->key); // 현재 노드 방문
        inOrder(node->right); // 오른쪽 서브트리 방문
    }
}

// 후위 순회 함수
void postOrder(TreeNode* node) {
    if (node != NULL) {
        postOrder(node->left); // 왼쪽 서브트리 방문
        postOrder(node->right); // 오른쪽 서브트리 방문
        printf("%c ", node->key); // 현재 노드 방문
    }
}

// 레벨 순회 함수 정의
void levelOrder(TreeNode *root) {
    if (!root) return;

    QueueType Q;
    initQueue(&Q, 100); // 큐 초기화, 필요한 만큼의 크기로 설정

    enqueue(&Q, root);

    while (!isEmpty(&Q)) {
        TreeNode *node = dequeue(&Q);
        printf("%c ", node->key);

        if (node->left) enqueue(&Q, node->left);
        if (node->right) enqueue(&Q, node->right);
    }
}

// 메인 함수
int main() {
    TreeNode *n11 = makeNode('I',NULL,NULL,NULL);
    TreeNode *n10 = makeNode('H',NULL,NULL,NULL);
    TreeNode *n7 = makeNode('G',NULL,NULL,NULL);
    TreeNode *n6 = makeNode('F',NULL,NULL,NULL);
    TreeNode *n5 = makeNode('E',NULL,n10,n11);
    TreeNode *n4 = makeNode('D',NULL,NULL,NULL);
    TreeNode *n3 = makeNode('C',NULL,n6,n7);
    TreeNode *n2 = makeNode('B',NULL,n4,n5);
    TreeNode *n1 = makeNode('A',NULL,n2,n3);

    n10->parent = n11->parent = n5;
    n6->parent = n7->parent = n3;
    n4->parent = n5->parent = n2;    
    n2->parent = n3->parent = n1;

    printf("Pre Order: "); preOrder(n1); printf("\n");
    printf("In Order: "); inOrder(n1); printf("\n");
    printf("Post Order: "); postOrder(n1); printf("\n");
    printf("Level Order: "); levelOrder(n1); printf("\n");

    return 0;
}
