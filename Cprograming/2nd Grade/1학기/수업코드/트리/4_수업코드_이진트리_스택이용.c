#include <stdio.h>
#include <stdlib.h>

typedef char element;
#define N 100

// 노드 구조체 정의
typedef struct TreeNode {
    element data;               // 노드의 데이터
    struct TreeNode* parent;   // 부모 노드를 가리키는 포인터
    struct TreeNode* left;     // 왼쪽 자식 노드를 가리키는 포인터
    struct TreeNode* right;    // 오른쪽 자식 노드를 가리키는 포인터
} TreeNode;

// ===== 스택 코드의 시작 ===== 
typedef struct {
   TreeNode* data[N]; // 스택의 배열: 최대 용량은 100
   int top;           // (현재 스택의 데이터 개수 - 1)
} StackType;

// 스택 초기화 함수
void Initialize(StackType *s) { s->top = -1; }

// 공백 상태 검출 함수
int IsEmpty(StackType *s) { return (s->top == -1); }

// 포화 상태 검출 함수
int IsFull(StackType *s) { return (s->top >= (N - 1)); }

// 삽입 함수
void Push(StackType *s, TreeNode* ipt) {
    if (IsFull(s)) {
        printf("스택 포화 발생\n");
        return;
    } else {
        s->data[++(s->top)] = ipt;
    }
}

// 삭제 함수
TreeNode* Pop(StackType *s) {
    if (IsEmpty(s)) {
        printf("스택 공백 발생: 프로그램을 종료합니다.");
        exit(1);
    } else {
        return s->data[(s->top)--];
    }
}

// 피크 함수
TreeNode* Peek(StackType *s) {
    if (IsEmpty(s)) {
        printf("스택 공백 발생: 프로그램을 종료합니다.");
        exit(1);
    } else {
        return s->data[s->top];
    }
}

// 노드 생성 함수
TreeNode* makeNode(element data, TreeNode *parent, TreeNode *left, TreeNode *right) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(1);
    }
    node->data = data;
    node->parent = parent;
    node->left = left;
    node->right = right;

    return node;
}

// 스택을 사용한 전위 순회 함수
void IterativePreOrder(TreeNode* root) {
    StackType S;
    Initialize(&S);
    if (root != NULL) Push(&S, root);

    while (!IsEmpty(&S)) {
        TreeNode* current = Pop(&S);
        printf("%c ", current->data);
        
        // 오른쪽 자식을 먼저 푸시(스택의 LIFO 특성으로 인해 나중에 처리됨)
        if (current->right != NULL) Push(&S, current->right);
        // 왼쪽 자식을 나중에 푸시(스택의 LIFO 특성으로 인해 먼저 처리됨)
        if (current->left != NULL) Push(&S, current->left);
    }
}

// 스택을 사용한 중위 순회 함수
// 스택을 사용한 중위 순회 함수
void IterativeInOrder(TreeNode* root) {
    StackType S;
    Initialize(&S);
    TreeNode* current = root;

    while (1) {
        // 현재 노드의 왼쪽으로 끝까지 내려가며 스택에 푸시
        for (; current != NULL; current = current->left) {
            Push(&S, current);
        }
        // 스택이 비어 있으면 순회 완료
        if (IsEmpty(&S)) {break;}
        
        // 스택에서 노드를 팝하고 출력
        current = Pop(&S);
        printf("%c ", current->data);
        // 현재 노드를 오른쪽 자식으로 이동
        current = current->right;
    }
}

// 스택을 사용한 후위 순회 함수
void IterativePostOrder(TreeNode* root) {
    StackType S1, S2;
    Initialize(&S1);
    Initialize(&S2);
    if (root != NULL) Push(&S1, root);

    while (!IsEmpty(&S1)) {
        TreeNode* current = Pop(&S1);
        Push(&S2, current);
        
        // 왼쪽 자식을 스택1에 푸시
        if (current->left != NULL) Push(&S1, current->left);
        // 오른쪽 자식을 스택1에 푸시
        if (current->right != NULL) Push(&S1, current->right);
    }

    while (!IsEmpty(&S2)) {
        TreeNode* current = Pop(&S2);
        printf("%c ", current->data);
    }
}

int main() {
    TreeNode *n11 = makeNode('I', NULL, NULL, NULL);
    TreeNode *n10 = makeNode('H', NULL, NULL, NULL);
    TreeNode *n7 = makeNode('G', NULL, NULL, NULL);
    TreeNode *n6 = makeNode('F', NULL, NULL, NULL);
    TreeNode *n5 = makeNode('E', NULL, n10, n11);
    TreeNode *n4 = makeNode('D', NULL, NULL, NULL);
    TreeNode *n3 = makeNode('C', NULL, n6, n7);
    TreeNode *n2 = makeNode('B', NULL, n4, n5);
    TreeNode *n1 = makeNode('A', NULL, n2, n3);

    n10->parent = n11->parent = n5;
    n6->parent = n7->parent = n3;
    n4->parent = n5->parent = n2;    
    n2->parent = n3->parent = n1;

    // printf("Pre (Recursive): "); preOrder(n1); printf("\n");
    // printf("In (Recursive): "); inOrder(n1); printf("\n");
    // printf("Post (Recursive): "); postOrder(n1); printf("\n");

    printf("Pre (Iterative): "); IterativePreOrder(n1); printf("\n");
    printf("In (Iterative): "); IterativeInOrder(n1); printf("\n");
    printf("Post (Iterative): "); IterativePostOrder(n1); printf("\n");

    return 0;
}
