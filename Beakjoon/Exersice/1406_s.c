#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	char data;
	struct node* next;
}ListNode;

ListNode* insert_rank(ListNode *head, int rank, int data){
    /*list의 순위 r에 원소 e를 추가해야함으로 순위r까지 반복한 후 해당 위치에 원소 e를 추가하도록한다.*/
    int cnt = 0;
    ListNode* tmp = head->next; 
    while(tmp != NULL){
	    cnt ++;
	    tmp = tmp->next;
    }free(tmp);
    ListNode* curr = head; 
    
    for(int i=0;i<rank && cnt!=0;i++)curr= curr->next;

    ListNode *p=(ListNode *)malloc(sizeof(ListNode));

    p->data = data;
    p->next = curr->next;
    curr->next = p;
    
    
    return head; 

}

ListNode* insert_last(ListNode *head, int data){
    /*list의 순위 r에 원소 e를 추가해야함으로 순위r까지 반복한 후 해당 위치에 원소 e를 추가하도록한다.*/
    int cnt = 0;
    ListNode* tmp = head->next; 
    while(tmp != NULL){
	    cnt ++;
	    tmp = tmp->next;
    }free(tmp);

    ListNode* curr = head; 
    for(int i=0;i<cnt;i++)curr= curr->next;
    
    ListNode *p=(ListNode *)malloc(sizeof(ListNode));

    p->data = data;
    p->next = curr->next;
    curr->next = p;
    
    return head; 

}

ListNode* remove_node(ListNode *head, int rank){
   
    ListNode* rear = head; 
    for(int i=0;i<rank-1;i++)rear= rear->next;
    ListNode* tmp = rear->next; 
    
    
    rear->next = tmp->next; 
    free(tmp);
    
    return head;
}

void print(ListNode *head){
    ListNode* prt = head->next; 
    while(prt != NULL){
	    printf("%c ", prt->data);
	    prt = prt->next;
    }free(prt);
    printf("\n");
}

int main(){
    char ipt_arr[100000],edit;
    int len_ipt_arr,M;
    scanf("%s",ipt_arr); len_ipt_arr = strlen(ipt_arr);
    scanf("%d",&M);
    getchar();


    ListNode* head = (ListNode*)malloc(sizeof(ListNode)); 
    ListNode* end = (ListNode*)malloc(sizeof(ListNode)); 
    end = NULL;
    
    
    for(int i=0;i<len_ipt_arr;i++){insert_last(head,ipt_arr[i]);}
    
   int Cursor; 
   Cursor = len_ipt_arr+1;



    for(int i=0;i<M;i++){
        scanf("%c",&edit);
        if(edit == 'L'){
            
            
            getchar();
        }
        else if(edit == 'D'){
            if(Cursor < len_ipt_arr)Cursor ++;
            
            getchar();
        }
        else if(edit == 'B'){ 
            if(Cursor != 1){
                
                
                remove_node(head,Cursor-1);
                if(Cursor > 1)Cursor --;
            }getchar();
            
        }
        else if(edit == 'P'){
            char ipt,tmp;
            scanf("%c%c",&tmp,&ipt);getchar();
            
            
            insert_rank(head,Cursor-1,ipt);
            
        }
    }
    print(head);
    

}
