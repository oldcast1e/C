#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100

typedef char element;

typedef struct TreeNode{
    element data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct{
    TreeNode **que; // 배열 포인터 
    int front, rear;
    int size; //현재 데이터 개수
} QueueType;

void initQue(QueueType* Q){
    Q->que = (TreeNode**)malloc(sizeof(TreeNode*)*MAX);
    Q->front = Q->rear = -1;
    Q->size = 0;
}

int isEmpty(QueueType* Q){return(Q->size == 0);}
int isFull(QueueType* Q){return(Q->rear >= MAX - 1);}

void enque(QueueType* Q, TreeNode* node){
    Q->que[ ++ Q->rear] = node;
    Q->size ++;
}

TreeNode* deque(QueueType* Q){
    TreeNode* node = Q->que[Q->front + 1];
    Q->front++;

    Q->size--;
    return node;
}


TreeNode* makeNode(element data, TreeNode* left, TreeNode* right){
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;

    node->left = left;
    node->right = right;

    return node;
}

void preorder(TreeNode* root) {
    if (root == NULL) return;
    printf("[%c]", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("[%c]", root->data);
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("[%c]", root->data);
}

void EulerTour(TreeNode* root) {
    if (root == NULL) return;
    printf("[%c]", root->data);

    if(root->left) EulerTour(root->left);
    printf("[%c]", root->data);

    if(root->left) EulerTour(root->right);
    printf("[%c]", root->data);

}

int main(){
    TreeNode *n10 = makeNode('J', NULL, NULL);
    TreeNode *n9 = makeNode('I', NULL, NULL);
    TreeNode *n8 = makeNode('H', NULL, NULL);
    TreeNode *n7 = makeNode('G', NULL, NULL);
    TreeNode *n6 = makeNode('F', NULL, NULL);
    TreeNode *n5 = makeNode('E', n10, NULL);
    TreeNode *n4 = makeNode('D', n8, n9);
    TreeNode *n3 = makeNode('C', n6, n7);
    TreeNode *n2 = makeNode('B', n4, n5);
    TreeNode *n1 = makeNode('A', n2, n3);

    // QueueType Q; initQue(&Q);
    preorder(n1); printf("\n");
    inorder(n1);  printf("\n");
    postorder(n1);printf("\n");
    EulerTour(n1);

}
/*
[A][B][C][D][E][F][G][H][I]

                                A
                B                               C
        D                E               F             G
    H       I       J

전위 순회 결과:[A][B][D][H][I][E][J][C][F][G]
중위 순회 결과: [H][D][I][B][J][E][A][F][C][G]
후위 순회 결과: [H][I][D][J][E][B][F][G][C][A]


*/