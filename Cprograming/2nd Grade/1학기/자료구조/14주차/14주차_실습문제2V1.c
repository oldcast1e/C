#include <stdio.h>
#include <stdlib.h>

typedef char element;

// 노드 구조체 정의
typedef struct TreeNode {
    element num;               // 노드의 데이터
    struct TreeNode* left;     // 왼쪽 자식 노드를 가리키는 포인터
    struct TreeNode* right;    // 오른쪽 자식 노드를 가리키는 포인터
} TreeNode;

/*
트리는 연결이진트리로 구현 (또는 링크 표현법 사용)하고, 각 노드에 저장되는 정보는 아래 와 같다.
1.왼쪽 자식 링크 노드 
2. 번호 
3. 오른쪽 자식 링크

전위(선위) 순서로 각 노드에 대한 정보가 주어지면, 
    트리를 루트부터 확장해 가는 방식 으로 트리를 구성할 수 있다.

- 노드 번호는 양의 정수로 모두 다르고, 노드 번호에 특별한 순서는 없다.
- 각 노드의 정보는 3개의 정수, (x, y, z)로 표현되는 데, 
    x는 해당 노드의 번호, 
    y는 x의 왼 쪽 자식 노드의 번호, 
    z는 x의 오른쪽 자식 노드의 번호를 나타낸다.
- 해당되는 자식이 없는 경우에는 0 이 주어진다.
*/

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

// 전위 순회 함수
void preOrder(TreeNode* node) {
    if (node != NULL) {
        printf("%c ", node->num); // 현재 노드 방문 
        preOrder(node->left); // 왼쪽 서브트리 방문
        preOrder(node->right); // 오른쪽 서브트리 방문
    }
}

// 중위 순회 함수
void inOrder(TreeNode* node) {
    if (node != NULL) {
        inOrder(node->left); // 왼쪽 서브트리 방문
        printf("%c ", node->num); // 현재 노드 방문
        inOrder(node->right); // 오른쪽 서브트리 방문
    }
}

// 후위 순회 함수
void postOrder(TreeNode* node) {
    if (node != NULL) {
        postOrder(node->left); // 왼쪽 서브트리 방문
        postOrder(node->right); // 오른쪽 서브트리 방문
        printf("%c ", node->num); // 현재 노드 방문
    }
}

// 노드의 요소를 반환
element elementNode(TreeNode* v) {return v->num;}

// 노드 v의 왼쪽 자식을 반환
TreeNode* leftChild(TreeNode* v) {return v->left;}

// 노드 v의 오른쪽 자식을 반환
TreeNode* rightChild(TreeNode* v) {return v->right;}

// 노드 v가 내부노드인지 확인
int isInternal(TreeNode* v) {return v->left != NULL || v->right != NULL;}

// 노드 v가 외부노드인지 확인
int isExternal(TreeNode* v) {return v->left == NULL && v->right == NULL;}

// 노드 v의 요소를 e로 설정
void setElement(TreeNode* v, element e) {v->num = e;}

// 노드 v와 w의 요소를 교환
void swapElements(TreeNode* v, TreeNode* w) {
    element temp = v->num;
    v->num = w->num;
    w->num = temp;
}

int main(){
    // int n; scanf("%d",&n);
    int cnt = 0;
    int n = 1;
    TreeNode **node = (TreeNode **)malloc(sizeof(TreeNode*)*n);
    for(int i=0;i<n*3;i++) node[i] = (TreeNode *)malloc(sizeof(TreeNode)*n);

    int num,right_data,left_data;
    int fir_node;
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&num,&left_data,&right_data);
        if(i==0) fir_node = num;
        node[num]->left = node[left_data]; node[left_data]->num = left_data;
        node[num]->right = node[right_data]; node[right_data]->num = right_data;
    }

    preOrder(node[fir_node]);
    return 0;
}
/*


예) 
5 3 9 ➜5의왼쪽자식은3,오른쪽자식은9
3 8 15 ➜3의왼쪽자식은8,오른쪽자식은15
8 0 2 ➜ 8의 왼쪽 자식은 없고, 오른쪽 자식은 2
2 0 0 ➜ (이하 생략)
15 0 0
9 7 10
7 12 0
12 0 0
10 0 0

위 노드 정보에서, x에 해당하는 노드 번호를 차례로 쓰면, 
    전위(선위) 순회 결과가 된다. 5 3 8 2 15 9 7 12 10
*/