#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct treeNode {
    int key;
    struct treeNode* left;
    struct treeNode* right;
    struct treeNode* parent;
} treeNode;

typedef struct treeType {
    struct treeNode* root;
    int size;
} treeType;

void init(treeType* tree) {
    tree->size = 0;
    tree->root = NULL;
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
    newNode->parent = NULL;

    if (tree->size == 0) tree->root = newNode; 
    else {
        treeNode* tmp = tree->root;
        treeNode* parent = NULL;
        while (tmp != NULL) {
            parent = tmp;
            if (key < tmp->key) tmp = tmp->left; 
            else  tmp = tmp->right;
        }
        newNode->parent = parent;

        if (key < parent->key) parent->left = newNode;
        else parent->right = newNode;
        
    }
    tree->size++;
}

treeNode* inOrderSucc(treeNode* w) {
    treeNode* current = w->right;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

void reduceExternal(treeType* tree, treeNode* z) {
    treeNode* p = z->parent;
    treeNode* s = (z == p->left) ? p->right : p->left;

    if (p->parent == NULL) {
        tree->root = s;
        if (s != NULL) s->parent = NULL;
    } 
    else {
        treeNode* g = p->parent;
        if (p == g->left) g->left = s;
        else  g->right = s;
        if (s != NULL) s->parent = g;
    }
    free(z);
    free(p);
}

int removeElement(treeType* tree, int key) {
    treeNode* w = treeSearch(tree->root, key);
    if (w == NULL) return -1;

    int e = w->key;
    
    // 자식이 하나인 경우 처리
    if (w->left == NULL || w->right == NULL) {
        treeNode* z = (w->left != NULL) ? w->left : w->right;

        if (w == tree->root) {
            tree->root = z;
            if (z != NULL) z->parent = NULL;
        } 
        else {
            if (w->parent->left == w) w->parent->left = z;
            else w->parent->right = z;
            if (z != NULL) z->parent = w->parent;
        }
        free(w);
    } 
    // 자식이 두 개인 경우 처리
    else {
        treeNode* y = inOrderSucc(w);
        w->key = y->key;
        
        // 중위 계승자를 직접 삭제
        // 수정 전: 중위 계승자를 재귀적으로 삭제
        // removeElement(tree, y->key);  // 기존 코드
        // 수정 후: 중위 계승자를 바로 삭제
        if (y->right != NULL) {  // 중위 계승자가 오른쪽 자식이 있을 경우
            if (y->parent->left == y) y->parent->left = y->right;
            else y->parent->right = y->right;
            y->right->parent = y->parent;
        } else {  // 중위 계승자가 오른쪽 자식이 없는 경우
            if (y->parent->left == y) y->parent->left = NULL;
            else y->parent->right = NULL;
        }
        free(y);  // 중위 계승자를 바로 삭제
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
    int data, key;
    while (1) {
        scanf("%c", &fuc); getchar();
        if (fuc == 'i') {
            scanf("%d", &data); getchar();
            insertItem(&tree, data);
        }
        if (fuc == 'd') {
            scanf("%d", &key); getchar();
            int val = removeElement(&tree, key);
            if (val == -1) printf("X\n");
            else printf("%d\n", val);
        }
        if (fuc == 'p') {
            preOrder(tree.root);
            printf("\n");
        }
        if (fuc == 's') {
            scanf("%d", &key); getchar();
            treeNode* s = treeSearch(tree.root, key);
            if (s == NULL) printf("X\n");
            else printf("%d\n", s->key);
        }
        if (fuc == 'q') {
            break;
        }
    }

    return 0;
}
