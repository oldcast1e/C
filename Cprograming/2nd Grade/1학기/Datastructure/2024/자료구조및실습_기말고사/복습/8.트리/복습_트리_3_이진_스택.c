#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char element;
#define MAX_SIZE 100 //배열 스택 사이즈

typedef struct TreeNode{
    element data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct {
    // TreeNode *stack; // 스택에 노드를 저장한다. (수정 전 코드)
    TreeNode **stack; // 스택에 노드 포인터를 저장한다. (수정 후 코드)
    int top; // 스택의 최상위 원소의 인덱스를 나타내는 변수
} StackType;

void initStack(StackType *S){
    // S->stack = (TreeNode *)malloc(sizeof(TreeNode)*MAX_SIZE); (수정 전 코드)
    S->stack = (TreeNode **)malloc(sizeof(TreeNode*) * MAX_SIZE); // (수정 후 코드)
    S->top = -1;
}

int isFull(StackType *S){ return(S->top == MAX_SIZE-1); }
int isEmpty(StackType *S){ return(S->top == -1); }

void push(StackType *S, TreeNode* node){
    if(isFull(S)){ printf("Stack is Full."); exit(1); }
    // S->stack[++S->top] = *root; (수정 전 코드)
    S->stack[++S->top] = node; // (수정 후 코드)
}

TreeNode* pop(StackType *S){
    if(isEmpty(S)){ printf("Stack is Empty."); exit(1); }
    // return &S->stack[S->top--]; (수정 전 코드)
    return S->stack[S->top--]; // (수정 후 코드)
}

void preorder(TreeNode* root){
    StackType S; initStack(&S);
    TreeNode* node = root;

    push(&S, node);

    while(!isEmpty(&S)){
        node = pop(&S);
        printf("[%c]", node->data);

        if(node->right != NULL) push(&S, node->right);
        if(node->left != NULL) push(&S, node->left);
    }
    
    // 스택 메모리 해제
    free(S.stack); // (수정 후 추가)
}

void inorder(TreeNode* root){
    StackType S; initStack(&S);
    TreeNode* node = root;

    // push(&S, root); (수정 전 코드)

    while(1){
        // while(node){  node = node->left; push(&S,node);} (수정 전 코드)
        for (; node != NULL; node = node->left) { push(&S, node); } // (수정 후 코드)
        if(isEmpty(&S)) { break; }
        
        node = pop(&S); printf("[%c]", node->data);
        node = node->right;
    }

    // 스택 메모리 해제
    free(S.stack); // (수정 후 추가)
}

void postorder(TreeNode* root){
    StackType S1,S2; initStack(&S1); initStack(&S2);

    if(root != NULL) push(&S1, root);

    while(!isEmpty(&S1)){
        TreeNode* node = pop(&S1);

        push(&S2, node);
        if(node->left) push(&S1, node->left);
        if(node->right) push(&S1, node->right);
    }
    while(!isEmpty(&S2)){
        TreeNode* node = pop(&S2);
        printf("[%c]",node->data);
    } 
}

TreeNode* makeNode(element data, TreeNode* left, TreeNode* right){
    TreeNode * node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = left; 
    node->right = right;
    return node;
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

    preorder(n1); printf("\n");
    inorder(n1); printf("\n");
    postorder(n1); printf("\n");
    // push(&S, n1);
    // printf("[%c]", pop(&S).data);
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
