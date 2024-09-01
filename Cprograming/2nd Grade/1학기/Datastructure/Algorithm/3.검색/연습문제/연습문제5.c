#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/**
 * [연습문제 5]
 * 검색할 값과 같은 값을 갖는 요소가 하나이상일 경우 같은 값 중 가장 앞으로 요소를 찾는 함수를 작성하라.
 */
int bin_search2(int arr[],int n,int key){
    int LOW,MID,HIGH;

    LOW = 0;
    HIGH = n -1;
    do{
        MID = (LOW + HIGH)/2;
        if(arr[MID] == key) return MID;
        else if(arr[MID] < key) LOW = MID + 1;
        else HIGH = (MID -1);
        /**
        중앙값보다 검색하고자 하는 값이 큰 경우
        -> (중앙값+1)를 LOW로
        
        중앙값보다 검색하고자 하는 값이 작은 경우
        -> (중앙값-1)를 HIGH
         */
    }while(LOW <= HIGH);
    return -1;
    /**
    LOW  : 검색 범위 맨 앞의 인덱스 == pl
    MID  : 검색 범위 가운데 인덱스  == pr
    HIGH : 검색 범위 맨 뒤의 인덱스 == pc
    */

}

int main(){
    int num,key,cnt=0;
    printf("이진검색\n");
    printf("요소 개수: ");scanf("%d",&num);

    int *arr = (int*)malloc(sizeof(int)*num);
    printf("오름차순으로 입력하세요.\n");

    while(num > cnt){
        if(cnt == 0){
            printf("x[%d]: ",cnt);
            scanf("%d",&arr[cnt]);    
            cnt ++;
        }
        else{
            printf("x[%d]: ",cnt);
            scanf("%d",&arr[cnt]);    
            if(arr[cnt-1] <= arr[cnt]) cnt ++;
            else printf("오름차순으로 다시 입력하세요.\n");
        }
    }
    printf("검색값: ");scanf("%d",&key);

    int idx  = bin_search2(arr,num,key);
    if(idx == -1) puts("검색에 실패했습니다.");
    else{
        for(int i=idx;i>=1;i--){
            if(arr[i-1]!=key){
                printf("첫번째 검색값 %d는 arr[%d]에 있습니다.",key,idx);
                break;
            }
        }
        // printf("%d는 arr[%d]에 있습니다.",key,idx);
    }
    free(arr);
}