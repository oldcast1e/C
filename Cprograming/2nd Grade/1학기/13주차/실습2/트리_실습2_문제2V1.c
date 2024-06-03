#include <stdio.h>
#include <stdlib.h>

typedef int element;
int sum = 0;
// 노드 구조체 정의
typedef struct TreeNode {
    element data;               // 노드의 데이터
    struct TreeNode* left;     // 왼쪽 자식 노드를 가리키는 포인터
    struct TreeNode* right;    // 오른쪽 자식 노드를 가리키는 포인터
} TreeNode;

// 노드 생성 함수
TreeNode* makeNode(element data, TreeNode *left, TreeNode *right) {
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(1);
    }
    node->data = data; // 데이터 저장

    node->left = left; // 왼쪽 노드 생성
    node->right = right;//오른쪽 노드 생성

    return node; //반환
}

element elementNode(TreeNode* v) {return v->data;}// 노드의 요소를 반환
TreeNode* leftChild(TreeNode* v) {return v->left;}// 노드 v의 왼쪽 자식을 반환
TreeNode* rightChild(TreeNode* v) {return v->right;}// 노드 v의 오른쪽 자식을 반환

// 전위 순회 함수
//노드를 자손들보다 먼저 방문하는 순회 방법
void preOrder(TreeNode* node) {
    if (node != NULL) {
        // printf(" %d", node->data); // 현재 노드 방문 
        sum += node->data;
        preOrder(node->left); // 왼쪽 서브트리 방문
        preOrder(node->right); // 오른쪽 서브트리 방문
    }
}


// 중위 순회 함수
//노드를 왼쪽 자식들 다음에, 오른쪽 자식들보다 앞서 방문
void inOrder(TreeNode* node) {
    if (node != NULL) {
        inOrder(node->left); // 왼쪽 서브트리 방문
        printf(" %d", node->data); // 현재 노드 방문
        inOrder(node->right); // 오른쪽 서브트리 방문
    }
}

// 후위 순회 함수
void postOrder(TreeNode* node) {
    if (node != NULL) {
        postOrder(node->left); // 왼쪽 서브트리 방문
        postOrder(node->right); // 오른쪽 서브트리 방문
        printf(" %d", node->data); // 현재 노드 방문
    }
}

int main(){
    //조건에 따른 트리 노드 생성
    TreeNode *n8 = makeNode(80,NULL,NULL);
    TreeNode *n7 = makeNode(130,NULL,NULL);
    TreeNode *n6 = makeNode(120,n7,n8);
    TreeNode *n5 = makeNode(90,NULL,NULL);
    TreeNode *n4 = makeNode(70,NULL,NULL);
    TreeNode *n3 = makeNode(50,NULL,n6);
    TreeNode *n2 = makeNode(30,n4,n5);
    TreeNode *n1 = makeNode(20,n2,n3);

    TreeNode *tmp; // 입력된 값에 따른 노드를 저장할 임의의 노드 변수

    int key,node; 
    // scanf("%d %d",&key,&node);//입력받기
    scanf("%d",&node);//입력받기
    /*
    ◦ 트리 순회를 이용하여 구현
    ◦ 합을 계산할 때 입력된 노드의 용량도 포함
    ◦ 존재하지 않는 폴더 이름이 입력되는 경우 –1을 출력
    */

    //1 2 ↦ 1: 전위순회, 노드 id
    switch (node)// // 입력된 번호에 따라 tmp가 가리킬 노드를 결정
    {
        case 1: tmp = n1;break;
        case 2: tmp = n2;break;
        case 3: tmp = n3;break;
        case 4: tmp = n4;break;
        case 5: tmp = n5;break;
        case 6: tmp = n6;break;
        case 7: tmp = n7;break;
        case 8: tmp = n8;break;

        default: printf("-1"); exit(1); // 유효하지 않은 입력 시 프로그램 종료
    }

    preOrder(tmp);
    printf("%d",sum);

}