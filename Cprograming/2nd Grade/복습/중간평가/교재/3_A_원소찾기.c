#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int findRow(int *A, int x, int n){
    int i = 0;
    // int n = (int)sizeof(A)/(int)sizeof(A[0]);
    printf("Clen = %d\n",n);
    while(n > i){
        if(A[i] == x) return i;
        else i  = i+1;
    }
    return -1;
}

void findMatrix(int **A,int x, int n){
    int i=0,j=0;
    // int n = (int)sizeof(**A);
    // for(int i=0;i<5;i++)printf("%d",A[0][i]);
    // printf("Rlen = %d\n",n);
    while(n > i){
        int val  = findRow(A[i],x,n);
        if(val == -1) i++;
        else {
            printf("find x in A[%d][%d]",i,val);
            break;
        }
    }
}



void randSave(int *A, int len){
    
    for(int i=0;i<len;i++){
        A[i] = rand()%10;
        printf("%d ",A[i]);
    }printf("\n");
}

int main(){
    int n; 
    // scanf("%d",&n);
    n = 5;
    int *num = (int*)malloc(sizeof(int)*n);
    
    int **dnum = (int **)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++) dnum[i] = (int*)malloc(sizeof(int)*n);
    srand(time(NULL));

    for(int i=0;i<n;i++)randSave(dnum[i],n);
    findMatrix(dnum,8,n);
}