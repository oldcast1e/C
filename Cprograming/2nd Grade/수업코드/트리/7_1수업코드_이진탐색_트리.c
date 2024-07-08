#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TreeNode { // 트리 노드 구조체 선언
    int key;// 트리의 데이터
    struct TreeNode *left, *right;//트리의 자식 노드 (이진)
} TreeNode;

// typedef TreeNode* element;
typedef int element;

typedef struct { // 큐 타입을 저장하는 구조체
    element *key; // 데이터 저장 배열
    int front, rear; // 포인터와 리어 변수
    int size; // 배열의 사이즈
} QueueType;

int isEmpty(QueueType *Q) {return Q->front == Q->rear;}
//큐의 프런트와 리어가 같은 경우 : 초기의 큐는 프런트와 리어가 같다.
/*
동작 원리: 원형 큐에서 큐가 비어 있는 상태는 front와 rear가 같은 위치를 가리킬 때입니다.

큐를 초기화할 때 front와 rear를 같은 값(예: 0)으로 설정합니다. 
큐에서 요소를 제거할 때마다 front가 증가하고, 큐에 요소를 삽입할 때마다 rear가 증가합니다.
이 경우, 큐가 비어 있으면 front와 rear가 다시 같은 위치를 가리키게 됩니다.
*/
int isFull(QueueType *Q) {return (Q->rear + 1) % Q->size == Q->front;}

// 새로운 노드를 생성하는 함수
TreeNode* makeNode(int key) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// // 자작
// element rightChild(TreeNode* root){
//     if(root){
//         if(root->right) return root->right->key;
//     }return -1;
// }

// // 자작
// element leftChild(TreeNode* root){
//     if(root){
//         if(root->left) return root->left->key;
//     }return -1;
// }

void preOrder(TreeNode* root) {
    if (root) {
        printf("[%d] ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

TreeNode *insert(TreeNode* root, element key){
    if(root == NULL){return makeNode(key);}
    if(root->key > key){root->left = insert(root->left,key);}
    else if(root->key < key) {root->right = insert(root->right,key);}

    return root;
}

/*
삭제

[조건]
1. 단말 또는 오른쪽 서브 트리만 있을 때 
    -> 왼쪽 자식이 없을 때 (오른쪽 자식 여부 상관 X)
    -> 오른쪽 자식 노드 리턴 : 그 오른쪽 자식의 부모가 받음
    -> 중간의 노드가 제거되도 문제가 없음
*/
//(root->key > key){root->right = delete(root->right,key);}
TreeNode *delete(TreeNode *root , element key){
    if(root == NULL){ // 키를 찾지 못한 경우
        return NULL;
    }
    else{
        if(root->key < key){ // 삭제할 노드가 현재 노드보다 오른쪽에 있는 경우
            root->left = delete(root->left,key);
        }
        else if(root->key > key){ // 삭제할 노드가 현재 노드보다 왼쪽에 있는 경우
            root->right = delete(root->right,key);
        }
        else{ // 삭제할 노드를 찾은 경우
            if(root->left == NULL){ // 삭제할 노드가 왼쪽 서브 트리만 가지고 있는 경우
                TreeNode *temp = root->right; // 삭제할 노드를 오른쪽 자식으로 대체
                free(root); // 삭제할 노드 메모리 해제
                return temp; // 대체된 노드 반환
            }
            else if(root->right == NULL){ // 삭제할 노드가 오른쪽 서브 트리만 가지고 있는 경우
                TreeNode *temp = root->left; // 삭제할 노드를 왼쪽 자식으로 대체
                free(root); // 삭제할 노드 메모리 해제
                root = NULL;
                return temp; // 대체된 노드 반환
            }   
        }
    } 
    return root;
}


void print(TreeNode* root, char *msg , element key){
    printf("[%s %2d] : ",msg,key);
    preOrder(root);
    printf("\n");
}

// void binarySearch(TreeNode* root, element key){

// }


// 메인 함수
int main() {
    // 이진 트리 생성
    TreeNode *root = NULL;
    // element data[] = {35, 18, 7, 26, 3, 22, 30, 12, 26, 68, 99};
    element data[] = { 35, 18, 7, 26, 3, 22, 39, 12, 26, 68, 99 };
    /*
    key : 인덱싱을 위한 것 -> 중복 불가(삽입 안됨) : 있으면 확인 후 삽입 안됨
    이진탐색트리 : 다 다른 값, 각자의 자리가 존재

    - 왼쪽 서브 트리 : 부모 노드 값 보다 작음
    - 오른쪽 서브 트리 : 루트 노드 값 보다 큼
    - 최대 탐색 높이 : 트리의 높이 = 로그2의 n
    - 
    */
   for(int i=0;i< sizeof(data)/sizeof(int);i++){
        root = insert(root,data[i]);
        print(root, "Insert" ,data[i]);
   }
   // 삭제할 노드의 키 값
    element deleteKey = 68;

    // delete 함수를 호출하여 삭제된 노드를 적절하게 처리
    root = delete(root, deleteKey);
    
    // 삭제된 노드를 출력하지 않도록 수정
    print(root, "Delete", deleteKey);

    return 0;
}
/*

                        35
                68            99
            18      26     

*/