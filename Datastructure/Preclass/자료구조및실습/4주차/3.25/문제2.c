#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
[ 문제 2 ] (20점) N (2 ≤ N ≤ 100) 개의 정수로 이루어진 수열 X를
 “위치 바꿈 정보”에 의해 변 환한 최종 결과를 출력하는 
 프로그램을 작성하시오. 
 
 위치 바꿈 방식은 다음과 같다. 
 예를 들어, 10 개 정수의 수열 X와 위치 바꿈 정보가 
 다음과 같이 주어졌을 때,

 */
int main(){
    int n,swb,tmp,cnt=1; 
    scanf("%d",&n);//수열의 크기
    int num[101];
    for(int i=0;i<n;i++)scanf("%d",&num[i]);//첫번째 수열 입력

    scanf("%d",&swb);//바꿈 정보 횟수 입력
    signed int *snum = (int *)malloc(sizeof(int)*swb);
    for(int i=0;i<swb;i++)scanf("%d",&snum[i]);//두번째 수열 입력
    
    signed int *save = (int *)malloc(sizeof(int)*(swb-1));
    for(int i=0;i<swb-1;i++){save[i] = num[snum[i]];}
    /*
    (순서바꿈 정보의 길이 - 1)만큼 반복
    = 처음과 마지막 위치는 항상 동일
    */
    for(int i=0;i<swb-1;i++){num[snum[swb-1-i]] = save[swb-2-i] ;}
    for(int i=0;i<n;i++) printf(" %d",num[i]);    
} 
/*
10
3 81 9 12 0 –9 36 33 91 10
5
3 8 0 9 3

6
0 20 40 30 10 50 
4
1 2 4 1
*/