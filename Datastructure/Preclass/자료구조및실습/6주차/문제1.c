#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    //연결리스트 본체: 가지고 있는 데이터 값과 전/후방 연결위치 저장
	int coe; //계수
    int squ; // 제곱수
	struct Node* next;

}Listnode;

typedef struct list {
    //리스트의 정보 :  리스트의 헤드노드와 테일 노드의 설정 구조체
	int size;
	Listnode* head;
	Listnode* trail;
}list_info;

void add(list_info* list,int Ncoe,int Nsqu){
    //계수:coe       제곱수:squ
	Listnode* curr = list->head;
	for (int i = 0; i < Nsqu; i++) {curr = curr->next;}
	Listnode* new = (Listnode*)malloc(sizeof(Listnode)); //새로 추가할 노드
	printf("계수[%d] 제곱수[%d]\n",Ncoe,Nsqu);
    new->coe = Ncoe;
    new->squ = Nsqu;
	new->next = curr;
	list->size++;

}
void delete(list_info* list,int squ){
    printf(">제곱수[%d]의 제거\n",squ);
	Listnode* curr = list->head;
	for (int i = 0; i < squ-1; i++) {
		curr = curr->next; // rank의 전 노드 위치까지 반복
	}
    /*
    1. "지울 노드의 뒷 노드(curr)"의 다음 노드는 
    "지울 노드의 다음 노드"가 NULL이 아니라면 
    "지울 노드의 다음 노드(curr->next->next)"가 되어야함.
    */
    if(curr->next->next != NULL){
        curr->next = (curr->next)->next;
    }
    else curr->next = list->trail;
	// (del->prev)->next = del->next;
	// (del->next)->prev = del->prev;
	// list->size--;
}
void print(list_info* list) {
    // printf("loading...\n");
	Listnode* p = list->head->next;
	while (p != list->trail) { 
		printf("%c", p->coe);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	list_info* xlist = (list_info*)malloc(sizeof(list_info));
	xlist->head = (Listnode*)malloc(sizeof(Listnode));
	xlist->trail = (Listnode*)malloc(sizeof(Listnode));
	xlist->head->next = xlist->trail;
	xlist->trail->next = NULL;
	xlist->size = 0;

    list_info* ylist = (list_info*)malloc(sizeof(list_info));
	ylist->head = (Listnode*)malloc(sizeof(Listnode));
	ylist->trail = (Listnode*)malloc(sizeof(Listnode));
	ylist->head->next = ylist->trail;
	ylist->trail->next = NULL;
	ylist->size = 0;

	int n,m,tmp_c,tmp_s,coe,squ;//
	scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&tmp_c,&tmp_s);
        printf(">%d %d\n",tmp_c,tmp_s);
        if(i==0){
            // printf(">%d %d",tmp_c,tmp_s);
            for(int j=tmp_s;j>=0;j--){
                // add(list_info* list,int squ,int coe)
                add(xlist,0,j);//계수/제곱수
            }
        }
        delete(xlist,tmp_s);printf(">제곱수[%d]의 추가\n",tmp_s);
        // add(xlist,tmp_c,tmp_s);
    }
    print(xlist);
    // scanf("%d",&m);
    // for(int i=0;i<n;i++){scanf("%d",&coe);add(ylist,i+1,coe);}



}
/*


3
5 3 3 2 3 1
3
2 6 2 3 1 0
*/