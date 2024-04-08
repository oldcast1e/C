#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}listnode;

int main(){
    //순환문이용
    int n; scanf("%d",&n);
    int *num = (int *)malloc(sizeof(int)*n);

    /*이중동적*/
    int **dnum = (int **)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++) dnum[i] = (int *)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++)scanf("%d",&num[i]);
    for(int i=0;i<n;i++)printf("%d",num[i]);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)printf("%d ",dnum[i][j]);
        printf("\n"); cnt++;
    }



} 
