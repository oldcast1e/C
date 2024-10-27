#include<stdio.h>
#include<stdlib.h>
struct node {
    int key;
    int height;
    struct node *lChild;
    struct node *rChild;
    struct node *parent;
};
struct node *root;

int isExternal(struct node *w) {
    if (w->lChild == NULL && w->rChild == NULL)
        return 1;
    return 0;
}

int isInternal(struct node *w) {
    if (w->lChild != NULL && w->rChild != NULL)
        return 1;
    return 0;
}

struct node* sibling(struct node *w) {
    if (w->parent == NULL)
        return NULL;
    if (w->parent->lChild == w)
        return w->parent->rChild;
    return w->parent->lChild;
}

struct node* inOrderSucc(struct node *w) {
    w = w->rChild;
    if (isExternal(w))
        return NULL;
    while (isInternal(w->lChild))
        w = w->lChild;
    return w;
}

void expandExternal(struct node *w) {
    struct node *leftnode = (struct node*)malloc(sizeof(struct node));
    struct node *rightnode = (struct node*)malloc(sizeof(struct node));
    leftnode->lChild = NULL;
    leftnode->rChild = NULL;
    leftnode->height = 0;
    leftnode->parent = w;
    rightnode->lChild = NULL;
    rightnode->rChild = NULL;
    rightnode->height = 0;
    rightnode->parent = w;
    w->lChild = leftnode;
    w->rChild = rightnode;
    w->height = 1;
}

struct node *reduceExternal(struct node *z) {
    struct node *p, *zs, *g;
    p = z->parent;
    zs = sibling(z);

    if (p->parent == NULL) {
        root = zs;
        zs->parent = NULL;
    } else {
        g = p->parent;
        zs->parent = g;
        if (p == g->lChild)
            g->lChild = zs;
        else if (p == g->rChild)
            g->rChild = zs;
    }

    free(z);
    free(p);
    return zs;
}

struct node* treeSearch(struct node *w, int k) {
    if (isExternal(w))
        return w;
    if (w->key == k)
        return w;
    if (w->key > k)
        return treeSearch(w->lChild, k);
    return treeSearch(w->rChild, k);
}

int updateHeight(struct node *w) {
    int height;
    if (w->lChild->height > w->rChild->height)
        height = w->lChild->height + 1;
    else
        height = w->rChild->height + 1;
    
    if (height != w->height) {
        w->height = height;
        return 1;
    }
    return 0;
}

int isBalanced(struct node *w) {
    if (-1 <= (w->lChild->height - w->rChild->height) && (w->lChild->height - w->rChild->height) <= 1)
        return 1;
    return 0;
}

struct node* restructure(struct node *x, struct node *y, struct node *z) {
    struct node *a, *b, *c;
    struct node *T0, *T1, *T2, *T3;

    if (z->key < y->key && y->key < x->key) {
        a = z;
        b = y;
        c = x;
        T0 = a->lChild;
        T1 = b->lChild;
        T2 = c->lChild;
        T3 = c->rChild;
    } else if (x->key < y->key && y->key < z->key) {
        a = x;
        b = y;
        c = z;
        T0 = a->lChild;
        T1 = a->rChild;
        T2 = b->rChild;
        T3 = c->rChild;
    } else if (z->key < x->key && x->key < y->key) {
        a = z;
        b = x;
        c = y;
        T0 = a->lChild;
        T1 = b->lChild;
        T2 = b->rChild;
        T3 = c->rChild;
    } else {
        a = y;
        b = x;
        c = z;
        T0 = a->lChild;
        T1 = b->lChild;
        T2 = b->rChild;
        T3 = c->rChild;
    }

    if (z->parent == NULL) {
        root = b;
        b->parent = NULL;
    } else if (z->parent->lChild == z) {
        z->parent->lChild = b;
        b->parent = z->parent;
    } else if (z->parent->rChild == z) {
        z->parent->rChild = b;
        b->parent = z->parent;
    }

    a->lChild = T0;
    T0->parent = a;
    a->rChild = T1;
    T1->parent = a;
    updateHeight(a);

    c->lChild = T2;
    T2->parent = c;
    c->rChild = T3;
    T3->parent = c;
    updateHeight(c);

    b->lChild = a;
    a->parent = b;
    b->rChild = c;
    c->parent = b;
    updateHeight(b);

    return b;
}

void searchAndFixAfterInsertion(struct node *w) {
    struct node *x, *y, *z;
    w->lChild->height = 0;
    w->rChild->height = 0;
    w->height = 1;

    if (w->parent == NULL)
        return;

    z = w->parent;
    while (updateHeight(z) && isBalanced(z)) {
        if (z->parent == NULL)
            return;
        z = z->parent;
    }

    if (isBalanced(z))
        return;

    if (z->lChild->height > z->rChild->height)
        y = z->lChild;
    else
        y = z->rChild;

    if (y->lChild->height > y->rChild->height)
        x = y->lChild;
    else
        x = y->rChild;

    restructure(x, y, z);
}

void insertItem(struct node *w, int k) {
    struct node *p = treeSearch(w, k);
    if (isInternal(p))
        return;
    p->key = k;
    expandExternal(p);
    searchAndFixAfterInsertion(p);
}

void searchAndFixAfterRemoval(struct node *w) {
    struct node *x, *y, *z, *b;

    if (w == NULL)
        return;

    z = w;
    while (updateHeight(z) && isBalanced(z)) {
        if (z->parent == NULL)
            return;
        z = z->parent;
    }

    if (isBalanced(z))
        return;

    if (z->lChild->height > z->rChild->height)
        y = z->lChild;
    else
        y = z->rChild;

    if (y->lChild->height > y->rChild->height)
        x = y->lChild;
    else if (y->lChild->height < y->rChild->height)
        x = y->rChild;
    else {
        if (z->lChild == y)
            x = y->lChild;
        else
            x = y->rChild;
    }

    b = restructure(x, y, z);
    searchAndFixAfterRemoval(b->parent);
}

int removeElement(struct node *w, int k) {
    struct node *p = treeSearch(w, k);
    struct node *z, *zs, *y;
    int e;

    if (isExternal(p))
        return -1;

    e = p->key;
    z = p->lChild;
    if (!isExternal(z))
        z = p->rChild;

    if (isExternal(z))
        zs = reduceExternal(z);
    else {
        y = inOrderSucc(p);
        z = y->lChild;
        p->key = y->key;
        zs = reduceExternal(z);
    }

    searchAndFixAfterRemoval(zs->parent);
    return e;
}

void printTree(struct node *w) {
    if (isExternal(w))
        return;

    printf(" %d", w->key);
    printTree(w->lChild);
    printTree(w->rChild);
}

void freeTree(struct node *w) {
    if (isExternal(w))
        return;

    freeTree(w->lChild);
    freeTree(w->rChild);
    free(w);
}

int main() {
    char text;
    int key, value;
    root = (struct node*)malloc(sizeof(struct node));
    root->parent = NULL;
    root->lChild = NULL;
    root->rChild = NULL;

    while (1) {
        scanf("%c", &text);
        if (text == 'i') {
            scanf("%d", &key);
            insertItem(root, key);
            getchar();
        } else if (text == 'd') {
            scanf("%d", &key);
            value = removeElement(root, key);
            if (value == key)
                printf("%d\n", value);
            else
                printf("X\n");
            getchar();
        } else if (text == 's') {
            scanf("%d", &key);
            if (treeSearch(root, key)->key != key)
                printf("X\n");
            else
                printf("%d\n", treeSearch(root, key)->key);
            getchar();
        } else if (text == 'p') {
            printTree(root);
            printf("\n");
        } else if (text == 'q') {
            break;
        }
    }

    freeTree(root);
}
