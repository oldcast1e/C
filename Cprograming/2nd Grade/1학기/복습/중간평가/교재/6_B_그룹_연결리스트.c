#include<stdio.h>
#include<stdlib.h>

typedef char element;

typedef struct DListGroup{
    /* group */
    element group;
    int data;
    struct DListGroup* next;//자기참조
    struct DListGroup* prev;

}DListGroup;

typedef struct DListType{
    /* group */
    DListGroup* Head;
    DListGroup* Tail;
    int size;
}DListType;

void initialize(DListType* linkNode){
    linkNode->Head = NULL;
    linkNode->Tail = NULL;
    linkNode->size = 0;

    // linkNode->Head->next = linkNode->Tail ;
    // linkNode->Tail->prev = linkNode->Head;


}

void traverse(DListType* linkNode,int r){
    DListGroup* curr = linkNode->Head;
    if((r<0)||(r>linkNode->size))printf("Invailed Connection.\n");
    else
        while(curr->next != NULL){
            curr = curr->next;
            /*function*/
            // printf("[%d]=>",curr->group);
        }
}
void print(DListType* linkNode){
    DListGroup* curr = linkNode->Head;
    printf("[Head]=>");
    while(curr != NULL){
        /*function*/
        printf("[%c]=>",curr->group);
        curr = curr->next;
    }
    printf("[Tail]\n");
}
// void print(DListType* DList) {
//    for (DListGroup* p = DList->Head; p != NULL; p = p->next) {
//       printf("[%c] <=> ", p->group);
//    }printf("\b\b\b\b   \n");
// }

void insertFirst(DListType* linkNode, element val){
    DListGroup* new = (DListGroup*)malloc(sizeof(DListGroup));//새로운 노드 동적할당
    DListGroup* H = linkNode->Head;/*노드 추가 시 기본 알고리즘*/
    new->group = val; // 새로운 노드에 값 저장
    new->prev = NULL; // 새로운 노드의 이전 노드를 NULL : 첫 노드이므로

    new->next = H;// 새로운 노드의 next를 H(헤드)를 저장한 p로 연결

    if (H == NULL) {linkNode->Head = linkNode->Tail = new;}//p가 널이면 헤드-테일을 각각 new로 초기화
    else {//아니라면
        H->prev = new;//헤드를 저장한 p의 이전 노드를 new로 설정
        linkNode->Head = new;//연결리스트의 헤드를 new로 설정
    }

    linkNode->size++;
}

void insertLast(DListType* linkNode, element val){
    DListGroup* new = (DListGroup*)malloc(sizeof(DListGroup));//새로운 노드 동적할당
    DListGroup* Last = linkNode->Tail;/*노드 추가 시 기본 알고리즘*/

    new->group = val;
    new->prev = Last;
    new->next = NULL;

    if(Last == NULL){linkNode->Head = linkNode->Tail = new;}//노드가 없는 경우
    else{
        Last->next = new;  
        linkNode->Tail = new;
    }
    linkNode->size ++;
}

int checkVailed(DListType* linkNode, int rank){
    if(rank < 0 || rank > linkNode->size){
        printf("Invailed Connection\n");
        return -1;
    }
    return 1;
}

void insert(DListType* linkNode, element val, int rank){
    if(rank == 1)insertFirst(linkNode,val);
    else if(rank == linkNode->size +1)insertFirst(linkNode,val);
    else{
        if(checkVailed(linkNode,rank) != -1){
            DListGroup* new = (DListGroup*)malloc(sizeof(DListGroup));//새로운 노드 동적할당
            DListGroup *curr = linkNode->Head;
            for(int i=0;i<rank-1;i++){curr = curr->next;}
            // printf("curr = %c\n",curr->group);
            new->group = val;
            new -> next = curr;
            new ->prev = curr->prev;

            curr->prev ->next = new;
            curr->prev = new;
            // printf("new = %c\n",new->group);
        }
    }
}

int deleteFirst(DListType* linkNode){//노드를 수정하려면 인자를 참조한다!!!
    DListGroup* delete = linkNode->Head;
    if(delete == NULL){
        printf("Invailed Connection.\n");
        return -1;
    }
    else{
        element val  = delete->group; 
        // delete = delete->next;
        linkNode->Head = delete->next;
        linkNode->size--;
        return val;
    }
}

int deleteLast(DListType* linkNode){//노드를 수정하려면 인자를 참조한다!!!
    DListGroup* delete = linkNode->Tail;
    DListGroup* p = linkNode->Head;

    element val = delete->group;
    for(int i=0;i<linkNode->size-1;i++){p = p->next;}
    linkNode->Tail = p;
    linkNode->Tail->next = NULL;
    return val;
}

int delete(DListType* linkNode, element rank){
    int val;
    if(rank == 1)deleteFirst(linkNode);
    else if(rank == linkNode->size +1)deleteFirst(linkNode);
    else{
        if(checkVailed(linkNode,rank) != -1){
            DListGroup* new = (DListGroup*)malloc(sizeof(DListGroup));//새로운 노드 동적할당
            DListGroup *curr = linkNode->Head;
            for(int i=0;i<rank;i++){curr = curr->next;}
            val  = curr->group;
            (curr->prev)->next = curr->next;
            curr->next->prev = curr->prev;
        }
    }
    return val;
}

int main(){
    DListType linkNode;
    initialize(&linkNode);
    printf("---------------------insert First--------------------\n");
    insertFirst(&linkNode,'A');print(&linkNode);
    insertFirst(&linkNode,'B');print(&linkNode);
    insertFirst(&linkNode,'C');print(&linkNode);
    insertFirst(&linkNode,'C');print(&linkNode);
    printf("---------------------insert Last---------------------\n");
    insertLast(&linkNode,'E');print(&linkNode);
    printf("--------------------insert Rank[2]-------------------\n");
    insert(&linkNode,'D',2);print(&linkNode);
    printf("---------------------delete First--------------------\n");
    deleteFirst(&linkNode);print(&linkNode);
    printf("---------------------delete Last---------------------\n");
    deleteLast(&linkNode);print(&linkNode);
    printf("--------------------delete Rank[1]--------------------\n");
    delete(&linkNode,1);print(&linkNode);
}
