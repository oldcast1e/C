#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
}Listnode;

typedef struct list {
	int size;
	Listnode* head;
	Listnode* trail;
}list_info;

void add(list_info* list,int rank,char data)
{
	Listnode* p = list->head;
	for (int i = 0; i < rank; i++) {
		p = p->next;
	}
	Listnode* new = (Listnode*)malloc(sizeof(Listnode));
	new->data = data;
	new->next = p;
	new->prev = p->prev;
	p->prev->next = new;
	p->prev = new;
	list->size++;

}

void delete(list_info* list,int rank)
{
	Listnode* p = list->head;
	for (int i = 0; i < rank; i++) {
		p = p->next;
	}
	p->prev->next = p->next;
	p->next->prev = p->prev;
	list->size--;
}

void get(list_info* list,int rank) {
	Listnode* p = list->head;
	for (int i = 0; i < rank; i++) {
		p = p->next;
	}
	printf("%c", p->data);
}

void print(list_info* list) {
	Listnode* p = list->head->next;
	while (p != list->trail) { 
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	list_info* list = (list_info*)malloc(sizeof(list_info));
	list->head = (Listnode*)malloc(sizeof(Listnode));
	list->trail = (Listnode*)malloc(sizeof(Listnode));
	list->head->prev = NULL;
	list->head->next = list->trail;
	list->trail->prev = list->head;
	list->trail->next = NULL;
	list->size = 0;

	int n;
	scanf("%d",&n);
	getchar();

	char operator ;
	for (int i = 0; i < n; i++) {
		scanf("%c", &operator);
		if (operator=='A') {
			int r;char data;
			scanf("%d %c", &r, &data);
			if ((r > list->size + 1) || (r < 1)) {printf("invalid position\n");}
            else add(list,r, data);
			getchar();
		}
		else if (operator=='D') {
			int r;
			scanf("%d", &r);
			if ((r > list->size) || (r < 1)) {printf("invalid position\n");}
			else delete(list, r);
			getchar();
		}
		else if (operator=='G') {
			int r;
			scanf("%d", &r);
			if (r > list->size) {printf("invalid position\n");}
			else get(list, r);
			getchar();
		}
		else if (operator=='P') {
			getchar();
			print(list);
		}
	}
	return 0;
}