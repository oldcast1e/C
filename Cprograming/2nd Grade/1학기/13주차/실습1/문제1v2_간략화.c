#include <stdio.h>
#include <stdlib.h>

typedef int element;

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

    int n; scanf("%d",&n);//입력받기
    switch (n)// // 입력된 번호에 따라 tmp가 가리킬 노드를 결정
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
    printf("%d ",elementNode(tmp));//현재 노드 출력
    if(leftChild(tmp)!=NULL) printf("%d ",elementNode(leftChild(tmp)));// 왼쪽 자식이 존재하면 왼쪽 자식의 데이터 출력
    if(rightChild(tmp)!=NULL) printf("%d ",elementNode(rightChild(tmp))); //오른쪽 자식이 존재하면 오른쪽 자식의 데이터 출력

}