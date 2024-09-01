#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* next;
} SlistNode;

void print(SlistNode* list) {
	SlistNode* p = list;
	while (p != NULL) {
		printf(" %d", p->data);
		p = p->next;
	}
	printf("\n");
}

void add(SlistNode* list, int val) {
	SlistNode* new = (SlistNode*)malloc(sizeof(SlistNode));
	new->data = val;
	new->next = NULL;
	
	if (list->next == NULL) {
		list->next = new;
	} else {
		SlistNode* p = list->next;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = new;
	}
}

int subset(SlistNode* A, SlistNode* B) {
    SlistNode* p_A = A->next;
    SlistNode* p_B = B->next;

    // A의 모든 원소가 B에 포함되어 있는지 확인
    while (p_A != NULL) {
        int found = 0;
        while (p_B != NULL) {
            if (p_A->data == p_B->data) {
                found = 1;
                break;
            }
            p_B = p_B->next;
        }
        if (!found) {
            // B에 포함되지 않는 원소 반환
            return p_A->data;
        }
        p_A = p_A->next;
        p_B = B->next;
    }
    // A이 B의 부분집합인 경우
    return 0;
}

int main() {
    int N, M, num;
    SlistNode* list1 = (SlistNode*)malloc(sizeof(SlistNode));
	list1->next = NULL;
	SlistNode* list2 = (SlistNode*)malloc(sizeof(SlistNode));
	list2->next = NULL;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        add(list1, num);
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &num);
        add(list2, num);
    }

    // print(list1);
    // print(list2);
    
    int rst = subset(list1, list2);
    printf("%d\n", rst);

    return 0;
} 
/*
0
3
9 20 77

3
4 6 13
6
1 3 4 6 8 13

3
7 10 53
4
7 10 15 45


0
3
9 20 77

3
9 20 77
0


*/
