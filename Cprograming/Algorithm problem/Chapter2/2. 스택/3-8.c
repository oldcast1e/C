#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
/*스택을 구현하는 구조체*/
typedef struct Stack{
    int data;
    struct Stack *next;
}IntStack;

// void InitializeStack(IntStack *head, int data){}

void Push(IntStack *head, int ipt){
    IntStack *prtStack = (IntStack*)malloc(sizeof(IntStack));
    prtStack->data = ipt;

    prtStack->next = head->next;
    head->next = prtStack;
}

int Pop(IntStack *head){
    IntStack *delStack = (IntStack*)malloc(sizeof(IntStack));

    delStack = head->next;
    head->next = head->next->next;
    int val = delStack->data;    
    free(delStack);

    return val;
}

void Print(IntStack *head,IntStack *tail){
    /*순회용 노드*/
    printf("[스택의 값 출력]\n");
    IntStack *cnt = head->next;
    while(cnt != tail){
        printf("%d",cnt->data); if(cnt->next != tail)printf("\n");
        cnt = cnt->next;
    }
}

int main(){
    IntStack *head = (IntStack*)malloc(sizeof(IntStack));
    IntStack *tail = (IntStack*)malloc(sizeof(IntStack)); 

    head->next = tail;
    tail->next = tail;

    for(int i=0;i<5;i++){
        Push(head,(i+1)*10);
    }
    Print(head,tail);
    // if(cnt != tail)
    printf("\n\n--Pop 함수 사용--\n\n");
    Pop(head); Print(head,tail);
}