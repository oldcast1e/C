#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

typedef TreeNode* element;

typedef struct {
    element *data; // 데이터 저장 배열
    int front, rear; // 포인터와 리어 변수
    int size; // 배열의 사이즈
} QueueType;

// 큐 초기화 함수
void init(QueueType *Q){
    Q->data = (char*)malloc(sizeof(char)*Q->size);
    // Q->data = (int*)malloc(sizeof(int)*Q->size);
    Q->front = Q->rear = 0; // 큐의 front와 rear를 초기화
}

void initQueue(QueueType *Q, int size) {
    Q->data = (element *)malloc(sizeof(element) * size);
    Q->front = Q->rear = 0;
    Q->size = size;
}

int isEmpty(QueueType *Q) {
    return Q->front == Q->rear;
}

int isFull(QueueType *Q) {
    return (Q->rear + 1) % Q->size == Q->front;
}

void enqueue(QueueType *Q, element item) {
    if (isFull(Q)) {
        printf("Queue is full\n");
        exit(1);
    }
    Q->rear = (Q->rear + 1) % Q->size;
    Q->data[Q->rear] = item;
}

element dequeue(QueueType *Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty\n");
        exit(1);
    }
    Q->front = (Q->front + 1) % Q->size;
    return Q->data[Q->front];
}

// 새로운 노드를 생성하는 함수
TreeNode* createNode(int data) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 레벨 순회 함수 정의
void levelOrder(TreeNode *root) {
    if (!root) return;

    QueueType Q;
    // initQueue(&Q, 100); // 큐 초기화, 필요한 만큼의 크기로 설정
    init(&Q);

    enqueue(&Q, root);

    while (!isEmpty(&Q)) {
        TreeNode *node = dequeue(&Q);
        printf("%d ", node->data);

        if (node->left) enqueue(&Q, node->left);
        if (node->right) enqueue(&Q, node->right);
    }
}

// 메인 함수
int main() {
    // 이진 트리 생성
    TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // 레벨 순회 출력
    printf("Level Order Traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
