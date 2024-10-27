/*
[ 문제 2 ] 위에서 설명한 방식대로 트리 정보와 탐색 정보가 주어졌을 때, 트리를 생성하고 탐색
도중 방문하는 노드 번호를 차례로 출력하는 프로그램을 작성하시오.

입력 상세:
◦ 트리 정보
- 첫 째 줄에 노드의 개수 n이 주어진다.
- 다음 n개의 줄에, 선위순회 순서로 노드의 정보가 주어진다(위 설명 참조).
◦ 탐색 정보 (트리 정보가 모두 주어진 후)
- 탐색 횟수 s가 주어진다.
- 다음 s개의 줄에 탐색 정보가 주어진다(각 탐색은 루트에서 새로 시작).
- 하나의 탐색 정보는 공백없이, L과 R로 구성된 문자열(최대 길이 100)로 주어진다.
- 유효하지 않은 탐색 정보는 주어지지 않는다. 예를 들어, 위 트리에서 RRR 과 같은 탐색
정보는 유효하지 않다. 두 번 오른쪽 자식을 따라 내려가면 노드 10인데, 노드 10의
오른쪽 자식은 정의되지 않았다.
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int element;

typedef struct treeNode{
    struct treeNode* left;
    struct treeNode* right;
    element data;
}treeNode;


treeNode* makeNode(element e,treeNode* left,treeNode* right){
    treeNode* new = (treeNode*)malloc(sizeof(treeNode));
    new->data = e;

    new->left = left;
    new->right = right;
    return new;
}

void preOrder(treeNode* node){
    if(node == NULL) return;
    printf("%d ",node->data);
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(treeNode* node){
    if(node == NULL) return;
    inOrder(node->left);
    printf("[%d] ",node->data);
    inOrder(node->right);
}

void postOrder(treeNode* node){
    if(node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    printf("[%d] ",node->data);
}

int main(){
    treeNode** treeList = (treeNode**)malloc(sizeof(treeNode*)*1001);
    for(int i=1;i<1001+1;i++) treeList[i] = NULL;

    int nodeNum,finNum,root;
    int data,leftData,rightData;
    scanf("%d",&nodeNum);

    for(int i=0;i<nodeNum;i++){
        scanf("%d %d %d",&data,&leftData,&rightData);
        if(i == 0) root = data;

        if(treeList[data] == NULL) 
            treeList[data] = makeNode(data,NULL,NULL);
        // treeList[data]->data = data;

        if(leftData != 0) {
            treeList[leftData] = makeNode(leftData,NULL,NULL);
            treeList[data]->left = treeList[leftData];
        }
        if(rightData != 0){
            treeList[rightData] = makeNode(rightData,NULL,NULL);
            treeList[data]->right = treeList[rightData];
        }
        // treeList[data] = makeNode(data,treeList[leftData],treeList[rightData]);
    }
    // scanf("%d",&finNum);
    // printf("root : %d\n",root);

    preOrder(treeList[root]);
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
RLL
LL
LR
*/