#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*[ 문제 4 ] N 개의 정수를 입력 받아 (N ≤ 20), 
최댓값을 구하는 프로그램을 작성하시오.

◦ 다음 예에서 보여주는 재귀 관계를 이용하여 구현하시오 
(재귀 함수 사용). 
- 예: (4, 1, 8, 3, 7)의 최댓값 ⇒ (4, 1, 8, 3)의 최댓값과 7 중 큰 값
*/

int max_fuc(int *num,int size, int *pmax){
    if(size > 0){
        for(int i=0;i<size;i++){
            //printf("%d, ",num[i] );
            if(num[i] > *pmax) *pmax = num[i];
        }//printf(" <-> %d\n",num[size]);
        size --;
        return max_fuc(num,size,pmax);
    }
    return *pmax;
}
int main(){
    int N,max = -1,*pmax = &max; 
    scanf("%d",&N);

    int *num = (int *)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++)scanf("%d",&num[i]);
    max = num[N-1];

    int rst  = max_fuc(num,N-1,pmax);
    printf("%d",rst);    
} 
/*
5
4 1 8 3 7
*/