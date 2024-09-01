#include <stdio.h>
#include <stdlib.h>

typedef char element;

// 노드 구조체 정의
typedef struct TreeNode {
    element data;               // 노드의 데이터
    struct TreeNode* parent;   // 부모 노드를 가리키는 포인터
    struct TreeNode* left;     // 왼쪽 자식 노드를 가리키는 포인터
    struct TreeNode* right;    // 오른쪽 자식 노드를 가리키는 포인터
} TreeNode;

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

// 전위 순회 함수
//노드를 자손들보다 먼저 방문하는 순회 방법
void preOrder(TreeNode* node) {
    if (node != NULL) {
        printf("%c ", node->data); // 현재 노드 방문 
        preOrder(node->left); // 왼쪽 서브트리 방문
        preOrder(node->right); // 오른쪽 서브트리 방문
    }
}


// 중위 순회 함수
//노드를 왼쪽 자식들 다음에, 오른쪽 자식들보다 앞서 방문
void inOrder(TreeNode* node) {
    if (node != NULL) {
        inOrder(node->left); // 왼쪽 서브트리 방문
        printf("%c ", node->data); // 현재 노드 방문
        inOrder(node->right); // 오른쪽 서브트리 방문
    }
}

// 후위 순회 함수
void postOrder(TreeNode* node) {
    if (node != NULL) {
        postOrder(node->left); // 왼쪽 서브트리 방문
        postOrder(node->right); // 오른쪽 서브트리 방문
        printf("%c ", node->data); // 현재 노드 방문
    }
}

int main(){
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

    printf("Pre : "); preOrder(n1);printf("\n");
    printf("In : "); inOrder(n1);printf("\n");
    printf("Post : "); postOrder(n1);printf("\n");

}