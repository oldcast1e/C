#include <stdio.h>
#include <stdlib.h>

typedef char element;

// 노드 구조체 정의
typedef struct TreeNode {
    element num;               // 노드의 데이터
    struct TreeNode* left;     // 왼쪽 자식 노드를 가리키는 포인터
    struct TreeNode* right;    // 오른쪽 자식 노드를 가리키는 포인터
} TreeNode;

// 노드 생성 함수
TreeNode* makeNode(element num, TreeNode *left, TreeNode *right) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(1);
    }
    node->num = num;
    node->left = left;
    node->right = right;

    return node;
}

// 전위 순회 함수
void preOrder(TreeNode* node) {
    if (node != NULL) {
        printf("%c ", node->num); // 현재 노드 방문 
        preOrder(node->left); // 왼쪽 서브트리 방문
        preOrder(node->right); // 오른쪽 서브트리 방문
    }
}

// 중위 순회 함수
void inOrder(TreeNode* node) {
    if (node != NULL) {
        inOrder(node->left); // 왼쪽 서브트리 방문
        printf("%c ", node->num); // 현재 노드 방문
        inOrder(node->right); // 오른쪽 서브트리 방문
    }
}

// 후위 순회 함수
void postOrder(TreeNode* node) {
    if (node != NULL) {
        postOrder(node->left); // 왼쪽 서브트리 방문
        postOrder(node->right); // 오른쪽 서브트리 방문
        printf("%c ", node->num); // 현재 노드 방문
    }
}

// 노드의 요소를 반환
element elementNode(TreeNode* v) {return v->num;}

// 노드 v의 왼쪽 자식을 반환
TreeNode* leftChild(TreeNode* v) {return v->left;}

// 노드 v의 오른쪽 자식을 반환
TreeNode* rightChild(TreeNode* v) {return v->right;}

// 노드 v가 내부노드인지 확인
int isInternal(TreeNode* v) {return v->left != NULL || v->right != NULL;}

// 노드 v가 외부노드인지 확인
int isExternal(TreeNode* v) {return v->left == NULL && v->right == NULL;}

// 노드 v의 요소를 e로 설정
void setElement(TreeNode* v, element e) {v->num = e;}

// 노드 v와 w의 요소를 교환
void swapElements(TreeNode* v, TreeNode* w) {
    element temp = v->num;
    v->num = w->num;
    w->num = temp;
}

int main(){
    int n; 
    printf("Enter the number of nodes: ");
    scanf("%d",&n);

    TreeNode **node = (TreeNode **)malloc(sizeof(TreeNode*)*(n+1));
    for(int i = 0; i <= 3*n; i++) {node[i] = NULL;}

    int num, left_data, right_data;
    int fir_node;

    for(int i = 0; i < n; i++){
        scanf("%d %d %d",&num,&left_data,&right_data);

        if (node[num] == NULL)  node[num] = makeNode(num, NULL, NULL);
        
        if (i == 0) fir_node = num;
        

        if(left_data != 0) {
            if (node[left_data] == NULL) {
                node[left_data] = makeNode(left_data, NULL, NULL);
            }
            node[num]->left = node[left_data];
        }
        if(right_data != 0) {
            if (node[right_data] == NULL) {
                node[right_data] = makeNode(right_data, NULL, NULL);
            }
            node[num]->right = node[right_data];
        }
    }

    printf("PreOrder: ");
    preOrder(node[fir_node]);
    printf("\n");

    return 0;
}
