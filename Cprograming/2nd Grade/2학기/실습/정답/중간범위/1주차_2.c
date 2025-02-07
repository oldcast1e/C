#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int element;

typedef struct TreeNode{
    element data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(element data, TreeNode* left, TreeNode* right){
    TreeNode* new = (TreeNode*)malloc(sizeof(TreeNode));
    new->data = data;
    new->left =  left;
    new->right = right;
    return new;
}

void preOrder(TreeNode* node){
    if(node!=NULL){
        printf("%d ",node->data);
        if(node->left!=NULL) preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TreeNode* node){
    if(node!=NULL){
        inOrder(node->left);
        printf("%d ",node->data);
        inOrder(node->right);
    }
}

void postOrder(TreeNode* node){
    if(node!=NULL){
        postOrder(node->left);
        postOrder(node->right);
        printf("%d ",node->data);
    }
}

int invaildCheck(TreeNode* root, char *arr){
    int check = 1;
    for(int i=0;i<(int)strlen(arr);i++){
        if(arr[i] == 'L'){
            if(root->left == NULL) check = 0;
            root = root->left;
        }
        if(arr[i] == 'R'){
            if(root->right == NULL) check = 0;
            root = root->right;
        }
    }
    return check;
}

int main(){
    TreeNode** TreeList = (TreeNode**)malloc(sizeof(TreeNode*)*1001);
    for(int i=0; i<1001;i++) TreeList[i] = NULL;

    int n;scanf("%d",&n);
    int firNode,key,leftData,rightData;
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&key,&leftData,&rightData);//5 3 9
        if(i == 0) firNode = key;
        // if(TreeList[key] == NULL) TreeList[key] = (TreeNode*)malloc(sizeof(TreeNode));
        if(TreeList[key] == NULL) TreeList[key] = makeNode(key,NULL,NULL);

        TreeList[key]->data = key;
        if(leftData != 0){
            TreeList[leftData] = makeNode(leftData,NULL,NULL);
            TreeList[key]->left = TreeList[leftData];
            // TreeList[key]->left = makeNode(leftData,NULL,NULL);
        }
        if(rightData != 0){
            // TreeList[key]->right = makeNode(rightData,NULL,NULL);
            TreeList[rightData] = makeNode(rightData,NULL,NULL);
            TreeList[key]->right = TreeList[rightData];
        }
    }
    // preOrder(TreeList[5]);
    int m; scanf("%d",&m); getchar();
    for(int i=0 ; i<m ; i++){
        char arr[100];scanf("%s",arr); getchar();
        TreeNode* tmp = TreeList[firNode];
        if(invaildCheck(tmp,arr)){
            // printf("OK\n");
            for(int j = 0; j< (int)strlen(arr)+1;j++){
                if(tmp == NULL) break;
                printf(" %d",tmp->data);
                switch(arr[j]){
                    case 'L':
                        tmp = tmp->left;
                        break;  
                    case 'R':
                        tmp = tmp->right;
                        break;
                }
            }printf("\n");
        }
    }

}
/*
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
3
RRR
RR
R

RLL
LL
LR
*/