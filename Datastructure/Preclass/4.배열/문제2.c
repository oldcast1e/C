/**[ 문제 2 ] (20점) N (2 ≤ N ≤ 100) 개의 정수로 이루어진 수열 X를 
“위치 바꿈 정보”에 의해 변 환한 최종 결과를 출력하는 프로그램을 작성하시오.
 
3 81 9 12 0 -9 36 33 91 10
dl
위치바꿈정보: 3--> 8-->0-->9-->3
(위치 바꿈 정보를 구성하는 수의 범위는 0~N-1이다. 주어지는 위치 바꿈 정보에서 처음과 마지막 위치는 항상 동일하고, 
그 외에는 동일한 위치는 없다고 가정하라.)

◦ 위 순서 바꿈 정보에 의해, 수열 X에서
3번 위치의 정수 ‘12’는 8번 위치로 이동,
8번 위치의 정수 ‘91’은 0번 위치로 이동,
0번 위치의 정수 ‘3’은 9번 위치로 이동,
9번 위치의 정수 ‘10'은 3번 위치로 이동 시킨다.

 */
#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct list{
    int data;
    int pre_data;
    struct list *next;
};
int main(){
    int N,rev_arr[101],rev_cnt;
    scanf("%d",&N);
    struct list *system = NULL;
    system = (struct list*)malloc(sizeof(struct list)*N);
    for(int i=0;i<N;i++){
        scanf("%d",&system[i].data);
        system[i].pre_data = system[i].data;
    }
    scanf("%d",&rev_cnt);
    for(int j=0;j<rev_cnt;j++)scanf("%d",&rev_arr[j]);
    for(int j=0;j<rev_cnt-1;j++){
        system[rev_arr[j]].next = &system[rev_arr[j+1]];
        system[rev_arr[j]].next->data = system[rev_arr[j]].pre_data;
    }
    for(int i=0;i<N;i++)printf("%d ",system[i].data);
}

/**
6
0 20 40 30 10 50 
4
1 2 4 1

10
3 81 9 12 0 –9 36 33 91 10
5
3 8 0 9 3
 91 81 9 10 0 -9 36 33 12 3 
>91 81 9 10 0 –9 36 33 12 3
 */



    // for(int i=0;i<N;i++)printf(">%d",system[i].data);
