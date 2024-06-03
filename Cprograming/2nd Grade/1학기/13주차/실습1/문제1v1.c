#include <stdio.h>
#include <stdlib.h>

typedef int element;

// 노드 구조체 정의
typedef struct TreeNode {
    element data;               // 노드의 데이터
    struct TreeNode* left;     // 왼쪽 자식 노드를 가리키는 포인터
    struct TreeNode* right;    // 오른쪽 자식 노드를 가리키는 포인터
} TreeNode;
/*
- data: 노드에 저장되는 값 (아래 문제에서 폴더의 용량) 
- left: 좌측 child 노드를 가리키는 링크
- right: 우측 child 노드를 가리키는 링크

*/

// 노드 생성 함수
TreeNode* makeNode(element data, TreeNode *left, TreeNode *right) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(1);
    }
    node->data = data;

    node->left = left;
    node->right = right;

    return node;
}

// 전위 순회 함수
//노드를 자손들보다 먼저 방문하는 순회 방법
void preOrder(TreeNode* node) {
    if (node != NULL) {
        printf("%d ", node->data); // 현재 노드 방문 
        preOrder(node->left); // 왼쪽 서브트리 방문
        preOrder(node->right); // 오른쪽 서브트리 방문
    }
}


// 중위 순회 함수
//노드를 왼쪽 자식들 다음에, 오른쪽 자식들보다 앞서 방문
void inOrder(TreeNode* node) {
    if (node != NULL) {
        inOrder(node->left); // 왼쪽 서브트리 방문
        printf("%d ", node->data); // 현재 노드 방문
        inOrder(node->right); // 오른쪽 서브트리 방문
    }
}

// 후위 순회 함수
void postOrder(TreeNode* node) {
    if (node != NULL) {
        postOrder(node->left); // 왼쪽 서브트리 방문
        postOrder(node->right); // 오른쪽 서브트리 방문
        printf("%d ", node->data); // 현재 노드 방문
    }
}
// 노드의 요소를 반환
element elementNode(TreeNode* v) {return v->data;}

// 노드 v의 왼쪽 자식을 반환
TreeNode* leftChild(TreeNode* v) {return v->left;}

// 노드 v의 오른쪽 자식을 반환
TreeNode* rightChild(TreeNode* v) {return v->right;}

int main(){
    TreeNode *n8 = makeNode(80,NULL,NULL);
    TreeNode *n7 = makeNode(130,NULL,NULL);
    TreeNode *n6 = makeNode(120,n7,n8);
    TreeNode *n5 = makeNode(90,NULL,NULL);
    TreeNode *n4 = makeNode(70,NULL,NULL);
    TreeNode *n3 = makeNode(50,NULL,n6);
    TreeNode *n2 = makeNode(30,n4,n5);
    TreeNode *n1 = makeNode(20,n2,n3);

    TreeNode *tmp;

    int n; scanf("%d",&n);
    switch (n)
    {
        case 1: tmp = n1;break;
        case 2: tmp = n2;break;
        case 3: tmp = n3;break;
        case 4: tmp = n4;break;
        case 5: tmp = n5;break;
        case 6: tmp = n6;break;
        case 7: tmp = n7;break;
        case 8: tmp = n8;break;

        default: printf("-1"); exit(1);
    }

    
    printf("%d ",elementNode(tmp));
    if(leftChild(tmp)!=NULL) printf("%d ",elementNode(leftChild(tmp)));
    if(rightChild(tmp)!=NULL) printf("%d ",elementNode(rightChild(tmp)));

    // preOrder(tmp);

    // printf("Pre : "); preOrder(n1);printf("\n");
    // printf("In : "); inOrder(n1);printf("\n");
    // printf("Post : "); postOrder(n1);printf("\n");

}