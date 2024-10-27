#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int element;

typedef struct treeNode{
    struct treeNode* left;
    struct treeNode* right;
    element data;
}treeNode;

treeNode* makeNode(element e, treeNode* left, treeNode* right){
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

int main(){

    int nodeNum, finNum, root;
    int data, leftData, rightData;
    treeNode** treeList = (treeNode**)malloc(sizeof(treeNode*)*1001);
    for(int i=0; i<1000; i++) treeList[i] = NULL;
    scanf("%d", &nodeNum);

    for(int i=0; i<nodeNum; i++){
        scanf("%d %d %d", &data, &leftData, &rightData);
        if(i == 0) root = data; // 루트 노드 설정

        if(treeList[data] == NULL) 
            treeList[data] = makeNode(data, NULL, NULL); // 새 노드 생성
        
        if(leftData != 0) {
            treeList[leftData] = makeNode(leftData, NULL, NULL); // 왼쪽 자식 노드 생성
            treeList[data]->left = treeList[leftData]; // 연결
        }
        if(rightData != 0) {
            treeList[rightData] = makeNode(rightData, NULL, NULL); // 오른쪽 자식 노드 생성
            treeList[data]->right = treeList[rightData]; // 연결
        }
    }

    // preOrder(treeList[root]);
    scanf("%d", &finNum); // 탐색 횟수 입력

    for(int i=0; i<finNum; i++){
        char path[20]; 
        scanf("%s",path); getchar();

        treeNode* tmp = treeList[root];
        printf(" %d", tmp->data); // 시작점인 루트 노드 출력
        for(int i = 0; i < strlen(path); i++){
            if(tmp == NULL) break;

            if(path[i] == 'L') tmp = tmp->left;
            else if(path[i] == 'R') tmp = tmp->right;
            printf(" %d", tmp->data); // 탐색 중 방문한 노드 출력
        }printf("\n");
    }
}

/*
입력 예시:
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

