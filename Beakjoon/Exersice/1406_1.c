/*
한 줄로 된 간단한 에디터를 구현하려고 한다. 
이 편집기는 영어 소문자만을 기록할 수 있는 편집기로, 
최대 600,000글자까지 입력할 수 있다.

이 편집기에는 '커서'라는 것이 있는데, 커서는 문장의 맨 앞(첫 번째 문자의 왼쪽), 
문장의 맨 뒤(마지막 문자의 오른쪽), 
또는 문장 중간 임의의 곳(모든 연속된 두 문자 사이)에 위치할 수 있다. 
즉 길이가 L인 문자열이 현재 편집기에 입력되어 있으면, 커서가 위치할 수 있는 곳은 L+1가지 경우가 있다.

이 편집기가 지원하는 명령어는 다음과 같다

L	커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
D	커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
B	커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
P $	$라는 문자를 커서 왼쪽에 추가함

초기에 편집기에 입력되어 있는 문자열이 주어지고, 그 이후 입력한 명령어가 차례로 주어졌을 때, 
모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 구하는 프로그램을 작성하시오. 
단, 명령어가 수행되기 전에 커서는 문장의 맨 뒤에 위치하고 있다고 한다.


입력
>첫째 줄에는 초기에 편집기에 입력되어 있는 문자열이 주어진다. 
이 문자열은 길이가 N이고, 영어 소문자로만 이루어져 있으며, 길이는 100,000을 넘지 않는다. 
>둘째 줄에는 입력할 명령어의 개수를 나타내는 정수 M(1 ≤ M ≤ 500,000)이 주어진다. 
>셋째 줄부터 M개의 줄에 걸쳐 입력할 명령어가 순서대로 주어진다. 명령어는 위의 네 가지 중 하나의 형태로만 주어진다.

출력
첫째 줄에 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 출력한다.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	char data;
	struct node* next;
}ListNode;

ListNode* insert_rank(ListNode *head, int rank, int data){//구조체 함수
    /*list의 순위 r에 원소 e를 추가해야함으로 순위r까지 반복한 후 해당 위치에 원소 e를 추가하도록한다.*/
    int cnt = 0;
    ListNode* tmp = head->next; //순회용 노드 생성
    while(tmp != NULL){
	    cnt ++;
	    tmp = tmp->next;
    }free(tmp);

    
    // if(cnt == 0){
    //     ListNode* new_head = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    //     head = new_head;
    //     // ListNode* curr = head; //순회용 노드 생성
    // }
    ListNode* curr = head; //순회용 노드 생성
    
       
    
    for(int i=0;i<rank && cnt!=0;i++)curr= curr->next;
    // printf("순위가 r인 노드의 데이터는 %c입니다.\n",curr->data);
    //위 반복문을  통해 이미 순위가 r인 노드까지 이동함.(ㄱ)
    ListNode *p=(ListNode *)malloc(sizeof(ListNode));//추가할 노드를 동적할당한다.

    p->data = data;
    p->next = curr->next;
    curr->next = p;
    // printf("추가된 노드의 데이터는 %c입니다.\n",p->data);
    printf("현재 연결리스트의 크기: %d\n",cnt);
    return head; //다음 노드의 위치를 반환함.

}

ListNode* insert_last(ListNode *head, int data){//구조체 함수
    /*list의 순위 r에 원소 e를 추가해야함으로 순위r까지 반복한 후 해당 위치에 원소 e를 추가하도록한다.*/
    int cnt = 0;
    ListNode* tmp = head->next; //순회용 노드 생성
    while(tmp != NULL){
	    cnt ++;
	    tmp = tmp->next;
    }free(tmp);

    ListNode* curr = head; //순회용 노드 생성
    for(int i=0;i<cnt;i++)curr= curr->next;
    //위 반복문을  통해 이미 순위가 r인 노드까지 이동함.(ㄱ)
    ListNode *p=(ListNode *)malloc(sizeof(ListNode));//추가할 노드를 동적할당한다.

    p->data = data;
    p->next = curr->next;
    curr->next = p;
    // printf("추가된 노드의 데이터는 %c입니다.\n",p->data);
    return head; //다음 노드의 위치를 반환함.

}

ListNode* delete(ListNode *head, int rank){//구조체 함수
   
    ListNode* rear = head; //순회용 노드 생성
    for(int i=0;i<rank-1;i++)rear= rear->next;//삭제할 노드의 뒤까지 반복
    ListNode* tmp = rear->next; 
    printf("rank[%d] 데이터 [%c]를 삭제합니다.\n",rank,tmp->data);
    //삭제할 노드는 저장한 노드의 다음 노드이다. 그 노드를 임시로 저장한다. 
    rear->next = tmp->next; 
    free(tmp);
    // (삭제할 노드-1)의 다음 노드는 (삭제할 노드의 + 1)
    return head;
}

void print(ListNode *head){
    ListNode* prt = head->next; //순회용 노드 생성
    while(prt != NULL){
	    printf("%c ", prt->data);
	    prt = prt->next;
    }free(prt);
    printf("\n");
}

int main(){
    char ipt_arr[100000],edit;
    int len_ipt_arr,M;//M:입력할 명령어의 개수
    scanf("%s",ipt_arr); len_ipt_arr = strlen(ipt_arr);// 초기에 편집기에 입력되어 있는 문자열
    scanf("%d",&M);//입력할 명령어의 개수
    getchar();


    ListNode* head = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    ListNode* end = (ListNode*)malloc(sizeof(ListNode)); //엔드 노드 생성
    end = NULL;// end->next = end; 
    // head->next = end; 
    // printf("check1\n");
    for(int i=0;i<len_ipt_arr;i++){insert_last(head,ipt_arr[i]);}
    // printf("check2\n");
    // print(head);
    /**
        L	커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
        D	커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
        B	커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
    */
   int Cursor; //rank로 사용할 것임.
   Cursor = len_ipt_arr+1;

//    printf("\n Cursor = %d\n\n",Cursor);

    for(int i=0;i<M;i++){
        scanf("%c",&edit);
        if(edit == 'L'){
            if(Cursor > 0)Cursor --;
            printf("[%d]Cursor = %d\n",i,Cursor);
            getchar();
        }
        else if(edit == 'D'){
            if(Cursor < len_ipt_arr)Cursor ++;
            printf("[%d]Cursor = %d\n",i,Cursor);
            getchar();
        }
        else if(edit == 'B'){ 
            if(Cursor != 1){
                printf("<delete> Cursor = %d\n",Cursor);
                // printf("rank[%d] | 데이터 [%c] |커서[%d]를 삭제합니다.\n",rank,tmp->data,Cursor);
                delete(head,Cursor);
                if(Cursor > 1)Cursor --;
            }getchar();
            // if(Cursor > 1)Cursor --;
        }
        else if(edit == 'P'){
            char ipt,tmp;
            scanf("%c%c",&tmp,&ipt);getchar();
            printf("ipt = %c\n",ipt);
            printf("Cursor = %d\n",Cursor);
            insert_rank(head,Cursor,ipt);
        }
    }
    print(head);
    // printf("len = %d",len_ipt_arr);

}
/**

abc
9
L
L
L
L
L
P x
L
B
P y


dmih
11
B
B
P x
L
B
B
B
P y
D
D
P z
 */