#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef int element;  // element 타입을 int로 정의

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


TreeNode* leftChild(TreeNode* v) {return v->left;}// 노드 v의 왼쪽 자식을 반환
TreeNode* rightChild(TreeNode* v) {return v->right;}// 노드 v의 오른쪽 자식을 반환
element elementNode(TreeNode* v) {return v->num;}

// 전위 순회 함수
void preOrder(TreeNode* node) {
    if (node != NULL) {
        printf("%d ", node->num); // 현재 노드 방문 
        preOrder(node->left); // 왼쪽 서브트리 방문
        preOrder(node->right); // 오른쪽 서브트리 방문
    }
}

// 중위 순회 함수
void inOrder(TreeNode* node) {
    if (node != NULL) {
        inOrder(node->left); // 왼쪽 서브트리 방문
        printf("%d ", node->num); // 현재 노드 방문
        inOrder(node->right); // 오른쪽 서브트리 방문
    }
}

// 후위 순회 함수
void postOrder(TreeNode* node) {
    if (node != NULL) {
        postOrder(node->left); // 왼쪽 서브트리 방문
        postOrder(node->right); // 오른쪽 서브트리 방문
        printf("%d ", node->num); // 현재 노드 방문
    }
}

int main() {
    int n; 
    // printf("Enter the number of nodes: ");
    scanf("%d", &n);

    TreeNode** node = (TreeNode**)malloc(sizeof(TreeNode*) * 1000);
    for (int i = 0; i < 1000; i++) {
        node[i] = NULL;
    }

    int num, left_data, right_data;
    TreeNode* root = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &num, &left_data, &right_data);

        if (node[num] == NULL) {
            node[num] = makeNode(num, NULL, NULL);
        }

        if (i == 0) {
            root = node[num];
        }

        if (left_data != 0) {
            if (node[left_data] == NULL) {
                node[left_data] = makeNode(left_data, NULL, NULL);
            }
            node[num]->left = node[left_data];
        }

        if (right_data != 0) {
            if (node[right_data] == NULL) {
                node[right_data] = makeNode(right_data, NULL, NULL);
            }
            node[num]->right = node[right_data];
        }
    }

    // printf("PreOrder: ");
    // preOrder(root);
    // printf("\nInOrder: ");
    // inOrder(root);
    // printf("\nPostOrder: ");
    // postOrder(root);printf("\n");

    // free(node);
    int find; scanf("%d",&find);
    for(int i=0;i<find;i++){
        TreeNode* tmp = root;
        char fuc[10]; scanf("%s",fuc);

        for(int j=0;j<(int)strlen(fuc);j++){
            if(j == 0) printf(" %d",tmp->num);
            if(fuc[j] == 'L') {
                printf(" %d",elementNode(leftChild(tmp)));
                tmp = tmp->left;
            }
            else if(fuc[j] == 'R') {
                printf(" %d",elementNode(rightChild(tmp)));
                tmp = tmp->right;
            }
        }
    }

    return 0;
}
/*
9
3 8 15
8 0 2
2 0 0
15 0 0
9 7 10
7 12 0
12 0 0
10 0 0

9

5 3 9
3 8 15
8 0 2
2 0 0
15 0 0
9 7 10
7 12 0
12 0 0
10 0 0
*/