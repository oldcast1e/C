#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct DListNode {
    /* data */
    element data;
    struct DListNode* next; // 자기참조
    struct DListNode* prev;
} DListNode;

typedef struct DListType {
    /* data */
    DListNode** Heads; // 각 배열 인덱스의 헤드
    DListNode** Tails; // 각 배열 인덱스의 테일
    int size;
} DListType;

void initialize(DListType* linkNode, int N) {
    linkNode->Heads = (DListNode**)malloc(N * sizeof(DListNode*)); // 각 배열 인덱스의 헤드 배열 동적 할당
    linkNode->Tails = (DListNode**)malloc(N * sizeof(DListNode*)); // 각 배열 인덱스의 테일 배열 동적 할당
    for (int i = 0; i < N; ++i) {
        linkNode->Heads[i] = NULL; // 각 배열 요소의 헤드를 NULL로 초기화
        linkNode->Tails[i] = NULL; // 각 배열 요소의 테일을 NULL로 초기화
    }
    linkNode->size = 0;
}

int checkVailed(DListType* linkNode, int rank){
    // printf("processing...2\n");
    if(rank < 0 || rank > linkNode->size){
        printf("Invailed Connection\n");
        return -1;
    }
    return 1;
}

void print(DListType* linkNode, int index) {
    DListNode* curr = linkNode->Heads[index];
    printf("[Head]=>");
    while (curr != NULL) {
        /*function*/
        printf("[%c]=>", curr->data);
        curr = curr->next;
    }
    printf("[Tail] size = %d\n",linkNode->size);
}

void insertFirst(DListType* linkNode, int index, element val) {
    DListNode* new = (DListNode*)malloc(sizeof(DListNode)); // 새로운 노드 동적할당
    DListNode* H = linkNode->Heads[index];
    new->data = val; // 새로운 노드에 값 저장
    new->prev = NULL; // 새로운 노드의 이전 노드를 NULL : 첫 노드이므로

    new->next = H; // 새로운 노드의 next를 해당 인덱스의 헤드로 연결

    if (linkNode->Heads[index] == NULL) {
        linkNode->Heads[index] = linkNode->Tails[index] = new; // 헤드와 테일을 새로운 노드로 초기화
    } else {
        H->prev = new; // 기존 헤드의 이전 노드를 새로운 노드로 설정
        linkNode->Heads[index] = new; // 헤드를 새로운 노드로 업데이트
    }
    linkNode->size++;
}

void insertLast(DListType* linkNode, int index, element val) {
    DListNode* new = (DListNode*)malloc(sizeof(DListNode)); // 새로운 노드 동적할당
    new->data = val;
    new->prev = linkNode->Tails[index];
    new->next = NULL;

    if (linkNode->Tails[index] == NULL) {
        linkNode->Heads[index] = linkNode->Tails[index] = new; // 헤드와 테일을 새로운 노드로 초기화
    } else {
        linkNode->Tails[index]->next = new; // 기존 테일의 다음 노드를 새로운 노드로 설정
        linkNode->Tails[index] = new; // 테일을 새로운 노드로 업데이트
    }
    linkNode->size++;
}

void insert(DListType* linkNode,int index, element val, int rank){
// void insertFirst(DListType* linkNode, int index, element val)
    // printf("processing...1\n");
    if(rank == 1)insertFirst(linkNode,1,val);
    else if(rank == linkNode->size )insertFirst(linkNode,(linkNode->size),val);
    else{
        // printf("processing...rank = %d\n",rank);
        if(checkVailed(linkNode,rank) != -1){

            DListNode* new = (DListNode*)malloc(sizeof(DListNode)); // 새로운 노드 동적할당
            DListNode* curr = linkNode->Heads[index];
            // printf("processing...\n");
            for(int i=0;i<rank-1;i++){curr = curr->next;}
            new->data = val;
            new -> next = curr;
            new ->prev = curr->prev;

            curr->prev ->next = new;
            curr->prev = new;
            // printf("new = %c\n",new->data);
            linkNode->size++;
        }
    }
}

int deleteFirst(DListType* linkNode, int index) {
    DListNode* delete = linkNode->Heads[index];
    if(delete == NULL){
        printf("Invailed Connection.\n");
        return -1;
    }
    else{
        element val  = delete->data; 
        // delete = delete->next;
        linkNode->Heads[index] = delete->next;
        linkNode->size--;
        return val;
    }
    
}

int deleteLast(DListType* linkNode,int index){//노드를 수정하려면 인자를 참조한다!!!
    DListNode* delete = linkNode->Tails[index];//연결리스트 배열의 테일 노드 저장
    DListNode* p = linkNode->Heads[index];//

    element val = delete->data;
    for(int i=0; i < (linkNode->size-2);i++){p = p->next;}
    // printf("p->data = %c\n",p->data);
    linkNode->Tails[index] = p;
    linkNode->Tails[index]->next = NULL;

    linkNode->size --;
    return val;
}

int delete(DListType* linkNode,int index, int rank){
// void insertFirst(DListType* linkNode, int index, element val)
    // printf("processing...1\n");
    int val = -1;
    if(rank == 1)deleteFirst(linkNode,1);
    else if(rank == linkNode->size )deleteLast(linkNode,(linkNode->size));
    else{
        // printf("processing...rank = %d\n",rank);
        if(checkVailed(linkNode,rank) != -1){
            DListNode* new = (DListNode*)malloc(sizeof(DListNode));//새로운 노드 동적할당
            DListNode *curr = linkNode->Heads[index];
            for(int i=0;i<rank-1;i++){curr = curr->next;}
            val  = curr->data;
            (curr->prev)->next = curr->next;
            curr->next->prev = curr->prev;

            linkNode->size --;
        }
        return val;
    }
    return val;
}

int main() {
    int N;
    printf("Enter the size of the linked list array: ");
    scanf("%d", &N);

    DListType linkNode;
    initialize(&linkNode, N);

    printf("---------------------insert First--------------------\n");
    insertFirst(&linkNode, 1, 'A');print(&linkNode, 1);
    insertFirst(&linkNode, 1, 'B');print(&linkNode, 1);
    insertFirst(&linkNode, 1, 'C');print(&linkNode, 1);
    insertFirst(&linkNode, 1, 'D');print(&linkNode, 1);

    printf("---------------------insert Last---------------------\n");
    insertLast(&linkNode, 1, 'E');print(&linkNode, 1);
    insertLast(&linkNode, 1, 'F');print(&linkNode, 1);
    // insertLast(&linkNode, 1, 'G');print(&linkNode, 1);
    // insertLast(&linkNode, 1, 'H');print(&linkNode, 1);
    printf("--------------------insert Rank[3]-------------------\n");
    insert(&linkNode, 1, 'G',3);print(&linkNode, 1);
    printf("---------------------delete First--------------------\n");
    deleteFirst(&linkNode,1);print(&linkNode,1);
    printf("---------------------delete Last---------------------\n");
    deleteLast(&linkNode,1);print(&linkNode,1);
    printf("--------------------delete Rank[3]-------------------\n");
    delete(&linkNode, 1, 3);print(&linkNode, 1);

    return 0;
}
