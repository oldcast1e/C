#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;

ListNode* insert(ListNode *head, ListNode *pre, int value){
    ListNode *p=(ListNode *)malloc(sizeof(ListNode));

    p->data=value;
    p->link=pre->link;
    pre->link=p;

    return head;
}