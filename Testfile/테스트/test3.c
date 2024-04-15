#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}ListNode;


int main(){
    //순환문이용
    ListNode* head = (ListNode*)malloc(sizeof(ListNode)); //헤드 노드 생성
    ListNode* end = (ListNode*)malloc(sizeof(ListNode)); //엔드 노드 생성
    end = NULL;// end->next = end; 
    head->next = end; 

    int n; scanf("%d",&n);
    int *num = (int *)malloc(sizeof(int)*n);




} 
