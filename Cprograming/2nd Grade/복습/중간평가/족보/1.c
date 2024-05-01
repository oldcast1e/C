#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int element; 
typedef struct ListNode {
    element data;
    struct ListNode *next; 
}ListNode;

typedef struct ListType { 
    ListNode *H;
}ListType;

// void init(ListType *L) { 
//     //헤드 노드인 경우 
//     L->H = (ListNode*)malloc(sizeof(ListNode)); 
//     L->H->next = NULL;
// }

void init(ListType *L) { 
    //헤드 포인터인 경우 
    L->H = NULL;
}
/*
1. 단순연결리스트를 사용한다. 
이때 헤드 노드, 헤드 포인터 중 원하는 하나를 사용하여 구현하며, 
    테일 노드와 size 변수 등은 만들 수 없다.
*/

void insertFirst(ListType *DT, element data){
    ListNode* new = (ListNode*)malloc(sizeof(ListNode));
    new->data = data;
    // printf("new data = %d\n",new->data);
    
    ListNode* p = DT->H;
    if(p == NULL) DT->H = new;
    else{
        new->next = p;
        DT->H = new;    
    }
    // p->next = new;

}

void insertLast(ListType *DT, element data){
    ListNode* new = (ListNode*)malloc(sizeof(ListNode));
    new->data = data;
    // printf("new data = %d\n",new->data);
    
    ListNode* p = DT->H;
    if(p == NULL) DT->H = new;
    else{
        ListNode* curr = DT->H;
        while(curr->next != NULL){
            // printf("%d ",curr->data);
            curr = curr->next;
        }
        curr->next = new;
        // new->next = p;
        // DT->H = new;    
    }
}

void print(ListType* DT){
    ListNode* p = DT->H;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    if(p == NULL)printf("NULL\n");
}

void partition(ListType* L1,ListType* L2, element rank){
    ListNode* first = L1->H;
    for(int i=0;i<rank;i++){first = first->next;}
    for(int i=rank;i<15;i++){
        insertLast(L2,first->data);
        first = first->next;
    }

    ListNode* deletedL1 = L1->H;
    for(int i=0;i<rank-1;i++){deletedL1 = deletedL1->next;}
    deletedL1 ->next = NULL;
}

void concat(ListType* L1,ListType* L2){
    ListNode* boforeL1 = L1->H;
    while(boforeL1 != NULL){boforeL1 = boforeL1->next;}
    //L1이 끝날때까지 반복

    ListNode* basicL2 = L2->H;
    while(basicL2 != NULL){
        insertLast(L1,basicL2->data);
        basicL2 = basicL2->next;
    }
}

// void deleteNode(ListType* L1, element e){
//     ListNode* boforeL1 = L1->H;
//     ListNode* prev;

//     while(boforeL1 != NULL){
//         if(boforeL1->data == e){
//             if(boforeL1 == L1->H){//삭제할 인덱스가 노드의 첫번째 인경우
//                 boforeL1->next = boforeL1->next->next;
//             }
//             else if(boforeL1->next == NULL){//삭제할 인덱스가 노드의 마지막인 경우
//                 boforeL1->next = NULL;
//             }
//             else{
//                 printf("삭제할 노드[%d]의 이전 노드: [%d]\n",boforeL1->data,prev->data);
//                 prev->next = boforeL1->next;
//                 boforeL1 = prev;
//             }
//         }
//         prev = boforeL1;
//         boforeL1 = boforeL1->next;

//     }
//     ListNode* AfterL1 = L1->H;
//     while(AfterL1 != NULL){
//         printf("-");
//         if(boforeL1->data == e)deleteNode(L1,e);
//         AfterL1 = AfterL1->next;
//     }printf("\n");
//     // printf("L1 Size = %d\n",L1size);
// }

/*----------------*/
// 노드 삭제 함수
void deleteNode(ListType *L, element e) {
    ListNode *prev = NULL;
    ListNode *curr = L->H;
    ListNode *temp = NULL;

    while (curr != NULL) {//순회
        if (curr->data == e) {//현재 노드에서 데이터를 찾으면
            if (prev == NULL) {//데이터를 찾았을 때 처음이라면.
                L->H = curr->next; //리스트의 헤드를 현재 노드의 다음 노드로 저장한다.
            } 
            else {//prev를 널이 아닌 경우 ==  데이터를 찾았고 연결함.
                prev->next = curr->next;
                //널의 값 다음을 찾는 값이 아닌 다음 노드의  다음으로 설정한다.
            }
            temp = curr;
            curr = curr->next;
            free(temp);
        } 

        else {//찾지못하면
            prev = curr;//pre값에 현재 순회중인 노드를 저장
            curr = curr->next;//노드 순회
        }
    }
}
/*--------*/


void reverse(ListType* L2){
    ListType* tmp = (ListType*)malloc(sizeof(ListType));
    ListType* rst = (ListType*)malloc(sizeof(ListType));
    init(tmp); init(rst);

    // printf("Processing reverse..");

    ListNode* curr = L2->H;
    // ListNode tmpNode = tmp->H;
    while(curr != NULL){
        insertFirst(tmp,curr->data);
        curr = curr->next;
    }//tmp에 L2의 반전값 저장
    // printf("tmp : ");
    // print(tmp);
    // L2 = tmp;

    //L2의 첫번째 임의의 노드를 생성하고 그 노드의 next를 tmp로 설정 후 그 임의의 노드 삭제
    insertFirst(L2,0);
    L2->H->next = tmp->H;
    L2->H = L2->H->next;

    
}

void deleteAll(ListType* L1){
    L1->H = NULL;
}

int main(){
    ListType* H = (ListType*)malloc(sizeof(ListType));
    init(H);
    /*
    이 연결리스트로 정수 리스트 하나(L1)와 빈 리스트 하나(L2)를 만든다. 
    정수 리스트의 정수 데이터는 반드시 1 ~ 20까지의 
        난수 15개를 발생시켜 생성한다. 
    본인이 입력함수(scanf())를 이용하여 임의로 
        값 을 입력하는 경우 총 점수의 50%가 감점이다. 
        리스트 출력 함수에서 마지막에 NULL이 출력되도록 한 다.
    */
    ListType L1, L2; 
    init(&L1); init(&L2); srand(time(NULL));
    for(int i = 0; i < 15; i++) insertFirst(&L1, rand() % 20 + 1);
    print(&L1);
    /**
    3. 정수 리스트(L1)를 위치(pos)를 입력받아 
    두 개의 리스트(L1, L2)로 나누는 partition() 함수를 작성하 고 테스트한다. 
    
    pos까지가 L1 리스트이고 pos 다음부터 마지막까지가 L2 리스트이다.
     */
    int pos;
    scanf("%d", &pos); 
    
    partition(&L1, &L2, pos); 
    print(&L1); 
    print(&L2);

    /*
    4. 위에서 분할된 두 리스트 L1, L2를 L1으로 
    다시 연결하는 concat() 함수를 작성하고 테스트한다. 
    L1은 원래의 리스트로 복원될 것이고 L2는 위에서 분할된 결과 그대로일 것이다.
    */
   concat(&L1, &L2); print(&L1); print(&L2);
   
   /*
   5. 리스트에서 특정한 값을 모두 삭제하는 deleteNode() 함수를 작성하고 테스트한다. 
   삭제할 값은 시뮬레 이션 리스트에 가장 많이 중복된 값으로 선택한다.
   */
    element e;
    scanf("%d", &e); 
    deleteNode(&L1, e); 
    print(&L1); 
    print(&L2);

    /*
    6. 리스트를 역순으로 만드는 reverse() 함수를 만들고 테스트한다. 
    주어진 환경에서 이를 구현하려면 세 개의 포인터 p, q, r이 필요하다. 
    리스트 L2를 역순으로 만들어보자.
    
    */
   reverse(&L2); 
   print(&L2);

    /*
    7. 리스트의 모든 노드를 삭제하는 deleteAll() 함수를 만들고 테스트하라.
    */
   deleteAll(&L1); print(&L1);
}
/*

9 12 11 3 12 12 10 19 14 5 6 1 19 19 18 NULL
19 10 14 5 6 1 18 NULL

*/