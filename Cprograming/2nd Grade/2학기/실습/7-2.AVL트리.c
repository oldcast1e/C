#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
struct node {
    int key;                   // 노드의 키 값
    int height;                // 노드의 높이
    struct node *lChild;       // 왼쪽 자식 노드 포인터
    struct node *rChild;       // 오른쪽 자식 노드 포인터
    struct node *parent;       // 부모 노드 포인터
};

struct node *root;             // 트리의 루트 노드 포인터

// 노드가 외부 노드(리프)인지 확인
int isExternal(struct node *w) {
    return (w->lChild == NULL && w->rChild == NULL);  // 자식 노드가 없으면 외부 노드
}

// 노드가 내부 노드인지 확인
int isInternal(struct node *w) {
    return (w->lChild != NULL && w->rChild != NULL);  // 자식 노드가 모두 있으면 내부 노드
}

// 노드의 형제를 반환
struct node* sibling(struct node *w) {
    if (w->parent == NULL) return NULL;              // 부모가 없으면 NULL 반환 (루트 노드인 경우)
    if (w->parent->lChild == w) return w->parent->rChild;  // 왼쪽 자식이면 오른쪽 자식을 반환
    return w->parent->lChild;                        // 오른쪽 자식이면 왼쪽 자식을 반환
}

// 노드의 중위 후속자를 반환 (오른쪽 서브트리에서 가장 작은 값)
struct node* inOrderSucc(struct node *w) {
    w = w->rChild;                                   // 오른쪽 자식으로 이동
    if (isExternal(w)) return NULL;                  // 외부 노드인 경우 NULL 반환
    while (isInternal(w->lChild)) w = w->lChild;     // 왼쪽 자식으로 계속 이동하여 가장 작은 값 찾기
    return w;                                        // 중위 후속자 반환
}

// 외부 노드를 확장하여 내부 노드로 변환
void expandExternal(struct node *w) {
    struct node *leftnode = (struct node*)malloc(sizeof(struct node));  // 왼쪽 자식 생성
    struct node *rightnode = (struct node*)malloc(sizeof(struct node)); // 오른쪽 자식 생성
    leftnode->lChild = NULL;                        // 왼쪽 자식의 자식 노드는 NULL
    leftnode->rChild = NULL;                        // 오른쪽 자식의 자식 노드는 NULL
    leftnode->height = 0;                           // 리프 노드의 높이는 0
    leftnode->parent = w;                           // 부모 노드를 현재 노드로 설정
    rightnode->lChild = NULL;                       // 오른쪽 자식의 자식 노드는 NULL
    rightnode->rChild = NULL;                       // 오른쪽 자식의 자식 노드는 NULL
    rightnode->height = 0;                          // 리프 노드의 높이는 0
    rightnode->parent = w;                          // 부모 노드를 현재 노드로 설정
    w->lChild = leftnode;                           // 현재 노드의 왼쪽 자식으로 설정
    w->rChild = rightnode;                          // 현재 노드의 오른쪽 자식으로 설정
    w->height = 1;                                  // 현재 노드의 높이를 1로 설정
}

// 외부 노드를 줄이고 트리를 균형 상태로 재구성
struct node *reduceExternal(struct node *z) {
    struct node *p, *zs, *g;
    p = z->parent;                                  // z의 부모 노드 설정
    zs = sibling(z);                                // z의 형제 노드 설정

    if (p->parent == NULL) {                        // p가 루트 노드인 경우
        root = zs;                                  // zs를 루트로 설정
        zs->parent = NULL;                          // 루트의 부모는 NULL
    } else {
        g = p->parent;                              // p의 부모 노드 g 설정
        zs->parent = g;                             // 형제 노드 zs의 부모를 g로 설정
        if (p == g->lChild)
            g->lChild = zs;                         // p가 g의 왼쪽 자식이면 zs를 왼쪽 자식으로 설정
        else
            g->rChild = zs;                         // p가 g의 오른쪽 자식이면 zs를 오른쪽 자식으로 설정
    }

    free(z);                                        // z 메모리 해제
    free(p);                                        // p 메모리 해제
    return zs;                                      // zs 반환 (균형 맞추기 위해 상위로 전달)
}

// 키 값을 기준으로 노드를 검색
struct node* treeSearch(struct node *w, int k) {
    if (isExternal(w)) return w;                    // 외부 노드면 검색 종료
    if (w->key == k) return w;                      // 키가 같으면 해당 노드 반환
    if (w->key > k) return treeSearch(w->lChild, k); // 키가 작으면 왼쪽 서브트리 검색
    return treeSearch(w->rChild, k);                // 키가 크면 오른쪽 서브트리 검색
}

// 노드의 높이 업데이트
int updateHeight(struct node *w) {
    int height;
    if (w->lChild->height > w->rChild->height)      // 왼쪽 자식과 오른쪽 자식 중 더 큰 높이
        height = w->lChild->height + 1;             // 큰 높이에 1을 더해 현재 노드의 높이 계산
    else
        height = w->rChild->height + 1;
    
    if (height != w->height) {                      // 높이가 변경되었을 경우
        w->height = height;                         // 노드의 높이를 업데이트
        return 1;                                   // 높이 변경되었음을 알림
    }
    return 0;                                       // 높이 변경되지 않음
}

// 노드가 균형 상태인지 확인
int isBalanced(struct node *w) {
    int balance = w->lChild->height - w->rChild->height; // 왼쪽과 오른쪽 자식의 높이 차이 계산
    return (-1 <= balance && balance <= 1);              // 높이 차이가 -1에서 1 사이면 균형
}

// 트리 재구성 (LL, RR, LR, RL 경우 처리)
struct node* restructure(struct node *x, struct node *y, struct node *z) {
    struct node *a, *b, *c;
    struct node *T0, *T1, *T2, *T3;

    // x, y, z의 키 값을 비교하여 a, b, c 및 서브트리 T0, T1, T2, T3를 결정
    if (z->key < y->key && y->key < x->key) {
        a = z; b = y; c = x;
        T0 = a->lChild; T1 = b->lChild; T2 = c->lChild; T3 = c->rChild;
    } else if (x->key < y->key && y->key < z->key) {
        a = x; b = y; c = z;
        T0 = a->lChild; T1 = a->rChild; T2 = b->rChild; T3 = c->rChild;
    } else if (z->key < x->key && x->key < y->key) {
        a = z; b = x; c = y;
        T0 = a->lChild; T1 = b->lChild; T2 = b->rChild; T3 = c->rChild;
    } else {
        a = y; b = x; c = z;
        T0 = a->lChild; T1 = b->lChild; T2 = b->rChild; T3 = c->rChild;
    }

    // 부모와 연결
    if (z->parent == NULL) {
        root = b;                                  // b가 새로운 루트 노드가 됨
        b->parent = NULL;
    } else if (z->parent->lChild == z) {
        z->parent->lChild = b;                     // z의 부모가 z의 왼쪽 자식이면 b를 왼쪽 자식으로 연결
        b->parent = z->parent;
    } else {
        z->parent->rChild = b;                     // z의 부모가 z의 오른쪽 자식이면 b를 오른쪽 자식으로 연결
        b->parent = z->parent;
    }

    // a와 c의 자식들을 연결하고 높이를 업데이트
    a->lChild = T0; T0->parent = a;
    a->rChild = T1; T1->parent = a;
    updateHeight(a);

    c->lChild = T2; T2->parent = c;
    c->rChild = T3; T3->parent = c;
    updateHeight(c);

    // a와 c를 b의 자식으로 연결
    b->lChild = a; a->parent = b;
    b->rChild = c; c->parent = b;
    updateHeight(b);

    return b;                                      // 재구성된 서브트리의 루트 반환
}

// 삽입 후 트리 균형 유지
void searchAndFixAfterInsertion(struct node *w) {
    struct node *x, *y, *z;
    w->lChild->height = 0;                         // 새로 삽입된 노드의 자식 노드 높이 설정
    w->rChild->height = 0;
    w->height = 1;                                 // 새로 삽입된 노드의 높이는 1

    if (w->parent == NULL) return;                 // 부모가 없으면(루트 노드) 반환

    z = w->parent;                                 // 부모 노드 z 설정
    while (updateHeight(z) && isBalanced(z)) {     // z의 높이 업데이트 및 균형 확인
        if (z->parent == NULL) return;             // 루트 노드까지 도달하면 반환
        z = z->parent;                             // 부모로 이동하며 검사
    }

    if (isBalanced(z)) return;                     // 균형 상태면 반환

    if (z->lChild->height > z->rChild->height) y = z->lChild;  // y를 높이가 큰 자식으로 설정
    else y = z->rChild;

    if (y->lChild->height > y->rChild->height) x = y->lChild;  // x도 높이가 큰 자식으로 설정
    else x = y->rChild;

    restructure(x, y, z);                          // 재구성 수행
}

// 트리에 새로운 키 삽입
void insertItem(struct node *w, int k) {
    struct node *p = treeSearch(w, k);             // 삽입할 위치 검색
    if (isInternal(p)) return;                     // 이미 존재하는 키면 삽입하지 않음
    p->key = k;                                    // 키 설정
    expandExternal(p);                             // 외부 노드를 내부 노드로 확장
    searchAndFixAfterInsertion(p);                 // 삽입 후 균형 유지
}

// 삭제 후 트리 균형 유지
void searchAndFixAfterRemoval(struct node *w) {
    struct node *x, *y, *z, *b;
    if (w == NULL) return;                         // w가 NULL이면 반환

    z = w;                                         // z를 w로 초기화
    while (updateHeight(z) && isBalanced(z)) {     // z의 높이 업데이트 및 균형 확인
        if (z->parent == NULL) return;             // 루트 노드까지 도달하면 반환
        z = z->parent;                             // 부모로 이동하며 검사
    }

    if (isBalanced(z)) return;                     // 균형 상태면 반환

    if (z->lChild->height > z->rChild->height) y = z->lChild;  // y를 높이가 큰 자식으로 설정
    else y = z->rChild;

    if (y->lChild->height > y->rChild->height) x = y->lChild;  // x도 높이가 큰 자식으로 설정
    else if (y->lChild->height < y->rChild->height) x = y->rChild;
    else {
        if (z->lChild == y) x = y->lChild;          // 높이가 같으면 왼쪽 또는 오른쪽 자식 선택
        else x = y->rChild;
    }

    b = restructure(x, y, z);                      // 재구성 수행
    searchAndFixAfterRemoval(b->parent);           // 재구성 후 부모에서 다시 균형 확인
}

// 트리에서 키를 삭제
int removeElement(struct node *w, int k) {
    struct node *p = treeSearch(w, k);             // 삭제할 위치 검색
    struct node *z, *zs, *y;
    int e;

    if (isExternal(p)) return -1;                  // 삭제할 키가 없으면 -1 반환

    e = p->key;                                    // 삭제할 키 값 저장
    z = p->lChild;
    if (!isExternal(z)) z = p->rChild;             // 자식 중 하나가 외부 노드가 아닐 경우

    if (isExternal(z)) zs = reduceExternal(z);     // 외부 노드를 줄임
    else {
        y = inOrderSucc(p);                        // 중위 후속자 찾기
        z = y->lChild;
        p->key = y->key;                           // 후속자의 키로 교체
        zs = reduceExternal(z);                    // 후속자 위치의 외부 노드 줄임
    }

    searchAndFixAfterRemoval(zs->parent);          // 삭제 후 균형 유지
    return e;                                      // 삭제된 키 반환
}

// 트리를 전위 순회로 출력
void printTree(struct node *w) {
    if (isExternal(w)) return;                     // 외부 노드면 출력 중지

    printf(" %d", w->key);                         // 노드의 키 출력
    printTree(w->lChild);                          // 왼쪽 서브트리 출력
    printTree(w->rChild);                          // 오른쪽 서브트리 출력
}

// 트리의 메모리를 해제
void freeTree(struct node *w) {
    if (isExternal(w)) return;                     // 외부 노드면 반환

    freeTree(w->lChild);                           // 왼쪽 서브트리 메모리 해제
    freeTree(w->rChild);                           // 오른쪽 서브트리 메모리 해제
    free(w);                                       // 현재 노드 메모리 해제
}

// 메인 함수 - 사용자 입력 처리
int main() {
    char text;
    int key, value;
    
    // 루트 노드 초기화
    root = (struct node*)malloc(sizeof(struct node));
    root->parent = NULL;
    root->lChild = NULL;
    root->rChild = NULL;

    // 사용자가 'q'를 입력할 때까지 명령어 처리
    while (1) {
        scanf("%c", &text);                        // 명령어 입력
        
        if (text == 'i') {
            // 삽입 명령어
            scanf("%d", &key);
            insertItem(root, key);                 // 트리에 키 삽입
            getchar();                             // 줄바꿈 문자 제거
        } else if (text == 'd') {
            // 삭제 명령어
            scanf("%d", &key);
            value = removeElement(root, key);      // 트리에서 키 삭제
            if (value == key)
                printf("%d\n", value);             // 삭제된 키 출력
            else
                printf("X\n");                     // 삭제 실패 시 'X' 출력
            getchar();                             // 줄바꿈 문자 제거
        } else if (text == 's') {
            // 검색 명령어
            scanf("%d", &key);
            if (treeSearch(root, key)->key != key)
                printf("X\n");                     // 키가 없으면 'X' 출력
            else
                printf("%d\n", treeSearch(root, key)->key);  // 키가 있으면 출력
            getchar();                             // 줄바꿈 문자 제거
        } else if (text == 'p') {
            // 트리 출력 명령어
            printTree(root);                       // 트리 출력
            printf("\n");
        } else if (text == 'q') {
            // 종료 명령어
            break;
        }
    }

    // 종료 전 트리 메모리 해제
    freeTree(root);
    
    return 0;                                      // 프로그램 종료
}
