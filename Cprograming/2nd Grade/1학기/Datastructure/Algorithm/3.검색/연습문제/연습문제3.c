#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/**
 * 요소가 n인 배열 a에서 key와 일치하는 모든 요소의 인덱스를 배열 idx의 맨 앞부분 부터 순서대로 저장하고
 * 일치한 요소의 개수를 반환하는 함수를 작성하라.
 */

int search_idx(int arr[],int num,int key,int idx[]){
    int cnt =0;
    for(int i=0;i<num;i++){
        if(arr[i] == key){
            idx[cnt] = i;
            cnt ++;
        }
    }
    return cnt;
}
int main() {
    int num,key;
    printf("요소의 개수를 입력하세요: ");scanf("%d",&num);
    int *arr = (int*)malloc(sizeof(int)*num);
    int *idx = (int*)malloc(sizeof(int)*num);
    for(int i=0;i<num;i++){printf("arr[%d]: ",i);scanf("%d",&arr[i]);}

    printf("검색하고자 하는 숫자를 입력하세요: ");scanf("%d",&key);
    
    int rst = search_idx(arr,num,key,idx);
    printf("반환값: %d\n",rst);
    for(int i=0;i<rst;i++)printf("%d번째 검색된 인덱스: %d\n",i+1,idx[i]);


}	
