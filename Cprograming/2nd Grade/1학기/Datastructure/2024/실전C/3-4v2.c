#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int bin_search(int *arr,int n,int key){
    int LOW,MID,HIGH;
    LOW = 0,HIGH = n-1;
    do{
        MID = (HIGH+LOW)/2;
        if(key == arr[MID])return MID;
        else if(key < arr[MID]) HIGH = MID-1; 
        else  LOW = MID+1; 
    }while(LOW < MID || MID < HIGH);
    return -1;
}

int main(){
    int num,key,*arr;
    printf("[선형 검색]\n");printf("검색 개수: ");scanf("%d",&num);

    arr = (int *)malloc(sizeof(int)*num);
    printf("오름차순으로 입력하세요.\n");
    for (int i = 0; i < num; i++)scanf("%d",&arr[i]);
    
    printf("검색값: ");scanf("%d",&key);
    int index  = bin_search(arr,num,key);
    if(index == -1)printf("검색에 실패했습니다.");
    else printf("%d(은)는 x[%d]에 있습니다.",key,index);
}