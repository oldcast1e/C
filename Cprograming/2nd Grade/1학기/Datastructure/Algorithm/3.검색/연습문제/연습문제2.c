#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/**
 * Q2. 선형 검색의 스캐닝 과정을 상세하게 표시하는 프로그램을 작성하시오.
 */
int main() {
    int num,key,cnt=0;
    printf("[선형 검색]\n");
    printf("검색 개수: ");scanf("%d",&num);
    
    int *arr = (int*)malloc(sizeof(int)*(num+1));//보초를 위한 공간 추가 할당
    for(int i=0;i<num;i++){printf("X[%d]: ",i);scanf("%d",&arr[i]);}
    arr[num] = key;

    printf("검색값: ");scanf("%d",&key);

    printf("검색을 시작합니다....\n\n");
    printf("    |");for(int i=0;i<num;i++)printf("%3d",arr[i]);printf("\n");
    printf("----+");for(int i=0;i<num*3+1;i++)printf("-");
    printf("\n");
    for(int i=1;i<=num+1;i++){
        if(i == num+1){
            printf("\n검사실패...\n");
            break;
        }
        
        printf("    |");for(int j=0;j<i*2+cnt;j++)printf(" "); printf("*\n");
        printf("  %d |",i);for(int i=0;i<num;i++)printf("%3d",arr[i]);printf("\n");
        if(arr[i-1]==key){
            printf("\n검사완료!\n");
            printf("%d는 x[%d]에 존재합니다.",key,i);
            break;
        }
        
        cnt ++;
    }
}	
//6 4 3 2 1 9 8