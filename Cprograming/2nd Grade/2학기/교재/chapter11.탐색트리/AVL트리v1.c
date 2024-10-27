/*
ADT AVLTree
-------------------------------
- treeSearch(root, key) -> Node
- insertItem(tree, key) -> Node
- searchAndFixAfterInsertion(node) -> Node
- restructure(x, y, z) -> Node
- removeElement(key) -> Element
- searchAndFixAfterRemoval(node) -> None
- isExternal(node) -> Boolean
- inOrderSucc(node) -> Node
- reduceExternal(node) -> Node

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct treeNode {
    int key;
    struct treeNode* left;
    struct treeNode* right;
    struct treeNode* parent;

    int height;  // 노드의 높이 추가
} treeNode;

typedef struct treeType {
    struct treeNode* root;
    int size;
} treeType;

void init(treeType* tree) {
    tree->size = 0;
    tree->root = NULL;
}

int finMax(int a,int b){
    if(a >= b)return a;
    return b;
}

int findHeight(treeNode* node) { /* ++ 노드의 높이 계산 ++*/
    if (node == NULL) return 0;  // NULL 노드의 높이는 0
    return node->height;
}

int balanceFactor(treeNode* node) {
    //균형도 계산 및 반환
    if (node == NULL) return 0;
    return findHeight(node->left) - findHeight(node->right); // 왼쪽과 오른쪽 서브트리의 높이 차이
}

treeNode* treeSearch(treeNode* root, int key) {
    if (root == NULL || root->key == key) return root;
    if (key < root->key) return treeSearch(root->left, key);
    else return treeSearch(root->right, key);
}
//restructure(x, y, z) -> Node
treeNode* restructure(treeNode* x, treeNode* y, treeNode* z) {
    // 중위순회 순서로 a, b, c를 결정
    treeNode* a, *b, *c;
    if (x->key < y->key && y->key < z->key) {  // LL 케이스
        a = x; b = y; c = z;
    } else if (z->key < y->key && y->key < x->key) {  // RR 케이스
        a = z; b = y; c = x;
    } else if (x->key < y->key && z->key < y->key) {  // LR 케이스
        a = x; b = y; c = z;
    } else {  // RL 케이스
        a = z; b = y; c = x;
    }

    // T0, T1, T2, T3를 정의
    treeNode* T0 = a->left;
    treeNode* T1 = a->right;
    treeNode* T2 = c->left;
    treeNode* T3 = c->right;

    // z의 부모와 연결
    if (z->parent != NULL) {
        if (z->parent->left == z) z->parent->left = b;
        else z->parent->right = b;
    }
    b->parent = z->parent;

    // a와 c를 각각 b의 자식으로 설정
    b->left = a;
    a->parent = b;
    b->right = c;
    c->parent = b;

    // a와 c의 서브트리를 설정
    a->left = T0;
    if (T0 != NULL) T0->parent = a;
    a->right = T1;
    if (T1 != NULL) T1->parent = a;
    c->left = T2;
    if (T2 != NULL) T2->parent = c;
    c->right = T3;
    if (T3 != NULL) T3->parent = c;

    // 높이 갱신
    a->height = 1 + finMax(findHeight(a->left), findHeight(a->right));
    c->height = 1 + finMax(findHeight(c->left), findHeight(c->right));
    b->height = 1 + finMax(findHeight(b->left), findHeight(b->right));

    return b;  // 새로운 루트 반환
}

//searchAndFixAfterInsertion(node) -> Node
void searchAndFixAfterInsertion(treeType* tree,treeNode* w){
    /*
    1. w에서 T의 루트로 올라가다가 처음 만나는 불균형 노드를 z라 하자.
    (균형이 맞으면 return)
    2. z의 높은 자식을 y라 하자.
    (y는 z의 자식 중 더 높은 쪽에 있는 노드)
    3. y의 높은 자식을 x라 하자.
    (x는 y의 자식 중 더 높은 쪽에 있는 노드)
    4. restructure(x, y, z)
    // x, y, z의 관계를 바탕으로 트리를 재구성해 균형을 맞춤.
    5. return
    */
   treeNode* current = w;
   while (current != NULL) {
        int balance = balanceFactor(current); // 현재 노드의 균형 인수 계산
        if (balance > 1 || balance < -1) { // -> 불균형: 높이 차이가 2 이상이면 불균형
            // 불균형의 유형에 따라 회전 수행
            // LL, LR, RR, RL 케이스에 따라 처리 (restructure 함수 호출)
            // 예시: balance > 1이고 왼쪽 자식의 balance가 >= 0이면 LL 케이스
            // 예시: balance < -1이고 오른쪽 자식의 balance가 <= 0이면 RR 케이스
            // restructure 함수 호출하여 균형 맞춤
            treeNode* z = current;  // 불균형이 발생한 조상 노드
            treeNode* y = (balance > 1) ? z->left : z->right;  // 왼쪽이나 오른쪽 자식
            treeNode* x = (balance > 1) ? ((balanceFactor(y) >= 0) ? y->left : y->right) : ((balanceFactor(y) <= 0) ? y->right : y->left);  // y의 자식 노드

            // Restructure 호출
            treeNode* newRoot = restructure(x, y, z);

            // newRoot가 트리의 새로운 루트라면 루트 업데이트
            if (newRoot->parent == NULL) {
                // 트리의 루트를 새로운 노드로 교체
                // AVL 트리의 루트가 current의 부모일 때
                // 이 코드는 호출자의 트리 루트를 업데이트하는 코드로 변경 필요
                tree->root = newRoot;  // 트리의 루트를 새로운 루트로 변경
            }
            break;  // 한 번 회전이 일어나면 더 이상 균형 검사를 할 필요 없음
        }
   }
}

void updateHeight(treeNode* node) {
    while (node != NULL) {
        // node->height = 1 + max(height(node->left), height(node->right));
        // node->height = findHeight(node->left) > findHeight(node->right) ? findHeight(node->left) : findHeight(node->right) + 1;
        node->height = 1 + finMax(findHeight(node->left), findHeight(node->right));

        //현재 노드의 높이는 최대 자식의 높이 + 1
        node = node->parent;  // 부모로 올라가며 높이를 업데이트
    }
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
    updateHeight(newNode);
    searchAndFixAfterInsertion(tree,newNode);
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

    int tmpArr[6] = {20,50,30,60,70,90};
    for(int i=0;i<6;i++)insertItem(&tree, tmpArr[i]);
    inOrder(tree.root);

    // char fuc;
    // int data, key;
    // while (1) {
    //     scanf("%c", &fuc); getchar();
    //     if (fuc == 'i') {
    //         scanf("%d", &data); getchar();
    //         insertItem(&tree, data);
    //     }
    //     if (fuc == 'd') {
    //         scanf("%d", &key); getchar();
    //         int val = removeElement(&tree, key);
    //         if (val == -1) printf("X\n");
    //         else printf("%d\n", val);
    //     }
    //     if (fuc == 'p') {
    //         preOrder(tree.root);
    //         printf("\n");
    //     }
    //     if (fuc == 's') {
    //         scanf("%d", &key); getchar();
    //         treeNode* s = treeSearch(tree.root, key);
    //         if (s == NULL) printf("X\n");
    //         else printf("%d\n", s->key);
    //     }
    //     if (fuc == 'q') {
    //         break;
    //     }
    // }

    // return 0;
}
/*





*/


/*
                a
        /               \
      b                  c
                      /     \
                    d        e
                   / \        \
                  f   g        h

        z3
       / \
      y2 C 1
     / \
    x1  B1


*/