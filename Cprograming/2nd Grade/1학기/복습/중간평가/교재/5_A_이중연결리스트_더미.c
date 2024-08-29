#include<stdio.h>
#include<stdlib.h>

typedef char element;

typedef struct DListNode{
    /* data */
    element data;
    struct DListNode* next;//자기참조
    struct DListNode* prev;

}DListNode;

typedef struct DListType{
    /* data */
    DListNode* Head;
    DListNode* Tail;
    int size;
}DListType;

void initialize(DListType* linkNode){
    linkNode->Head = NULL;
    linkNode->Tail = NULL;
    linkNode->size = 0;

    // linkNode->Head->next = linkNode->Tail ;
    // linkNode->Tail->prev = linkNode->Head;


}

void traverse(DListType* linkNode,int r){
    DListNode* curr = linkNode->Head;
    if((r<0)||(r>linkNode->size))printf("Invailed Connection.\n");
    else
        if(curr->next != NULL){
            curr = curr->next;
            /*function*/
            // printf("[%d]=>",curr->data);
        }
}
void print(DListType* linkNode){
    DListNode* curr = linkNode->Head;
    printf("[Head]=>");
    if(curr != NULL){
        /*function*/
        printf("[%c]=>",curr->data);
        curr = curr->next;
    }
    printf("[Tail]\n");
}

void insertFirst(DListType* linkNode, element val){
    DListNode* new = (DListNode*)malloc(sizeof(DListNode));
    new->data = val;
    linkNode->size ++;

    printf("----1----\n");
    (linkNode->Head->next)->prev = new;
    new->next = linkNode->Head->next;
    printf("----2----\n");
    // linkNode->Head->next = new;
    // new->prev = linkNode->Head;


}

void inssertLast(DListType* linkNode, element data){
    

}

void inssert(DListType* linkNode, element data, int rank){


}

int main(){
    DListType linkNode;
    initialize(&linkNode);
    linkNode.Head->next = linkNode.Tail;
    linkNode.Tail->prev = linkNode.Head;
    printf("-----");
    // insertFirst(&linkNode,'A');
    // print(&linkNode);
}
