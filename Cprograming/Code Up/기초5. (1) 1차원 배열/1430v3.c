#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int bin_search2(int fir[],int n,int key){
    int LOW,MID,HIGH;

    LOW = 0;
    HIGH = n -1;
    do{
        MID = (LOW + HIGH)/2;
        if(fir[MID] == key) return MID;
        else if(fir[MID] < key) LOW = MID + 1;
        else HIGH = (MID -1);

    }while(LOW <= HIGH);
    return -1;


}

int main(){
    int key,cnt=0;
    int N,M;
    scanf("%d",&N);
    int *fir = (int*)malloc(sizeof(int)*N);
    // printf("오름차순으로 입력하세요.\n"); okay
    for(int i=0;i<N;i++)scanf("%d",&fir[i]);
    for(int i=0;i<N;i++)
        for(int j=i;j<N;j++)
            if(fir[i]>fir[j]){cnt = fir[i];fir[i] = fir[j];fir[j]=cnt;}cnt = 0;

    scanf("%d",&M);
    int *sec = (int*)malloc(sizeof(int)*M);
    for(int i=0;i<M;i++)scanf("%d",&sec[i]);
    
    for(int i=0;i<M;i++){
        int idx  = bin_search2(fir,N,sec[i]);
        if(idx == -1) printf("%d ",0);
        else printf("%d ",1);
    }

    free(fir);
}