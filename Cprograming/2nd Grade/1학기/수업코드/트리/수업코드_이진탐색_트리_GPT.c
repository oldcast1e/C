#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int key;
    struct TreeNode *left, *right;
} TreeNode;

typedef int element;

typedef struct {
    element *key;
    int front, rear;
    int size;
} QueueType;

TreeNode *findMin(TreeNode *root) ;

int isEmpty(QueueType *Q) {
    return Q->front == Q->rear;
}

int isFull(QueueType *Q) {
    return (Q->rear + 1) % Q->size == Q->front;
}

TreeNode* makeNode(int key) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void preOrder(TreeNode* root) {
    if (root) {
        printf("[%d] ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

TreeNode *insert(TreeNode* root, element key) {
    if (root == NULL) {
        return makeNode(key);
    }
    if (root->key > key) {
        root->left = insert(root->left, key);
    } else if (root->key < key) {
        root->right = insert(root->right, key);
    }

    return root;
}
TreeNode *delete(TreeNode *root, element key) {
    if (root == NULL) { // 키를 찾지 못한 경우
        return NULL;
    } else {
        if (root->key < key) { // 삭제할 노드가 현재 노드보다 오른쪽에 있는 경우
            root->left = delete(root->left, key);
        } else if (root->key > key) { // 삭제할 노드가 현재 노드보다 왼쪽에 있는 경우
            root->right = delete(root->right, key);
        } else { // 삭제할 노드를 찾은 경우
            if (root->left == NULL) { // 삭제할 노드가 왼쪽 서브 트리만 가지고 있는 경우 또는 단말 노드인 경우
                TreeNode *temp = root->right; // 삭제할 노드를 오른쪽 자식으로 대체
                free(root); // 삭제할 노드 메모리 해제
                return temp; // 대체된 노드 반환
            } 
            else if (root->right == NULL) { // 삭제할 노드가 오른쪽 서브 트리만 가지고 있는 경우
                TreeNode *temp = root->left; // 삭제할 노드를 왼쪽 자식으로 대체
                free(root); // 삭제할 노드 메모리 해제
                return temp; // 대체된 노드 반환
            } 
            else { // 삭제할 노드가 두 개의 자식을 모두 가진 경우
                // 오른쪽 서브 트리에서 가장 작은 값을 찾아 해당 값을 삭제할 노드로 대체
                TreeNode *temp = findMin(root->right);
                root->key = temp->key; // 삭제할 노드의 값을 오른쪽 서브 트리에서 가장 작은 값으로 대체
                root->right = delete(root->right, temp->key); // 오른쪽 서브 트리에서 가장 작은 값 삭제
            }
        }
    }
    return root;
}


TreeNode *findMin(TreeNode *root) {
    TreeNode *current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

void print(TreeNode* root, char *msg , element key){
    if (root == NULL) {
        printf("[%s %2d] : \n", msg, key);
        return;
    }
    printf("[%s %2d] : ",msg,key);
    preOrder(root);
    printf("\n");
}


int main() {
    TreeNode *root = NULL;
    element data[] = { 35, 18, 7, 26, 3, 22, 39, 12, 26, 68, 99 };

    for (int i = 0; i < sizeof(data) / sizeof(int); i++) {
        root = insert(root, data[i]);
        print(root, "Insert", data[i]);
    }
    
    element deleteKey = 68;
    root = delete(root, deleteKey);
    print(root, "Delete", deleteKey);

    return 0;
}
