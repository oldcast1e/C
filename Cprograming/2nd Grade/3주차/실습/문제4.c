#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*[ 문제 4 ] N 개의 정수를 입력 받아 (N ≤ 20), 
최댓값을 구하는 프로그램을 작성하시오.

◦ 다음 예에서 보여주는 재귀 관계를 이용하여 구현하시오 
(재귀 함수 사용). - 예: (4, 1, 8, 3, 7)의 최댓값 ⇒ (4, 1, 8, 3)의 최댓값과 7 중 큰 값
*/
int num[21],max_num = -1;
int max(int n){
    if(n > 0){
        max_num = num[n]>max_num?num[n]:max_num;
        n --;
        return max(n);
    }
    return max_num;
}
int main(){
    int N; scanf("%d",&N);
    for(int i=1;i<=N;i++)scanf("%d",&num[i]);

    int rst = max(N);
    printf("%d",rst);
    

    
} 
/*
5
4 1 8 3 7
*/