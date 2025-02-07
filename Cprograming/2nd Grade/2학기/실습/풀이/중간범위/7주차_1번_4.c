/*
다음은 수정된 부분을 기존과 비교하여 주석을 추가한 코드입니다. 줄바꿈 양식도 수정 전 양식을 따릅니다.
*/

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
        else parent->right = newNode;
    }
    tree->size++;
}

treeNode* inOrderSucc(treeNode* w) {
    treeNode* current = w->right;  // 오른쪽 서브트리로 이동
    while (current->left != NULL) {
        current = current->left;  // 가장 왼쪽에 있는 노드가 중위 계승자
    }
    return current;
}

void reduceExternal(treeType* tree, treeNode* z) {
    treeNode* p = z->parent;
    treeNode* s = (z == p->left) ? p->right : p->left;

    if (p->parent == NULL) {
        tree->root = s;  // 형제 노드를 새로운 루트로 설정
        if (s != NULL) s->parent = NULL;  // 부모 포인터를 NULL로 설정
    } 
    else {
        treeNode* g = p->parent;
        if (p == g->left) g->left = s;
        else g->right = s;
        if (s != NULL) s->parent = g;  // 부모 포인터 설정 추가 (기존 코드에선 누락)
    }
    free(z);  // 메모리 해제
    free(p);  // 메모리 해제
}

int removeElement(treeType* tree, int key) {
    treeNode* w = treeSearch(tree->root, key);
    if (w == NULL) return -1;

    int e = w->key;  // 삭제할 노드의 값 저장
    
    // 자식이 하나 있는 경우 처리 (기존 코드 수정)
    if (w->left == NULL || w->right == NULL) {  // 자식이 하나인 경우 처리 방식 개선
        treeNode* z = (w->left != NULL) ? w->left : w->right;

        if (w == tree->root) {  // 루트 노드일 때 처리 추가
            tree->root = z;  // 자식을 새로운 루트로 설정
            if (z != NULL) z->parent = NULL;  // 자식이 루트가 되면 부모 설정
        } 
        else {  // 루트가 아닌 경우
            if (w->parent->left == w) w->parent->left = z;  // 부모의 자식 포인터 설정
            else w->parent->right = z;
            if (z != NULL) z->parent = w->parent;  // 부모 포인터 설정 추가 (기존 코드에서 누락)
        }
        free(w);  // 삭제할 노드 메모리 해제
    }
    // 자식이 두 개 있는 경우 처리 (기존 코드 개선)
    else {
        treeNode* y = inOrderSucc(w);  // 중위 계승자 찾기
        w->key = y->key;  // 중위 계승자의 키를 삭제할 노드 w로 복사
        removeElement(tree, y->key);  // 중위 계승자를 재귀적으로 삭제 (기존 재귀 방식 유지)
    }
    
    tree->size--;
    return e;
}

void inOrder(treeNode* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf(" %d", root->key);
    inOrder(root->right);
}

void preOrder(treeNode* root) {
    if (root == NULL) return;
    printf(" %d", root->key);
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    treeType tree;
    init(&tree);

    char fuc;
    int data,key;
    while(1){
        scanf("%c",&fuc); getchar();
        if(fuc == 'i'){
            scanf("%d",&data);getchar();
            insertItem(&tree,data);
            // printf(">>i %d\n",data);
        }
        if(fuc == 'd'){
            scanf("%d",&key);getchar();
            int val = removeElement(&tree,key);
            if(val == -1) printf("X\n");
            else printf("%d\n",val);
            // printf(">>d\n");
        }
        if(fuc == 'p'){
            preOrder(tree.root);printf("\n");
            // printf(">>p\n");
        }
        if(fuc == 's'){
            scanf("%d",&key);getchar();
            treeNode* s = treeSearch(tree.root,key);
            if(s == NULL)printf("X\n");
            else printf("%d\n",s->key);

            // printf(">>s\n");
        }
        if(fuc == 'q'){break;}
    }


    return 0;
}
/*
i 3
i 2
i 7
s 4
i 6
p
i 5
s 6
q

i 9
i 2
i 15
i 1
i 7
i 11
i 5
i 8
i 3
i 4
p
d 2
d 13
p
q
*/