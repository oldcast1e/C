#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*연결 리스트를 구현할 구조체*/
typedef struct ListNode {
   int data1;// 항의 계수
   int data2; // 항의 차수
   struct ListNode *next;//다음 노드의 위치
   struct ListNode *pre;//이전 노드의 위치
}ListNode;

int main(void){
   int num,n,m,cnt=0;
   //num : 연결리스트의 개수
   ListNode* firhead = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
   scanf("%d",&num);

   for(int i=0;i<num;i++){//항의 계수만큼 반복하되, 한번의 입력과정에서 계수와 차수를 입력받음.
      scanf("%d %d",&n,&m);//계수와 차수를 입력받는다.
      //n: data1
      //m: data2
      ListNode* curr = firhead; //순회용 노드 생성
      for(cnt=0;cnt<i;cnt++)curr= curr->next;

      ListNode *new=(ListNode *)malloc(sizeof(ListNode));//추가할 노드를 동적할당한다.
      new->data1 = n;
      new->data2 = m;

      curr ->next = new;
      new->pre = curr;
      printf("입력된 두 정수의 값: %d %d\n",new->data1,new->data2);
   }
    ///
    ListNode* print = firhead->next; //순회용 노드 생성
	while(print != NULL){
		printf(">%d %d\n", print->data1,print->data2);
		print = print->next;
	}
}