#include <stdio.h>
#include <stdlib.h>

typedef char element;
#define MAX_SIZE 100 // 배열의 최대 크기 정의

typedef struct NodeType {
    element data;

    struct NodeType *left;
    struct NodeType *right;
} TreeNode;

typedef struct { // 큐 타입을 저장하는 구조체
    TreeNode *data; // 데이터 저장 배열
    int front, rear; // 포인터와 리어 변수
    int size; // 배열의 사이즈
} QueTyoe;

void initQue(QueTyoe *Q){
    Q->data = (TreeNode*)malloc(sizeof(TreeNode)*Q->size); //데이터 저장 배열 동적할당
    Q->front = Q->rear = 0; // 큐의 front와 rear를 초기화
}

int isEmpty(QueTyoe *Q) {return Q->front == Q->rear;}
int isFull(QueTyoe *Q) {return (Q->rear + 1) % Q->size == Q->front;}

void enque(QueTyoe *Q, TreeNode item) { // 큐에 데이터를 넣는 함수
    if (isFull(Q)) {printf("Queue is full\n");exit(1);} //큐가 가득 차있으면 메세지를 출력하고 종료
    
    Q->rear = (Q->rear + 1) % Q->size; // 리어를 증가하고, 증가된 리어의 위치에 데이터 저장(증가되지 않은 리어에는 이미 데이터 저장 되있음)
    Q->data[Q->rear] = item;
}

TreeNode deque(QueTyoe *Q) { // 큐에 데이터를 빼는 함수
    if (isEmpty(Q)) {printf("Queue is empty\n");exit(1);} //큐가 비어있으면 데이터를 뺄 수 없으므로 메세지 출력 후 종료

    Q->front = (Q->front + 1) % Q->size; 
    return Q->data[Q->front];
}

TreeNode* makeNode(element data, TreeNode* left , TreeNode* right){
    TreeNode *node  = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    // printf("add data.\n");
    
    node->left = left; 
    node->right = right;

    return node;
}

void preorder(TreeNode* T){
    printf("[%c]",T->data);
    if(T->left != NULL) preorder(T->left);
    if(T->right != NULL) preorder(T->right);
}

void inorder(TreeNode* T){
    if(T->left != NULL) inorder(T->left);
    printf("[%c]",T->data);
    if(T->right != NULL) inorder(T->right);
}

void postorder(TreeNode* T){
    if(T->left != NULL) postorder(T->left);
    if(T->right != NULL) postorder(T->right);
    printf("[%c]",T->data);
}

void levelOrder(TreeNode* root){
    if(root==NULL) return;

    QueTyoe Q; initQue(&Q);

    enque(&Q,*root);
    // printf("Q size : %d\n",Q.size);

    // printf("[%c]",deque(&Q).data);
    // printf("[%c]",deque(&Q).data);

    while(!isEmpty(&Q)){
        TreeNode node = deque(&Q);
        printf("[%c]",node.data);
        if(node.left) enque(&Q,*node.left);
        if(node.right) enque(&Q,*node.right);
    }
}


void print(TreeNode* T){
    // TreeNode *p = T->node;
    // while(p != NULL){
    //     printf("[%c]",p->data);
    //     p = p->next;
    // }printf("\n");
}

int main(){
    TreeNode *n10 = makeNode('J',NULL,NULL);
    TreeNode *n9 = makeNode('I',NULL,NULL);
    TreeNode *n8 = makeNode('H',NULL,NULL);
    TreeNode *n7 = makeNode('G',NULL,NULL);
    TreeNode *n6 = makeNode('F',NULL,NULL);
    TreeNode *n5 = makeNode('E',n10,NULL);
    TreeNode *n4 = makeNode('D',n8,n9);
    TreeNode *n3 = makeNode('C',n6,n7);
    TreeNode *n2 = makeNode('B',n4,n5);
    TreeNode *n1 = makeNode('A',n2,n3);

    preorder(n1); printf("\n");
    inorder(n1); printf("\n");
    postorder(n1); printf("\n");
    
    levelOrder(n1);
    // QueType Q; initQue(&Q);
    // levelOrder(n1, &Q);

    // enque(&Q,'a'); enque(&Q,'b');enque(&Q,'c');enque(&Q,'d');enque(&Q,'e');
    // printf("[%c]",deque(&Q));printf("[%c]",deque(&Q));printf("[%c]",deque(&Q));
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