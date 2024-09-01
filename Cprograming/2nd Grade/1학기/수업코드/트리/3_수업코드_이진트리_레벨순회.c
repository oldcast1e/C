#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TreeNode { // 트리 노드 구조체 선언
    int data;// 트리의 데이터
    struct TreeNode *left, *right;//트리의 자식 노드 (이진)
} TreeNode;

typedef TreeNode* element;

typedef struct { // 큐 타입을 저장하는 구조체
    element *data; // 데이터 저장 배열
    int front, rear; // 포인터와 리어 변수
    int size; // 배열의 사이즈
} QueueType;

// 큐 초기화 함수
void init(QueueType *Q){
    Q->data = (element*)malloc(sizeof(element)*Q->size); //데이터 저장 배열 동적할당
    Q->front = Q->rear = 0; // 큐의 front와 rear를 초기화
}

int isEmpty(QueueType *Q) {return Q->front == Q->rear;}
//큐의 프런트와 리어가 같은 경우 : 초기의 큐는 프런트와 리어가 같다.
/*
동작 원리: 원형 큐에서 큐가 비어 있는 상태는 front와 rear가 같은 위치를 가리킬 때입니다.

큐를 초기화할 때 front와 rear를 같은 값(예: 0)으로 설정합니다. 
큐에서 요소를 제거할 때마다 front가 증가하고, 큐에 요소를 삽입할 때마다 rear가 증가합니다.
이 경우, 큐가 비어 있으면 front와 rear가 다시 같은 위치를 가리키게 됩니다.
*/
int isFull(QueueType *Q) {return (Q->rear + 1) % Q->size == Q->front;}
/*
동작 원리: 원형 큐에서 큐가 가득 차 있는 상태는 rear의 다음 위치가 front의 위치와 같을 때입니다. 

이는 rear가 front 바로 뒤에 있는 상태로, 큐에 더 이상 요소를 삽입할 공간이 없음을 나타냅니다.
(Q->rear + 1) % Q->size는 rear의 다음 위치를 계산합니다. 
% Q->size는 원형 큐의 특성을 유지하기 위해 사용됩니다. 
rear가 배열의 끝에 도달하면 다시 배열의 시작으로 돌아가야 하기 때문입니다.
만약 이 계산된 위치가 front와 같다면, 큐는 가득 찬 상태입니다.
*/
void enqueue(QueueType *Q, element item) { // 큐에 데이터를 넣는 함수
    if (isFull(Q)) {printf("Queue is full\n");exit(1);} //큐가 가득 차있으면 메세지를 출력하고 종료
    
    Q->rear = (Q->rear + 1) % Q->size; // 리어를 증가하고, 증가된 리어의 위치에 데이터 저장(증가되지 않은 리어에는 이미 데이터 저장 되있음)
    Q->data[Q->rear] = item;
}

element dequeue(QueueType *Q) { // 큐에 데이터를 빼는 함수
    if (isEmpty(Q)) {printf("Queue is empty\n");exit(1);} //큐가 비어있으면 데이터를 뺄 수 없으므로 메세지 출력 후 종료

    Q->front = (Q->front + 1) % Q->size; 
    return Q->data[Q->front];
}

// 새로운 노드를 생성하는 함수
TreeNode* makeNode(int data) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 레벨 순회 함수 정의
void levelOrder(TreeNode *root) {
    if (!root) return;

    QueueType Q;
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
    TreeNode *root = makeNode(1);
    
    root->left = makeNode(2);
    root->right = makeNode(3);

    root->left->left = makeNode(4);
    root->left->right = makeNode(5);

    root->right->left = makeNode(6);
    root->right->right = makeNode(7);

    // 레벨 순회 출력
    printf("Level Order Traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
