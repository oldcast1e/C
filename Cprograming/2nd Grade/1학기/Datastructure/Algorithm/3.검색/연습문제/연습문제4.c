#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/**
 * [연습문제4]
 * 이진 검색의 과정을 자세히 출력하는 프로그램을 작성하라
 * 
 * 각 행의 맨 왼쪽에 현재 검색하고 있는 요소의 인덱스를 출력하고,
 * 검색범위의 맨 앞 위에 <-, 맨 끝 요소 위에 ->
 * 현재 검색하고 있는 중앙 요소 위에 +를 출력하라.
 */
int main() {
    int num,key,cnt=0;
    int LOW,MID,HIGH;
    printf("[이진 검색]\n");
    printf("검색 개수: ");scanf("%d",&num);
    
    
    int *arr = (int*)malloc(sizeof(int)*(num+1));//보초를 위한 공간 추가 할당
    for(int i=0;i<num;i++){printf("X[%d]: ",i);scanf("%d",&arr[i]);}
    arr[num] = key;

    printf("검색값: ");scanf("%d",&key);
    printf("검색을 시작합니다....\n\n");

    printf("    |");for(int i=0;i<num;i++)printf("%3d",arr[i]);printf("\n");
    printf("----+");for(int i=0;i<num*3+1;i++)printf("-");
    printf("\n");//인터페이스
    
    LOW = 0,HIGH=num-1;
    do{ 
        MID = (LOW + HIGH)/2;
        printf("  %d |",cnt);for(int i=0;i<num;i++)printf("%3d",arr[i]);printf("\n");
        if(arr[MID] == key) return MID;
        else if(arr[MID] < key) LOW = MID + 1;
        else HIGH = (MID -1);

        cnt ++;
    }while(LOW <= HIGH);
    // for(int i=1;i<=num+1;i++){
    //     if(i == num+1){
    //         printf("\n검사실패...\n");
    //         break;
    //     }
        
    //     printf("    |");for(int j=0;j<i*2+cnt;j++)printf(" "); printf("*\n");
    //     printf("  %d |",i);for(int i=0;i<num;i++)printf("%3d",arr[i]);printf("\n");
    //     if(arr[i-1]==key){
    //         printf("\n검사완료!\n");
    //         printf("%d는 x[%d]에 존재합니다.",key,i);
    //         break;
    //     }
        
    //     cnt ++;
    // }
}		
