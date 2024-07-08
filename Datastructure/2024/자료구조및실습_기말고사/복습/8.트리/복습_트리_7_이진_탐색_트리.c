#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef int element;

typedef struct TreeNode{
    element data;
    struct TreeNode* left, * right;
} TreeNode;

TreeNode* makeNode(element data){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

TreeNode* insert(TreeNode* root, element data){
    
    if (root == NULL) return makeNode(data);

    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);

    return root;
}

TreeNode* findMin(TreeNode* root) {
    
    while (root->left != NULL) root = root->left;
    return root;
}

TreeNode* getMinNode(TreeNode* root){
    
    TreeNode *p = root;
    while(p ->left != NULL) p = p->left;
    return p;
}

TreeNode* delete(TreeNode* root, element data){

    if (root == NULL) return NULL;

    if (data < root->data) root->left = delete(root->left, data);
    else if (data > root->data) root->right = delete(root->right, data);
    else{

        if (root->left == NULL){
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        else{
            //다시 풀기
            TreeNode* temp = getMinNode(root->right);
            root->data = temp->data;
            root->right = delete(root->right,temp->data);

        }

        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

void preOrder(TreeNode* root)
{
    if (root){
        printf("[%d] ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void print(TreeNode* root, char* msg, element data){
    printf("[%s %2d] : ", msg, data);
    preOrder(root);
    printf("\n");
}

int main()
{
    TreeNode* root = NULL; // root 변수를 NULL로 초기화
    element data[] = { 35, 18, 7, 26, 3, 22, 39, 12, 68, 99 };

    for (int i = 0; i < (sizeof(data) / sizeof(int)); i++)
    {
        root = insert(root, data[i]);
        print(root, "Insert", data[i]);
    }
    printf("\n");

    // root = delete(root, 68);
    // print(root, "Delete", 68);

    root = delete(root, 18);
    // print(root, "Delete", 18);

    return 0;
}
/*
                35
                /  \
            18   39
            /  \    \
            7   26   68
            /   /      \
            3  22      99
            \
            12

                    35
                    /  \
                22   39
                /  \    \
                7   26   68
                /         \
                3         99
                \
                12


*/