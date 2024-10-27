#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct treeNode {
    int key;
    struct treeNode* left;
    struct treeNode* right;
    struct treeNode* parent;  // 부모 포인터 추가
} treeNode;

typedef struct treeType {
    struct treeNode* root;
    int size;
} treeType;

void init(treeType* tree) {
    tree->size = 0;
    tree->root = NULL;  // root 초기화
}

treeNode* treeSearch(treeNode* root, int key) {
    if (root == NULL || root->key == key) return root;
    if (key < root->key) return treeSearch(root->left, key);
    else return treeSearch(root->right, key);
}

void insertItem(treeType* tree, int key) {
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->key = key;

    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;  // 부모 포인터 초기화

    if (tree->size == 0) {
        tree->root = newNode;
    } 
    else {
        treeNode* tmp = tree->root;
        treeNode* parent = NULL;
        while (tmp != NULL) {
            parent = tmp;
            if (key < tmp->key) {tmp = tmp->left; } 
            else { tmp = tmp->right; }
        }
        newNode->parent = parent;  // 부모 설정

        if (key < parent->key) parent->left = newNode;
        else  parent->right = newNode;
    
    }
    tree->size++;
}


treeNode* inOderSucc(treeNode* w){
    treeNode* current = w->right;  // 오른쪽 서브트리로 이동
    while (current->left != NULL) {
        current = current->left;  // 가장 왼쪽에 있는 노드가 중위 계승자
    }
    return current;
}

void reduceExternal(treeType* tree, treeNode* z) {
    treeNode* p = z->parent;
    //위 의사코드에서 s는 외부 노드 z가 제거된 후, 그 자리로 대체될 형제 노드
    treeNode* s = (z == p ->left) ? p->right : p->left;

    if(p->parent == NULL){
        tree->root = s;  // 형제 노드를 새로운 루트로 설정
        s->parent = NULL;  // 부모 포인터를 NULL로 설정
    }
    else{
        treeNode* g = p->parent;
        if (p == g->left) g->left = s;
        else g->right = s;
        s->parent = g;  // 형제 노드의 부모 포인터 설정

        // if(p == g->left) g->left = s;
        // else{
        //     g->right = s;
        //     s->parent = g;
        // }
    }
    // free(z);
    // free(p);
}

int removeElement(treeType* tree, int key) {
    treeNode* w = treeSearch(tree->root, key);
    if (w == NULL) return -1;

    int e = w->key; // 삭제할 노드의 값 저장
    
    treeNode* z = w->left;//왼쪽 자식 노드 저장

    if (!z) z = w->right;  // 자식이 하나 있는 경우
    if (z == NULL){
        /*확인!!!!*/
        if (w->parent->left == w) w->parent->left = NULL;  // 부모의 왼쪽 자식이면 NULL로 설정
        else w->parent->right = NULL;  // 부모의 오른쪽 자식이면 NULL로 설정
        free(w);  // 삭제할 노드 w 메모리 해제
        return e;
    }
    else{//두 개의 자식이 있는 경우
        treeNode* y = inOderSucc(w);
        /*중위순회계승자 잘 찾음*/
        // printf("w의 값: %d\n",w->key);
        // printf("중위순회계승자 : %d\n",y->key);

        /*다시 작성!!!!*/
        w->key = y->key;  // 중위 계승자의 키를 삭제할 노드 w로 복사
        // 중위 계승자 y를 재귀적으로 삭제해야 함
        reduceExternal(tree, y);
        free(y);  // y 노드 메모리 해제
        // exit(1);

    }

    free(w);  // 노드 삭제
    return e;
}

void inOrder(treeNode* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf(" %d", root->key);
    inOrder(root->right);
}

int main() {
    treeType tree;
    init(&tree);

    int data;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &data);
        insertItem(&tree, data);
    }

    inOrder(tree.root); printf("\n");
    int e =  removeElement(&tree,2);
    printf("%d 삭제.\n",e);
    // inOrder(tree.root); printf("\n");ㄴ
    return 0;
}
/*
1 2 7 8 9 11 15

1 2 3 4 5 7 8 9 11 15
*/