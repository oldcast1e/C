#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef int element;

// typedef struct treeType{
//     struct treeNode* root;
//     int size;
// }treeType;

typedef struct treeNode{
    struct treeNode* left;
    struct treeNode* right;
    element data;
}treeNode;

// void init(treeType* T){
//     T->root = (treeNode*)malloc(sizeof(treeNode));
//     T->size = 0;
// }

treeNode* makeNode(element e,treeNode* left,treeNode* right){
    treeNode* new = (treeNode*)malloc(sizeof(treeNode));
    new->data = e;
    new->left = left;
    new->right = right;

    return new;
}

void preOrder(treeNode* node){
    //왼쪽자식-루트-오른쪽자식
    if(node == NULL) return;
    preOrder(node->left);
    printf("[%d] ",node->data);
    preOrder(node->right);
}

void inOrder(treeNode* node){
    //왼쪽자식-루트-오른쪽자식
    if(node == NULL) return;
    printf("[%d] ",node->data);
    inOrder(node->left);
    inOrder(node->right);
}

void postOrder(treeNode* node){
    //왼쪽자식-루트-오른쪽자식
    if(node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    printf("[%d] ",node->data);
}

int main(){
    treeNode* n9 = makeNode(9,NULL,NULL);
    treeNode* n8 = makeNode(8,NULL,NULL);
    treeNode* n7 = makeNode(7,NULL,NULL);
    treeNode* n6 = makeNode(6,NULL,NULL);
    treeNode* n5 = makeNode(5,NULL,NULL);
    treeNode* n4 = makeNode(4,n8,n9);
    treeNode* n3 = makeNode(3,n6,n7);
    treeNode* n2 = makeNode(2,n4,n5);
    treeNode* n1 = makeNode(1,n2,n3);

    preOrder(n1); printf("\n");
    inOrder(n1); printf("\n");
    postOrder(n1); //printf("\n");
}
/*
                            1
                2                       3
        4               5       6               7
    8       9       

*/