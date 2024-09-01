#include <stdio.h>
#include <stdlib.h>

typedef char element;

// 노드 구조체 정의
typedef struct TreeNode {
    element key;               // 노드의 데이터
    struct TreeNode* parent;   // 부모 노드를 가리키는 포인터
    struct TreeNode* left;     // 왼쪽 자식 노드를 가리키는 포인터
    struct TreeNode* right;    // 오른쪽 자식 노드를 가리키는 포인터
} TreeNode;

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

// 노드의 요소를 반환
element elementNode(TreeNode* v) {return v->key;}

// 루트 노드를 반환
TreeNode* root(TreeNode* node) {
    while (node->parent != NULL) {
        node = node->parent;
    }
    return node;
}

// 노드 v가 루트인지 확인
int isRoot(TreeNode* v) {return v->parent == NULL;}

// 노드 v의 부모를 반환
TreeNode* parent(TreeNode* v) {return v->parent;}

// 노드 v의 왼쪽 자식을 반환
TreeNode* leftChild(TreeNode* v) {return v->left;}

// 노드 v의 오른쪽 자식을 반환
TreeNode* rightChild(TreeNode* v) {return v->right;}

// 노드 v의 형제를 반환
TreeNode* sibling(TreeNode* v) {
    if (v->parent == NULL) return NULL;
    if (v->parent->left == v) return v->parent->right;
    else return v->parent->left;
}

// 노드 v가 내부노드인지 확인
int isInternal(TreeNode* v) {return v->left != NULL || v->right != NULL;}

// 노드 v가 외부노드인지 확인
int isExternal(TreeNode* v) {return v->left == NULL && v->right == NULL;}

// 노드 v의 요소를 e로 설정
void setElement(TreeNode* v, element e) {v->key = e;}

// 노드 v와 w의 요소를 교환
void swapElements(TreeNode* v, TreeNode* w) {
    element temp = v->key;
    v->key = w->key;
    w->key = temp;
}

// int height(TreeNode* v){
//     if(isExternal(v)) return 0;
//     else{
//         int leftHeight = height(v->left);
//         int rightHeight = height(v->right);
//         return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
//     }
// }

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

    // 메서드 테스트
    printf("Element of n1: %c\n", elementNode(n1));
    printf("Root of n1: %c\n", elementNode(root(n1)));
    printf("n1 is root: %d\n", isRoot(n1));
    printf("Parent of n3: %c\n", elementNode(parent(n3)));
    printf("Left child of n2: %c\n", elementNode(leftChild(n2)));
    printf("Right child of n2: %c\n", elementNode(rightChild(n2)));
    printf("Sibling of n2: %c\n", elementNode(sibling(n2)));
    printf("n1 is internal: %d\n", isInternal(n1));
    printf("n11 is external: %d\n", isExternal(n11));
    setElement(n1, 'Z');
    printf("New element of n1: %c\n", elementNode(n1));
    swapElements(n1, n2);
    printf("After swap, element of n1: %c, element of n2: %c\n", elementNode(n1), elementNode(n2));

    return 0;
}
