#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}ListNode;


int main(){
    int A[5];
    int k = sizeof(A)/(int)sizeof(A[0]);
    // printf("%d",k);
    printf("%d",(int)sizeof(A));



} 
