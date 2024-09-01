#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int bin_search(int *arr,int n,int key){
    int LOW,MID,HIGH;
    LOW = 0,HIGH = n-1;
    // printf("L:%d M:%d H:%d",LOW,MID,HIGH);
    do{
        MID = (HIGH+LOW)/2;
        // if(MID > HIGH || LOW > MID) break;
        if(key == arr[MID])return MID;
        else if(key < arr[MID]){//배열의 중앙값보다 작은 경우
            HIGH = MID-1; 
        }
        else { // printf(">배열의 중앙값보다 큰 경우\n");   
            LOW = MID+1; // printf("L:%d M:%d H:%d\n",LOW,MID,HIGH);
        }
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
/*
7
15 27 39 77 92 118 121   
*/