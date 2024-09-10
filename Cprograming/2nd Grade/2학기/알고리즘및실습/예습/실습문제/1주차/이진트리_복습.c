#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef int element;

typedef struct TreeNode{
    element key;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(element key){
    TreeNode* new = (TreeNode*)malloc(sizeof(TreeNode*));
    new->key = key;

    new->left = NULL;
    new->right = NULL;

    return new;
}

int main(){

}
