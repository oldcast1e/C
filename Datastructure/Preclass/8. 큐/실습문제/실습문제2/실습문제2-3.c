#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct ListNode {
	char data;//현재 노드가 가지고 있는 데이터(값)
	struct ListNode *next;//다음 노드의 위치
    struct ListNode *pre;//이전 노드의 위치
}ListNode;

// add_front(list, r, e) : list의 순위 r에 원소 e를 추가한다.
ListNode* add_front(ListNode *start, int value){//구조체 함수
    // printf("processing of add_front\n");
    /*list의 순위 r에 원소 e를 추가해야함으로 순위r까지 반복한 후 해당 위치에 원소 e를 추가하도록한다.*/
    int tmp = start->data;
    ListNode *new = (ListNode *)malloc(sizeof(ListNode));//추가할 노드를 동적할당한다.

    new->pre = start;
    new -> next = start->next;

    start->next = new;

    start->data = value;
    new->data = tmp;

    return start; //다음 노드의 위치를 반환함.
}

// ListNode* add_rear(ListNode *start, int value){//구조체 함수
//     printf("processing of add_rear: %d\n",value);
//     int cnt = 0;
//     ListNode* check =  (ListNode *)malloc(sizeof(ListNode));//추가할 노드를 동적할당한다
//     check = start;
//     while(check->next != NULL){
//         printf("check->data: %d\n",check->data);
// 	    cnt ++;
// 	    check = check->next;
//     }
//     printf("cnt = %d\n",cnt);

//     ListNode *p=(ListNode *)malloc(sizeof(ListNode));//추가할 노드를 동적할당한다.
    

//     (check)->next = p;
//     p->pre = check;
//     p->data = value;
//     printf("p->data: %d\n",check->next->data);
//     // check->next =p;
//     p ->next = NULL;
    
//     free(check);
//     /*
//     ListNode* prt = start; //순회용 노드 생성
//     while(prt->next != NULL){
// 	    printf("%d ", prt->data);
// 	    prt = prt->next;
//     }free(prt);
//     printf("\n");
//     */
    
//     return start; //다음 노드의 위치를 반환함.
// }

// delete(list, r) : list의 순위 r에 위치한 원소를 삭제한다 (주교재의 remove와 동일)
ListNode* delete_front(ListNode *start){//구조체 함수
    printf("processing of delete_front\n");
    start->data = (start->next)->data;
    start->next = (start->next)->next;
    start->pre = NULL;
    return start; //다음 노드의 위치를 반환함.
    
}

// delete(list, r) : list의 순위 r에 위치한 원소를 삭제한다 (주교재의 remove와 동일)
ListNode* delete_rear(ListNode *start){//구조체 함수
    printf("processing of delete_rear\n");
    int cnt = 0;
    ListNode* del = start; //순회용 노드 생성
    while(del->next != NULL){
	    cnt ++;
	    del = del->next;
    }
    printf("del = %d\n",(del->pre)->data);
    // (del->pre)->next = NULL;
    return start; //다음 노드의 위치를 반환함.
}

void add_rear(ListNode *start, int data){
	// 전달받은 값을 저장하는 새로운 노드를 생성한다.
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    newNode->data = data;
    printf("newNode->data = %d\n",newNode->data);
	// 헤드에 아무것도 없을 경우
	// 즉, 현재 노드가 하나도 없을 경우
	if(start == NULL){
		// 헤드에 생성한 노드를 연결
        start = newNode;
    }
	else{
		ListNode* tmp = start;
		// 마지막 노드를 찾는 루프
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		// 마지막 노드일 경우 새로 생성한 노드 연결
		tmp->next = newNode;
        printf(">>newNode->data = %d\n",newNode->data);

	}
}


void print(ListNode *start){
    printf("processing of print\n");
    ListNode* prt = start; //순회용 노드 생성
    while(prt->next != NULL){
	    printf("%d ", prt->data);
	    prt = prt->next;
    }free(prt);
    printf("\n");
}
int main(void){
    int N,data;scanf("%d",&N);getchar();
    char chk[3],tmp;
    ListNode* start = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    ListNode* last = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    start->next = last;
    start->pre = NULL;

    last->next = NULL;
    last -> pre = start;

    for(int i=0;i<N;i++){
        scanf("%s%c",chk,&tmp);
        if(strcmp(chk,"AF") == 0){
            scanf("%d",&data);getchar();
            // printf(">Input: AF\n");
            add_front(start,data);
        }
        else if(strcmp(chk,"AR") == 0){
            scanf("%d",&data);getchar();
            // printf(">Input: AR\n");
            add_rear(start,data);
        }

        else if(strcmp(chk,"DF") == 0){
            // printf(">Input: DF\n");
            delete_front(start);
        }

        else if(strcmp(chk,"DR") == 0){
            // printf(">Input: DR\n");
            delete_rear(start);
        }

        else if(strcmp(chk,"P") == 0){
            // getchar();
            // printf(">Input: P\n");
            print(start);
        }

        
    }

    
}
/**
10
AF 10
AF 20
AF 30
AR 40
 */