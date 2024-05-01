#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	int data;
    int size;
	struct node* next;
}listnode;

void print(listnode* list) {
	listnode* p = list->next;
    printf(">>");
	while (p != NULL) {
		printf(" %d", p->data);
		p = p->next;
	}printf("\n");
}

void add(listnode* list,int val) {
	
	listnode* new = (listnode*)malloc(sizeof(listnode));
	new->next = NULL;
	new->data = val;
	while (list->next != NULL) {
		list = list->next;
	}
	list->next = new;
}

int subset(listnode* list1,listnode* list2){
    listnode* big = (list1->size)>=(list2->size)?list1:list2;
	listnode* small = (list1->size)<=(list2->size)?list1:list2;
    small = small->next;
    

    int len_big = (int)(big->size);
    int len_small = (int)(small->size);
    

    int val_big,val_small = small->data;
    int rst, same = 0, etc = -1;
    
    big = big->next;
    for(int i=0;i<len_big;i++){
        val_big = big->data;
        // printf("val_big = %d | val_small = %d\n",val_big,val_small);
        if(val_big == val_small){ // 집합에 속하는 경우
            same ++;
            printf("%d : 집합에 속함 | same = %d\n",val_small,same);
            small = small->next;
            val_small = small->data;
        }
        else{//집합에 속하지 않는 경우
            if(etc == -1){
                etc = val_small;
                printf("집합에 속하지 않음\n");
            }
        }
        big = big->next;
        if(small == NULL) break;
    }

    rst = (same == len_small)?0:etc;
    printf("rst= %d\n",rst);
    return rst;
    // return 0;
}
//출력: A ⊂ B이면 0을 출력하고, 그렇지 않으면 집합 B에 속하지 않은 집합 A의 가장 작은 원 소를 표준 출력한다.

int main(){
    //순환문이용
    int N,M,num;
    listnode* list1 = (listnode*)malloc(sizeof(listnode));
	list1->next = NULL;
	listnode* list2 = (listnode*)malloc(sizeof(listnode));
	list2->next = NULL;

    scanf("%d",&N);list1->size = N;
    for(int i=0;i<N;i++){scanf("%d",&num); add(list1,num);}
    scanf("%d",&M);list2->size = M;
    for(int i=0;i<M;i++){scanf("%d",&num); add(list2,num);}

    // print(list1);print(list2);
    int rst = subset(list1,list2);
    printf("%d",rst);
} 
/*
3
4 6 13
6
1 3 4 6 8 13
*/
