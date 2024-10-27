#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode {
    int key;
    struct treeNode* left;
    struct treeNode* right;
    struct treeNode* parent;
    int height;
} treeNode;

typedef struct treeType {
    struct treeNode* root;
    int size;
} treeType;

void init(treeType* tree) {
    tree->size = 0;
    tree->root = NULL;
}

int finMax(int a, int b) {
    return (a >= b) ? a : b;
}

int findHeight(treeNode* node) {
    if (node == NULL) return 0;
    return node->height;
}

int balanceFactor(treeNode* node) {
    if (node == NULL) return 0;
    return findHeight(node->left) - findHeight(node->right);
}

treeNode* treeSearch(treeNode* root, int key) {
    if (root == NULL || root->key == key) return root;
    if (key < root->key) return treeSearch(root->left, key);
    return treeSearch(root->right, key);
}

treeNode* restructure(treeNode* x, treeNode* y, treeNode* z) {
    treeNode* a, *b, *c;
    if (x->key < y->key && y->key < z->key) {
        a = x; b = y; c = z;
    } else if (z->key < y->key && y->key < x->key) {
        a = z; b = y; c = x;
    } else if (x->key < y->key && z->key < y->key) {
        a = x; b = y; c = z;
    } else {
        a = z; b = y; c = x;
    }

    treeNode* T0 = a->left;
    treeNode* T1 = a->right;
    treeNode* T2 = c->left;
    treeNode* T3 = c->right;

    if (z->parent != NULL) {
        if (z->parent->left == z) z->parent->left = b;
        else z->parent->right = b;
    }
    b->parent = z->parent;

    b->left = a;
    a->parent = b;
    b->right = c;
    c->parent = b;

    a->left = T0;
    if (T0 != NULL) T0->parent = a;
    a->right = T1;
    if (T1 != NULL) T1->parent = a;
    c->left = T2;
    if (T2 != NULL) T2->parent = c;
    c->right = T3;
    if (T3 != NULL) T3->parent = c;

    a->height = 1 + finMax(findHeight(a->left), findHeight(a->right));
    c->height = 1 + finMax(findHeight(c->left), findHeight(c->right));
    b->height = 1 + finMax(findHeight(b->left), findHeight(b->right));

    return b;
}

void searchAndFixAfterInsertion(treeType* tree, treeNode* w) {
    treeNode* current = w;
    while (current != NULL) {
        int balance = balanceFactor(current);
        if (balance > 1 || balance < -1) {
            treeNode* z = current;
            treeNode* y = (balance > 1) ? z->left : z->right;
            treeNode* x = (balance > 1) ? ((balanceFactor(y) >= 0) ? y->left : y->right) : ((balanceFactor(y) <= 0) ? y->right : y->left);
            treeNode* newRoot = restructure(x, y, z);

            if (newRoot->parent == NULL) {
                tree->root = newRoot;
            }
            break;
        }
        current = current->parent;
    }
}

void updateHeight(treeNode* node) {
    while (node != NULL) {
        node->height = 1 + finMax(findHeight(node->left), findHeight(node->right));
        node = node->parent;
    }
}

void insertItem(treeType* tree, int key) {
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    if (tree->size == 0) {
        tree->root = newNode;
    } else {
        treeNode* tmp = tree->root;
        treeNode* parent = NULL;
        while (tmp != NULL) {
            parent = tmp;
            if (key < tmp->key) tmp = tmp->left;
            else tmp = tmp->right;
        }
        newNode->parent = parent;
        if (key < parent->key) parent->left = newNode;
        else parent->right = newNode;
    }

    updateHeight(newNode);
    searchAndFixAfterInsertion(tree, newNode);
    tree->size++;
}

void inOrder(treeNode* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->key);
    inOrder(root->right);
}

int main() {
    treeType tree;
    init(&tree);

    int tmpArr[6] = {20, 50, 30, 60, 70, 90};
    for (int i = 0; i < 6; i++) {
        insertItem(&tree, tmpArr[i]);
    }

    printf("InOrder Traversal: ");
    inOrder(tree.root);
    printf("\n");

    return 0;
}
